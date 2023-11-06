#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(1);

    connect(ui->pushButton1, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->pushButton2, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    ui->comboBox->addItems(QStringList()<<"奔驰"<<"宝马"<<"奥迪");
    connect(ui->pushButton3, &QPushButton::clicked, this, [=](){
        ui->comboBox->setCurrentIndex(1);
    });
}

Widget::~Widget()
{
    delete ui;
}
