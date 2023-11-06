#include "student.h"

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::eat()
{
    qDebug()<<"去食堂吃饭";
}

void Student::eat(QString food)
{
    //QString -> char *     1、toUtf8()转换成QByteArray 2、data()转换成char *
    qDebug()<<"去食堂吃"<<food.toUtf8().data();
}
