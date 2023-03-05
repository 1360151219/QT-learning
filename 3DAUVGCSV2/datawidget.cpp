#include "datawidget.h"
#include "ui_datawidget.h"
#include <QDate>
#include <QDebug>
#include <QVector>
#include <QSqlRecord>
#include <QMutableMapIterator>
#include <QFileDialog>
#include "common.h"

DataWidget::DataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataWidget)
{
    ui->setupUi(this);
    connect(ui->tableView,&TableView::rightClicked,this,[=](QModelIndex index){
        if(index.column() == 0)
            this -> ui -> timeEdit_stop -> setTime(QTime::fromString(index.data().toString()));
    });
    connect(ui->tableView,&TableView::leftClicked,this,[=](QModelIndex index){
        if(index.column() == 0)
            this -> ui -> timeEdit_start -> setTime(QTime::fromString(index.data().toString()));
    });
    this -> ui -> tableView -> setItemDelegateForColumn(5,new DataDelegate());
    this -> ui -> tableView -> setItemDelegateForColumn(6,new DataDelegate());
    model = nullptr;
    listTableModel = nullptr;
    listNavigationModel = nullptr;
}

DataWidget::~DataWidget()
{
    on_pushButton_clear_all_figure_clicked();
    delete model;
    QSqlDatabase::removeDatabase("DataWidget");
    delete ui;
}

void DataWidget::on_pushButton_update_table_clicked()  //打开数据库，更新表
{
    if(model)
        delete model;
    QSqlDatabase::removeDatabase("DataWidget");

    QSqlDatabase db;
    QString path = QFileDialog::getOpenFileName(this,"Please Select DB",QDir::currentPath()+"/log","DB File(*.db)");
    db = QSqlDatabase::addDatabase("QSQLITE","DataWidget");
    db.setDatabaseName(path);
    if(!db.open())
    {
        qDebug()<<db.lastError().text();
        return;
    }
    QStringList list = db.tables();
    if(listTableModel)
        delete listTableModel;
    listTableModel = new QStringListModel(list);
    this -> ui -> listView -> setModel(listTableModel);
    model = new QSqlTableModel(this,db);
}

void DataWidget::on_listView_doubleClicked(const QModelIndex &index)  //选中数据表中的表，打开表，更新航次表
{
    tableName = index.data().toString();

    model->setTable(tableName);

    for (int i=this->ui->comboBox_data_draw->count()-1; i>4; i--) {
        this -> ui -> comboBox_data_draw -> removeItem(i);
    }
    for (int i=1; i<model->columnCount(); i++) {
        this -> ui -> comboBox_data_draw -> addItem(model->headerData(i,Qt::Horizontal).toString());
    }

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if(!model->select()) //选取整个表的所有行
        qDebug()<<model->lastError().text();
    while (model->canFetchMore())
        model->fetchMore();

    int allRows = model->rowCount();
    int flagIndex = model->record(0).indexOf("Working");
    int navigationInde=1;
    int startRow = 0,endRow;
    QStringList navigationStrList;
    for(int i=1;i<allRows;i++)
    {
        int firstFlag = model->record(i).value(flagIndex).toInt();
        int secondFlag = model->record(i+1).value(flagIndex).toInt();
        if(firstFlag == 0 && secondFlag == 1)
            startRow = i+1;
        if(firstFlag == 1 && secondFlag == 0)
        {
            endRow = i;
            navigationStrList << QString("%1,%2,%3,%4").arg(navigationInde).arg(startRow).arg(endRow).arg(taskTypeStrList.at(model->record(startRow).value(2).toInt()));
            navigationInde++;
        }
    }
    if(listNavigationModel)
        delete listNavigationModel;
    listNavigationModel = new QStringListModel(navigationStrList);
    this -> ui -> listView_navigation_table -> setModel(listNavigationModel);

    this -> ui -> tableView -> setModel(model);
    this -> ui -> tableView -> resizeColumnsToContents();

    QSqlRecord record = model -> record(0);
    this -> ui -> timeEdit_start -> setTime(QTime::fromString(record.value("Time").toString(),"hh:mm:ss.zzz"));
    record = model -> record(model->rowCount()-1);
    this -> ui -> timeEdit_stop -> setTime(QTime::fromString(record.value("Time").toString(),"hh:mm:ss.zzz"));
}

