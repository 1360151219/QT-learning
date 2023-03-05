#ifndef MFIGURE_H
#define MFIGURE_H

#include <QWidget>
#include <QVector>
#include "qcustomplot.h"

namespace Ui {
class MFigure;
}

class MFigure : public QWidget
{
    Q_OBJECT

public:
    explicit MFigure(QWidget *parent = nullptr);
    MFigure(QVector<QCPCurveData> lnglatData, QVector<QCPCurveData> xyData, QVector<double> t, QVector<double> depth,
            QVector<double> deisredDepth, QVector<double> height, QVector<double> yaw, QVector<double> course, QVector<double> desiredYaw, QVector<double> pitch, QVector<double> desiredPitch, QVector<double> heel, QVector<double> ye, QVector<double> rudder, QVector<double> elevator,  QVector<double> velocity, QVector<double> alpha, QVector<double> beta, QWidget *parent = nullptr);
    ~MFigure();

private:
    Ui::MFigure *ui;
};

#endif // MFIGURE_H
