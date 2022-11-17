#include "student.h"

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::eat(){
    qDebug("eat");
}
