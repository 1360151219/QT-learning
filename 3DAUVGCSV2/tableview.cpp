#include "tableview.h"

TableView::TableView(QWidget *parent) : QTableView(parent)
{

}

void TableView::mousePressEvent(QMouseEvent *e)
{
    setCurrentIndex(QModelIndex());
    QTableView::mousePressEvent(e);
    QModelIndex index = currentIndex();
    if(index.row()<0 && index.column()<0)
        return;
    if(e->button() == Qt::LeftButton)
        emit leftClicked(index);
    else
        emit rightClicked(index);
    e->accept();
}
