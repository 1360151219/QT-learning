#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>
#include <QIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
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
    QAction *newAction = textMenu->addAction("新增");
    // 添加icon
    newAction->setIcon(QIcon(":/psfe.jpeg"));
    textMenu->addSeparator();
    textMenu->addAction("修改");

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
}

