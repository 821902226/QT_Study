#include "mypushbutton.h"

MyPushButton::MyPushButton(QString firstImage, QString secondImage)
{
    this->firstImage = firstImage;
    this->secondImage = secondImage;

    QPixmap pix;

    bool flag = pix.load(this->firstImage);

    if(!flag)
    {
        qDebug()<<firstImage<<"读取失败";
        return;
    }

    //设置按钮固定大小
    this->setFixedSize(pix.width(), pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置按钮图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));
}

void MyPushButton::zoomDown()
{
    //创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");

    animation->setDuration(200);    //动画时长0.2s

    //设置起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //设置结束位置
    animation->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));

    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation->setEasingCurve(QEasingCurve::OutInElastic);

    //执行动画
    animation->start();

}

void MyPushButton::zoomUp()
{
    //创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");

    animation->setDuration(200);    //动画时长0.2s

    //设置起始位置
    animation->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    //设置结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation->setEasingCurve(QEasingCurve::OutInElastic);

    //执行动画
    animation->start();

}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->secondImage != "") //back按键按下
    {
        QPixmap pix;

        bool flag = pix.load(this->secondImage);

        if(!flag)
        {
            qDebug()<<secondImage<<"读取失败";
            return;
        }

        //设置按钮固定大小
        this->setFixedSize(pix.width(), pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置按钮图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }

    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->secondImage != "") //back按键按下
    {
        QPixmap pix;

        bool flag = pix.load(this->firstImage);

        if(!flag)
        {
            qDebug()<<firstImage<<"读取失败";
            return;
        }

        //设置按钮固定大小
        this->setFixedSize(pix.width(), pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置按钮图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }

    return QPushButton::mouseReleaseEvent(e);
}
