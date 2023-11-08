#ifndef CHOOSELEVELWINDOW_H
#define CHOOSELEVELWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <QSound>
#include "playwindow.h"

namespace Ui {
class ChooseLevelWindow;
}

class ChooseLevelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseLevelWindow(QWidget *parent = nullptr);
    ~ChooseLevelWindow();

    void paintEvent(QPaintEvent *);

    PlayWindow *play = NULL;

private:
    Ui::ChooseLevelWindow *ui;

signals:
    //自定义信号， 告诉主窗口 点击了back按键
    void chooseBack();

public slots:

};

#endif // CHOOSELEVELWINDOW_H
