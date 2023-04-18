#include "kd.h"
#include "ui_kd.h"

kd::kd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kd)
{
    ui->setupUi(this);
}

kd::~kd()
{
    delete ui;
}