void DataWidget::on_listView_navigation_table_doubleClicked(const QModelIndex &index)
{
    on_pushButton_reset_clicked();

    QString navigationName = index.data().toString();
    QStringList strs = navigationName.split(',');
    int startRow = strs.at(1).toInt();
    int endRow = strs.at(2).toInt();

    QString startTime = model->record(startRow).value(0).toString();
    QString stopTime = model->record(endRow).value(0).toString();
    this -> ui -> timeEdit_start -> setTime(QTime::fromString(startTime,"hh:mm:ss.zzz"));
    this -> ui -> timeEdit_stop -> setTime(QTime::fromString(stopTime,"hh:mm:ss.zzz"));

    model -> setFilter(QString("Time >= '%1' and Time <= '%2'").arg(startTime).arg(stopTime));
    while (model->canFetchMore())
        model->fetchMore();
}

void DataWidget::on_pushButton_draw_clicked()  //新建Customplot，画图
{    
    const int len = model->rowCount();

    if(this->ui->comboBox_data_draw->currentIndex() == 0)
    {
        QVector<QCPCurveData> lnglatData(len), xyData(len);
        QVector<double> t(len);
        QVector<double> course(len), yaw(len), rudder(len), desiredYaw(len), ye(len), velocity(len);

        for (int i=0; i<len; i++) {
            QSqlRecord record = model -> record(i);
            lnglatData[i] = QCPCurveData(i,record.value("Lng").toDouble(),record.value("Lat").toDouble());
            xyData[i] = QCPCurveData(i,record.value("Y").toDouble(),record.value("X").toDouble());
            QTime time = QTime::fromString(record.value("Time").toString(),"hh:mm:ss.zzz");
            t[i] = this -> ui -> timeEdit_start -> time().msecsTo(time)/1000.0;
            yaw[i] = record.value("Yaw").toDouble();
            course[i] = record.value("Course").toDouble();
            desiredYaw[i] = record.value("DesiredYaw").toDouble();
            rudder[i] = record.value("RudderAngle").toDouble();
            ye[i] = record.value("ye").toDouble();
            velocity[i] = record.value("Velocity").toDouble();
        }
        hFigure = new HFigure(lnglatData,xyData,t,yaw,course,desiredYaw,rudder,ye,velocity);
        hFigure -> show();
    }
    else if(this->ui->comboBox_data_draw->currentIndex() == 1)
    {
        QVector<double> t(len), depth(len), desiredDepth(len), height(len), pitch(len), desiredPitch(len), elevator(len),heel(len),heelReject(len),alpha(len);

        for (int i=0; i<len; i++) {
            QSqlRecord record = model -> record(i);
            QTime time = QTime::fromString(record.value("Time").toString(),"hh:mm:ss.zzz");
            t[i] = this -> ui -> timeEdit_start -> time().msecsTo(time)/1000.0;
            depth[i] = record.value("Depth").toDouble();
            desiredDepth[i] = record.value("DesiredDepth").toDouble();
            height[i] = 0;
            pitch[i] = record.value("Pitch").toDouble();
            desiredPitch[i] = record.value("desiredPitch").toDouble();
            elevator[i] = record.value("SternAngle").toDouble();
            heel[i] = record.value("Heel").toDouble();
            heelReject[i] = record.value("heelControlAngle").toDouble();
            alpha[i] = record.value("alpha").toDouble();
        }
        vFigure = new VFigure(t,depth,desiredDepth,height,pitch,desiredPitch,elevator,heel,heelReject,alpha);
        vFigure -> show();
    }else if(this->ui->comboBox_data_draw->currentIndex() == 2)
    {
        QVector<QCPCurveData> lnglatData(len), xyData(len);
        QVector<double> t(len);
        QVector<double> depth(len), desiredDepth(len), height(len), yaw(len), course(len), desiredYaw(len), pitch(len), desiredPitch(len), heel(len), ye(len), rudder(len), elevator(len), velocity(len), alpha(len), beta(len);

        for (int i=0; i<len; i++) {
            QSqlRecord record = model -> record(i);
            lnglatData[i] = QCPCurveData(i,record.value("Lng").toDouble(),record.value("Lat").toDouble());
            xyData[i] = QCPCurveData(i,record.value("Y").toDouble(),record.value("X").toDouble());
            QTime time = QTime::fromString(record.value("Time").toString(),"hh:mm:ss.zzz");
            t[i] = this -> ui -> timeEdit_start -> time().msecsTo(time)/1000.0;
            depth[i] = record.value("Depth").toDouble();
            desiredDepth[i] = record.value("DesiredDepth").toDouble();
            height[i] = 0;
            yaw[i] = record.value("Yaw").toDouble();
            course[i] = record.value("Course").toDouble();
            desiredYaw[i] = record.value("DesiredYaw").toDouble();
            pitch[i] = record.value("Pitch").toDouble();
            desiredPitch[i] = record.value("desiredPitch").toDouble();
            heel[i] = record.value("Heel").toDouble();
            ye[i] = record.value("ye").toDouble();
            rudder[i] = record.value("RudderAngle").toDouble();
            elevator[i] = record.value("SternAngle").toDouble();
            velocity[i] = record.value("Velocity").toDouble();
            alpha[i] = record.value("alpha").toDouble();
            beta[i] = record.value("beta").toDouble();
        }
        mFigure = new MFigure(lnglatData,xyData,t,depth,desiredDepth,height,yaw,course,desiredYaw,pitch,desiredPitch,heel,ye,rudder,elevator,velocity,alpha,beta);
        mFigure -> show();
    }else{
        QString name = this -> ui -> comboBox_data_draw -> currentText();
        QString figureName = name;
        int index = 1;
        while(!this->ui->listWidget->findItems(figureName,Qt::MatchExactly).isEmpty())
        {
            figureName = name + QString::number(index);
            index++;
        }

        QPointer<QCustomPlot> newPlot = new QCustomPlot();
        newPlot->setWindowTitle(figureName);
        newPlot->setMinimumSize(600,400);
        newPlot->setAttribute(Qt::WA_QuitOnClose,false);

        if(this->ui->comboBox_data_draw->currentIndex() == 3)
        {
            QVector<double> lng(len),lat(len),depth(len);
            QSqlRecord record;
            for(int i=0; i<len; i++)
            {
                record = model->record(i);
                lng[i] = record.value("Lng").toDouble();
                lat[i] = record.value("Lat").toDouble();
                depth[i] = record.value("Depth").toDouble();
            }
            double course = record.value("Course").toDouble();
            double height = record.value("Height").toDouble();
            QCPCurve *track = new QCPCurve(newPlot->xAxis, newPlot->yAxis);
            track->addData(lng,lat);
            emit initTrack();
            emit transMapPoint(lng,lat,course,depth,height);
        }else if(this->ui->comboBox_data_draw->currentIndex() == 4)
        {
            QVector<QCPCurveData> data(len);
            for(int i=0; i<len; i++)
            {
                QSqlRecord record = model->record(i);
                data[i] = QCPCurveData(i,record.value("Y").toDouble(),record.value("X").toDouble());
            }
            QCPCurve *track = new QCPCurve(newPlot->xAxis, newPlot->yAxis);
            track->data()->set(data);
        }else{
            QVector<double> x(len), y(len);
            QString str = this -> ui -> comboBox_data_draw -> currentText();
            for (int i=0; i<len; i++)
            {
                QSqlRecord record = model->record(i);
                QTime time = QTime::fromString(record.value("Time").toString(),"hh:mm:ss.zzz");
                x.append(this -> ui -> timeEdit_start -> time().msecsTo(time)/1000.0);
                y.append(record.value(str).toDouble());
            }
            newPlot->addGraph();
            newPlot->graph(0)->addData(x,y);
        }

        newPlot->xAxis->setLabelFont(QFont("Helvetica",11));
        newPlot->yAxis->setLabelFont(QFont("Helvetica",11));
        if(this->ui->comboBox_data_draw->currentIndex() == 3)
        {
            newPlot->xAxis->setLabel("Lng");
            newPlot->yAxis->setLabel("Lat");
        }else if(this->ui->comboBox_data_draw->currentIndex() == 4){
            newPlot->xAxis->setLabel("Y");
            newPlot->yAxis->setLabel("X");
        }else{
            newPlot->xAxis->setLabel("time");
            newPlot->yAxis->setLabel(this->ui->comboBox_data_draw->currentText());
            QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
            timeTicker->setTimeFormat("%m:%s");
            newPlot->xAxis->setTicker(timeTicker);
        }

        newPlot->rescaleAxes();
        newPlot->axisRect() -> setupFullAxesBox();  //显示上边框和右边框
        newPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        newPlot->show();

        figureMap.insert(figureName, newPlot);
        this->ui->listWidget->addItem(figureName);
    }
}

