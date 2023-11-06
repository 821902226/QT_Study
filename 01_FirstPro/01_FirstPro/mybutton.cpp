#include "mybutton.h"

myButton::myButton(QWidget *parent) : QPushButton(parent)
{
    qDebug()<<"构造函数调用";
}

myButton::~myButton()
{
    qDebug()<<"析构函数调用";
}
