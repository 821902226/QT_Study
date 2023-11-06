#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

void MyWidget::enterEvent(QEvent *event)
{
    qDebug()<<"鼠标进入了";
}

void MyWidget::leaveEvent(QEvent *event)
{
    qDebug()<<"鼠标离开了";
}

MyWidget::~MyWidget()
{
    delete ui;
}
