#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    Teacher * t = new Teacher(this);    //放在对象树上，不用考虑内存释放
    Student * s = new Student(this);

    //connect(t, &Teacher::hungery, s, &Student::eat);

//    void (Teacher::*sign_t)(QString) = &Teacher::hungery;
//    void (Student::*slot_s)(QString food) = &Student::eat;
//    connect(t, sign_t, s, slot_s);

    //点击一个按钮触发饥饿
    QPushButton *btn = new QPushButton("下课", this);
//    void (Teacher::*slot_t)() = &Teacher::classOver;
//    connect(btn, &QPushButton::clicked, t, slot_t);

    //信号可以连接信号(参数必须保持一致)
    void (Teacher::*sign_t)() = &Teacher::hungery;
    void (Student::*slot_s)() = &Student::eat;
    connect(btn, &QPushButton::clicked, t, sign_t);
    connect(t, sign_t, s, slot_s);

    //用lamdba表达式实现点击按钮关闭窗口
    QPushButton *btn2 = new QPushButton("关闭窗口", this);
    btn2->move(100, 0);
//    connect(btn2, &QPushButton::clicked, this, &QWidget::close);
    connect(btn2, &QPushButton::clicked, this, [=](){this->close();});  //lambda表达式中可以调用槽函数

}

Widget::~Widget()
{
    delete ui;
}
