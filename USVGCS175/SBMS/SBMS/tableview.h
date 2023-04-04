#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include <QTableView>
#include <QModelIndex>
#include <QMouseEvent>

class TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = nullptr);

signals:
    void leftClicked(QModelIndex);
    void rightClicked(QModelIndex);

protected:
    void mousePressEvent(QMouseEvent *e);
};

#endif // TABLEVIEW_H
