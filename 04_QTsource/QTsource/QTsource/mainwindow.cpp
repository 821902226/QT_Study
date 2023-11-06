#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->actionnew->setIcon(QIcon("C:/Users/GENG/Desktop/1.jpeg")); //绝对路径

    //使用添加QT资源 ": + 前缀名 + 文件名"
    ui->actionnew->setIcon(QIcon(":/image/1.jpeg"));
    ui->actionopen->setIcon(QIcon(":/image/2.jpeg"));

    //点击新建按钮弹出对话框
    connect(ui->actionnew, &QAction::triggered, this, [=](){
        //分为模态对话框和非模态对话框 模态对话框--打开以后不可以对其它窗口进行操作 非模态对话框--打开以后还可以操作其它窗口
        //模态对话框
        //QDialog dialog(this);
        //dialog.resize(200, 150);
        //dialog.exec();

        //非模态对话框 需要创建在堆上，否则lamdba表达式用完就会释放 创建在堆上并指定this会通过对象树释放
        //QDialog *dialog2 = new QDialog(this);
        //dialog2->resize(200, 150);
        //dialog2->setAttribute(Qt::WA_DeleteOnClose); //关闭对话框后释放资源， 防止有人一直打开关闭造成内存泄露
        //dialog2->show();

        //标准对话框：消息对话框
        //1、错误对话框
        //QMessageBox::critical(this, "critical", "error!");
        //2、信息对话框
        //QMessageBox::information(this, "information", "信息!");
        //3、问题对话框 第四个参数可以自己选择按键 第五个参数是按回车键的默认值
        //if(QMessageBox::Save == QMessageBox::question(this, "question", "确定要保存吗？", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel))
        //{
        //    qDebug()<<"保存";
        //}else {
        //    qDebug()<<"取消";
        //}
        //4、警告对话框
        //QMessageBox::warning(this, "warning", "警告!");

        //其它标准对话框
        //1、颜色对话框
        //QColor color = QColorDialog::getColor(QColor(255, 0, 0), this); //参数是默认颜色, QColor第四个参数是透明度
        //qDebug()<<"r:"<<color.red()<<" g:"<<color.green()<<" b:"<<color.blue();
        //2、文件对话框 参数1——父亲 参数2——标题 参数3——默认打开路径 参数4——过滤文件格式 返回选择的文件路径
        //QString dir = QFileDialog::getOpenFileName(this, "打开文件", "C:/Users/GENG/Desktop", "(*.txt *.pdf)");
        //qDebug()<<dir;
        //字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag, QFont("Times New Roman", 12) ,this);
        qDebug()<<"字体："<<font.family().toUtf8().data()<<"字号："<<font.pointSize()<<"是否加粗："<<font.bold()<<"是否斜体："<<font.italic();

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
