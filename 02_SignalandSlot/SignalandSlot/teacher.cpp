#include "teacher.h"

Teacher::Teacher(QObject *parent) : QObject(parent)
{

}

void Teacher::classOver()
{
    //emit this->hungery();   //触发饥饿信号
    emit this->hungery("麻辣香锅");
}
