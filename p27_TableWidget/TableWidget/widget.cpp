#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(5);

//    QTableWidgetItem *item1 = new QTableWidgetItem("姓名");
//    QTableWidgetItem *item2 = new QTableWidgetItem("性别");
//    QTableWidgetItem *item3 = new QTableWidgetItem("年龄");
//    ui->tableWidget->setHorizontalHeaderItem(0, item1);
//    ui->tableWidget->setHorizontalHeaderItem(1, item2);
//    ui->tableWidget->setHorizontalHeaderItem(2, item3);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("妲己"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("女"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("19"));


}

Widget::~Widget()
{
    delete ui;
}
