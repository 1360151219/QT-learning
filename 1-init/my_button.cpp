#include "my_button.h"
#include <QDebug>
#include <QPushButton>

My_Button::My_Button(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "my_button 构造";
}

My_Button::~My_Button()
{
    qDebug() << "my_button 析构";
}
