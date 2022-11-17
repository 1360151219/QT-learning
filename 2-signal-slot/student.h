#ifndef STUDENT_H
#define STUDENT_H
#include <QObject>
#include <QDebug>
class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    // 槽函数可以直接写在public里
    void eat();
signals:

};
#endif // STUDENT_H
