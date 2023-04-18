#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QSqlError>
#include <QFileDialog>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widgetInit();
    sonWidgetInit();
    mapInit();
    //dataBaseInit();
    commuInit();
    TCPClientInit();
    TCPClientInit2();
    simuTimer = new QTimer(this);
    connect(simuTimer,&QTimer::timeout,this,&MainWindow::dockSimuStep);
    sendINSDock = new QTimer(this);
    connect(sendINSDock,&QTimer::timeout,this,&MainWindow::InsDockSend);
}

MainWindow::~MainWindow()
{
    delete taskWidget;
    delete dataAnalyse;
    channel -> deregisterObject(mapChannel);
    if(db.isOpen())
        db.close();
    delete ui;
}

void MainWindow::widgetInit()
{
    //this->showMaximized(); //初始化界面最大化

    /*绘制左上角Logo*/
    QPixmap pix = QPixmap::fromImage(*new QImage(":/image/image/xiaohui.png"));
    pix = pix.scaled(ui->label_logo1->width(),ui->label_logo1->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this -> ui-> label_logo1 ->setPixmap(pix);
    pix = QPixmap::fromImage(*new QImage(":/image/image/xiaozi.png"));
    pix = pix.scaled(ui->label_logo2->width(),ui->label_logo2->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this -> ui-> label_logo2 ->setPixmap(pix);
    pix = QPixmap::fromImage(*new QImage(":/image/image/yuanhui.png"));
    pix = pix.scaled(ui->label_logo3->width(),ui->label_logo3->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this -> ui-> label_logo3 ->setPixmap(pix);

    /*设置StackedWidget初始界面，绑定导航栏到StackedWidget*/
    this -> ui -> stackedWidget -> setCurrentIndex(0);
    connect(ui->buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(changeStackedWidgetPage(int)));
}

void MainWindow::sonWidgetInit()
{
    /*非模态式MessageBox初始化*/
    this -> messageBox = new QMessageBox(this);
    this -> messageBox -> setModal(false);

    /*预设航点界面初始化*/
    this -> taskWidget = new TaskWidget();

    /*数据分析界面初始化*/
    dataAnalyse = new DataAnalyse();
    dataAnalyse -> setData(&usv);
    connect(ui->actionDataAnalyse,&QAction::triggered,[=](){
        dataAnalyse->show();
    });
   connect(ui->actionOpen_Tracer,&QAction::triggered,[=](){
        this -> ui -> page_data -> setTracerVisible(true);
    });
    connect(ui->actionClose_Tracer,&QAction::triggered,[=](){
        this -> ui -> page_data -> setTracerVisible(false);
    });
}

void MainWindow::mapInit()
{
    isOfflineMap = true;
    channel = new QWebChannel(this);
    mapChannel = new MapChannel(this);
    channel -> registerObject("passId",mapChannel);
    this -> ui -> widget_map ->  page() -> setWebChannel(channel);
    //this -> ui -> widget_mapWidget -> load(QUrl("D:/qtstudy/AUVGCS/bdmap/map.html"));
    this -> ui -> widget_map -> load(QUrl("file:///./offlinemap/map.html"));

    waypoints = new QList<Waypoint>;

    connect(mapChannel,&MapChannel::mousePointChanged,[=](double lng, double lat){
        this -> ui -> label_mouse_point -> setText(QString::number(lng,'f',7)+"  "+QString::number(lat,'f',7));
    });
    connect(mapChannel,&MapChannel::reloadMapClicked,[=](){
        if(isOfflineMap)
            this -> ui -> widget_map -> load(QUrl("file:///./offlinemap/map.html"));
        else
            this -> ui -> widget_map -> load(QUrl("file:///./onlinemap/map.html"));
    });
    connect(mapChannel,&MapChannel::taskCome,[=](int _mapTask, int _waypointsNum){
        maptaskType = static_cast<uint8_t>(_mapTask);
        waypointsNum = static_cast<uint8_t>(_waypointsNum);
        waypoints->clear();
    });
    connect(mapChannel,&MapChannel::pointsCome,[=](int id, double lng , double lat ){
        waypoints->append(*new Waypoint(lng,lat));
        if(id == (waypointsNum-1) && waypoints->length() == waypointsNum)
        {
//            for (int i=0; i<waypoints->length(); i++) {
//                qDebug()<<i<<waypoints->at(i).lat<<waypoints->at(i).lng<<waypoints->at(i).depth;
//            }
            taskWidget->getWaypointsList(waypoints);
            taskWidget->show();
        }
    });
    connect(ui->actionLoad_Online_Map,&QAction::triggered,[=](){
        this -> ui -> widget_map -> load(QUrl("file:///./onlinemap/map.html"));
        isOfflineMap = false;
    });
    connect(ui->actionLoad_Offline_Map,&QAction::triggered,[=](){
        this -> ui -> widget_map -> load(QUrl("file:///./offlinemap/map.html"));
        isOfflineMap = true;
    });
}

void MainWindow::dataBaseInit()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath()+"/log/"+"Log.db");
    if(!db.open())
    {
        showMessageBox(QMessageBox::Warning,"提示",db.lastError().text());
        return;
    }
    sqlQurey = QSqlQuery(db);
}

void MainWindow::commuInit()
{
    this -> serial = new QSerialPort(this);
    connect(serial,&QSerialPort::readyRead,this,&MainWindow::serialRead);

    //static int i=0;
   // connect(serial,&QSerialPort::readyRead,[=]()mutable{qDebug()<<i++<<endl;});

    sendTimer = new QTimer(this);
    connect(sendTimer,&QTimer::timeout,this,&MainWindow::sendWaypoint);
    commuTimer = new QTimer(this);
    connect(commuTimer,&QTimer::timeout,this,[=](){
        QTime currentTime = QTime::currentTime();
        if(wirelessTime.msecsTo(currentTime) > 1500)
        {
            this -> ui -> lightPoint -> setBgColor(Qt::red);
        }else{
            if(usv.mode == 0)
                this -> ui -> lightPoint -> setBgColor(Qt::green);
            else
                this -> ui -> lightPoint -> setBgColor(Qt::yellow);
        }
    });

}

void MainWindow::changeStackedWidgetPage(int index)  //根据导航栏切换主界面显示
{
    if(currentPageIndex != index)
    {
        this -> ui -> stackedWidget -> setCurrentIndex(index);
        currentPageIndex = index;
    }
}

void MainWindow::on_pushButton_search_serialport_clicked()
{
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QString availablePort = info.portName();
        uint8_t i;
        for(i = 0; i<this->ui->comboBox_serial_port->count(); i++)
        {
            if(availablePort == this->ui->comboBox_serial_port->itemText(i))
            {
                this -> ui -> comboBox_serial_port -> setCurrentIndex(i);
                break;
            }
        }
        if(i == this->ui->comboBox_serial_port->count())
        {
            this->ui->comboBox_serial_port->addItem(info.portName());
            this -> ui -> comboBox_serial_port -> setCurrentIndex(i);
        }
    }
}

