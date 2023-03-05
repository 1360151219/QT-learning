#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDir>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image/ship.png"));
    communicateInit();
    widgetInit();
    paramTableInit();
    mapInit();
    GCSFile.setFileName(QDir::currentPath() + "/log/gcslog.txt");
}

MainWindow::~MainWindow()
{
    delete taskWidget;
    channel->deregisterObject(mapChannel);
    delete ui;
}

void MainWindow::communicateInit()
{
    this->usvClient = new QTcpSocket(this);
    this->usvClient->abort();
    connect(usvClient, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &MainWindow::showTcpError);
    connect(usvClient, &QTcpSocket::readyRead, this, &MainWindow::usvTcpRead);

    this->serial = new QSerialPort(this);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::usvSerialRead);

    commuTimer = new QTimer(this);
    commuTimer->start(3000);
    lastCommuTime = QTime::currentTime();
    connect(commuTimer, &QTimer::timeout, this, [=]()
            {
        if(lastCommuTime.msecsTo(QTime::currentTime()) > 3000)
        {
            connectLabel -> setText("  Disconnected  ");
            connectLabel -> setStyleSheet("color:red;");
        }else{
            connectLabel -> setText("  Connected  ");
            connectLabel -> setStyleSheet("color:green;");
        } });
}

void MainWindow::widgetInit()
{
    //    this -> ui -> remoteRudderAngle -> setEnabled(false);
    //    this -> ui -> remotePropellerPW -> setEnabled(false);

    //    connect(this->ui->radioButton_remote_enable,&QRadioButton::clicked,this->ui->remoteRudderAngle,&QSlider::setEnabled);
    //    connect(this->ui->radioButton_remote_enable,&QRadioButton::clicked,this->ui->remotePropellerPW,&QSlider::setEnabled);

    //    connect(this->ui->remoteRudderAngle,&QSlider::sliderReleased,[=](){
    //        this -> ui -> label_Rudder_display -> setText(QString::number(this->ui->remoteRudderAngle->value()));
    //        remoteControl();
    //    });
    //    connect(this->ui->remotePropellerPW,&QSlider::sliderReleased,[=](){
    //        this -> ui -> label_Propeller_dispaly -> setText(QString::number(this->ui->remotePropellerPW->value()));
    //        remoteControl();
    //    });

    /*设置StackedWidget初始界面，绑定导航栏到StackedWidget*/
    this->ui->tabWidget_3->setCurrentIndex(0);
    //    connect(ui->buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(changeStackedWidgetPage(int)));

    /*非模态式MessageBox初始化*/
    this->messageBox = new QMessageBox(this);
    this->messageBox->setModal(false);

    /*预设航点界面初始化*/
    this->taskWidget = new TaskWidget();

    /*永久状态栏*/
    QFont ft;
    ft.setPointSize(14);

    statusLabel = new QLabel("  NoAutoWorking  ");
    statusLabel->setFont(ft);
    connectLabel = new QLabel("  Disconnected  ");
    connectLabel->setFont(ft);
    connectLabel->setStyleSheet("color:red;");
    spaceLabel = new QLabel("      ");
    this->ui->statusBar->addPermanentWidget(statusLabel);
    this->ui->statusBar->addPermanentWidget(connectLabel);
    this->ui->statusBar->addPermanentWidget(spaceLabel);
}

