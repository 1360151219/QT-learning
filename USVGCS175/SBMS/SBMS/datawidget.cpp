#include "datawidget.h"
#include "ui_datawidget.h"
#include <QDate>
#include <QDebug>
#include <QVector>
#include <QSqlRecord>
#include <QMutableMapIterator>
#include <QFileDialog>

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
    model = nullptr;
    listModel = nullptr;
    connect(mFigure,&QCustomPlot::destroyed,this,[=]()
    {
        qDebug()<<"mFigure is destroyed";
    });
}

DataWidget::~DataWidget()
{
    on_pushButton_clear_all_figure_clicked();
    delete model;
    QSqlDatabase::removeDatabase("DataWidget");
    delete ui;
}

void DataWidget::on_pushButton_update_table_clicked()  //打开数据库，更新表列表
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
    else
        qDebug()<<"Database Opened";
    QStringList list = db.tables();
    if(listModel)
        delete listModel;
    listModel = new QStringListModel(list);
    this -> ui -> listView -> setModel(listModel);
    model = new QSqlTableModel(this,db);
}

void DataWidget::on_listView_doubleClicked(const QModelIndex &index)  //选中表列表中表，打开表
{
    QString tableName = index.data().toString();
    model->setTable(tableName);

    for (int i=this->ui->comboBox->count()-1; i>4; i--) {
        this -> ui -> comboBox -> removeItem(i);
    }
    for (int i=1; i<model->columnCount(); i++) {
        this -> ui -> comboBox -> addItem(model->headerData(i,Qt::Horizontal).toString());
    }
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if(!model->select()) //选取整个表的所有行
        qDebug()<<model->lastError().text(); 
    while (model->canFetchMore())
        model->fetchMore();
    this -> ui -> tableView -> setModel(model);
    this -> ui -> tableView -> setItemDelegateForColumn(2,new DataDelegate());
    this -> ui -> tableView -> setItemDelegateForColumn(3,new DataDelegate());
    this -> ui -> tableView -> resizeColumnsToContents();

    QSqlRecord record = model -> record(0);
    this -> ui -> timeEdit_start -> setTime(QTime::fromString(record.value("Time").toString(),"hh:mm:ss.zzz"));
    record = model -> record(model->rowCount()-1);
    this -> ui -> timeEdit_stop -> setTime(QTime::fromString(record.value("Time").toString(),"hh:mm:ss.zzz"));
}

void DataWidget::on_pushButton_draw_clicked()  //新建Customplot，画图
{
    QString startTime = this -> ui -> timeEdit_start -> time().toString("hh:mm:ss.zzz");
    QString stopTime = this -> ui -> timeEdit_stop -> time().toString("hh:mm:ss.zzz");
    model -> setFilter(QString("Time >= '%1' and Time <= '%2'").arg(startTime).arg(stopTime));
    while (model->canFetchMore())
        model->fetchMore();
    const int len = model->rowCount();

    if(this->ui->comboBox->currentIndex() == 0)
    {
        QVector<QCPCurveData> lnglatData(len), xyData(len);
        QVector<double> t(len);
        QVector<double> yaw(len), heel(len), pitch(len), velocity(len), thrust(len), rudder(len), progress(len);

        for (int i=0; i<len; i++) {
            QSqlRecord record = model -> record(i);
            lnglatData[i] = QCPCurveData(i,record.value("lng").toDouble(),record.value("lat").toDouble());
            xyData[i] = QCPCurveData(i,record.value("y").toDouble(),record.value("x").toDouble());
            QTime time = QTime::fromString(record.value("Time").toString(),"hh:mm:ss.zzz");
            t[i] = this -> ui -> timeEdit_start -> time().msecsTo(time)/1000.0;
            yaw[i] = record.value("yaw").toDouble();
            heel[i] = record.value("heel").toDouble();
            pitch[i] = record.value("pitch").toDouble();
            velocity[i] = record.value("velocity").toDouble();
            thrust[i] = record.value("thrust").toDouble();
            rudder[i] = record.value("rudder").toDouble();
            progress[i] = record.value("progress").toDouble();
        }
        mFigure = new MFigure(lnglatData,xyData,t,yaw,pitch,heel,velocity,thrust,rudder,progress);
        mFigure -> show();
    }else{
        QString name = this -> ui -> comboBox -> currentText();
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

        if(this->ui->comboBox->currentIndex() == 1)
        {
            QVector<double> lng(len),lat(len);
            QSqlRecord record;
            for(int i=0; i<len; i++)
            {
                record = model->record(i);
                lng[i] = record.value("lng").toDouble();
                lat[i] = record.value("lat").toDouble();
            }
            double course = record.value("course").toDouble();
            QCPCurve *track = new QCPCurve(newPlot->xAxis, newPlot->yAxis);
            track->addData(lng,lat);
            emit initTrack();
            emit transMapPoint(lng,lat,course);
        }else if(this->ui->comboBox->currentIndex() == 2)
        {
            QVector<QCPCurveData> data(len);
            for(int i=0; i<len; i++)
            {
                QSqlRecord record = model->record(i);
                data[i] = QCPCurveData(i,record.value("y").toDouble(),record.value("x").toDouble());
            }
            QCPCurve *track = new QCPCurve(newPlot->xAxis, newPlot->yAxis);
            track->data()->set(data);
        }else{
            QVector<double> x(len), y(len);
            QString str = this -> ui -> comboBox -> currentText();
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
        if(this->ui->comboBox->currentIndex() == 1)
        {
            newPlot->xAxis->setLabel("lng");
            newPlot->yAxis->setLabel("lat");
        }else if(this->ui->comboBox->currentIndex() == 2){
            newPlot->xAxis->setLabel("y");
            newPlot->yAxis->setLabel("x");
        }else{
            newPlot->xAxis->setLabel("time");
            newPlot->yAxis->setLabel(this->ui->comboBox->currentText());
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

void DataWidget::on_pushButton_clicked()
{
    on_pushButton_clear_all_figure_clicked();
    delete listModel;
    listModel = nullptr;
    delete model;
    model = nullptr;
    QSqlDatabase::removeDatabase("DataWidget");
}

void DataWidget::setTracerVisible(bool visible)
{
    if(mFigure)
        mFigure->setTracerVisible(visible);
}
