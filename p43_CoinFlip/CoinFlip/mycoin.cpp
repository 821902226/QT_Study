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
}
