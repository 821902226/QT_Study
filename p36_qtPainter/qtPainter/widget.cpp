#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //图片左移
    connect(ui->btn1, &QPushButton::clicked, [=](){
        posX-=20;
        update();   //重新调用绘图事件paintEvent
    });

    //图片右移
    connect(ui->btn2, &QPushButton::clicked, [=](){
        posX+=20;
        update();
    });

    //图片上移
    connect(ui->btn3, &QPushButton::clicked, [=](){
        posY-=20;
        update();
    });

    //图片下移
    connect(ui->btn4, &QPushButton::clicked, [=](){
        posY+=20;
        update();
    });
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this); //实例化画家对象，this指定的是绘图设备

    /*//设置画笔，可以改变线条颜色
    QPen pen(QColor(255, 0, 0));

    //设置线条宽度
    pen.setWidth(2);

    //设置线型
    pen.setStyle(Qt::DotLine);

    //设置画刷, 可以起到填充效果
    QBrush brush(QColor(125, 125, 125));

    //设置填充样式
    brush.setStyle(Qt::Dense4Pattern);

    painter.setBrush(brush);

    painter.setPen(pen);

    //抗锯齿
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    painter.drawLine(QPoint(0, 0), QPoint(100, 100));   //画线

    painter.drawEllipse(QPoint(100, 100), 50, 50);  //画圆或者是椭圆 圆心，长，宽

    painter.drawRect(200, 50, 100, 100);

    painter.drawText(50, 20, "好好学习，天天向上");*/

    painter.drawPixmap(this->posX, this->posY, 200, 100, QPixmap(":/images/1.jpeg"));
}

Widget::~Widget()
{
    delete ui;
}