void MainWindow::on_pushButton_open_serialport_clicked()
{
    if(this -> ui -> pushButton_open_serialport->text() == "打开串口")
    {
        serial->setPortName(this->ui->comboBox_serial_port->currentText());
        serial->setBaudRate(this->ui->comboBox_baud->currentText().toInt());
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        if(!serial->open(QIODevice::ReadWrite))
        {
            showMessageBox(QMessageBox::Critical,"错误",QString("串口打开失败,错误代码：%1").arg(serial->error()));
            return;
        }
        this -> ui -> pushButton_open_serialport -> setText("关闭串口");
        this -> ui -> comboBox_serial_port -> setEnabled(false);
        this -> ui -> comboBox_baud -> setEnabled(false);
        this -> ui -> pushButton_search_serialport -> setEnabled(false);

    }
    else {
        serial->close();
        this -> ui -> pushButton_open_serialport -> setText("打开串口");
        this -> ui -> comboBox_serial_port -> setEnabled(true);
        this -> ui -> comboBox_baud -> setEnabled(true);
        this -> ui -> pushButton_search_serialport -> setEnabled(true);

    }
}

void MainWindow::serialRead()
{
    /*QByteArray buffer = serial->readAll();
    //QString s(buffer);
    qDebug()<<buffer;
    ins.read(buffer.toStdString());
    dock.lat=ins.latitude;
    dock.lng=ins.longitude;
    dock.yaw=ins.yaw;

    dock.velocity_course=ins.speed_Course;
    dock.velocity_number=ins.speed*0.514f;
    dock.pitch=ins.pitch;
    dock.gyrox=ins.GyroX;
    this->ui->label_dock_lng->setText(QString::number(dock.lng,'f',7)+"°");
    this->ui->label_dock_lat->setText(QString::number(dock.lat,'f',7)+"°");
    this->ui->label_dock_yaw->setText(QString::number(static_cast<double>(dock.yaw),'f',2)+"°");
    mapChannel->updateDockPos(static_cast<double>(dock.lng),static_cast<double>(dock.lat),static_cast<double>(dock.yaw));*/
    QByteArray TCPbuf = serial->readAll();

    if(!TCPbuf.isEmpty())
    {
        mavlink_message_t msg;
        mavlink_status_t status;
        for (int i=0; i<TCPbuf.length(); i++) {
            if(MAVLINK_FRAMING_OK == mavlink_parse_char(MAVLINK_COMM_0,static_cast<uint8_t>(TCPbuf[i]),&msg,&status))
            {
                switch (msg.msgid) {
                case MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM:
                    dock.lat=mavlink_msg_dock_message_transform_get_lat(&msg)/10000000.0;
                    dock.lng=mavlink_msg_dock_message_transform_get_lng(&msg)/10000000.0;
                    dock.yaw=mavlink_msg_dock_message_transform_get_yaw(&msg);
                    dock.pitch=mavlink_msg_dock_message_transform_get_pitch(&msg);
                    dock.roll=mavlink_msg_dock_message_transform_get_roll(&msg);
                    dock.velocity_course=mavlink_msg_dock_message_transform_get_course(&msg);
                    dock.velocity_number=mavlink_msg_dock_message_transform_get_velocity(&msg);


                    this->ui->label_dock_lng->setText(QString::number(dock.lng,'f',7)+"°");
                    this->ui->label_dock_lat->setText(QString::number(dock.lat,'f',7)+"°");
                    this->ui->label_dock_yaw->setText(QString::number(static_cast<double>(dock.yaw),'f',2)+"°");
                    this->ui->label_dock_pitch->setText(QString::number(static_cast<double>(dock.pitch),'f',2)+"°");
                     this->ui->label_dock_roll->setText(QString::number(static_cast<double>(dock.roll),'f',2)+"°");
                     this->ui->label_dock_vel->setText(QString::number(static_cast<double>(dock.velocity_number),'f',2)+"°");
                     this->ui->label_dock_course->setText(QString::number(static_cast<double>(dock.velocity_course),'f',2)+"°");
                    mapChannel->updateDockPos(static_cast<double>(dock.lng),static_cast<double>(dock.lat),static_cast<double>(dock.yaw));

                break;
                default:
                break;
                }
            }
        }
    }

}

void MainWindow::sendMavlink(mavlink_message_t msg)
{

    if(tcpClient->isOpen())
    {
        uint8_t buf[100];
        uint16_t len = mavlink_msg_to_send_buffer(buf,&msg);
        tcpClient -> write(reinterpret_cast<char*>(buf),len);

    }
   if(tcpClient->isOpen()==false)
    {
       showMessageBox(QMessageBox::Warning,QString("提示"),QString("请先连接网口"));
    }
}

void MainWindow::showMessageBox(QMessageBox::Icon icon, QString title, QString text)
{
    messageBox -> setIcon(icon);
    messageBox -> setWindowTitle(title);
    messageBox -> setText(text);
    messageBox -> show();
}

