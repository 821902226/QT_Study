#include "chooselevelwindow.h"
#include "ui_chooselevelwindow.h"
#include "mypushbutton.h"

ChooseLevelWindow::ChooseLevelWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseLevelWindow)
{
    ui->setupUi(this);

    this->setFixedSize(320, 588);
    //设置标题图标
    this->setWindowIcon(QIcon(":/images/Coin0001.png"));
    //设置窗口标题
    this->setWindowTitle("选择关卡");

    //选择关卡音效
    QSound *chooseSound = new QSound(":/musics/TapButtonSound.wav");
    //返回按钮音效
    QSound *backSound = new QSound(":/musics/BackButtonSound.wav");

    connect(ui->actionexit2, &QAction::triggered, [=](){
        this->close();
    });

    //返回按钮
    MyPushButton *back_btn = new MyPushButton(":/images/BackButton.png", ":/images/BackButtonSelected.png");
    back_btn->setParent(this);
    back_btn->move(this->width()-back_btn->width(), this->height()-back_btn->height());

    //点击返回
    connect(back_btn, &MyPushButton::clicked, [=](){
        backSound->play();
        //发送back按下信号
        QTimer::singleShot(200, this, [=](){
            emit this->chooseBack();
        });
    });


    //创建选择关卡按钮
    for (int i=0; i<20; i++) {
        //添加二十个关卡按钮
        MyPushButton *menuBtn = new MyPushButton(":/images/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(i%4*70+25, i/4*70+140);

        //为每个按钮添加关卡编号
        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(i%4*70+25, i/4*70+140);
        label->setAlignment(Qt::AlignCenter);

        //设置鼠标穿透事件，鼠标可以透过label点击按钮
        label->setAttribute(Qt::WA_TransparentForMouseEvents);


        //监听每个按钮的点击情况
        connect(menuBtn, &MyPushButton::clicked, [=](){
            chooseSound->play();
            //进入到游戏场景
            this->hide();
            this->play = new PlayWindow(i+1);
            this->play->show();

            //从游戏界面返回
            connect(this->play, &PlayWindow::playBack, [=](){
                delete this->play;
                this->play = NULL;
                this->show();
            });

        });
    }
}

void ChooseLevelWindow::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //绘制背景图片
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/images/OtherSceneBg.png"));

    QPixmap pix(":/images/Title.png");
    painter.drawPixmap((this->width()-pix.width())/2, 30, pix.width(), pix.height(), pix);
}

ChooseLevelWindow::~ChooseLevelWindow()
{
    delete ui;
}
