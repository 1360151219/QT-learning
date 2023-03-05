#include "taskwidget.h"
#include "ui_taskwidget.h"
#include <QDebug>

TaskWidget::TaskWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskWidget)
{
    ui->setupUi(this);
    this -> model = new QStandardItemModel(this);
    this -> ui -> tableView -> setModel(model);
    this -> ui -> tableView -> horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this -> ui -> tableView -> setEditTriggers(QAbstractItemView::DoubleClicked);
    this->setAttribute(Qt::WA_QuitOnClose,false);
}

TaskWidget::~TaskWidget()
{
    delete model;
    delete ui;
}

void TaskWidget::getWaypointsList(QList<Waypoint> *list)
{
    _waypointst = list;
    disconnect(model,&QStandardItemModel::itemChanged,this,&TaskWidget::onItemChanged);
    model->clear();
    this -> model -> setHorizontalHeaderItem(0,new QStandardItem("ID"));
    this -> model -> setHorizontalHeaderItem(1,new QStandardItem("经度"));
    this -> model -> setHorizontalHeaderItem(2,new QStandardItem("纬度"));
    this -> model -> setHorizontalHeaderItem(3,new QStandardItem("深度或高度"));
    for (int i=0; i<list->length(); i++) {
        model->setItem(i,0,new QStandardItem(QString::number(i)));
        model->setItem(i,1,new QStandardItem(QString::number((*list)[i].lng,'f',7)));
        model->setItem(i,2,new QStandardItem(QString::number((*list)[i].lat,'f',7)));
        model->setItem(i,3,new QStandardItem(QString::number(static_cast<double>((*list)[i].depth))));
    }
    connect(model,&QStandardItemModel::itemChanged,this,&TaskWidget::onItemChanged);
}

void TaskWidget::onItemChanged(QStandardItem *item)
{
    int row = item -> row();
    int col = item -> column();
    qDebug()<<row<<"  "<<col<<endl;
    if(col == 1)
    {
    (*_waypointst)[row].lng = item->text().toDouble();
    emit itemChanged((*_waypointst)[row].lng, (*_waypointst)[row].lat,row);
    }
    else if (col == 2)
    {
    (*_waypointst)[row].lat = item->text().toDouble();
    emit itemChanged((*_waypointst)[row].lng, (*_waypointst)[row].lat,row);
    }
    else
    {
    (*_waypointst)[row].depth = item->text().toFloat();
    //emit itemChanged(item->text().toDouble(),item->text().toDouble(),row);
    }
}
