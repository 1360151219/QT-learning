#include "widget.h"
#include "ui_widget.h"
#include "student.h"
#include "teacher.h"
#include "secondwidget.h"
#include <QPushButton>
#include <QDebug>
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
    // 函数指针
    void (Teacher:: *teaNoFood)() = &Teacher::finishClass;
    void (Student:: *eatNoFood)() =  &Student::eat;
    void (Student:: *studentSignal)(QString) =  &Student::eat;
    void (Teacher:: *teacherSignal)(QString) = &Teacher::finishClass;
    connect(btn,&QPushButton::clicked,tea,teaNoFood);
    connect(tea,teacherSignal,stu,studentSignal);
    connect(tea,teaNoFood,stu,eatNoFood);
//    disconnect(tea,teacherSignal,stu,studentSignal); // 一开始的有参信号的断开

    QPushButton *btn2 = new QPushButton("lambda",this);
    btn2->move(100,0);
    connect(btn2,&QPushButton::clicked,this,[=](){
        this->classIsOver(tea);
    });
    // toggle
    QPushButton *btn3 = new QPushButton("toggle",this);
    btn3->move(100,100);
    SecondWidget *w = new SecondWidget();
    bool isShow = false;
    bool &ptr = isShow; // c++引用
    connect(btn3,&QPushButton::clicked,this,[=]()mutable{
        if(ptr){
            w->close();
            ptr = false;
        }else{
            w->show();
            ptr = true;
        }
        qDebug()<<ptr;
    });
    // 初始化的时候调用一次
    // this->classIsOver(tea);

}

void Widget::classIsOver(Teacher *teacher){
    // 使用emit触发信号（事件名）
    emit teacher->finishClass("apple");
}
Widget::~Widget()
{
    delete ui;
}

