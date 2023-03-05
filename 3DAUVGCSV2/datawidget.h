#ifndef DATAWIDGET_H
#define DATAWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QList>
#include <QMouseEvent>
#include <QMap>
#include <QPointer>
#include "tableview.h"
#include "datadelegate.h"
#include "qcustomplot.h"
#include "hfigure.h"
#include "vfigure.h"
#include "mfigure.h"
#include <QUrl>
#include <QFtp>
#include <QTreeWidgetItem>
#include <QFile>

namespace Ui {
class DataWidget;
}

class DataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataWidget(QWidget *parent = nullptr);
    ~DataWidget();

signals:
    void initTrack();
    void transMapPoint(QVector<double> lng, QVector<double> lat, double course, QVector<double> depth, double height);
    void trans3DPoint(QVector<double> lng, QVector<double> lat, QVector<double> depth);

private slots:

    void ftpCommandFinished(int commandId, bool error);
    void downLoadFile();

    void on_pushButton_update_table_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_pushButton_draw_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clear_all_figure_clicked();

    void on_pushButton_download_motion_log_clicked();

    void on_pushButton_close_sql_clicked();

    void on_listView_navigation_table_doubleClicked(const QModelIndex &index);

    void on_pushButton_reset_clicked();

private:
    Ui::DataWidget *ui;
    QString tableName;
    QSqlTableModel *model;
    QStringListModel *listTableModel;
    QStringListModel *listNavigationModel;
    QMap<QString,QPointer<QCustomPlot>> figureMap;
    HFigure *hFigure;
    VFigure *vFigure;
    MFigure *mFigure;
    bool isAuvSaved;

    QFtp *ftp = nullptr;
    QFile *file = nullptr;
    QString filePath;
    QString fileName;
    QString ftpServer;
};

#endif // DATAWIDGET_H
