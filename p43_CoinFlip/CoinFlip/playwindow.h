#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <mypushbutton.h>
#include <QDebug>
#include <QLabel>
#include <QFont>
#include "mycoin.h"
#include "dataconfig.h"

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayWindow(int i, QWidget *parent = nullptr);
    ~PlayWindow();

    void paintEvent(QPaintEvent *);

    int gameArray[4][4];

    MyCoin * coinBtn[4][4];

    int level;



private:
    Ui::PlayWindow *ui;

signals:
    void playBack();

};

#endif // PLAYWINDOW_H
