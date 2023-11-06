#include "mywidget.h"
#include "ui_mywidget.h"
#include <QSpinBox>
#include <QSlider>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //函数指针
    void (QSpinBox:: * value_changed)(int) = &QSpinBox::valueChanged;

    connect(ui->spinBox, value_changed, ui->horizontalSlider, &QSlider::setValue);

    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

void MyWidget::setNum(int num)
{
    ui->spinBox->setValue(num);
}

int MyWidget::getNum()
{
    return ui->spinBox->value();
}

MyWidget::~MyWidget()
{
    delete ui;
}
