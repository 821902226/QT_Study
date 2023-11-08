#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QSound>
#include "mypushbutton.h"
#include "chooselevelwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *);

    ChooseLevelWindow *chooseLevelWindow = NULL;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
