#include "xygraph.h"
#include "ui_xygraph.h"
#include <QLineSeries>

#include <QValueAxis>
#include <QCategoryAxis>
#include <QColorDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
xyGraph::xyGraph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::xyGraph)
{
    ui->setupUi(this);
    this->series = new QSplineSeries();   // 创建一个样条曲线对象
//    series->setName("曲线"); // 图例名称


    QChart* chart = ui->graphicsView->chart();    // 获取一个chart用于管理不同类型的series和其他图表相关对象
    chart->legend()->hide();                   // 隐藏图例
    chart->addSeries(series);                  // 添加创建好的曲线图对象
    chart->setTitle("x-y坐标曲线图");           // 设置标题
    chart->createDefaultAxes();                // 基于已添加到图表中的series为图表创建轴。以前添加到图表中的任何轴都将被删除。
    chart->axes(Qt::Vertical).first()->setRange(0, 300);  // 设置Y轴的范围
    chart->axes(Qt::Horizontal).first()->setRange(-20, 20);
    this->ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

xyGraph::~xyGraph()
{
    delete ui;
}

void xyGraph::paint(QJsonArray &array){
    for (auto value : array) {
        // 在这里处理 value
        QJsonObject item = value.toObject();
        double currentX = item["current_x"].toDouble();
        double currentY = item["current_y"].toDouble();
//        this->series->append(QPointF(currentX, currentY));
        qDebug()<<"x::"<<currentX<<"y::"<<currentY;
        this->series->append(currentX, currentY);
    }

}
