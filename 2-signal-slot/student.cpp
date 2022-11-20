#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::eat(){
    qDebug("eat");
}

void Student::eat(QString food){
    qDebug()<<"eat"<<food.toUtf8().data();
}
