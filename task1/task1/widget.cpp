#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton *btn1 = new QPushButton;
    btn1->setParent(this);
    btn1->setText("Open");
    btn1->resize(100, 50);

    QPushButton *btn2 = new QPushButton("Close", this);
    btn2->resize(100, 50);
    btn2->move(200, 0);

    resize(600, 400);
    setWindowTitle("作业1");

    QWidget *window = new QWidget;
    connect(btn1, &QPushButton::clicked, this, [=]{
        window->show();
    });

    connect(btn2, &QPushButton::clicked, [=]{   //使用lambda表达式可以省略this
        window->close();
    });


    QPushButton *btn3 = new QPushButton("Open", this);
    btn3->resize(100, 50);
    btn3->move(0, 200);
    connect(btn3, &QPushButton::clicked, [=](bool checked){
        if(btn3->text() == "Open")
        {
            btn3->setText("Close");
            window->show();
        }
        else if (btn3->text() == "Close") {
            btn3->setText("Open");
            window->close();
        }
    });

    QPushButton *btn4 = new QPushButton("Open", this);
    btn4->resize(100, 50);
    btn4->move(200, 200);
    btn4->setCheckable(true);    //设置按键可以切换状态
    connect(btn4, &QPushButton::toggled, [=](bool checked){
        if(checked == true)
        {
            btn4->setText("Close");
            window->show();
        }
        else if (checked == false) {
            btn4->setText("Open");
            window->close();
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