void MainWindow::paramTableInit()
{
    // 必须要设置此项，否则样式表的hover无法生效
    this->ui->tableView->setMouseTracking(true);
    // 为指定列设置代理
    btnDelegate = new QMyTableViewBtnDelegate(QStringList() << "Read"
                                                            << "Set",
                                              this);

    connect(btnDelegate, &QMyTableViewBtnDelegate::readData, this, [=](const QModelIndex &index)
            {
        uint16_t paramIndex = static_cast<uint16_t>(tableModel->item(index.row(),0)->text().toUInt());
        sendGcsSet(11,paramIndex);
        qDebug()<<"Read"<<paramIndex; });
    connect(btnDelegate, &QMyTableViewBtnDelegate::setData, this, [=](const QModelIndex &index)
            {
        uint8_t paramIndex = static_cast<uint8_t>(tableModel->item(index.row(),0)->text().toUInt());
        float param = tableModel->item(index.row(),2)->text().toFloat();
        mavlink_message_t sendMsg;
        mavlink_msg_usv_params_list_pack(0,0,&sendMsg,paramIndex,param);
        sendMavlinkMsg(sendMsg);
        qDebug()<<"Set"<<paramIndex<<tableModel->item(index.row(),1)->text()<<paramIndex; });

    this->ui->tableView->setItemDelegateForColumn(3, btnDelegate);

    tableModel = new QStandardItemModel(this);
    this->ui->tableView->setModel(tableModel);
    QStringList columnTitles;
    columnTitles << "Index"
                 << "Name"
                 << "Value"
                 << "Action";
    tableModel->setHorizontalHeaderLabels(columnTitles);

    tableModelInit();
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::tableModelInit()
{
    QFile jsonFile(QDir::currentPath() + "/param/gcs_param/paramsList.json");
//    qDebug()<<QDir::currentPath() + "/param/gcs_param/paramsList.json";
    if (!jsonFile.open(QIODevice::ReadOnly))
    {
        this->ui->statusBar->showMessage("Json文件打开失败，请重试", 2000);
        return;
    }

    QJsonObject rootObj = QJsonDocument::fromJson(jsonFile.readAll()).object();
    jsonFile.close();

    int cnt = 1;
    while (1)
    {
        if (rootObj.contains(QString::number(cnt)))
        {
            if (rootObj.value(QString::number(cnt)).isObject())
            {
                QJsonObject paramObj = rootObj.value(QString::number(cnt)).toObject();
                QString paramName = paramObj.value("Name").toString();
                double paramValue = paramObj.value("Value").toDouble();
                tableModel->setItem(cnt - 1, 0, new QStandardItem(QString::number(cnt)));
                tableModel->setItem(cnt - 1, 1, new QStandardItem(paramName));
                tableModel->setItem(cnt - 1, 2, new QStandardItem(QString::number(paramValue)));
            }
            cnt++;
        }
        else
            break;
    }
}

void MainWindow::usvTcpRead()
{
    QByteArray buffer = usvClient->readAll();
    mavlinkRead(buffer);
}

void MainWindow::usvSerialRead()
{
    QByteArray buffer = serial->readAll();
    mavlinkRead(buffer);
}

void MainWindow::mavlinkRead(QByteArray buf)
{
    lastCommuTime = QTime::currentTime();
    for (int i = 0; i < buf.length(); i++)
    {
        if (MAVLINK_FRAMING_OK == mavlink_parse_char(MAVLINK_COMM_0, static_cast<uint8_t>(buf.at(i)), &msg, &status))
        {
            qDebug() << "MsgID" << msg.msgid;
            switch (msg.msgid)
            {
            // marked: 显示船舶状态，以及绘制轨迹
            case MAVLINK_MSG_ID_USV_STATE:
                usv.lng = mavlink_msg_usv_state_get_lon(&msg) / 10000000.0;
                usv.lat = mavlink_msg_usv_state_get_lat(&msg) / 10000000.0;
                usv.x = mavlink_msg_usv_state_get_x(&msg);
                usv.y = mavlink_msg_usv_state_get_y(&msg);
                usv.velocity = mavlink_msg_usv_state_get_vel(&msg) / 1000.f;
                usv.roll = mavlink_msg_usv_state_get_roll(&msg) / 100.f;
                usv.pitch = mavlink_msg_usv_state_get_pitch(&msg) / 100.f;
                usv.yaw = mavlink_msg_usv_state_get_yaw(&msg);
                usv.course = mavlink_msg_usv_state_get_course(&msg);
                usv.HDOP = mavlink_msg_usv_state_get_HDOP(&msg) / 100.f;
                usv.SVs = mavlink_msg_usv_state_get_SVs(&msg);

                this->ui->label_lng->setText(QString::number(usv.lng, 'f', 7) + "°");
                this->ui->label_lat->setText(QString::number(usv.lat, 'f', 7) + "°");
                this->ui->label_x->setText(QString::number(static_cast<double>(usv.x), 'f', 2) + "m");
                this->ui->label_y->setText(QString::number(static_cast<double>(usv.y), 'f', 2) + "m");

                this->ui->label_roll_field->setText(QString::number(static_cast<double>(usv.roll), 'f', 2) + "°");
                this->ui->label_pitch_field->setText(QString::number(static_cast<double>(usv.pitch), 'f', 2) + "°");
                this->ui->label_yaw_field->setText(QString::number(static_cast<double>(usv.yaw), 'f', 2) + "°");
                this->ui->label_course_field->setText(QString::number(static_cast<double>(usv.course), 'f', 2) + "°");
                this->ui->label_SVs->setText(QString("%1/%2").arg(usv.SVs).arg(static_cast<double>(usv.HDOP)));
                this->ui->label_velocity->setText(QString::number(static_cast<double>(usv.velocity), 'f', 2) + "m/s");

                //                this->ui->widget_gaugeCompassPan->setValue(static_cast<double>(usv.yaw));
                //                this->ui->widget_gaugePlane->setRollValue(static_cast<int>(usv.pitch));
                //                this->ui->widget_gaugePlane->setDegValue(static_cast<int>(usv.roll));
                mapChannel->updateBoatPos(usv.lng,usv.lat,static_cast<double>(usv.yaw),0);
                break;
            case MAVLINK_MSG_ID_USV_HEARTBEAT:
                usv.mode = mavlink_msg_usv_heartbeat_get_mode(&msg);
                usv.task_id = mavlink_msg_usv_heartbeat_get_task_id(&msg);
                usv.autoWorking = mavlink_msg_usv_heartbeat_get_autoWorking(&msg);

                if (usv.mode == 0)
                    statusLabel->setText("  Debug  ");
                else if (usv.mode == 1)
                    statusLabel->setText("  Remote  ");
                else if (usv.mode == 2)
                {
                    if (usv.autoWorking == 1)
                        statusLabel->setText(QString("  Auto-%1:AutoWorking  ").arg(this->ui->comboBox_task_type->itemText(usv.task_id)));
                    else
                        statusLabel->setText(QString("  Auto:NoAutoWorking  "));
                }
                else if (usv.mode == 3)
                    statusLabel->setText("  Emergency  ");
                break;
            case MAVLINK_MSG_ID_USV_PARAMS_LIST:
            {
                uint8_t paramIndex = mavlink_msg_usv_params_list_get_index(&msg);
                float param = mavlink_msg_usv_params_list_get_param(&msg);
                tableModel->item(paramIndex - 1, 2)->setText(QString::number(static_cast<double>(param)));
                showMessageBox(QMessageBox::Information, "成功", "读取or下达参数成功！");
            }
            break;

            case MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK:
            {
                uint8_t type = mavlink_msg_gcs_set_or_rpi_ack_get_type(&msg);
                uint16_t content = mavlink_msg_gcs_set_or_rpi_ack_get_content(&msg);
                qDebug() << "type" << type << "content" << content;
                switch (type)
                {
                case 0:
                    showMessageBox(QMessageBox::Information, "成功", "AUV初始化成功！");
                    break;
                case 1:
                {
                    QString str("AUV切换为");
                    if (content == 0)
                        str += "调试模式！";
                    else if (content == 1)
                        str += "遥控模式！";
                    else if (content == 2)
                        str += "自主模式！";
                    else if (content == 3)
                        str += "应急模式！";
                    showMessageBox(QMessageBox::Information, "成功", str);
                }
                break;
                case 2:
                    if (content == 0)
                    {
                        this->ui->pushButton_task_work->setText("开始执行");
                        showMessageBox(QMessageBox::Information, "成功", "任务停止执行！");
                    }
                    else
                    {
                        this->ui->pushButton_task_work->setText("停止执行");
                        showMessageBox(QMessageBox::Information, "成功", "任务开始执行！");
                    }
                    break;
                case 3:
                    if (content == 0)
                        showMessageBox(QMessageBox::Information, "成功", "关闭速度控制！");
                    else
                        showMessageBox(QMessageBox::Information, "成功", "开启速度控制！");
                    break;
                case 4:
                    if (content == 0)
                        showMessageBox(QMessageBox::Information, "成功", "使用Los！");
                    else
                        showMessageBox(QMessageBox::Information, "成功", "使用ILos！");
                    break;
                case 5:
                    if (content == 0)
                        showMessageBox(QMessageBox::Information, "成功", "使用艏向控制！");
                    else
                        showMessageBox(QMessageBox::Information, "成功", "使用航向控制！");
                    break;
                case 6:
                    mapChannel->setOrigin(usv.lng, usv.lat);
                    showMessageBox(QMessageBox::Information, "成功", "设定原点！");
                    break;
                case 7:
                {
                    QString str("成功下发");
                    str += QString::number(content);
                    str += "个航点";
                    showMessageBox(QMessageBox::Information, "成功", str);
                }
                break;
                case 10:
                {
                    /*
                     if(BITREAD(content,0))
                        this -> ui -> comboBox_VelControl_select -> setCurrentIndex(1);
                    else
                        this -> ui -> comboBox_VelControl_select -> setCurrentIndex(0);
                     */
                    if (BITREAD(content, 1))
                        this->ui->comboBox_los_select->setCurrentIndex(1);
                    else
                        this->ui->comboBox_los_select->setCurrentIndex(0);
                    int contype = (BITREAD(content, 3) << 1) | BITREAD(content, 2);
                    if (contype == 0)
                    {
                        this->ui->comboBox_HeadingOrCourse_select->setCurrentIndex(0);
                    }
                    if (contype == 1)
                    {
                        this->ui->comboBox_HeadingOrCourse_select->setCurrentIndex(1);
                    }

                    showMessageBox(QMessageBox::Information, "成功", "已更新控制配置！");
                }
                break;

                default:
                    break;
                }
            }
            break;
            case MAVLINK_MSG_ID_GCS_SET_TASK:
            {
                uint8_t taskType = mavlink_msg_gcs_set_task_get_tasktype(&msg);
                QString str;
                if (taskType == 0)
                {
                    str = QString("USV执行多航点任务：巡航速度%1，持续时间%2秒！ ").arg(static_cast<int>(mavlink_msg_gcs_set_task_get_xunhang_pwm(&msg))).arg(static_cast<int>(mavlink_msg_gcs_set_task_get_time_allow(&msg)));
                }
                else if (taskType == 1)
                {
                    str = QString("USV执行返航任务：巡航速度%1，持续时间%2秒！ ").arg(static_cast<int>(mavlink_msg_gcs_set_task_get_xunhang_pwm(&msg))).arg(static_cast<int>(mavlink_msg_gcs_set_task_get_time_allow(&msg)));
                }
                showMessageBox(QMessageBox::Information, "任务已下达", str);
            }
            break;
            case MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM:
                this->ui->lineEdit_param_xunhang->setText(QString::number(mavlink_msg_gcs_set_control_param_get_xunhang_pwm(&msg)));
                this->ui->lineEdit_param_course_p->setText(QString::number(static_cast<double>(mavlink_msg_gcs_set_control_param_get_kp_psi(&msg))));
                this->ui->lineEdit_param_course_i->setText(QString::number(static_cast<double>(mavlink_msg_gcs_set_control_param_get_ki_psi(&msg))));
                this->ui->lineEdit_param_course_d->setText(QString::number(static_cast<double>(mavlink_msg_gcs_set_control_param_get_kd_psi(&msg))));
                this->ui->lineEdit_param_course_los->setText(QString::number(static_cast<double>(mavlink_msg_gcs_set_control_param_get_Los(&msg))));
                showMessageBox(QMessageBox::Information, "成功", "获取控制参数");
                break;
            case MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM:
                this->ui->lineEdit_param_leftMidPW->setText(QString::number(static_cast<uint16_t>(mavlink_msg_gcs_set_servo_param_get_propeller_left_pwm(&msg))));
                this->ui->lineEdit_param_rightMidPW->setText(QString::number(static_cast<uint16_t>(mavlink_msg_gcs_set_servo_param_get_propeller_right_pwm(&msg))));
                showMessageBox(QMessageBox::Information, "成功", "获取执行机构零位参数");
                break;
            default:
                break;
            }
        }
    }
}

void MainWindow::showTcpError(QAbstractSocket::SocketError socketError)
{
    QTcpSocket *errSocket = qobject_cast<QTcpSocket *>(sender());
    if (errSocket == usvClient)
    {
        this->ui->statusBar->showMessage(QString("USVClient连接错误，错误代码：%1：%2").arg(socketError).arg(usvClient->errorString()), 3000);
        this->usvClient->abort();
        this->ui->pushButton_tcp_connect->setText("TCP通信");
    }
}

void MainWindow::on_pushButton_tcp_connect_clicked()
{
    if (this->ui->pushButton_tcp_connect->text() == "TCP通信")
    {
        QFile jsonFile(QDir::currentPath() + "/param/gcs_param/setting.json");
        //        qDebug()<<QDir::currentPath() + "/param/gcs_param/setting.json";
        if (!jsonFile.open(QIODevice::ReadOnly))
        {
            this->ui->statusBar->showMessage("Json文件打开失败，请重试", 2000);
            return;
        }

        QJsonObject rootObj = QJsonDocument::fromJson(jsonFile.readAll()).object();
        jsonFile.close();
        QString ip = rootObj.value("RPIIP").toString();
        int port = rootObj.value("RPIPort").toInt();
        qDebug()<<"tcp连接："<<ip<<port;
        this->usvClient->connectToHost(ip, static_cast<quint16>(port));
        if (this->usvClient->waitForConnected(1000))
        {
            this->ui->pushButton_tcp_connect->setText("断开TCP");
        }
        else
            this->ui->statusBar->showMessage("RPI连接失败", 1000);
    }
    else
    {
        this->usvClient->disconnectFromHost();
        if (usvClient->state() == QAbstractSocket::UnconnectedState || usvClient->waitForDisconnected(1000))
        {
            this->ui->pushButton_tcp_connect->setText("TCP通信");
        }
    }
}

void MainWindow::remoteControl()
{
    mavlink_message_t sendMsg;
    //    mavlink_msg_usv_actuator_control_pack(0,0,&sendMsg,
    //                                          static_cast<int16_t>(this->ui->remotePropellerPW->value()),
    //                                          static_cast<int16_t>(this->ui->remoteRudderAngle->value())
    //                                         );
    sendMavlinkMsg(sendMsg);
}

void MainWindow::sendMavlinkMsg(const mavlink_message_t msg)
{
    uint16_t len = mavlink_msg_to_send_buffer(sendBuf, &msg);
    if (usvClient->state() == QAbstractSocket::ConnectedState)
        usvClient->write(reinterpret_cast<char *>(sendBuf), len);
    else if (serial->isOpen())
        serial->write(reinterpret_cast<char *>(sendBuf), len);
    else
        this->ui->statusBar->showMessage(QString("未建立通信连接！"), 2000);
}

void MainWindow::sendGcsSet(uint8_t type, uint16_t content)
{

    mavlink_message_t sendMsg;
    mavlink_msg_gcs_set_or_rpi_ack_pack(0, 0, &sendMsg, type, content);
    sendMavlinkMsg(sendMsg);
}

void MainWindow::on_comboBox_mode_currentIndexChanged(int index)
{
    sendGcsSet(1, static_cast<uint16_t>(index));
}

void MainWindow::on_pushButton_usv_init_clicked()
{
    sendGcsSet(0, 1);
}

void MainWindow::showMessageBox(QMessageBox::Icon icon, QString title, QString text)
{
    messageBox->setIcon(icon);
    messageBox->setWindowTitle(title);
    messageBox->setText(text);
    messageBox->show();
    recordLog(text);
}

void MainWindow::on_pushButton_task_work_clicked()
{
    if (this->ui->pushButton_task_work->text() == "开始执行")
        sendGcsSet(2, 1);
    else
        sendGcsSet(2, 0);
}

void MainWindow::on_pushButton_read_control_param_clicked()
{
    sendGcsSet(8, 0);
}

void MainWindow::on_pushButton_set_control_param_clicked()
{
    mavlink_message_t sendMsg;
    mavlink_msg_gcs_set_control_param_pack(0, 0, &sendMsg,
                                           static_cast<int16_t>(this->ui->lineEdit_param_xunhang->text().toInt()),
                                           this->ui->lineEdit_param_course_p->text().toFloat(),
                                           this->ui->lineEdit_param_course_i->text().toFloat(),
                                           this->ui->lineEdit_param_course_d->text().toFloat(),
                                           0,
                                           0,
                                           0,
                                           this->ui->lineEdit_param_course_los->text().toFloat()); // 三个0参数为速度控制预留
    sendMavlinkMsg(sendMsg);
}

void MainWindow::on_pushButton_read_mid_param_clicked()
{
    sendGcsSet(9, 0);
}

void MainWindow::on_pushButton_set_mid_param_clicked()
{
    mavlink_message_t sendMsg;
    mavlink_msg_gcs_set_servo_param_pack(0, 0, &sendMsg,
                                         static_cast<uint16_t>(this->ui->lineEdit_param_leftMidPW->text().toInt()),
                                         static_cast<uint16_t>(this->ui->lineEdit_param_rightMidPW->text().toInt()));
    sendMavlinkMsg(sendMsg);
}

void MainWindow::on_pushButton_serial_connect_clicked()
{
    if (this->ui->pushButton_serial_connect->text() == "串口通信")
    {
        serial->setPortName(this->ui->comboBox_serial_port->currentText());
        serial->setBaudRate(this->ui->comboBox_serial_baud->currentText().toInt());
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        if (!serial->open(QIODevice::ReadWrite))
        {
            this->ui->statusBar->showMessage(QString("串口打开失败,错误代码：%1").arg(serial->error()), 2000);
            return;
        }
        this->ui->pushButton_serial_connect->setText("关闭串口");
        this->ui->comboBox_serial_port->setEnabled(false);
        this->ui->comboBox_serial_baud->setEnabled(false);
        this->ui->pushButton_search_serial->setEnabled(false);
    }
    else
    {
        serial->close();
        this->ui->pushButton_serial_connect->setText("串口通信");
        this->ui->comboBox_serial_port->setEnabled(true);
        this->ui->comboBox_serial_baud->setEnabled(true);
        this->ui->pushButton_search_serial->setEnabled(true);
    }
}

void MainWindow::on_pushButton_search_serial_clicked()
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QString availablePort = info.portName();
        uint8_t i;
        for (i = 0; i < this->ui->comboBox_serial_port->count(); i++)
        {
            if (availablePort == this->ui->comboBox_serial_port->itemText(i))
            {
                this->ui->comboBox_serial_port->setCurrentIndex(i);
                break;
            }
        }
        if (i == this->ui->comboBox_serial_port->count())
        {
            this->ui->comboBox_serial_port->addItem(info.portName());
            this->ui->comboBox_serial_port->setCurrentIndex(i);
        }
    }
}

