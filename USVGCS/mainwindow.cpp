#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xygraph.h"
#include <QWebEnginePage>
#include <QDebug>
#include <QMessageBox>
#include <QSerialPortInfo>
#include <QFileDialog>
#include "./usv/USV/mavlink.h" //此处路径需要修改
#include "jsbchannel.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->pushButton_sendCommond->setEnabled(false);
    this->runOrStopGroup = new QButtonGroup(this);
    this->runOrStopGroup->addButton(this->ui->radioButton_stop, 0);
    this->runOrStopGroup->addButton(this->ui->radioButton_run, 1);
    // 兼容macos
    this->ui->menuBar->setNativeMenuBar(false);

    // 嵌入h5
    page = new QWebEnginePage(this);
    page->load(QUrl("file:///Applications/workplace/QT-project/USVGCS/bdmap/map.html"));
    this->ui->widget_web->setPage(page);
    // 建立jsb
    JsbChannel *jsbChannel = new JsbChannel(this);
    this->channel = new QWebChannel(this);
    this->channel->registerObject("jsbChannel", jsbChannel);
    page->setWebChannel(channel);
    connect(jsbChannel, &JsbChannel::Mousemove, this, &MainWindow::setMousePoint);
    connect(jsbChannel, &JsbChannel::AppendBall, this, &MainWindow::usvAppendBall);

    // 建立链接
    this->tcpClinet = new QTcpSocket(this);
    this->tcpClinet->abort(); // 取消原有连接
    connect(tcpClinet, &QTcpSocket::readyRead, this, &MainWindow::readTcpData);
    connect(tcpClinet, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &MainWindow::showTcpError);
    serial = new QSerialPort(this);
    QJsonArray trackedList;
    this->trackedData.insert("trackedList", trackedList);
    this->trackedIndex = 0;
    this->trackedTimer = new QTimer();
}

MainWindow::~MainWindow()
{
    channel->deregisterObject(this);
    delete ui;
}

