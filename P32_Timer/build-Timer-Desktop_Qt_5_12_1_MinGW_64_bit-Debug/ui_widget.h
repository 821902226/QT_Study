/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label2;
    QLabel *label3;
    QPushButton *btn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 40, 181, 61));
        label->setFrameShape(QFrame::Box);
        label2 = new QLabel(Widget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(90, 110, 181, 61));
        label2->setFrameShape(QFrame::Box);
        label3 = new QLabel(Widget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(90, 180, 181, 61));
        label3->setFrameShape(QFrame::Box);
        btn = new QPushButton(Widget);
        btn->setObjectName(QString::fromUtf8("btn"));
        btn->setGeometry(QRect(290, 200, 75, 23));
        btn->setCheckable(true);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "Tim1", nullptr));
        label2->setText(QApplication::translate("Widget", "Tim2", nullptr));
        label3->setText(QApplication::translate("Widget", "Tim3", nullptr));
        btn->setText(QApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
