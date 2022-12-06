#include "widget.h"
#include "ui_widget.h"
#include <QTreeWidget>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    ui->treeWidget->setHeaderLabels()
    QTreeWidgetItem *cbd = new QTreeWidgetItem(QStringList()<<"CBD");
    ui->treeWidget->addTopLevelItem(cbd);
    QTreeWidgetItem *cbd_zhouMaPo = new QTreeWidgetItem(QStringList()<<"周麻婆"<<"脆皮鸭");
    cbd->addChild(cbd_zhouMaPo);
}

Widget::~Widget()
{
    delete ui;
}

