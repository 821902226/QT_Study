#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    //需要重写父类中的虚函数，函数名不可改动
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
