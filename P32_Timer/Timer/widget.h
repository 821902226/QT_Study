#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer> //定时器类

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void timerEvent(QTimerEvent *event);

    int id1, id2;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