void MainWindow::on_pushButton_add_point_clicked()
{
    mapChannel->addPoint(this->ui->lineEdit_lng->text().toDouble(),this->ui->lineEdit_lat->text().toDouble());
}

void MainWindow::on_pushButton_move_point_clicked()
{
    mapChannel->movePoint(this->ui->lineEdit_id->text().toInt(),this->ui->lineEdit_lng->text().toDouble(),this->ui->lineEdit_lat->text().toDouble());
}

void MainWindow::on_pushButton_set_home_clicked()
{
    mavlink_message_t msg;
    mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,1,0);
    sendMavlink(msg);
}

void MainWindow::on_pushButton_download_task_clicked()
{

   qDebug()<<waypoints->length()<<endl;
    if(waypoints->length() > 0)
    {
        mavlink_message_t msg;
        mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,2,waypointsNum);
        sendMavlink(msg);
        sendTimer->start(50);
    }else{
        showMessageBox(QMessageBox::Warning,"提示","请先添加航点！");
    }
}

void MainWindow::sendWaypoint()
{
    static uint8_t index = 0;
    mavlink_message_t msg;
    mavlink_msg_waypoints_pack(0,0,&msg,index,static_cast<uint32_t>(waypoints->at(index).lng*10000000),static_cast<uint32_t>(waypoints->at(index).lat*10000000));
    sendMavlink(msg);
    index++;
    if(index == waypoints->length())
    {
        index = 0;
        sendTimer->stop();
        qDebug()<<"a"<<endl;
    }
}

void MainWindow::on_pushButton_go_home_clicked()
{
    mavlink_message_t msg;
    mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,3,0);
    sendMavlink(msg);
}

void MainWindow::on_pushButton_do_task_clicked()
{
    mavlink_message_t msg;
    if(this -> ui -> pushButton_do_task -> text() == "开始执行")
       { mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,4,1);
        this->ui->pushButton_do_task->setText("停止执行");
    }
    else
    {mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,4,0);
      this->ui->pushButton_do_task->setText("开始执行");
    }
    sendMavlink(msg);
}

void MainWindow::on_pushButton_query_param_clicked()
{
    mavlink_message_t msg;
    mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,5,0);
    sendMavlink(msg);
}

void MainWindow::on_pushButton_set_param_clicked()
{
    mavlink_message_t msg;
    mavlink_msg_control_param_pack(0,0,&msg,
                                   this->ui->lineEdit_kp->text().toFloat(),
                                   this->ui->lineEdit_ki->text().toFloat(),
                                   this->ui->lineEdit_kd->text().toFloat(),
                                   this->ui->lineEdit_los->text().toFloat(),
                                   this->ui->lineEdit_threshold_dis->text().toFloat(),
                                   static_cast<uint32_t>(this->ui->lineEdit_xunhang_pwm->text().toUInt()),
                                   this->ui->lineEdit_los2->text().toFloat(),
                                   this->ui->kp_Visual->text().toFloat(),
                                   this->ui->ki_Visual->text().toFloat(),
                                   this->ui->kd_Visual->text().toFloat(),
                                   this->ui->kp_vel->text().toFloat(),
                                   this->ui->ki_vel->text().toFloat(),
                                   this->ui->kd_vel->text().toFloat(),
                                   this->ui->desired_vel->text().toFloat()
                                   );
    //qDebug()<< static_cast<uint8_t>(this->ui->lineEdit_xunhang_pwm->text().toUInt()/7.8125f-1)<<endl;
   sendMavlink(msg);
}

void MainWindow::on_pushButton_save_clicked()
{
    if(this->ui->pushButton_save->text() == "保存数据")
    {
        sqlUsvLogTableName = QString("auvlog%1").arg(QDateTime::currentDateTime().toString("yy_MM_dd"));  //表名称
        QString sql = QString("select * from sqlite_master where name = '%1'").arg(sqlUsvLogTableName);
        sqlQurey.exec(sql); //判断表是否已经存在
        if(sqlQurey.next())
             qDebug()<<QString("Table %1 already exists").arg(sqlUsvLogTableName);  //存在
        else  //不存在则创建
        {
             if(!sqlQurey.exec(QString("create table %1(Time text primary key, mode int, lng double, lat double, x float, y float, yaw float, pitch float, heel float, velocity float, thrust int, rudder int, progress int, satellite int)").arg(sqlUsvLogTableName)))
                 qDebug()<<sqlQurey.lastError();
             else
                 qDebug()<<QString("Create table %1 successfully").arg(sqlUsvLogTableName);
        }

        isSaving = true;
        this->ui->pushButton_save->setText("停止保存");
    }else{
        isSaving = false;
        this->ui->pushButton_save->setText("保存数据");
    }
}

