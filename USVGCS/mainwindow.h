#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#pragma execution_character_set("utf-8")
#endif

#include <QMainWindow>
#include <QWebEnginePage>
#include <QWebChannel>
#include <QTcpSocket>
#include <QButtonGroup>
#include <QSerialPort>
#include "usv.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTimer>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setMousePoint(QString lng, QString lat);
    void usvAppendBall(int ballId, double ballLng, double ballLat, int ballColor);
private slots:
    void readTcpData();
    void startSimulate(double cmdTurn, qint64 cmdVel);
    void showTcpError(QAbstractSocket::SocketError socketError);

    QJsonDocument readJsonFile(QFile &file);
    void writeJsonFile(QFile &file, QByteArray &data);
    void on_pushButton_addBall_clicked();

    void on_pushButton_connect_clicked();

    void on_pushButton_sendCommond_clicked();

    void on_pushButton_clearMap_clicked();

    void on_pushButton_showoverlays_clicked();

    void on_pushButton_test_clicked();

    void on_actionReload_Map_triggered();

    void on_actionRuler_triggered();

    void on_pushButton_simulatorInit_clicked();

    void on_pushButton_setHome_clicked();

    void on_pushButton_simulatorStart_clicked();

    void on_pushButton_setEnd_clicked();

    void on_pushButton_serial_search_clicked();

    void on_pushButton_serial_open_clicked();

    void on_pushButton_playback_clicked();

    void on_pushButton_showGraph_clicked();

private:
    Ui::MainWindow *ui;
    QWebChannel *channel;
    QWebEnginePage *page;
    QTcpSocket *tcpClinet;
    QButtonGroup *runOrStopGroup;
    USV usv;
    QSerialPort *serial;
    // 回放数据
    QJsonObject trackedData;
    int trackedIndex;
    QTimer *trackedTimer;

    void updateLabel();
    void sendSimUSVStatus();
};

#endif // MAINWINDOW_H
