#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabels(QStringList() <<"英雄"<<"英雄简介");

    QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<"速度");
    QTreeWidgetItem *item3 = new QTreeWidgetItem(QStringList()<<"智力");
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);

    QStringList l;
    l<<"刚被猪"<<"前排坦克，能在吸收伤害的同时造成可观的伤害输出";
    QTreeWidgetItem *item11 = new QTreeWidgetItem(l);
    item1->addChild(item11);
}

Widget::~Widget()
{
    delete ui;
}
