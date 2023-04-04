#include "datadelegate.h"
#include <QLabel>

DataDelegate::DataDelegate(QObject *parent) : QItemDelegate(parent)
{

}

QWidget *DataDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    QLabel *editor = new QLabel(parent);
    editor->setText(QString::number(index.data().toDouble(),'f',7));
    return editor;
}
