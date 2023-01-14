#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>
#include <QIcon>
 #include <QDialog>
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("my window");
    this->resize(600,400);
    // 新建菜单栏(只能有一个)
    QMenuBar *menubar = this->menuBar();
    // 设置菜单栏
    this->setMenuBar(menubar);
    menubar->setNativeMenuBar(false); // 兼容macOs
    // 添加菜单栏选项
    QMenu *textMenu = menubar->addMenu("文本");
    QMenu *editMenu = menubar->addMenu("编辑");
    textMenu->addSeparator();
    QAction *newAction = textMenu->addAction("新增(模态框)");
    QAction *noticeAction = textMenu->addAction("消息");
    QAction *queAction = textMenu->addAction("问题");
    QAction *modifyAction = editMenu->addAction("修改(非模态框)");
    // 添加action函数
    connect(newAction,&QAction::triggered,this,[=](){
        // 阻塞 因此不需要new 内存放在栈上
        QDialog dlg(this);
        dlg.exec();
    });
    connect(modifyAction,&QAction::triggered,this,[=](){
        // 由于是非模态框，因此需要放在内存中，否则在lambda执行完毕后dlg2释放导致dialog闪退
        QDialog *dlg2 = new QDialog(this);
        // 添加自动释放内存属性
        dlg2->setAttribute(Qt::WA_DeleteOnClose);
        dlg2->resize(100,200);
        dlg2->show();
    });
    connect(noticeAction,&QAction::triggered,this,[=](){
        QMessageBox::critical(this,"error","your file is not found!!");
    });

    connect(queAction,&QAction::triggered,this,[=](){
//        QMessageBox::question(this,"question","do you have dinner?",QMessageBox::Ok,QMessageBox::Ignore,QMessageBox::NoButton);
        int res = QMessageBox::question(this,"question","do you have dinner?","确认","不是");
        if(res == 0){
           qDebug("确认了");
        }else{
            qDebug("取消了");
        }
    });
    // 添加icon
    newAction->setIcon(QIcon(":/psfe.jpeg"));
    textMenu->addSeparator();

    QToolBar *toolbar = new QToolBar("工具栏",this);
    this->addToolBar(Qt::LeftToolBarArea,toolbar);
    // 可设置「移动」或者「浮动」
    toolbar->setFloatable(false);
    // 工具栏：设置「控件」或者「Action」
    toolbar->addAction(newAction);
    toolbar->addSeparator();
    toolbar->addWidget(new QPushButton("click"));

    // 状态栏
    QStatusBar * statubar = this->statusBar();
    this->setStatusBar(statubar);
    QLabel *label = new QLabel("提示",this);
    QLabel *rightLabel = new QLabel("右侧提示",this);
    statubar->addWidget(label);
    statubar->addPermanentWidget(rightLabel);

    // 中心部件
    QTextEdit *editArea = new QTextEdit("placeholder",this);
    this->setCentralWidget(editArea);

    // 铆接组件
    QDockWidget *dock = new QDockWidget(this);
    dock->setAllowedAreas(Qt::BottomDockWidgetArea);
    this->addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea,dock);

}

MainWindow::~MainWindow()
{
    delete ui;
}

