#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>
#include <QAction>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 400);

    //1、创建菜单栏 最多只有一个
    QMenuBar* menu = menuBar();
    //将菜单栏放到窗口中
    setMenuBar(menu);
    //创建菜单
    QMenu *filemenu = menu->addMenu("文件");
    QMenu *editmenu = menu->addMenu("编辑");
    //创建菜单项
    filemenu->addAction("新建");
    //菜单项之间添加分隔线
    filemenu->addSeparator();
    filemenu->addAction("打开");
    QAction *act = editmenu->addAction("撤销");


    //2、创建工具栏 可以有多个
    QToolBar *tool = new QToolBar(this);
    //addToolBar(tool);
    addToolBar(Qt::LeftToolBarArea, tool); //指定工具栏默认位置
    //设置只允许左右停靠
    tool->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置不允许浮动
    tool->setFloatable(false);
    //工具栏设置内容
    tool->addAction(act);
    //工具栏添加控件
    QPushButton *btn = new QPushButton("Debug", this);
    tool->addWidget(btn);


    //创建状态栏 最多只有一个
    QStatusBar * status = statusBar();
    setStatusBar(status);
    //放置标签控件
    QLabel *label = new QLabel("提示信息", this);
    status->addWidget(label);

    QLabel *label2 = new QLabel("右侧提示信息", this);
    status->addPermanentWidget(label2);


    //添加铆接部件（浮动窗口） 可以有多个
    QDockWidget *dock = new QDockWidget("浮动窗口", this);
    addDockWidget(Qt::RightDockWidgetArea, dock);   //靠右浮动

    //添加中心部件    只能有一个
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

}

MainWindow::~MainWindow()
{

}
