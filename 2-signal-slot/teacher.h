#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    // 自定义信号
    // 返回值是void
    void finishClass();
    void finishClass(QString food);
};

#endif // TEACHER_H
