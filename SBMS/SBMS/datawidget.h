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
#include "mfigure.h"

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
    void transMapPoint(QVector<double> lng, QVector<double> lat, double course);

public slots:
    void setTracerVisible(bool);

private slots:
    void on_pushButton_update_table_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_pushButton_draw_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clear_all_figure_clicked();

    void on_pushButton_clicked();

private:
    Ui::DataWidget *ui;
    QSqlTableModel *model;
    QStringListModel *listModel;
    QMap<QString,QPointer<QCustomPlot>> figureMap;
    QPointer<MFigure> mFigure;
};

#endif // DATAWIDGET_H
