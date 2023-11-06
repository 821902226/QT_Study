#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent)
    : QWidget(parent)   //初始化列表
{

    QPushButton *btn1 = new QPushButton;    //创建按钮
    btn1->setParent(this);
    btn1->setText("Hello");

    QPushButton *btn2 = new QPushButton("World", this);  //创建一个新的按钮
    btn2->move(100, 0);    //移动按钮的位置

    btn2->resize(100, 50);  //重设按钮大小

    //resize(200, 150);   //设置窗口的大小

    setFixedSize(600, 400);  //设置固定窗口大小

    setWindowTitle("Hello World");  //设置窗口标题

    myButton *mybtn = new myButton;
    mybtn->setParent(this);
    mybtn->setText("自定义按钮");
    mybtn->move(250, 0);

    //connect(mybtn, &myButton::clicked, this, &MyWindow::close);
    connect(mybtn, &QPushButton::clicked, this, &QWidget::close);   //QPushButton和QWidget分别是myButton和MyWindow的父类
}

MyWindow::~MyWindow()
{

}
