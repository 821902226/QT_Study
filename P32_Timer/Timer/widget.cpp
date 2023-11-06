#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setAlignment(Qt::AlignCenter);
    ui->label2->setAlignment(Qt::AlignCenter);
    ui->label3->setAlignment(Qt::AlignCenter);

    static int num = 1;

    //启动定时器
    this->id1 = startTimer(1000); //参数1--调用时间间隔（ms）

    this->id2 = startTimer(2000);

    //定时器第二种实现方式（使用QTimer类创建对象）
    QTimer *timer = new QTimer;
    timer->start(500); //每0.5毫秒触发一次
    //信号与槽实现定时器触发事件
    connect(timer, &QTimer::timeout, [=](){
        ui->label3->setText(QString::number(num++));
    });

    connect(ui->btn, &QPushButton::toggled, timer, [=](bool checked){
        if(checked)
        {
            timer->stop();
        }
        if(!checked)
        {
            timer->start(500);
        }
    });
}

//定时器第一种实现方式（重写timerEvent虚函数）
void Widget::timerEvent(QTimerEvent *event)
{
    static int num1 = 1;
    static int num2 = 1;

    if(event->timerId() == id1)
    {
        ui->label->setText(QString::number(num1++));
    }
    if(event->timerId() == id2)
    {
        ui->label2->setText(QString::number(num2++));
    }

}

Widget::~Widget()
{
    delete ui;
}
