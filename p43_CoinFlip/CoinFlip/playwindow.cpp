#include "playwindow.h"
#include "ui_playwindow.h"

PlayWindow::PlayWindow(int i, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    this->level = i;

    this->setFixedSize(320, 588);
    //设置标题图标
    this->setWindowIcon(QIcon(":/images/Coin0001.png"));
    //设置标题
    this->setWindowTitle(QString("翻金币：第%1关").arg(this->level));

    //back按钮音效
    QSound *backSound = new QSound(":/musics/BackButtonSound.wav");
    QSound *flipSound = new QSound(":/musics/ConFlipSound.wav");
    QSound *winSound = new QSound(":/musics/LevelWinSound.wav");

    //退出功能
    connect(ui->actionexit3, &QAction::triggered, [=](){
        this->close();
    });

    //返回按钮
    MyPushButton *back_btn2 = new MyPushButton(":/images/BackButton.png", ":/images/BackButtonSelected.png");
    back_btn2->setParent(this);
    back_btn2->move(this->width()-back_btn2->width(), this->height()-back_btn2->height());

    //点击返回
    connect(back_btn2, &MyPushButton::clicked, [=](){
        backSound->play();
        //发送back按下信号
        QTimer::singleShot(200, this, [=](){
            emit this->playBack();
        });
    });


    //左下角显示当前关卡
    QLabel *label = new QLabel;
    label->setParent(this);
    //自定义字体
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    //设置标签字体
    label->setFont(font);
    //设置标签内容
    label->setText(QString("Level %1").arg(this->level));
    //设置标签位置
    label->setGeometry(30, this->height()-60, 120, 50);

    //初始化关卡数组
    dataConfig config;
    for (int m=0;m<4;m++) {
        for (int n=0;n<4;n++) {
            this->gameArray[m][n] = config.mData[this->level][m][n];
        }
    }

    QLabel *success = new QLabel;
    QPixmap pix;
    pix.load(":/images/LevelCompletedDialogBg.png");
    success->setParent(this);
    success->setPixmap(pix);
    success->setGeometry(0, 0, pix.width(), pix.height());
    success->move((this->width()-pix.width())/2, -pix.height());    //放在页面的上方

    //添加金币及其背景
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            //绘制背景图片
            QLabel *label = new QLabel;
            label->setParent(this);
            label->setGeometry(0, 0, 50, 50);
            label->setPixmap(QPixmap(":/images/BoardNode.png"));
            label->move(57+i*50, 200+j*50);

            //绘制金币
            QString str;
            if(this->gameArray[i][j] == 1)  //判断是金币还是银币
            {
                str = ":/images/Coin0001.png";
            }
            else {
                str = ":/images/Coin0008.png";
            }
            MyCoin *coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59+i*50, 203+j*50);
            //记录金币的位置
            coin->posX = i;
            coin->posY = j;
            //是否是金币
            coin->flag = this->gameArray[i][j];
            //默认没有过关
            coin->isWin = false;

            //将每个金币保存下来
            this->coinBtn[i][j] = coin;

            //翻转金币
            connect(coin, &MyCoin::clicked, [=](){
                flipSound->play();
                //点击金币后禁用所有金币，即金币没有翻转完成不能再次点击
                for (int m=0; m<4; m++) {
                    for (int n=0; n<4; n++) {
                        this->coinBtn[m][n]->isWin = true;
                    }
                }

                //翻转当前金币
                coin->coin_filp();
                this->gameArray[coin->posX][coin->posY] = this->gameArray[coin->posX][coin->posY]?0:1;

                QTimer::singleShot(150, this, [=](){
                    //翻转周围金币
                    if(coin->posX+1<=3)
                    {
                        this->coinBtn[coin->posX+1][coin->posY]->coin_filp();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY]?0:1;
                    }
                    if(coin->posX-1>=0)
                    {
                        this->coinBtn[coin->posX-1][coin->posY]->coin_filp();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY]?0:1;
                    }
                    if(coin->posY+1<=3)
                    {
                        this->coinBtn[coin->posX][coin->posY+1]->coin_filp();
                        this->gameArray[coin->posX][coin->posY+1] = this->gameArray[coin->posX][coin->posY+1]?0:1;
                    }
                    if(coin->posY-1>=0)
                    {
                        this->coinBtn[coin->posX][coin->posY-1]->coin_filp();
                        this->gameArray[coin->posX][coin->posY-1] = this->gameArray[coin->posX][coin->posY-1]?0:1;
                    }

                    for (int m=0; m<4; m++) {
                        for (int n=0; n<4; n++) {
                            this->coinBtn[m][n]->isWin = false;
                        }
                    }

                    //判断是否胜利
                    int index = 0;
                    for (int m=0; m<4; m++) {
                        for (int n=0; n<4; n++) {
                            if(this->gameArray[m][n] == 1)
                            {
                                index++;
                            }
                        }
                    }
                    if(index == 16)
                    {
                        coin->isWin = true;
                        qDebug()<<"恭喜你，游戏胜利！";
                        for (int m=0; m<4; m++) {
                            for (int n=0; n<4; n++) {
                                this->coinBtn[m][n]->isWin = true;
                            }
                        }

                        winSound->play();
                        //让胜利图片砸下来
                        //创建动画对象
                        QPropertyAnimation *animation = new QPropertyAnimation(success, "geometry");
                        animation->setDuration(1000);    //动画时长1s
                        //设置起始位置
                        animation->setStartValue(QRect(success->x(), success->y(), success->width(), success->height()));
                        //设置结束位置
                        animation->setEndValue(QRect(success->x(), -success->y()*1.2, success->width(), success->height()));
                        //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        //执行动画
                        animation->start();

                    }
                });

            });
        }
    }
}

void PlayWindow::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //绘制背景图片
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/images/PlayLevelSceneBg.png"));

    QPixmap pix(":/images/Title.png");
    pix = pix.scaled(pix.width()/2, pix.height()/2);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}

PlayWindow::~PlayWindow()
{
    delete ui;
}