void MainWindow::readTcpData()
{
    QByteArray buffer = tcpClinet->readAll(); // 读取数据
    mavlink_message_t msg;
    mavlink_status_t status;
    for (int i = 0; i < buffer.length(); i++)
    {
        char c = buffer[i];
        if (mavlink_parse_char(MAVLINK_COMM_0, static_cast<unsigned char>(c), &msg, &status))
        {
            qDebug() << msg.msgid;
            switch (msg.msgid)
            {
            case MAVLINK_MSG_ID_USV_BALL: // 152 添加球
            {
                double ballLng = mavlink_msg_usv_ball_get_ball_lon(&msg) / 10000000.0;
                double ballLat = mavlink_msg_usv_ball_get_ball_lat(&msg) / 10000000.0;
                int ballColorIndex = mavlink_msg_usv_ball_get_ball_color(&msg);
                if(this->savePath != ""){
                    QJsonObject currentData;
                    currentData.insert("ballLng", ballLng);
                    currentData.insert("ballLat", ballLat);
                    currentData.insert("ballColorIndex", ballColorIndex);
                    currentData.insert("type", 152);
                    QJsonArray array = this->trackedData.value("trackedList").toArray();
                    array.append(currentData);
                    // 一定要insert回去
                    this->trackedData.insert("trackedList", array);
                }
                QString cmd = QString("addBall(%1,%2,%3)").arg(ballLng, 0, 'f', 8).arg(ballLat, 0, 'f', 8).arg(ballColorIndex);
                page->runJavaScript(cmd);
            }
            break;
            case MAVLINK_MSG_ID_USV_STATUS:
            {
                usv.stage = mavlink_msg_usv_status_get_stage(&msg);
                usv.current_x = static_cast<double>(mavlink_msg_usv_status_get_x(&msg));
                usv.current_y = static_cast<double>(mavlink_msg_usv_status_get_y(&msg));
                usv.current_lng = mavlink_msg_usv_status_get_lon(&msg) / 10000000.0;
                usv.current_lat = mavlink_msg_usv_status_get_lat(&msg) / 10000000.0;
                usv.current_course = static_cast<double>(mavlink_msg_usv_status_get_course(&msg));
                usv.velocity = mavlink_msg_usv_status_get_velocity(&msg);
                usv.cmd_vel = mavlink_msg_usv_status_get_command_velocity(&msg);
                usv.cmd_turn = mavlink_msg_usv_status_get_command_turn(&msg);
                updateLabel();
                page->runJavaScript(QString("showBoatPosition(%1,%2,%3,%4)").arg(usv.current_lng, 0, 'f', 7).arg(usv.current_lat, 0, 'f', 7).arg(usv.current_course).arg(1));
            }
            break;
            case MAVLINK_MSG_ID_USV_SIMULATION_COMMOND: // 154：仿真时状态
            {
                char stage = mavlink_msg_usv_simulation_commond_get_stage(&msg);
                usv.cmd_vel = mavlink_msg_usv_simulation_commond_get_command_velocity(&msg);
                usv.cmd_turn = mavlink_msg_usv_simulation_commond_get_command_turn(&msg);
                usv.calculate_xy();
                usv.xytowgs84();
                sendSimUSVStatus();
                updateLabel();
                // 记录回放数据
                QJsonObject currentData;
                currentData.insert("current_x", usv.current_x);
                currentData.insert("current_y", usv.current_y);
                currentData.insert("current_lng", usv.current_lng);
                currentData.insert("current_lat", usv.current_lat);
                currentData.insert("velocity", usv.velocity);
                currentData.insert("cmd_vel", usv.cmd_vel);
                currentData.insert("cmd_turn", usv.cmd_turn);
                currentData.insert("current_course", usv.current_course);
                currentData.insert("type", 154);
                QJsonArray array = this->trackedData.value("trackedList").toArray();
                array.append(currentData);
                // 一定要insert回去
                this->trackedData.insert("trackedList", array);
                 if(this->savePath != ""){
                    // 更新本地数据
                    QJsonDocument document;
                    document.setObject(this->trackedData);
                    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
                    QFile file(this->savePath);
                    writeJsonFile(file, byteArray);
                }
                page->runJavaScript(QString("showBoatPosition(%1,%2,%3,%4)").arg(usv.current_lng, 0, 'f', 7).arg(usv.current_lat, 0, 'f', 7).arg(usv.current_course).arg(1));
                // this->startSimulate(usv.cmd_turn, usv.cmd_vel);
            }
            break;
            case MAVLINK_MSG_ID_GCS_SET_OR_USV_ACK:
            {
                uint8_t type = mavlink_msg_gcs_set_or_usv_ack_get_type(&msg);
                switch (type)
                {
                case 1:
                    QMessageBox::information(this, "成功", "仿真初始化成功！");
                    break;
                case 2:
                    QMessageBox::information(this, "成功", "仿真原点设置成功！");
                    break;
                case 3:
                    QMessageBox::information(this, "成功", "仿真原点终点成功！");
                    break;
                default:
                    break;
                }
            }
            break;
            default:
                break;
            }
        }
    }
}

void MainWindow::showTcpError(QAbstractSocket::SocketError socketError)
{
    this->tcpClinet->disconnectFromHost();
    this->ui->pushButton_sendCommond->setEnabled(false);
    this->ui->pushButton_connect->setText("建立连接");
    QMessageBox::critical(this, "TCP连接错误", QString("错误代码：%1\n错误原因：%2").arg(socketError).arg(tcpClinet->errorString()));
}

void MainWindow::setMousePoint(QString lng, QString lat)
{
    this->ui->label_mouse_lng->setText(lng);
    this->ui->label_mouse_lat->setText(lat);
}

void MainWindow::usvAppendBall(int ballId, double ballLng, double ballLat, int ballColor)
{
    if (ballId == 0)
    {
        if (usv.balls.length() != 0)
            usv.balls.clear();
    }
    switch (ballColor)
    {
    case 0:
        usv.balls.append(new BALL(ballLng, ballLat, red));
        break;
    case 1:
        usv.balls.append(new BALL(ballLng, ballLat, blue));
        break;
    case 2:
        usv.balls.append(new BALL(ballLng, ballLat, yellow));
        break;
    case 3:
        usv.balls.append(new BALL(ballLng, ballLat, green));
        break;
    case 4:
        usv.balls.append(new BALL(ballLng, ballLat, black));
        break;
    default:
        break;
    }
}

