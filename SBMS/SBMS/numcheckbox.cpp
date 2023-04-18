#include "numcheckbox.h"

NumCheckBox::NumCheckBox(QWidget *parent) : QWidget(parent)
{
    checkBox = new QCheckBox(this);
    setName("");
    connect(checkBox,&QCheckBox::stateChanged,[=](int state){
        if(state)
        {
            m_checked = true;
            emit stateChanged(m_checked);
        }else{
            m_checked = false;
            emit stateChanged(m_checked);
        }
    });
    label = new QLabel(this);
    m_value = 0;
    label->setText(QString::number(m_value));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(checkBox);
    layout->addWidget(label);
    this->setLayout(layout);

    m_checked = false;
}

NumCheckBox::NumCheckBox(QString name, QWidget *parent): QWidget (parent)
{
    checkBox = new QCheckBox(this);
    setName(name);

    connect(checkBox,&QCheckBox::stateChanged,[=](int state){
        if(state)
        {
            m_checked = true;
            emit stateChanged(m_checked);
        }else{
            m_checked = false;
            emit stateChanged(m_checked);
        }
    });
    label = new QLabel(this);
    m_value = 0;
    label->setText(QString::number(m_value));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(checkBox);
    layout->addWidget(label);
    this->setLayout(layout);

    m_checked = false;
}

NumCheckBox::NumCheckBox(QString name, double value, QWidget *parent): QWidget (parent)
{
    checkBox = new QCheckBox(this);
    m_name = name;
    checkBox -> setText(m_name);

    label = new QLabel(this);
    m_value = value;
    label->setText(QString::number(m_value));

    connect(checkBox,&QCheckBox::stateChanged,[=](int state){
        if(state)
        {
            m_checked = true;
            emit stateChanged(m_checked);
        }else{
            m_checked = false;
            emit stateChanged(m_checked);
        }
    });

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(checkBox);
    layout->addWidget(label);
    this->setLayout(layout);

    m_checked = false;
}

double NumCheckBox::Value() const
{
    return m_value;
}

QString NumCheckBox::Name() const
{
    return  m_name;
}

bool NumCheckBox::Checked() const
{
    return m_checked;
}

void NumCheckBox::setValue(double value)
{
    m_value = value;
    label -> setText(QString::number(m_value));
    emit valueChanged(m_value);
}

void NumCheckBox::setName(QString name)
{
    m_name = name;
    checkBox -> setText(m_name);
}
