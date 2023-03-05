#ifndef QMYTABLEVIEWBTNDELEGATE_H
#define QMYTABLEVIEWBTNDELEGATE_H

#include <QObject>
#include <QPushButton>
#include <QStyledItemDelegate>

class QMyTableViewBtnDelegate: public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit QMyTableViewBtnDelegate(QStringList btnNames, QWidget *parent = nullptr);
    ~QMyTableViewBtnDelegate();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index);

signals:
    void readData(const QModelIndex &index);
    void setData(const QModelIndex &index);

private:
    QPoint m_mousePoint;  // 鼠标位置
    int m_nType;  // 按钮状态：0-划过 1-按下
    QStringList m_btnNames;
};


#endif // QMYTABLEVIEWBTNDELEGATE_H