void DataWidget::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(figureMap.contains(item->text()))
        figureMap.value(item->text())->show();
}

void DataWidget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    if(figureMap.contains(item->text()))
    {
        figureMap.value(item->text())->close();
        delete figureMap.take(item->text());
    }
    delete item;
    this -> ui -> listWidget -> removeItemWidget(item);
}

void DataWidget::on_pushButton_clear_all_figure_clicked()
{
    QMutableMapIterator<QString,QPointer<QCustomPlot>> i(figureMap);
    while (i.hasNext()) {
        i.next();
        i.value()->close();
        delete i.value();
        i.remove();
    }
    this->ui->listWidget->clear();
}

void DataWidget::on_pushButton_close_sql_clicked()
{
    on_pushButton_clear_all_figure_clicked();

    delete listTableModel;
    listTableModel = nullptr;
    delete listNavigationModel;
    listNavigationModel = nullptr;
    delete model;
    model = nullptr;
    QSqlDatabase::removeDatabase("DataWidget");

    int counts = this -> ui -> comboBox_data_draw-> count();
    for(int i=counts-1;i>4;i--)
        this -> ui -> comboBox_data_draw -> removeItem(i);
}

void DataWidget::on_pushButton_reset_clicked()
{
    model->setTable(tableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    while (model->canFetchMore())
        model->fetchMore();
    QSqlRecord record = model -> record(0);
    this -> ui -> timeEdit_start -> setTime(QTime::fromString(record.value("Time").toString(),"hh:mm:ss.zzz"));
    record = model -> record(model->rowCount()-1);
    this -> ui -> timeEdit_stop -> setTime(QTime::fromString(record.value("Time").toString(),"hh:mm:ss.zzz"));
}

/*********************Ftp**************************/
void DataWidget::on_pushButton_download_motion_log_clicked()
{
    if (ftp) {
        ftp -> abort();
        ftp -> deleteLater();
        ftp = nullptr;
        this -> ui -> label_ftp_status -> setText("Please enter the name of an FTP server.");
    }

    ftp = new QFtp(this);
    connect(ftp, &QFtp::commandFinished,this, &DataWidget::ftpCommandFinished);

    QFile jsonFile(QDir::currentPath()+"/param/gcs_param/setting.json");
    if(!jsonFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, "Json", "Json配置文件打开失败，请检查");
        return;
    }
    QJsonObject rootObj = QJsonDocument::fromJson(jsonFile.readAll()).object();
    jsonFile.close();
    ftpServer = rootObj.value("RPIIP").toString();

    ftp -> connectToHost(ftpServer,21);
    ftp -> login("pi","302302302");

    filePath = "AUV_mpu_field/Log";
    fileName = "log.db";

    this -> ui -> label_ftp_status ->setText(tr("Connecting to FTP server %1...").arg(ftpServer));
}