void MainWindow::on_pushButton_open_task_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"Open Json Task",QDir::currentPath()+"/task","JSON File(*.json)");
    QFile jsonFile(path);
    if(!jsonFile.open(QIODevice::ReadOnly))
    {
        showMessageBox(QMessageBox::Warning,"提示","Json文件打开失败，请重试");
        return;
    }
    QStringList stringList = path.split('/');
    this -> ui -> lineEdit_task_name -> setText(stringList.last());
    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(jsonFile.readAll(),&jsonError));
    jsonFile.close();
    if(jsonError.error != QJsonParseError::NoError)
    {
        showMessageBox(QMessageBox::Warning,"提示",QString("Json解析失败，错误代码：%1，%2").arg(jsonError.error).arg(jsonError.errorString()));
        return;
    }
    QJsonObject rootObj = jsonDoc.object();
    int taskType = 0;
    if(rootObj.contains("taskType"))
    {
        QJsonValue taskTypeValue = rootObj.value("taskType");
        if(taskTypeValue.isDouble())
        {
            taskType = taskTypeValue.toInt();
            if(taskType<5)
            {
                if(taskType == 4 )
                    showMessageBox(QMessageBox::Information,"提示","在已在地图中添加围栏！");
            }
            else{
                showMessageBox(QMessageBox::Warning,"提示","Json中taskType取值范围错误!");
                return;
            }
        }
        else
        {
            showMessageBox(QMessageBox::Warning,"提示","Json中taskType类型错误");
            return;
        }
    }else{
        showMessageBox(QMessageBox::Warning,"提示","Json中无taskType！");
        return;
    }

    if(taskType == 1)
    {
        mapChannel->clearWaypoints();
        waypoints->clear();
        int pointsNum=0;
        if(rootObj.contains("pointsNum"))
        {
            QJsonValue pointsNumValue = rootObj.value("pointsNum");
            if(pointsNumValue.isDouble())
                pointsNum = pointsNumValue.toInt();
            else{
                showMessageBox(QMessageBox::Warning,"提示","Json中pointsNum类型错误！");
                return;
            }
        }else{
            showMessageBox(QMessageBox::Warning,"提示","Json中无pointsNum！");
            return;
        }
        if(rootObj.contains("waypoints"))
        {
            QJsonValue waypointsValue = rootObj.value("waypoints");
            if(waypointsValue.isObject())
            {
                QJsonObject waypointsObject = waypointsValue.toObject();
                for (int i=0; i<pointsNum; i++)
                {
                    QString waypointIndex = QString::number(i);
                    if(waypointsObject.contains(waypointIndex))
                    {
                        QJsonObject waypointObject = waypointsObject.value(waypointIndex).toObject();
                        qDebug()<<waypointIndex<< waypointObject.value("lng").toDouble()<< waypointObject.value("lat").toDouble();
                        waypoints->append(*new Waypoint(waypointObject.value("lng").toDouble(),waypointObject.value("lat").toDouble()));
                    }else{
                        showMessageBox(QMessageBox::Warning,"提示","Json中pointsNum和waypoints内的航点个数不同！");
                        return;
                    }
                }
                taskWidget->getWaypointsList(waypoints);
                taskWidget->show();
                waypointsNum=(uint8_t)waypoints->length();
                for(int i=0; i<waypoints->length(); i++)
                    mapChannel->addPoint(waypoints->at(i).lng,waypoints->at(i).lat);
            }else{
                showMessageBox(QMessageBox::Warning,"提示","Json中waypoints不是JsonObject！");
                return;
            }
        }else{
            showMessageBox(QMessageBox::Warning,"提示","Json中无waypoints！");
            return;
        }
    }
    else if (taskType == 4) {
        mapChannel -> clearFence();
        int pointsNum=0;
        if(rootObj.contains("pointsNum"))
        {
            QJsonValue pointsNumValue = rootObj.value("pointsNum");
            if(pointsNumValue.isDouble())
                pointsNum = pointsNumValue.toInt();
            else{
                showMessageBox(QMessageBox::Warning,"提示","Json中pointsNum类型错误！");
                return;
            }
        }else{
            showMessageBox(QMessageBox::Warning,"提示","Json中无pointsNum！");
            return;
        }
        if(rootObj.contains("waypoints"))
        {
            QJsonValue waypointsValue = rootObj.value("waypoints");
            if(waypointsValue.isObject())
            {
                QJsonObject waypointsObject = waypointsValue.toObject();
                for (int i=0; i<pointsNum; i++)
                {
                    QString waypointIndex = QString::number(i);
                    if(waypointsObject.contains(waypointIndex))
                    {
                        QJsonObject waypointObject = waypointsObject.value(waypointIndex).toObject();
                        mapChannel->addFencePoint(waypointObject.value("lng").toDouble(),waypointObject.value("lat").toDouble());
                    }else{
                        showMessageBox(QMessageBox::Warning,"提示","Json中pointsNum和waypoints内的航点个数不同！");
                        return;
                    }
                }
                mapChannel->addFence();
            }else{
                showMessageBox(QMessageBox::Warning,"提示","Json中waypoints不是JsonObject！");
                return;
            }
        }else{
            showMessageBox(QMessageBox::Warning,"提示","Json中无waypoints！");
            return;
        }
    }
}

void MainWindow::on_pushButton_save_task_clicked()
{
    if(this -> ui -> lineEdit_task_name -> text().isEmpty())
    {
        showMessageBox(QMessageBox::Warning,"提示","文件名称未填写，请填写！");
        return;
    }else{
        QJsonObject rootObject;
        QJsonObject waypointsObject;
        if(waypoints->length() == 0)
        {
            showMessageBox(QMessageBox::Warning,"提示","无航点，请先添加航点！");
            return;
        }
        for(int i=0; i<waypoints->length(); i++)
        {
            QJsonObject waypointObject;
            waypointObject["lng"] = waypoints->at(i).lng;
            waypointObject["lat"] = waypoints->at(i).lat;
            QString waypointIndex = QString::number(i);
            waypointsObject[waypointIndex] = waypointObject;
        }
        rootObject["taskType"] = 1;
        rootObject["pointsNum"] = waypoints->length();
        rootObject["waypoints"] = waypointsObject;

        QFile file(QDir::currentPath()+"/task/"+this -> ui -> lineEdit_task_name -> text()+".json");
        file.open(QIODevice::WriteOnly);
        file.write(QJsonDocument(rootObject).toJson());
        file.close();
    }
}

