#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter> //画家类

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *);

    int posX = 0;
    int posY = 0;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
