#include "one_beginer.h"
#include "ui_one_beginer.h"
#include "my_button.h"
#include <QPushButton>
#include <QDebug>

One_beginer::One_beginer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::One_beginer)
{
    ui->setupUi(this);
    QPushButton *btn1 = new QPushButton;
    btn1->setParent(this); // 在父级窗口中显示
    btn1->setText("click 1");
    QPushButton *btn2 = new QPushButton("click 2",this);
    btn2->move(100,100); // 按钮设置位置
    setFixedSize(800,600); // 窗口固定大小
    setWindowTitle("first app");
    My_Button *btn3 = new My_Button;
    btn3->setParent(this); // 在父级窗口中显示
    btn3->move(200,200);
    btn3->setText("click to close");
    connect(btn3,&My_Button::clicked,this,&QWidget::close);
}

One_beginer::~One_beginer()
{
    qDebug("父类的析构函数");
    delete ui;
}

