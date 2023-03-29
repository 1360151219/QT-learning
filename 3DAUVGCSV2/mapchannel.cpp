#include "mapchannel.h"
#include <QDebug>
MapChannel::MapChannel(QObject *parent) : QObject(parent)
{
}

void MapChannel::getMousePoint(double lng, double lat)
{
    emit mousePointChanged(lng, lat);
}

void MapChannel::addPoint(double lng, double lat)
{
    emit addPointClicked(lng, lat);
}

void MapChannel::movePoint(int id, double lng, double lat)
{
    emit movePointClicked(id, lng, lat);
}

void MapChannel::transTask(int type, int len)
{
    emit taskCome(type, len);
}

void MapChannel::transPoints(int id, double lng, double lat)
{
    emit pointsCome(id, lng, lat);
}
// id, lng, lat, course, depth, hasQuaternion, v, quaternionOpacity
void MapChannel::updateBoatPos(int id, double lng, double lat, double course, double depth, bool hasQuaternion, double v, double quaternionOpacity)
{
    emit boatPosUpdated(id,lng, lat, course, depth, hasQuaternion, v, quaternionOpacity);
}

void MapChannel::reloadMap()
{
    emit reloadMapClicked();
}

void MapChannel::setOrigin(double lng, double lat)
{
    emit setOriginPoint(lng, lat);
}

void MapChannel::clearWaypoints()
{
    emit clearWaypointsClicked();
}

void MapChannel::clearAll()
{
    emit clearAllClicked();
}

void MapChannel::addFencePoint(double lng, double lat)
{
    emit addFencePointClicked(lng, lat);
}

void MapChannel::addFence()
{
    emit addFenceClicked();
}

void MapChannel::clearFence()
{
    emit clearFenceClicked();
}

void MapChannel::addCablePoint(double lng, double lat)
{
    emit addCablePointClicked(lng, lat);
}

void MapChannel::addCable()
{
    emit addCableClicked();
}

void MapChannel::clearCable()
{
    emit clearCableClicked();
}

void MapChannel::switchBoat(int id)
{
    emit boatSwitched(id);
}
void MapChannel::predictBoat(double lng, double lat, double initialPsi, double initialU, double initialV, double initialR, double angle, int PWM, bool isDynamic, double dt, int id, int time)
{
    qDebug()<<"test"<<lng<<lat<<initialPsi<<initialU<<initialV<<initialR<<angle<<PWM<<isDynamic<<dt<<id<<time;
    emit boatPredicted(lng, lat, initialPsi, initialU, initialV, initialR, angle, PWM, isDynamic, dt, id, time);
}
