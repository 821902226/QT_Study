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
#include <mywidget.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    MyWidget *widget;
    QPushButton *btn_set;
    QPushButton *btn_get;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        widget = new MyWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 0, 281, 51));
        btn_set = new QPushButton(Widget);
        btn_set->setObjectName(QString::fromUtf8("btn_set"));
        btn_set->setGeometry(QRect(60, 70, 75, 23));
        btn_get = new QPushButton(Widget);
        btn_get->setObjectName(QString::fromUtf8("btn_get"));
        btn_get->setGeometry(QRect(270, 70, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        btn_set->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\346\225\260\345\255\227", nullptr));
        btn_get->setText(QApplication::translate("Widget", "\350\216\267\345\217\226\346\225\260\345\255\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
