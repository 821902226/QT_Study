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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *btn2;
    QPushButton *btn1;
    QPushButton *btn4;
    QPushButton *btn3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        btn2 = new QPushButton(Widget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(310, 240, 75, 23));
        btn1 = new QPushButton(Widget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setGeometry(QRect(210, 240, 75, 23));
        btn4 = new QPushButton(Widget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setGeometry(QRect(310, 270, 75, 23));
        btn3 = new QPushButton(Widget);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setGeometry(QRect(210, 270, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        btn2->setText(QApplication::translate("Widget", "\345\217\263\347\247\273", nullptr));
        btn1->setText(QApplication::translate("Widget", "\345\267\246\347\247\273", nullptr));
        btn4->setText(QApplication::translate("Widget", "\344\270\213\347\247\273", nullptr));
        btn3->setText(QApplication::translate("Widget", "\344\270\212\347\247\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