void MainWindow::on_pushButton_query_control_config_clicked()
{
    sendGcsSet(10, 0);
}

void MainWindow::on_comboBox_los_select_currentIndexChanged(int index)
{
    sendGcsSet(4, static_cast<uint8_t>(index));
}

void MainWindow::on_pushButton_read_all_clicked()
{
    sendGcsSet(11, 0);
}

void MainWindow::on_pushButton_load_local_param_clicked()
{
    tableModelInit();
}

void MainWindow::on_pushButton_write_all_clicked()
{
    int paramsCount = tableModel->rowCount();
    for (int i = 0; i < paramsCount; i++)
    {
        uint8_t paramIndex = static_cast<uint8_t>(tableModel->item(i, 0)->text().toUInt());
        float param = tableModel->item(i, 2)->text().toFloat();
        mavlink_message_t sendMsg;
        mavlink_msg_usv_params_list_pack(0, 0, &sendMsg, paramIndex, param);
        sendMavlinkMsg(sendMsg);
        qDebug() << "Set" << paramIndex << tableModel->item(i, 1)->text() << paramIndex;
    }
}

void MainWindow::on_pushButton_save_param_to_local_clicked()
{
    int paramsCount = tableModel->rowCount();
    QJsonObject rootObject;
    for (int i = 0; i < paramsCount; i++)
    {
        QJsonObject paramObj;
        paramObj["Name"] = tableModel->item(i, 1)->text();
        paramObj["Value"] = tableModel->item(i, 2)->text().toDouble();
        rootObject[tableModel->item(i, 0)->text()] = paramObj; // 键值对
    }
    QFile file(QDir::currentPath() + "/param/gcs_param/paramsList.json");
    file.open(QIODevice::WriteOnly);
    file.write(QJsonDocument(rootObject).toJson());
    file.close();
}

