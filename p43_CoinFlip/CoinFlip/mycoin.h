#ifndef MYCOIN_H
#define MYCOIN_H

//金币类
#include <QPushButton>
#include <QDebug>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);

    //参数：表示传入的是金币还是银币
    MyCoin(QString btnImg);

signals:

public slots:
};

#endif // MYCOIN_H
