#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QtDebug>

class myButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myButton(QWidget *parent = nullptr);

    ~myButton();

signals:

public slots:
};

#endif // MYBUTTON_H
