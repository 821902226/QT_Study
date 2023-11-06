#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QDebug>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:   //槽函数在早期版本必须写到public slots下，高级版本可以写到public或者是作为全局函数
    void eat();
    void eat(QString food); //槽函数重载
};

#endif // STUDENT_H
