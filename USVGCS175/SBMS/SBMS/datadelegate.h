#ifndef DATADELEGATE_H
#define DATADELEGATE_H

#include <QObject>
#include <QItemDelegate>

class DataDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit DataDelegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // DATADELEGATE_H
