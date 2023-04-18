#ifndef MFIGURE_H
#define MFIGURE_H

#include <QWidget>
#include <QVector>
#include "tracerplus.h"

namespace Ui
{
    class MFigure;
}

class MFigure : public QWidget
{
    Q_OBJECT

public:
    explicit MFigure(QWidget *parent = nullptr);
    MFigure(QVector<QCPCurveData> lnglatData, QVector<QCPCurveData> xyData, QVector<double> t, QVector<double> yaw, QVector<double> pitch, QVector<double> heel, QVector<double> velocity, QVector<double> thrust, QVector<double> rudder, QVector<double> progress, QWidget *parent = nullptr);
    ~MFigure();

public slots:
    void setTracerVisible(bool);

private:
    Ui::MFigure *ui;

    QCPCurve *track;
    QCPCurve *xyTrack;

    QCPItemTracer *tracer = nullptr;
    QCPItemTracer *xyTracer = nullptr;
    TracerPlus *tracer_yaw = nullptr;
    TracerPlus *tracer_heel = nullptr;
    TracerPlus *tracer_pitch = nullptr;
    TracerPlus *tracer_velocity = nullptr;
    TracerPlus *tracer_thrust = nullptr;
    TracerPlus *tracer_rudder = nullptr;
    TracerPlus *tracer_progress = nullptr;
    void showTracer(QMouseEvent *event);
};

#endif // MFIGURE_H
