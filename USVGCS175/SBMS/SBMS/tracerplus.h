#ifndef TRACERPLUS_H
#define TRACERPLUS_H

#include <QObject>
#include "qcustomplot.h"

class TracerPlus : public QObject
{
    Q_OBJECT
public:
    explicit TracerPlus(QCustomPlot *_plot,QCPGraph *_graph);
    ~TracerPlus();

    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setText(const QString &text);
    void setLabelPen(const QPen &pen);
    void updatePosition(double xValue);

public slots:
    void setVisible(bool visible);

private:
    QCustomPlot *plot;	     //传入实例化的QcustomPlot
    QCPGraph *graph;	   	 //这里是存传入的绘图图层
    QCPItemTracer *tracer;   // 跟踪的点
    QCPItemText *dlabel;   	 // 数据 label
    QCPItemLine *darrow;  	 // 数据 箭头
    QCPItemText *xlabel;   	 // 横轴 label
    QCPItemLine *xarrow;  	 // 横轴 箭头

    bool visible;
};

#endif // TRACERPLUS_H
