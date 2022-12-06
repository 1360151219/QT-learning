#include "login_window.h"
#include "ui_login_window.h"
#include <QPushButton>
login_window::login_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login_window)
{
    ui->setupUi(this);
    connect(ui->logoutBtn,&QPushButton::clicked,this,&QWidget::close);

}

login_window::~login_window()
{
    delete ui;
}