void MainWindow::on_lineEdit_table_search_textChanged(const QString &arg1)
{
    if (arg1 == "")
    {
        for (int i = 0; i < tableModel->rowCount(); i++)
            ui->tableView->setRowHidden(i, false);
    }
    else
    {
        QString queryStr = this->ui->lineEdit_table_search->text().remove(QRegExp("\\s"));
        for (int i = 0; i < tableModel->rowCount(); i++)
        {
            QString thisName = tableModel->item(i, 1)->text().remove(QRegExp("\\s"));
            if (thisName.contains(queryStr))
                this->ui->tableView->setRowHidden(i, false);
            else
                this->ui->tableView->setRowHidden(i, true);
        }
    }
}

void MainWindow::mapInit()
{
    isOfflineMap = true;
    channel = new QWebChannel(this);
    mapChannel = new MapChannel(this);
    channel->registerObject("passId", mapChannel);
    this->ui->widget_mapWidget->page()->setWebChannel(channel);
    this->ui->widget_mapWidget->load(QUrl("file:///Applications/workplace/QT-project/3DAUVGCSV2/offlineMap/map.html"));

    waypoints = new QList<Waypoint>;

    connect(mapChannel, &MapChannel::mousePointChanged, [=](double lng, double lat)
            { this->ui->label_mouse_point->setText(QString::number(lng, 'f', 7) + "  " + QString::number(lat, 'f', 7)); });
    connect(mapChannel, &MapChannel::reloadMapClicked, [=]()
            {
        if(isOfflineMap)
            this -> ui -> widget_mapWidget -> load(QUrl("file:///Applications/workplace/QT-project/3DAUVGCSV2/offlineMap/map.html"));
        else
            this -> ui -> widget_mapWidget -> load(QUrl("file:///Applications/workplace/QT-project/3DAUVGCSV2/onlineMap/map.html")); });
    connect(mapChannel, &MapChannel::taskCome, [=](int _mapTask, int _waypointsNum)
            {
        maptaskType = static_cast<uint8_t>(_mapTask);
        waypointsNum = static_cast<uint8_t>(_waypointsNum);
        waypoints->clear(); });
    connect(mapChannel, &MapChannel::pointsCome, [=](int id, double lng, double lat)
            {
        waypoints->append(*new Waypoint(lng,lat));
        if(id == (waypointsNum-1) && waypoints->length() == waypointsNum)
        {
            taskWidget->getWaypointsList(waypoints);
            taskWidget->show();
        } });

    connect(ui->actionLoad_Online_Map, &QAction::triggered, [=]()
            {
        this -> ui -> widget_mapWidget -> load(QUrl("file:///Applications/workplace/QT-project/3DAUVGCSV2/onlineMap/map.html"));
        isOfflineMap = false; });
    connect(ui->actionLoad_Offline_Map, &QAction::triggered, [=]()
            {
        this -> ui -> widget_mapWidget -> load(QUrl("file:///Applications/workplace/QT-project/3DAUVGCSV2/offlineMap/map.html"));
        isOfflineMap = true; });
    connect(this->taskWidget, &TaskWidget::itemChanged, [=](double lng, double lat, int id)
            { mapChannel->movePoint(id, lng, lat); });
}

