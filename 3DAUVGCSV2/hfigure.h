#ifndef HFIGURE_H
#define HFIGURE_H

#include <QWidget>
#include <QVector>
#include "tracerplus.h"
#include "qcustomplot.h"

namespace Ui {
class HFigure;
}

class HFigure : public QWidget
{
    Q_OBJECT

public:
    explicit HFigure(QWidget *parent = nullptr);
    HFigure(QVector<QCPCurveData> lnglatData, QVector<QCPCurveData> xyData, QVector<double> t, QVector<double> yaw, QVector<double> course, QVector<double> desiredYaw, QVector<double> rudder, QVector<double> ye, QVector<double> velocity, QWidget *parent=nullptr);
    ~HFigure();

private:
    Ui::HFigure *ui;

    QCPCurve *track;
    QCPCurve *xyTrack;

    QCPItemTracer *tracer = nullptr;
    QCPItemTracer *xyTracer = nullptr;
    TracerPlus *tracer_ye = nullptr;
    TracerPlus *tracer_course = nullptr;
    TracerPlus *tracer_course_rudder = nullptr;
    TracerPlus *tracer_velocity = nullptr;
    void showTracer(QMouseEvent *event);
};

#endif // HFIGURE_H
