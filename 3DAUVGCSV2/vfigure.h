#ifndef VFIGURE_H
#define VFIGURE_H

#include <QWidget>
#include <QVector>
#include "tracerplus.h"
#include "qcustomplot.h"

namespace Ui {
class VFigure;
}

class VFigure : public QWidget
{
    Q_OBJECT

public:
    explicit VFigure(QWidget *parent = nullptr);
    VFigure(QVector<double> t, QVector<double> depth, QVector<double> despredDepth, QVector<double> height, QVector<double> pitch, QVector<double> desired_stern_rudder, QVector<double> stern_left_rudder, QVector<double> stern_right_rudder, QVector<double> desired_bow_rudder, QVector<double> beta, QWidget *parent = nullptr);
    ~VFigure();

private:
    Ui::VFigure *ui;

    TracerPlus *dpethTracer = nullptr;
    TracerPlus *heightTracer = nullptr;
    TracerPlus *pitchTracer = nullptr;
    TracerPlus *sternTracer = nullptr;
    TracerPlus *bowTracer = nullptr;
    TracerPlus *heelTracer = nullptr;
    void showTracer(QMouseEvent *event);
};

#endif // VFIGURE_H
