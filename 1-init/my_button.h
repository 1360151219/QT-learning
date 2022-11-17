#ifndef MY_BUTTON_H
#define MY_BUTTON_H
#include <QWidget>
#include <QPushButton>

class My_Button : public QPushButton
{
    Q_OBJECT
public:
    explicit My_Button(QWidget *parent = nullptr);
    ~My_Button();

signals:

};

#endif // MY_BUTTON_H