void MainWindow::on_pushButton_read_param_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"Open Json Task",QDir::currentPath()+"/param/control_param","JSON File(*.json)");
    QFile jsonFile(path);
    if(!jsonFile.open(QIODevice::ReadOnly))
    {
        showMessageBox(QMessageBox::Warning,"提示","Json文件打开失败，请重试！");
        return;
    }
    QStringList stringList = path.split('/');
    this -> ui -> lineEdit_param_name -> setText(stringList.last());
    QJsonObject rootObj = QJsonDocument::fromJson(jsonFile.readAll()).object();
    jsonFile.close();
    this->ui->lineEdit_kp->setText(QString::number(rootObj.value("kp").toDouble()));
    this->ui->lineEdit_ki->setText(QString::number(rootObj.value("ki").toDouble()));
    this->ui->lineEdit_kd->setText(QString::number(rootObj.value("kd").toDouble()));
    this->ui->lineEdit_los->setText(QString::number(rootObj.value("los").toDouble()));
    this->ui->lineEdit_threshold_dis->setText(QString::number(rootObj.value("threshold_dis").toDouble()));
    this->ui->lineEdit_xunhang_pwm->setText(QString::number(rootObj.value("xunhang_pwm").toDouble()));
    this->ui->lineEdit_los2->setText(QString::number(rootObj.value("los2").toDouble()));
    this->ui->kp_Visual->setText(QString::number(rootObj.value("kp_visual").toDouble()));
    this->ui->ki_Visual->setText(QString::number(rootObj.value("ki_visual").toDouble()));
    this->ui->kd_Visual->setText(QString::number(rootObj.value("kd_visual").toDouble()));
    this->ui->kp_vel->setText(QString::number(rootObj.value("kp_vel").toDouble()));
    this->ui->ki_vel->setText(QString::number(rootObj.value("ki_vel").toDouble()));
    this->ui->kd_vel->setText(QString::number(rootObj.value("kd_vel").toDouble()));
    this->ui->desired_vel->setText(QString::number(rootObj.value("desired_vel").toDouble()));
}

void MainWindow::on_pushButton_save_param_clicked()
{
    if(this -> ui -> lineEdit_param_name -> text().isEmpty())
    {
        showMessageBox(QMessageBox::Warning,"提示","文件名称未填写，请填写！");
        return;
    }else{
        QJsonObject rootObject;
        rootObject["kp"] = this->ui->lineEdit_kp->text().toDouble();
        rootObject["ki"] = this->ui->lineEdit_ki->text().toDouble();
        rootObject["kd"] = this->ui->lineEdit_kd->text().toDouble();
        rootObject["los"] = this->ui->lineEdit_los->text().toDouble();
        rootObject["threshold_dis"] = this->ui->lineEdit_threshold_dis->text().toDouble();
        rootObject["xunhang_pwm"] = this->ui->lineEdit_xunhang_pwm->text().toDouble();
        rootObject["los2"] = this->ui->lineEdit_los2->text().toDouble();
        rootObject["kp_visual"] = this->ui->kp_Visual->text().toDouble();
        rootObject["ki_visual"] = this->ui->ki_Visual->text().toDouble();
        rootObject["kd_visual"] = this->ui->kd_Visual->text().toDouble();
        rootObject["kp_vel"] = this->ui->kp_vel->text().toDouble();
        rootObject["ki_vel"] = this->ui->ki_vel->text().toDouble();
        rootObject["kd_vel"] = this->ui->kd_vel->text().toDouble();
        rootObject["desired_vel"] = this->ui->desired_vel->text().toDouble();
        QFile file;
        file.setFileName(QDir::currentPath()+"/param/param_"+this -> ui -> lineEdit_param_name -> text()+".json");
        file.open(QIODevice::WriteOnly);
        file.write(QJsonDocument(rootObject).toJson());
        file.close();
    }
}

void MainWindow::on_pushButton_test_clicked()
{
    static int i = 0;
    if(isSaving)
    {

        QString nowTime = QTime::currentTime().toString("hh:mm:ss.zzz");
        //qDebug()<<nowTime;
        if(!sqlQurey.exec(QString("insert into %1 values('%2',%3,%4,%5,%6,%7,%8,%9,%10,%11,%12,%13,%14,%15)").arg(sqlUsvLogTableName)
                          .arg(nowTime).arg(i).arg(i).arg(i).arg(static_cast<double>(i),0,'f',1).arg(static_cast<double>(i),0,'f',1)
                          .arg(static_cast<double>(i),0,'f',1).arg(static_cast<double>(i),0,'f',1).arg(static_cast<double>(i),0,'f',1)
                          .arg(static_cast<double>(i),0,'f',1).arg(i).arg(i)
                          .arg(i).arg(i)))
            qDebug()<<sqlQurey.lastError();
        i++;
    }
}
void MainWindow::TCPClientInit()
{
    tcpClient = new QTcpSocket(this);   //实例化tcpClient
    tcpClient->abort();                 //取消原有连接
    connect(tcpClient, &QTcpSocket::readyRead, this, &MainWindow::readData);
    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(ReadError(QAbstractSocket::SocketError)));
}

