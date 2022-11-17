#include "widget.h"
#include "ui_widget.h"
#include "student.h"
#include "teacher.h"
#include <QPushButton>
// 创建老师类和学生类
// 老师通知下课，学生响应吃饭
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(400,200);
    Teacher *tea = new Teacher(this);
    Student *stu = new Student(this);
    QPushButton *btn = new QPushButton("click",this);

    connect(btn,&QPushButton::clicked,tea,&Teacher::finishClass);
    connect(tea,&Teacher::finishClass,stu,&Student::eat);
    // 初始化的时候调用一次
    this->classIsOver(tea);
}

void Widget::classIsOver(Teacher *teacher){
    // 使用emit触发信号（事件名）
    emit teacher->finishClass();
}
Widget::~Widget()
{
    delete ui;
}