void MainWindow::on_pushButton_add_point_clicked()
{
    mapChannel->addPoint(this->ui->lineEdit_lng->text().toDouble(), this->ui->lineEdit_lat->text().toDouble());
}

void MainWindow::on_pushButton_load_waypoints_clicked()
{
    if (waypoints->length() != 0)
    {
        mavlink_message_t msg;
        mavlink_msg_gcs_set_or_rpi_ack_pack(0, 0, &msg, 7, static_cast<uint8_t>(waypoints->length()));
        sendMavlinkMsg(msg);

        for (uint8_t i = 0; i < waypoints->length(); i++)
        {
            qDebug() << i << waypoints->at(i).lng << waypoints->at(i).lat << waypoints->at(i).depth;
            mavlink_msg_gcs_set_waypoints_pack(0, 0, &msg, i, static_cast<int>(waypoints->at(i).lng * 10000000), static_cast<int>(waypoints->at(i).lat * 10000000));
            sendMavlinkMsg(msg);
        }
    }
    else
        showMessageBox(QMessageBox::Warning, "提示", "请先设置或加载航点");
}

void MainWindow::on_pushButton_gohome_clicked()
{
    this->ui->comboBox_task_type->setCurrentIndex(1);
    on_pushButton_load_task_clicked();
}

