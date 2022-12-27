#ifndef JSBCHANNEL_H
#define JSBCHANNEL_H

#include <QObject>
#include <QMessageBox>
#include "mainwindow.h"
class JsbChannel : public QObject
{
    Q_OBJECT
public:
    explicit JsbChannel(QObject *parent = nullptr);

public slots:
    void showMessage(const QString &text);
    void getMousePoint(QString lng, QString lat);
    void getBalls(int ballId, double ballLng, double ballLat, int ballColor);
signals:
    void Mousemove(QString, QString);
    void AppendBall(int ballId, double ballLng, double ballLat, int ballColor);
};

#endif // JSBCHANNEL_H