QJsonDocument MainWindow::readJsonFile(QFile &file)
{
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString jsonValue = file.readAll();
    file.close();
    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(jsonValue.toUtf8(), &parseJsonErr);
    if (!(parseJsonErr.error == QJsonParseError::NoError))
    {
        qDebug() << tr("解析json文件错误！");
    }
    return document;
}

void MainWindow::writeJsonFile(QFile &file, QByteArray &data)
{
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "写入文件失败";
        return;
    }
    file.write(data);
    file.close();
}

void MainWindow::on_pushButton_addBall_clicked()
{
    double ballLng = this->ui->lineEdit_ballLng->text().toDouble();
    double ballLat = this->ui->lineEdit_ballLat->text().toDouble();
    int ballColor = this->ui->comboBox_ballColor->currentIndex();
    QString cmd = QString("addBall(%1,%2,%3)").arg(ballLng, 0, 'f', 8).arg(ballLat, 0, 'f', 8).arg(ballColor);
    page->runJavaScript(cmd);
}

void MainWindow::on_pushButton_connect_clicked()
{
    if (this->ui->pushButton_connect->text() == "建立连接")
    {
        this->tcpClinet->connectToHost(this->ui->lineEdit_ip->text(), this->ui->lineEdit_port->text().toUShort());
        if (this->tcpClinet->waitForConnected(1000))
        {
            this->ui->pushButton_sendCommond->setEnabled(true);
            this->ui->pushButton_connect->setText("断开连接");
        }
        else
        {
            qDebug() << "连接失败";
        }
    }
    else
    {
        this->tcpClinet->disconnectFromHost();
        if (tcpClinet->state() == QAbstractSocket::UnconnectedState || tcpClinet->waitForDisconnected(1000))
        {
            this->ui->pushButton_sendCommond->setEnabled(false);
            this->ui->pushButton_connect->setText("建立连接");
        }
    }
}
// 发送指令
void MainWindow::on_pushButton_sendCommond_clicked()
{
    int record = QMessageBox::question(this, "是否录制", "是否要录制此次的仿真轨迹？", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (QMessageBox::Yes == record)
    {
        this->savePath = QFileDialog::getSaveFileName(this, "Open", "./", "JSON Files (*.json)");
    }else{
        this->savePath = "";
    }
    mavlink_message_t msg;
    unsigned char buf[25];
    mavlink_msg_gcs_commond_pack(2, 2, &msg, ui->lineEdit_p->text().toFloat(), ui->lineEdit_i->text().toFloat(), ui->lineEdit_d->text().toFloat(), static_cast<unsigned char>(this->runOrStopGroup->checkedId()));
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    tcpClinet->write(reinterpret_cast<char *>(buf), len);
}

void MainWindow::on_pushButton_clearMap_clicked()
{
    page->runJavaScript(QString("clear()"));
    this->ui->pushButton_playback->setText("开始回放");
    this->trackedTimer->stop();
    this->trackedIndex = 0;
}

void MainWindow::on_pushButton_showoverlays_clicked()
{
    page->runJavaScript(QString("showOverlays()"));
}

void MainWindow::on_pushButton_test_clicked()
{
    page->runJavaScript(QString("clearBalls()"));
}

void MainWindow::on_actionReload_Map_triggered()
{
    page->load(QUrl("D:/qtstudy/USVGCS/bdmap/map.html")); // 此处路径需要修改
}

void MainWindow::on_actionRuler_triggered()
{
    page->runJavaScript(QString("ruler()"));
}

void MainWindow::on_pushButton_simulatorInit_clicked()
{
    usv.current_x = 0;
    usv.current_y = 0;
    usv.current_course = 0;
    mavlink_message_t msg;
    unsigned char buf[25];
    mavlink_msg_gcs_set_or_usv_ack_pack(2, 2, &msg, 1, usv.balls.length(), 0, 0);
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    tcpClinet->write(reinterpret_cast<char *>(buf), len);
    // 定死终点
    float end_lng = 113.6127;
    float end_lat = 22.3796;
    QJsonObject end;
    end.insert("lng", end_lng);
    end.insert("lat", end_lat);
    this->trackedData.insert("end", end);
    if (usv.balls.length() != 0)
    {
        for (int i = 0; i < usv.balls.length(); i++)
        {
            mavlink_msg_usv_ball_pack(2, 2, &msg, static_cast<uint8_t>(i), usv.balls.at(i)->color, static_cast<int>(usv.balls.at(i)->lat * 10000000), static_cast<int>(usv.balls.at(i)->lng * 10000000));
            len = mavlink_msg_to_send_buffer(buf, &msg);
            tcpClinet->write(reinterpret_cast<char *>(buf), len);
        }
    }
    else
    {
        QMessageBox::warning(this, "错误", "请先加载球!");
    }
}
// 设置起点
void MainWindow::on_pushButton_setHome_clicked()
{
    double lng = this->ui->lineEdit_ballLng->text().toDouble();
    double lat = this->ui->lineEdit_ballLat->text().toDouble();
    usv.setHome(lng, lat, 0);
    QJsonObject home;
    home.insert("lng", lng);
    home.insert("lat", lat);
    this->trackedData.insert("home", home);
    mavlink_message_t msg;
    unsigned char buf[25];
    mavlink_msg_gcs_set_or_usv_ack_pack(2, 2, &msg, 2, static_cast<int>(lng * 10000000), static_cast<int>(lat * 10000000), 0);
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    tcpClinet->write(reinterpret_cast<char *>(buf), len);
}
// 设置终点
void MainWindow::on_pushButton_setEnd_clicked()
{
    double lng = this->ui->lineEdit_ballLng->text().toDouble();
    double lat = this->ui->lineEdit_ballLat->text().toDouble();
    mavlink_message_t msg;
    unsigned char buf[25];
    mavlink_msg_gcs_set_or_usv_ack_pack(2, 2, &msg, 3, static_cast<int>(lng * 10000000), static_cast<int>(lat * 10000000), 0);
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    tcpClinet->write(reinterpret_cast<char *>(buf), len);
}

void MainWindow::on_pushButton_simulatorStart_clicked()
{
}

void MainWindow::updateLabel()
{
    this->ui->label_X->setText(QString::number(usv.current_x, 'f', 1) + "m");
    this->ui->label_Y->setText(QString::number(usv.current_y, 'f', 1) + "m");
    this->ui->label_boat_lng->setText(QString::number(usv.current_lng, 'f', 7) + "°");
    this->ui->label_boat_lat->setText(QString::number(usv.current_lat, 'f', 7) + "°");
    this->ui->label_boat_velocity->setText(QString::number(static_cast<double>(usv.velocity), 'f', 1));
    this->ui->label_boat_course->setText(QString::number(usv.current_course, 'f', 1));
    this->ui->label_boat_cmdvel->setText(QString::number(static_cast<double>(usv.cmd_vel), 'f', 2));
    this->ui->label_boat_cmdturn->setText(QString::number(static_cast<double>(usv.cmd_turn), 'f', 2));
}

void MainWindow::sendSimUSVStatus()
{
    mavlink_message_t msg;
    unsigned char buf[25];
    mavlink_msg_gcs_simulation_status_pack(2, 2, &msg, static_cast<int>(usv.current_lat * 10000000), static_cast<int>(usv.current_lng * 10000000), static_cast<float>(usv.current_course));
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    tcpClinet->write(reinterpret_cast<char *>(buf), len);
}

void MainWindow::on_pushButton_serial_search_clicked()
{
    this->ui->comboBox_serial_name->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        this->ui->comboBox_serial_name->addItem(info.portName());
    }
}

