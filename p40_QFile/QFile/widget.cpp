#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QDebug>
#include <QFileInfo>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击按钮，弹出文件对话框
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QString filename = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\82190\\Desktop");
        //将路径放到lineEdit中
        ui->lineEdit->setText(filename);

        //编码格式类
        QTextCodec *codec = QTextCodec::codecForName("utf-8");  //指定文件编码格式

        //读取文件内容 放到textEdit中
        QFile file(filename);
        file.open(QIODevice::ReadOnly);

        //QByteArray array = file.readAll();  //读取所有文件内容

        //每次读取一行
        QByteArray array;
        while(!file.atEnd())
        {
            array+=file.readLine();
        }

        ui->textEdit->setText(codec->toUnicode(array)); //先将文件内容转码，再填充到textEdit

        file.close();

        //进行写文件
//        file.open(QIODevice::Append);
//        file.write("读取成功！");
//        file.close();

        //QFileInfo 文件信息类
        QFileInfo info(filename);
        qDebug()<<"文件名："<<info.fileName()<<"文件后缀："<<info.suffix()<<"文件大小："<<info.size();

        //创建日期和修改日期
        qDebug()<<"创建日期："<<info.birthTime().toString("yyyy/MM/dd hh:mm:ss");
        qDebug()<<"最后修改："<<info.lastModified().toString("yyyy/MM/dd hh:mm:ss");

    });
}

Widget::~Widget()
{
    delete ui;
}
