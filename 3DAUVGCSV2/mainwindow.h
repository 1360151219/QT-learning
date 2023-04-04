#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QTcpSocket>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QWebEnginePage>
#include <QWebChannel>
#include "waypoint.h"
#include "taskwidget.h"
#include "mapchannel.h"
#include "common.h"
#include "qcustomplot.h"
#include "./Mavlink/USV76/mavlink.h"
#include "qmytableviewbtndelegate.h"
#include "qdebug.h"

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

private slots:
    void showTcpError(QAbstractSocket::SocketError socketError);
    void usvTcpRead();
    void usvSerialRead();

    void on_pushButton_tcp_connect_clicked();

    void on_comboBox_mode_currentIndexChanged(int index);

    void on_pushButton_usv_init_clicked();

    void on_pushButton_task_work_clicked();

    void on_pushButton_read_control_param_clicked();

    void on_pushButton_set_control_param_clicked();

    void on_pushButton_read_mid_param_clicked();

    void on_pushButton_set_mid_param_clicked();

    void on_pushButton_serial_connect_clicked();

    void on_pushButton_search_serial_clicked();

    void on_pushButton_query_control_config_clicked();

    void on_comboBox_los_select_currentIndexChanged(int index);

    void on_pushButton_read_all_clicked();

    void on_pushButton_load_local_param_clicked();

    void on_pushButton_write_all_clicked();

    void on_pushButton_save_param_to_local_clicked();

    void on_lineEdit_table_search_textChanged(const QString &arg1);

    void on_pushButton_add_point_clicked();

    void on_pushButton_load_waypoints_clicked();

    void on_pushButton_gohome_clicked();

    void on_pushButton_usv_setHome_clicked();

    void on_pushButton_load_task_clicked();

    void on_comboBox_HeadingOrCourse_select_currentIndexChanged(int index);

    void changeStackedWidgetPage(int index);

    void on_btn_Rudder_returnMid_clicked();

    void on_btn_Propeller_returnMid_clicked();

    void on_pushButton_predict_clicked();

private:
    Ui::MainWindow *ui;
    bool isShowPrediction;
    USV usv;
    QTcpSocket *usvClient;
    mavlink_message_t msg;
    mavlink_status_t status;
    void communicateInit();
    void mavlinkRead(QByteArray);

    QSerialPort *serial;

    uint8_t sendBuf[100];
    void sendMavlinkMsg(const mavlink_message_t msg);
    int currentPageIndex = 0;
    void widgetInit();

    void paramTableInit();
    void tableModelInit();
    QTime start_time;

    QStandardItemModel *tableModel;
    QMyTableViewBtnDelegate *btnDelegate;

    void remoteControl();
    void sendGcsSet(uint8_t type, uint16_t content);

    /*非模态式MessagBox*/
    QMessageBox *messageBox;
    void showMessageBox(QMessageBox::Icon, QString, QString);

    /*保存上位机的记录*/
    QFile GCSFile;
    void recordLog(QString str);

    /*地图*/
    bool isOfflineMap;
    QWebChannel *channel;
    MapChannel *mapChannel;
    void mapInit();

    /*接收html传来的任务和航点*/
    QList<Waypoint> *waypoints;
    TaskWidget *taskWidget;
    uint8_t maptaskType;
    uint8_t waypointsNum;

    QLabel *statusLabel;
    QLabel *connectLabel;
    QLabel *spaceLabel;
    QTimer *commuTimer;
    QTime lastCommuTime;
};

#endif // MAINWINDOW_H