void MainWindow::readData()
{
    QByteArray TCPbuf = tcpClient->readAll();
    if(!TCPbuf.isEmpty())
    {
        mavlink_message_t msg;
        mavlink_status_t status;
        for (int i=0; i<TCPbuf.length(); i++) {
            if(MAVLINK_FRAMING_OK == mavlink_parse_char(MAVLINK_COMM_0,static_cast<uint8_t>(TCPbuf[i]),&msg,&status))
            {
                switch (msg.msgid) {
                case MAVLINK_MSG_ID_USV_STATE:
                    usv.mode = mavlink_msg_usv_state_get_mode(&msg);
                    usv.lng = mavlink_msg_usv_state_get_lng(&msg)/10000000.0;
                    usv.lat = mavlink_msg_usv_state_get_lat(&msg)/10000000.0;
                    usv.x = mavlink_msg_usv_state_get_x(&msg);
                    usv.y = mavlink_msg_usv_state_get_y(&msg);
                    usv.yaw = mavlink_msg_usv_state_get_yaw(&msg);
                    usv.pitch = mavlink_msg_usv_state_get_pitch(&msg);
                    usv.heel = mavlink_msg_usv_state_get_heel(&msg);
                    usv.velocity = mavlink_msg_usv_state_get_velocity(&msg);
                    usv.course = mavlink_msg_usv_state_get_course(&msg);
                    usv.rudder = mavlink_msg_usv_state_get_rudder(&msg);
                    usv.GyroZ = mavlink_msg_usv_state_get_GyroZ(&msg);
                    usv.electric_current = mavlink_msg_usv_state_get_electric_current(&msg);
                    usv.voltage=mavlink_msg_usv_state_get_voltage(&msg);
                    this -> ui -> label_boat_lng -> setText(QString::number(usv.lng,'f',7)+"°");
                    this -> ui -> label_boat_lat -> setText(QString::number(usv.lat,'f',7)+"°");
                    this -> ui -> label_boat_x -> setText(QString::number(static_cast<double>(usv.x))+"m");
                    this -> ui -> label_boat_y -> setText(QString::number(static_cast<double>(usv.y))+"m");
                    this -> ui -> label_boat_yaw -> setText(QString::number(static_cast<double>(usv.yaw))+"°");
                    this -> ui -> label_boat_heel -> setText(QString::number(static_cast<double>(usv.heel))+"°");
                    this -> ui -> label_boat_velocity -> setText(QString::number(static_cast<double>(usv.velocity)) +"m/s");
                    this -> ui -> label_boat_rudder -> setText(QString::number(usv.rudder)+"°");
                    this -> ui -> label_voltage -> setText(QString::number(usv.voltage,'f',3)+"V");
                    this -> ui -> label_electric_current -> setText(QString::number(usv.electric_current,'f',3)+"A");
                    this -> ui -> gaugePlane -> setRollValue(static_cast<int>(usv.pitch));
                    this -> ui -> gaugePlane -> setDegValue(static_cast<int>(usv.heel));
                    this -> ui -> gaugeCompassPan -> setValue(static_cast<double>(usv.yaw));

                    if(usv.mode == 0)
                      {this -> ui -> lightPoint -> setBgColor(Qt::green);
                    }
                    else
                        this -> ui -> lightPoint -> setBgColor(Qt::yellow);
                    mapChannel->updateBoatPos(0, usv.lng, usv.lat, static_cast<double>(usv.yaw) * 180 / M_PI, 0, false, 0, 0);
                    if (this->isShowPrediction)
                    {
                        mapChannel->predictBoat(usv.lng, usv.lat, static_cast<double>(usv.yaw), usv.velocity * cos(usv.course - usv.yaw), usv.velocity * sin(usv.course - usv.yaw), usv.GyroZ, usv.rudder, 1300, false, 0.01, 0, 10);
                    }
                    if(isSaving)
                    {
                        QString nowTime = QTime::currentTime().toString("hh:mm:ss.zzz");
                        //qDebug()<<nowTime;
                        if(!sqlQurey.exec(QString("insert into %1 values('%2',%3,%4,%5,%6,%7,%8,%9,%10,%11,%12,%13,%14,%15)").arg(sqlUsvLogTableName)
                                          .arg(nowTime).arg(usv.mode).arg(usv.lng,0,'f',7).arg(usv.lat,0,'f',7).arg(static_cast<double>(usv.x),0,'f',1).arg(static_cast<double>(usv.y),0,'f',1)
                                          .arg(static_cast<double>(usv.yaw),0,'f',1).arg(static_cast<double>(usv.pitch),0,'f',1).arg(static_cast<double>(usv.heel),0,'f',1)
                                          .arg(static_cast<double>(usv.velocity),0,'f',1).arg(usv.course).arg(usv.rudder)
                                          .arg(usv.GyroZ).arg(usv.satellite)))
                            qDebug()<<sqlQurey.lastError();
                    }
                    break;
                case MAVLINK_MSG_ID_GCS_SET_OR_USV_ACK:
                {
                    uint8_t type = mavlink_msg_gcs_set_or_usv_ack_get_type(&msg);
                    switch (type) {
                    case 1:
                        showMessageBox(QMessageBox::Information,"提示","原点设置成功！");
                        mapChannel->setOrigin(usv.lng,usv.lat);
                        break;
                    case 2:
                        showMessageBox(QMessageBox::Information,"提示","航点下达成功！");
                        break;
                    case 3:
                        showMessageBox(QMessageBox::Information,"提示","一键返航任务下达成功！");
                        break;
                    case 4:
                        if(mavlink_msg_gcs_set_or_usv_ack_get_content(&msg))
                            showMessageBox(QMessageBox::Information,"提示","开始执行任务！");
                        else
                            showMessageBox(QMessageBox::Information,"提示","停止执行任务！");
                        break;
                    case 5:
                         showMessageBox(QMessageBox::Information,"提示","参数下达成功");
                    break;
                    case 12:
                        showMessageBox(QMessageBox::Information,"提示","任务完成");
                         this->ui->pushButton_do_task->setText("开始执行");
                    break;
                    default:
                    break;
                    }
                }
                    break;
                case MAVLINK_MSG_ID_CONTROL_PARAM:
                {
                    float kp = mavlink_msg_control_param_get_kp(&msg);
                    float ki = mavlink_msg_control_param_get_ki(&msg);
                    float kd = mavlink_msg_control_param_get_kd(&msg);
                    float los = mavlink_msg_control_param_get_los(&msg);
                    float threshold_dis = mavlink_msg_control_param_get_threshold_dis(&msg);
                    uint32_t xunhang_pwm = (uint32_t)((mavlink_msg_control_param_get_xunhang_pwm(&msg)+1)*7.8125);
                    float los2 = mavlink_msg_control_param_get_los2(&msg);

                    this -> ui -> lineEdit_kp -> setText(QString::number(static_cast<double>(kp)));
                    this -> ui -> lineEdit_ki -> setText(QString::number(static_cast<double>(ki)));
                    this -> ui -> lineEdit_kd -> setText(QString::number(static_cast<double>(kd)));
                    this -> ui -> lineEdit_los -> setText(QString::number(static_cast<double>(los)));
                    this -> ui -> lineEdit_threshold_dis -> setText(QString::number(static_cast<double>(threshold_dis)));
                    this -> ui -> lineEdit_xunhang_pwm -> setText(QString::number(xunhang_pwm));
                    this -> ui -> lineEdit_los2 -> setText(QString::number(los2));

                    showMessageBox(QMessageBox::Information,"提示","获取艇载控制参数！");
                }
                    break;
                default:
                    break;
                }
            }
        }
    }
}
void MainWindow::ReadError(QAbstractSocket::SocketError)
{
    QTcpSocket *errSocket = qobject_cast<QTcpSocket *>(sender());
    if(errSocket == tcpClient)
    {
        tcpClient->disconnectFromHost();
        ui->TCPconnect->setText(tr("连接"));
        this -> ui -> lightPoint -> setBgColor(Qt::red);
        QMessageBox msgBox;
        msgBox.setText(tr("failed to connect server because %1").arg(tcpClient->errorString()));
    }
}

