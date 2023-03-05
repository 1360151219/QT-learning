#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QList>
#include "waypoint.h"

namespace Ui {
class TaskWidget;
}

class TaskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TaskWidget(QWidget *parent = nullptr);
    ~TaskWidget();

public slots:
    void getWaypointsList(QList<Waypoint>*);

private slots:
    void onItemChanged(QStandardItem *item);

signals:
    void itemChanged(double,double,int);

private:
    Ui::TaskWidget *ui;
    QStandardItemModel *model;
    QList<Waypoint> *_waypointst;
};

#endif // TASKWIDGET_H
