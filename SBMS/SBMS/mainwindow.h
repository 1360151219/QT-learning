
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QWebChannel>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "mapchannel.h"
#include "waypoint.h"
#include "taskwidget.h"
#include "usv.h"
#include "dataanalyse.h"
#include <QTcpSocket>
#include <QHostAddress>
#include ".\usv2\USV2\mavlink.h"
#include "INS.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*网络通信*/
    void TCPClientInit();
    void TCPClientInit2();
private slots:
    void serialRead();
    void sendWaypoint();
    void changeStackedWidgetPage(int index);
    void dockSimuStep();

    void on_pushButton_search_serialport_clicked();

    void on_pushButton_open_serialport_clicked();

    void on_pushButton_add_point_clicked();

    void on_pushButton_move_point_clicked();

    void on_pushButton_set_home_clicked();

    void on_pushButton_download_task_clicked();

    void on_pushButton_go_home_clicked();

    void on_pushButton_do_task_clicked();


    void on_pushButton_query_param_clicked();

    void on_pushButton_set_param_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_open_task_clicked();

    void on_pushButton_save_task_clicked();

    void on_pushButton_read_param_clicked();

    void on_pushButton_save_param_clicked();

    void on_pushButton_test_clicked();

    /*网络通信*/

    void readData();
    void readAUVData();
    void ReadError(QAbstractSocket::SocketError);

    void on_TCPconnect_clicked();

    void on_set_task_clicked();

    void on_RC_control_send_clicked();

    void on_send_neu_point_clicked();



    void on_LED_close_clicked();

    void on_pushButton_start_simulate_dock_clicked();



    void on_visual_set_clicked();

    void on_get_insdock_clicked();

    void on_LED_open_clicked();

    void on_TCP_AUV_Connect_clicked();



    void on_btn_ilos_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    USV usv;
    DOCK dock;
    INS ins;

    /*通信*/
    QSerialPort *serial;
    QTimer *sendTimer;
    QTimer *commuTimer;
    QTimer *sendINSDock;
    void InsDockSend();
    QTime wirelessTime;
    void commuInit();
    void sendMavlink(mavlink_message_t);

    /*网口通信*/
    QTcpSocket* tcpClient;
    QTcpSocket* tcpClient2;


    /*界面*/
    int currentPageIndex = 0;
    DataAnalyse *dataAnalyse = Q_NULLPTR;
    void widgetInit();
    void sonWidgetInit();

    /*非模态式MessagBox*/
    QMessageBox *messageBox;
    void showMessageBox(QMessageBox::Icon,QString,QString);

    /*地图*/
    bool isOfflineMap;
    QWebChannel *channel;
    MapChannel *mapChannel;
    void mapInit();

    /*数据库*/
    QSqlDatabase db;
    bool isSaving = false;
    QString sqlUsvLogTableName;
    QSqlQuery sqlQurey;
    void dataBaseInit();

    /*接收html传来的任务和航点*/
    QList<Waypoint> *waypoints;
    TaskWidget *taskWidget;
    uint8_t maptaskType;
    uint8_t waypointsNum;

    /*运动坞站模拟*/
    QTimer *simuTimer;
    double dockLng;
    double dockLat;
    double dockVel;
    double dockHeading;
    double posNoise;
    double headingNoise;
    double noiseDockLng, noiseDockLat,noiseDockHeading;
    const double a = 6378137;
    const double ee = 0.00669437999;
    const double d2r = 57.2957795130;



    bool isShowPrediction=false;

};

#endif // MAINWINDOW_H
