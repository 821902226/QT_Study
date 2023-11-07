#include "mycoin.h"

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool flag = pix.load(btnImg);

    if(!flag)
    {
        QString str = QString("图片%1加载失败").arg(btnImg);
        qDebug()<<str;
        return;
    }

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    this->timer = new QTimer;
    this->isAnimation = false;
    connect(this->timer, &QTimer::timeout, [=](){
        if(this->start == this->end)
        {
            this->isAnimation = false;
            timer->stop();
        }

        QString str;
        if(this->flag)
        {
            str = QString(":/images/Coin000%1.png").arg(this->start--);
        }
        else {
            str = QString(":/images/Coin000%1.png").arg(this->start++);
        }

        QPixmap pix;
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    });
}

void MyCoin::coin_filp()
{
    this->isAnimation = true;
    if(this->flag)
    {
        this->start = 1;
        this->end = 8;
        this->flag = false;
    }
    else {
        this->start = 8;
        this->end = 1;
        this->flag = true;
    }
    this->timer->start(30);
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation)
    {
        return;
    }
    else {
        return QPushButton::mousePressEvent(e);
    }
}
