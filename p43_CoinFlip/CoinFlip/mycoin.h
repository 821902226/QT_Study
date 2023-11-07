#ifndef MYCOIN_H
#define MYCOIN_H

//金币类
#include <QPushButton>
#include <QDebug>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);

    //参数：表示传入的是金币还是银币
    MyCoin(QString btnImg);

    void coin_filp();

    //重写鼠标按下时间
    void mousePressEvent(QMouseEvent *e);

    int posX, posY; //记录金币的位置，第几行第几列
    bool flag;  //判断是正面还是反面
    bool isAnimation; //判断是否在执行动画

    int start, end;

    QTimer *timer = nullptr;   //金币翻转定时器

signals:

public slots:


};

#endif // MYCOIN_H