void DataWidget::ftpCommandFinished(int, bool error)
{
    switch (ftp->currentCommand())
    {
        case QFtp::ConnectToHost:
            if (error) {
                QMessageBox::information(this, tr("FTP"), tr("Unable to connect to the FTP server. Please check that the host "));
            }
            else {
                this -> ui -> label_ftp_status -> setText(tr("Connected onto %1.").arg(ftpServer));
            }
            break;
        case QFtp::Login:
        {
                this -> ui -> label_ftp_status -> setText(tr("Logged onto %1.").arg(ftpServer));
                QString cdfilePath = this->ui->lineEdit_log_path->text()+filePath;
                ftp->cd(cdfilePath);
        }
            break;
        case QFtp::Get:
        {
            if (error) {
                this->ui->label_ftp_status->setText(tr("Canceled download of %1.").arg(file->fileName()));
                file->close();
                file->remove();
            } else {
                this->ui->label_ftp_status->setText(tr("Downloaded %1 to Log.").arg(file->fileName()));
                file->close();
            }
            delete file;
            ftp->close();
        }
            break;
        case QFtp::Cd:
            downLoadFile();
            break;
        default:
            break;
    }
}

void DataWidget::downLoadFile()
{
    QString saveFileName = "./Log/"+fileName;
    if (QFile::exists(saveFileName)) {
        QMessageBox::information(this, tr("FTP"),
                                 tr("There already exists a file called %1 in "
                                    "the current directory. Delete it first.")
                                 .arg(saveFileName));
        QFile::remove(saveFileName);
    }

    file = new QFile(saveFileName);
    if (!file->open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("FTP"),
                                 tr("Unable to save the file %1: %2.")
                                 .arg(saveFileName).arg(file->errorString()));
        delete file;
        return;
    }

    ftp->get(fileName, file);
}