void MainWindow::on_TCPconnect_clicked()
{
    if(this->ui->TCPconnect->text()=="连接")
    {
        tcpClient->connectToHost(ui->lineEdit_IP->text(), ui->lineEdit_port->text().toUInt());
        if (tcpClient->waitForConnected(1000))  // 连接成功则进入if{}
        {
            this->ui->TCPconnect->setText("断开");
            this -> ui -> lightPoint -> setBgColor(Qt::green);
            this -> commuTimer -> start(1000);
        }
    }
    else
    {
        tcpClient->disconnectFromHost();


        if (tcpClient->state() == QAbstractSocket::UnconnectedState  || tcpClient->waitForDisconnected(1000))  //已断开连接则进入if{}
        {
          this -> ui -> lightPoint -> setBgColor(Qt::red);
          this->ui->TCPconnect->setText("连接");
          this -> commuTimer -> stop();

        }
    }
}

void MainWindow::on_set_task_clicked()
{
    mavlink_message_t msg;
    mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,static_cast<uint8_t>(ui->task_mode->currentIndex()+7),static_cast<uint8_t>(ui->MA_mode->currentIndex()));
    sendMavlink(msg);
    mavlink_msg_maneuverability_control_pack(0,0,&msg,ui->lineEdit_FI->text().toFloat(),ui->lineEdit_Z5->text().toFloat(),ui->lineEdit_huizhuanangle->text().toFloat());
    sendMavlink(msg);
    mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,static_cast<uint8_t>(13),static_cast<uint8_t>(ui->VelCtrMode->currentIndex()));
    sendMavlink(msg);
    mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,static_cast<uint8_t>(14),static_cast<uint8_t>(ui->VelCtrMode_2->currentIndex()));
    sendMavlink(msg);
}

void MainWindow::on_RC_control_send_clicked()
{
    mavlink_message_t msg;
    mavlink_msg_rc_control_pack(0,0,&msg,ui->RC_v_PWM->text().toUShort(),ui->RC_rudder_Angle->text().toFloat());
    sendMavlink(msg);
}

void MainWindow::on_send_neu_point_clicked()
{
    mavlink_message_t msg;
    mavlink_msg_neupoint_with_course_follow_pack(0,0,&msg,static_cast<uint32_t>(ui->LON_point->text().toFloat()*10000000),static_cast<uint32_t>(ui->LAT_point->text().toFloat()*10000000),ui->point_course->text().toFloat());
    sendMavlink(msg);
}


void MainWindow::on_LED_close_clicked()
{
    mavlink_message_t msg;
    mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,(uint16_t)12,static_cast<uint16_t>(ui->LEDColor_comboBox->currentIndex()));
    sendMavlink(msg);
}

void MainWindow::dockSimuStep()
{
    double latRad = dockLat/d2r;
    double headingRad = dockHeading/d2r;

    double midValue = 1-ee*sin(latRad)*sin(latRad);
    double Rn = a/sqrt(midValue);
    double Rm = Rn*(1-ee)/midValue;

    dockLat = dockLat + dockVel*cos(headingRad)/Rm*0.2*d2r;
    dockLng = dockLng + dockVel*sin(headingRad)/Rn/cos(latRad)*0.2*d2r;

    noiseDockLat = dockLat + (QRandomGenerator::global()->bounded(posNoise*2)-posNoise)/Rm*d2r;
    noiseDockLng = dockLng + (QRandomGenerator::global()->bounded(posNoise*2)-posNoise)/Rn/cos(latRad)*d2r;
    noiseDockHeading = dockHeading + (QRandomGenerator::global()->bounded(headingNoise*2)-headingNoise);
    if(noiseDockHeading>360)
        noiseDockHeading-=360;
    else if(noiseDockHeading<0)
        noiseDockHeading+=360;
    this -> ui -> label_simulate_dock_status -> setText(QString("%1°,%2°,%3°").arg(noiseDockLng,0,'f',7).arg(noiseDockLat,0,'f',7).arg(noiseDockHeading,0,'f',1));
    mapChannel->updateDockPos(noiseDockLng,noiseDockLat,noiseDockHeading);
    mavlink_message_t msg;
    mavlink_msg_neupoint_with_course_follow_pack(0,0,&msg,static_cast<uint32_t>(noiseDockLng*10000000),static_cast<uint32_t>(noiseDockLat*10000000),static_cast<uint32_t>(noiseDockHeading));
    sendMavlink(msg);
    /*向无人艇发送虚拟坞站状态*/
}

void MainWindow::on_pushButton_start_simulate_dock_clicked()
{
    if(this->ui->pushButton_start_simulate_dock->text()=="开始模拟")
    {
        dockLat = this->ui->lineEdit__origin_dock_lat->text().toDouble();
        dockLng = this->ui->lineEdit_origin_dock_lng->text().toDouble();
        dockVel = this->ui->lineEdit_dock_vel->text().toDouble();
        dockHeading = this->ui->lineEdit_dock_heading->text().toDouble();

        posNoise = this->ui->lineEdit_pos_noise->text().toDouble();
        headingNoise = this->ui->lineEdit_heading_noise->text().toDouble();
        simuTimer->start(200);
        this->ui->pushButton_start_simulate_dock->setText("停止模拟");
    }else {
        simuTimer->stop();
        this->ui->pushButton_start_simulate_dock->setText("开始模拟");
    }
}



