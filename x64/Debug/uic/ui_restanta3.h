/********************************************************************************
** Form generated from reading UI file 'restanta3.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTANTA3_H
#define UI_RESTANTA3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_restanta3Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *restanta3Class)
    {
        if (restanta3Class->objectName().isEmpty())
            restanta3Class->setObjectName("restanta3Class");
        restanta3Class->resize(600, 400);
        menuBar = new QMenuBar(restanta3Class);
        menuBar->setObjectName("menuBar");
        restanta3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(restanta3Class);
        mainToolBar->setObjectName("mainToolBar");
        restanta3Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(restanta3Class);
        centralWidget->setObjectName("centralWidget");
        restanta3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(restanta3Class);
        statusBar->setObjectName("statusBar");
        restanta3Class->setStatusBar(statusBar);

        retranslateUi(restanta3Class);

        QMetaObject::connectSlotsByName(restanta3Class);
    } // setupUi

    void retranslateUi(QMainWindow *restanta3Class)
    {
        restanta3Class->setWindowTitle(QCoreApplication::translate("restanta3Class", "restanta3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class restanta3Class: public Ui_restanta3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTANTA3_H
