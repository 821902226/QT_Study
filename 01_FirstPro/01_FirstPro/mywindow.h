#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget> //窗口类头文件
#include <QPushButton>
#include <mybutton.h>

class MyWindow : public QWidget
{
    Q_OBJECT    //Q_OBKECT宏，允许类中使用信号和槽的机制

public:
    MyWindow(QWidget *parent = 0);
    ~MyWindow();
};

#endif // MYWINDOW_H
