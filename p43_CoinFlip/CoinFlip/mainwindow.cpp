#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置固定大小
    this->setFixedSize(320, 588);
    //设置标题图标
    this->setWindowIcon(QIcon(":/images/Coin0001.png"));
    //设置窗口标题
    this->setWindowTitle("老帮主带你翻金币");

    QMenu *menu_start = ui->menuBar->addMenu("开始");
    QAction *action_exit = menu_start->addAction("退出");

    connect(action_exit, &QAction::triggered, [=](){
        this->close();
    });

    //开始按钮
    MyPushButton *start_btn = new MyPushButton(":/images/MenuSceneStartButton.png");
    start_btn->setParent(this);
    start_btn->move((this->width()-start_btn->width())/2, 412);

    //选择关卡窗口
    this->chooseLevelWindow = new ChooseLevelWindow;

    connect(start_btn, &MyPushButton::clicked, [=](){
        //按下动画特效
        start_btn->zoomDown();
        start_btn->zoomUp();

        //延时400ms，保证动画显示完整
        QTimer::singleShot(400, this, [=](){
            //隐藏当前窗口
            this->hide();
            //显示选择关卡窗口
            this->chooseLevelWindow->show();
        });

    });

    connect(this->chooseLevelWindow, &ChooseLevelWindow::chooseBack, [=](){
        this->chooseLevelWindow->hide();
        this->show();
    });
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //绘制背景图片
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/images/PlayLevelSceneBg.png"));

    //绘制游戏标题
    //缩放图片
    QPixmap pix(":/images/Title.png");
    pix = pix.scaled(pix.width()/2, pix.height()/2);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}
