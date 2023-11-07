#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QPropertyAnimation>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:

    //构造函数， 正常显示的图片路径 按下后显示图片路径
    MyPushButton(QString firstImage, QString secondImage = "");

    //按钮向下跳
    void zoomDown();
    //按钮向上跳
    void zoomUp();

    //重写鼠标按下和释放事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    //保存正常显示的图片路径以及按下后显示的图片路径
    QString firstImage, secondImage;

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
