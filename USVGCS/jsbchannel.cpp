#include "jsbchannel.h"

JsbChannel::JsbChannel(QObject *parent) : QObject(parent)
{
}
void JsbChannel::showMessage(const QString &text)
{
    QMessageBox::information(NULL, "消息通知", text);
}

void JsbChannel::getMousePoint(QString lng, QString lat)
{
    emit Mousemove(lng, lat);
}

void JsbChannel::getBalls(int ballId, double ballLng, double ballLat, int ballColor)
{
    emit AppendBall(ballId, ballLng, ballLat, ballColor);
}
