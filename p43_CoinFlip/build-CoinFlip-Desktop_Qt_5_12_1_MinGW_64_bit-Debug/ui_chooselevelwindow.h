/********************************************************************************
** Form generated from reading UI file 'chooselevelwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELEVELWINDOW_H
#define UI_CHOOSELEVELWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseLevelWindow
{
public:
    QAction *actionexit;
    QAction *actionexit2;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menustart;

    void setupUi(QMainWindow *ChooseLevelWindow)
    {
        if (ChooseLevelWindow->objectName().isEmpty())
            ChooseLevelWindow->setObjectName(QString::fromUtf8("ChooseLevelWindow"));
        ChooseLevelWindow->resize(320, 588);
        actionexit = new QAction(ChooseLevelWindow);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        actionexit2 = new QAction(ChooseLevelWindow);
        actionexit2->setObjectName(QString::fromUtf8("actionexit2"));
        centralwidget = new QWidget(ChooseLevelWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ChooseLevelWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChooseLevelWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 23));
        menustart = new QMenu(menubar);
        menustart->setObjectName(QString::fromUtf8("menustart"));
        ChooseLevelWindow->setMenuBar(menubar);

        menubar->addAction(menustart->menuAction());
        menustart->addAction(actionexit2);

        retranslateUi(ChooseLevelWindow);

        QMetaObject::connectSlotsByName(ChooseLevelWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChooseLevelWindow)
    {
        ChooseLevelWindow->setWindowTitle(QApplication::translate("ChooseLevelWindow", "MainWindow", nullptr));
        actionexit->setText(QApplication::translate("ChooseLevelWindow", "\351\200\200\345\207\272", nullptr));
        actionexit2->setText(QApplication::translate("ChooseLevelWindow", "\351\200\200\345\207\272", nullptr));
        menustart->setTitle(QApplication::translate("ChooseLevelWindow", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseLevelWindow: public Ui_ChooseLevelWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELEVELWINDOW_H
