﻿#ifndef MAPCHANNEL_H
#define MAPCHANNEL_H

#include <QObject>

class MapChannel : public QObject
{
    Q_OBJECT
public:
    explicit MapChannel(QObject *parent = nullptr);

    /*MainWindow 调用*/
    void addPoint(double lng, double lat);
    void movePoint(int id, double lng, double lat);
    void updateBoatPos(double lng, double lat, double course, double depth);
    void setOrigin(double lng, double lat);
    void addFencePoint(double,double);
    void addFence();
    void clearFence();
    void addCablePoint(double,double);
    void addCable();
    void clearCable();
    void clearWaypoints();

signals:

    /*MapChannel -> MainWindow*/
    void mousePointChanged(double, double);
    void reloadMapClicked();
    void taskCome(int,int);
    void pointsCome(int,double,double);

    /*MapChannel -> html*/
    void addPointClicked(double,double);
    void movePointClicked(int,double,double);
    void setOriginPoint(double,double);
    void boatPosUpdated(double,double,double,double);
    void addFencePointClicked(double,double);
    void addFenceClicked();
    void clearFenceClicked();
    void clearWaypointsClicked();
    void addCablePointClicked(double,double);
    void addCableClicked();
    void clearCableClicked();
    void clearAllClicked();

public slots:
    /*html调用*/
    void getMousePoint(double lng, double lat);
    void reloadMap();
    void transTask(int type, int len);
    void transPoints(int id, double lng, double lat);

    /*MainWindow 调用*/
    void clearAll();
};

#endif // MAPCHANNEL_H