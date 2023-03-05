#include "qmytableviewbtndelegate.h"

#include <QApplication>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPainter>
#include <QStyleOption>
#include <QDesktopWidget>
#include <QToolTip>
#include <QDebug>

QMyTableViewBtnDelegate::QMyTableViewBtnDelegate(QStringList btnNames, QWidget *parent)
    : QStyledItemDelegate(parent),
      m_btnNames(btnNames)
{
}

QMyTableViewBtnDelegate::~QMyTableViewBtnDelegate()
{

}

// 绘制按钮
void QMyTableViewBtnDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem viewOption(option);
    initStyleOption(&viewOption, index);
    if (option.state.testFlag(QStyle::State_HasFocus))
        viewOption.state = viewOption.state ^ QStyle::State_HasFocus;

    QStyledItemDelegate::paint(painter, viewOption, index);

    // 计算按钮显示区域
    int nCount = m_btnNames.count();

    int w = nCount != 0 ? option.rect.width() / nCount : 0;
    if(w < 0) {
        return;
    }

    for (int i = 0; i < nCount; ++i)
    {
        // 绘制按钮
        QStyleOptionButton button;
        button.rect =  option.rect.adjusted(4 + i*w , 4, -(w * ( nCount - i -1 ) + 4)  , -4);
        button.text = m_btnNames.at(i);
        button.state |= QStyle::State_Enabled;

        if (button.rect.contains(m_mousePoint))
        {
            if (m_nType == 0)
            {
                button.state |= QStyle::State_MouseOver;
            }
            else if (m_nType == 1)
            {
                button.state |= QStyle::State_Sunken;
            }
        }
        QPushButton pushBtn;
        if (i == nCount - 1)
        {
            pushBtn.setStyleSheet("QPushButton{border-width: 0px;\
                                position: absolute;\
                                left: 0px;\
                                top: 0px;\
                                max-width: 80px;\
                                width:80px;\
                                height: 30px;\
                                background: inherit;\
                                background-color: rgba(255, 255, 255, 0);\
                                border-width: 1px;\
                                border-style: solid;\
                                border-color: red;\
                                border-radius: 10px;\
                                font-size: 11px;\
                                color: red;}\
                                QPushButton:hover{background-color:red; color:#FFFFFF;}");
        }
        else
        {
            pushBtn.setStyleSheet("QPushButton{border-width: 0px;\
                                position: absolute;\
                                left: 0px;\
                                top: 0px;\
                                max-width:120px; \
                                width:120px;\
                                height: 30px;\
                                background: inherit;\
                                background-color: rgba(255, 255, 255, 0);\
                                border-width: 1px;\
                                border-style: solid;\
                                border-color: rgba(2, 182, 212, 1);\
                                border-radius: 10px;\
                                font-size: 11px;\
                                color: #000000;}\
                                QPushButton:hover{background-color:rgba(2, 182, 212, 1); color:#FFFFFF;}");
        }

        pushBtn.style()->drawControl(QStyle::CE_PushButton, &button, painter, &pushBtn);
    }
}

// 响应按钮事件 - 划过、按下
bool QMyTableViewBtnDelegate::editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index)
{
    Q_UNUSED(model)
    m_nType = -1;
    bool bRepaint = false;
    QMouseEvent *pEvent = static_cast<QMouseEvent *> (event);
    m_mousePoint = pEvent->pos();

    int nCount = m_btnNames.count();

    int w = nCount != 0 ? option.rect.width() / nCount : 0;
    if(w < 0) {
        return false;
    }

    // 还原鼠标样式
    QApplication::restoreOverrideCursor();

    for (int i = 0; i < nCount; ++i)
    {
        QStyleOptionButton button;
        button.rect =  option.rect.adjusted(4 + i*w , 4, -(w * ( nCount - i -1 ) + 4)  , -4);

        // 鼠标位于按钮之上
        if (!button.rect.contains(m_mousePoint))
            continue;

        bRepaint = true;
        switch (event->type())
        {
        // 鼠标滑过
        case QEvent::MouseMove:
        {
            // 设置鼠标样式为手型
            QApplication::setOverrideCursor(Qt::PointingHandCursor);

            m_nType = 0;

            //QToolTip::showText(pEvent->globalPos(), m_btnNames.at(i));
            break;
        }
        // 鼠标按下
        case QEvent::MouseButtonPress:
        {
            m_nType = 1;
            break;
        }
        // 鼠标释放
        case QEvent::MouseButtonRelease:
        {
            switch (i)
            {
            case 0:
            {
                emit readData(index);
                break;
            }
            case 1:
            {
                emit setData(index);
                break;
            }
            default:
            break;
            }
        }
        break;
        default:
            break;
        }
    }
    return bRepaint;
}