void MainWindow::on_visual_set_clicked()
{
    mavlink_message_t msg;
    mavlink_msg_visual_setting_pack(0,0,&msg,static_cast<uint8_t>(this->ui->visual_test->currentIndex()),static_cast<uint8_t>(this->ui->isLinear->currentIndex()),static_cast<uint8_t>(this->ui->filter_type->currentIndex()));
    sendMavlink(msg);
}

void MainWindow::on_get_insdock_clicked()
{
    if(this->ui->get_insdock->text()=="开启惯导获取")
    {

        this->ui->get_insdock->setText("停止惯导获取");
        this -> sendINSDock -> start(200);
    }
    else
    {


          this->ui->get_insdock->setText("开启惯导获取");
          this ->sendINSDock -> stop();


    }
}
void MainWindow::InsDockSend()
{
    mavlink_message_t msg1;
    mavlink_message_t msg2;
    mavlink_msg_neupoint_with_course_follow_pack(0,0,&msg1,static_cast<uint32_t>(dock.lng*10000000),static_cast<uint32_t>(dock.lat*10000000),static_cast<float>(dock.velocity_course));
    mavlink_msg_dock_message_transform_pack(0,0,&msg2,static_cast<uint32_t>(dock.lng*10000000),static_cast<uint32_t>(dock.lat*10000000),static_cast<float>(dock.velocity_number),dock.velocity_course,dock.roll,dock.pitch,dock.yaw,1);
    sendMavlink(msg1);
    sendMavlink(msg2);
}

void MainWindow::on_LED_open_clicked()
{
    mavlink_message_t msg;
    mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,static_cast<uint16_t>(15),static_cast<uint16_t>(ui->LEDColor_comboBox->currentIndex()));
    sendMavlink(msg);
}

void MainWindow::on_TCP_AUV_Connect_clicked()
{
    if(this->ui->TCP_AUV_Connect->text()=="连接")
    {
        tcpClient2->connectToHost(ui->AUV_IP->text(), ui->AUV_PORT->text().toUInt());
        if (tcpClient2->waitForConnected(1000))  // 连接成功则进入if{}
        {
            this->ui->TCP_AUV_Connect->setText("断开");

        }
    }
    else
    {
        tcpClient2->disconnectFromHost();


        if (tcpClient2->state() == QAbstractSocket::UnconnectedState  || tcpClient2->waitForDisconnected(1000))  //已断开连接则进入if{}
        {

          this->ui->TCP_AUV_Connect->setText("连接");

        }
    }
}
void MainWindow::readAUVData()
{
    QByteArray TCPbuf = tcpClient2->readAll();
    if(!TCPbuf.isEmpty())
    {
        mavlink_message_t msg;
        mavlink_status_t status;
        for (int i=0; i<TCPbuf.length(); i++) {
            if(MAVLINK_FRAMING_OK == mavlink_parse_char(MAVLINK_COMM_0,static_cast<uint8_t>(TCPbuf[i]),&msg,&status))
            {
                switch (msg.msgid) {
                case MAVLINK_MSG_ID_AUV_FIELD_STATUS:
                dock.lat=static_cast<double>(mavlink_msg_auv_field_status_get_lat(&msg)/10000000.f);
                dock.lng=static_cast<double>(mavlink_msg_auv_field_status_get_lon(&msg)/10000000.f);
                dock.yaw=mavlink_msg_auv_field_status_get_yaw(&msg);
                dock.pitch=mavlink_msg_auv_field_status_get_pitch(&msg);
                dock.roll=mavlink_msg_auv_field_status_get_roll(&msg);
                dock.velocity_course=mavlink_msg_auv_field_status_get_course(&msg);
                dock.velocity_number=mavlink_msg_auv_field_status_get_vel(&msg);


                this->ui->label_dock_lng->setText(QString::number(dock.lng,'f',7)+"°");
                this->ui->label_dock_lat->setText(QString::number(dock.lat,'f',7)+"°");
                this->ui->label_dock_yaw->setText(QString::number(static_cast<double>(dock.yaw),'f',2)+"°");
                this->ui->label_dock_pitch->setText(QString::number(static_cast<double>(dock.pitch),'f',2)+"°");
                this->ui->label_dock_roll->setText(QString::number(static_cast<double>(dock.roll),'f',2)+"°");
                this->ui->label_dock_vel->setText(QString::number(static_cast<double>(dock.velocity_number/100.f),'f',2)+"m/s");
                this->ui->label_dock_course->setText(QString::number(static_cast<double>(dock.velocity_course),'f',2)+"°");
                mapChannel->updateDockPos(static_cast<double>(dock.lng),static_cast<double>(dock.lat),static_cast<double>(dock.yaw));
                break;
                default:
                break;
                }
            }
        }
    }
}
void MainWindow::TCPClientInit2()
{
    tcpClient2 = new QTcpSocket(this);   //实例化tcpClient
    tcpClient2->abort();                 //取消原有连接
    connect(tcpClient2, &QTcpSocket::readyRead, this, &MainWindow::readAUVData);
    connect(tcpClient2, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(ReadError(QAbstractSocket::SocketError)));
}


void MainWindow::on_btn_ilos_clicked()
{
    if(this->ui->btn_ilos->text()=="ilos_start")
   {
    this->ui->btn_ilos->setText("ilos_stop");
    mavlink_message_t msg;
    mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,(uint16_t)16,static_cast<uint16_t>(1));
    sendMavlink(msg);
    }
    else{
        this->ui->btn_ilos->setText("ilos_start");
        mavlink_message_t msg;
        mavlink_msg_gcs_set_or_usv_ack_pack(0,0,&msg,(uint16_t)16,static_cast<uint16_t>(0));
        sendMavlink(msg);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if ( this->ui->pushButton_predict->text()=="开始预测")
    {

          this->isShowPrediction = true;
          this->ui->pushButton_predict->setText("停止预测");
    }
    else
   {
       this->ui->pushButton_predict->setText("开始预测");
       this->isShowPrediction = false;
    }

}