void MainWindow::on_pushButton_usv_setHome_clicked()
{
    sendGcsSet(6, 0);
}

void MainWindow::on_pushButton_load_task_clicked()
{
    mavlink_message_t sendMsg;
    uint8_t taksId = static_cast<uint8_t>(this->ui->comboBox_task_type->currentIndex());
    switch (taksId)
    {
    case 0:
        mavlink_msg_gcs_set_task_pack(0, 0, &sendMsg,
                                      taksId,
                                      0,
                                      static_cast<uint16_t>(this->ui->spinBox_task_time->value()),
                                      static_cast<uint16_t>(this->ui->spinBox_xunhang_pwm->value()));
        sendMavlinkMsg(sendMsg);
        break;
    case 1:
        mavlink_msg_gcs_set_task_pack(0, 0, &sendMsg,
                                      taksId,
                                      0,
                                      static_cast<uint16_t>(this->ui->spinBox_task_time->value()),
                                      static_cast<uint16_t>(this->ui->spinBox_xunhang_pwm->value()));
        sendMavlinkMsg(sendMsg);
        break;
    default:
        break;
    }
}

void MainWindow::recordLog(QString str)
{
    GCSFile.open(QIODevice::Append | QIODevice::WriteOnly | QIODevice::Text);
    str = QDateTime::currentDateTime().toString("yyyy.MM.dd,hh:mm:ss,") + " " + str + "\n";
    GCSFile.write(str.toUtf8().data());
    GCSFile.close();
}

void MainWindow::on_comboBox_HeadingOrCourse_select_currentIndexChanged(int index)
{
    sendGcsSet(5, static_cast<uint8_t>(index));
}
void MainWindow::changeStackedWidgetPage(int index)
{
    if (currentPageIndex != index)
    {
        this->ui->tabWidget_3->setCurrentIndex(index);
        currentPageIndex = index;
    }
}

void MainWindow::on_btn_Rudder_returnMid_clicked()
{
    //    this->ui->remoteRudderAngle->setValue(0);
    //    emit this->ui->remoteRudderAngle->sliderReleased();
}

void MainWindow::on_btn_Propeller_returnMid_clicked()
{
    //     this->ui->remotePropellerPW->setValue(0);
    //    emit this->ui->remotePropellerPW->sliderReleased();
}