void MainWindow::on_pushButton_serial_open_clicked()
{
    if (this->ui->pushButton_serial_open->text() == "Open")
    {
        serial->setPortName(this->ui->comboBox_serial_name->currentText());
        serial->setBaudRate(this->ui->comboBox_serial_baud->currentText().toInt());
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        if (!serial->open(QIODevice::ReadWrite))
        {
            return;
        }
        this->ui->pushButton_serial_open->setText("关闭串口");
        this->ui->comboBox_serial_name->setEnabled(false);
        this->ui->comboBox_serial_baud->setEnabled(false);
        this->ui->pushButton_serial_search->setEnabled(false);
    }
    else
    {
        serial->close();
        this->ui->pushButton_serial_open->setText("打开串口");
        this->ui->comboBox_serial_name->setEnabled(true);
        this->ui->comboBox_serial_baud->setEnabled(true);
        this->ui->pushButton_serial_search->setEnabled(true);
    }
}
void MainWindow::startSimulate(double cmdTurn, qint64 cmdVel)
{
    usv.cmd_vel = cmdTurn;
    usv.cmd_turn = cmdVel;
    usv.calculate_xy();
    usv.xytowgs84();
    updateLabel();
    page->runJavaScript(QString("showBoatPosition(%1,%2,%3,%4)").arg(usv.current_lng, 0, 'f', 7).arg(usv.current_lat, 0, 'f', 7).arg(usv.current_course).arg(1));
}

void MainWindow::on_pushButton_playback_clicked()
{
    if (this->ui->pushButton_playback->text() == "开始回放")
    {
        this->ui->pushButton_playback->setText("停止回放");
        QFile file(this->trackedPath);
        QJsonDocument doc = this->readJsonFile(file);
        QJsonObject object = doc.object();
        QJsonArray array = object.value("trackedList").toArray();
        this->trackedData.insert("trackedList", array);
        QJsonObject home = object.value("home").toObject();
        this->trackedTimer->start(200);
        connect(this->trackedTimer, &QTimer::timeout, this, [=]()
                {
            if(trackedIndex == array.size()) {
                // 回放完毕
                this->ui->pushButton_playback->setText("开始回放");
                this->trackedTimer->stop();
                this->trackedIndex = 0;
                qDebug()<<"end";
                return;
            }
            if(trackedIndex == 0){
                // 一开始设置起点
                usv.setHome(home.value("lng").toDouble(), home.value("lat").toDouble(), 0);
                qDebug()<<"home";
            }
            QJsonObject item = array.at(trackedIndex).toObject();
            double currentX = item["current_x"].toDouble();
            double currentY = item["current_y"].toDouble();
            double currentLng = item["current_lng"].toDouble();
            double currentLat = item["current_lat"].toDouble();
            double velocity = item["velocity"].toDouble();
            double currentCourse = item["current_course"].toDouble();
            double cmdVel = item["cmd_vel"].toDouble();
            double cmdTurn = item["cmd_turn"].toDouble();
            int type = item["type"].toInt();
            if(type == 154){
                this->ui->label_X->setText(QString::number(currentX, 'f', 1) + "m");
                this->ui->label_Y->setText(QString::number(currentY, 'f', 1) + "m");
                this->ui->label_boat_lng->setText(QString::number(currentLng, 'f', 7) + "°");
                this->ui->label_boat_lat->setText(QString::number(currentLat, 'f', 7) + "°");
                this->ui->label_boat_velocity->setText(QString::number(static_cast<double>(velocity), 'f', 1));
                this->ui->label_boat_course->setText(QString::number(currentCourse, 'f', 1));
                this->ui->label_boat_cmdvel->setText(QString::number(static_cast<double>(cmdVel), 'f', 2));
                this->ui->label_boat_cmdturn->setText(QString::number(static_cast<double>(cmdTurn), 'f', 2));
                page->runJavaScript(QString("showBoatPosition(%1,%2,%3,%4)").arg(currentLng, 0, 'f', 7).arg(currentLat, 0, 'f', 7).arg(currentCourse).arg(1));
            }else if(type == 152){
                double ballLng = item["ballLng"].toDouble();
                double ballLat = item["ballLat"].toDouble();
                int ballColorIndex = item["ballColorIndex"].toInt();
                QString cmd = QString("addBall(%1,%2,%3)").arg(ballLng, 0, 'f', 8).arg(ballLat, 0, 'f', 8).arg(ballColorIndex);
                page->runJavaScript(cmd);
            }
            this->trackedIndex += 1; });
    }
    else
    {
        this->ui->pushButton_playback->setText("开始回放");
        this->trackedTimer->stop();
    }
}
// 生成曲线
void MainWindow::on_pushButton_showGraph_clicked()
{
    xyGraph *g = new xyGraph(this);
    QJsonArray array = this->trackedData.value("trackedList").toArray();
    g->paint(array);
    g->show();
}

void MainWindow::on_pushButton_readFile_clicked()
{
    this->trackedPath = QFileDialog::getOpenFileName(this, "Open", "./", "JSON Files (*.json)");
    if (trackedPath.isEmpty() == false)
    {
        this->ui->pushButton_playback->setEnabled(true);
    }
    return;
}
