/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *button0;
    QPushButton *buttonDot;
    QPushButton *buttonAdd;
    QPushButton *buttonEqual;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *buttonSubtract;
    QPushButton *button1;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *buttonMultiply;
    QPushButton *button4;
    QPushButton *button8;
    QPushButton *button9;
    QPushButton *buttonDivide;
    QPushButton *button7;
    QPushButton *buttonParenR;
    QPushButton *buttonClear;
    QPushButton *buttonClearAll;
    QPushButton *buttonParenL;
    QLineEdit *inputDisplay;
    QLCDNumber *resultDisplay;
    QLabel *oldInputDisplay;
    QPushButton *buttonPower;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(231, 320);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        button0 = new QPushButton(centralWidget);
        button0->setObjectName(QString::fromUtf8("button0"));
        button0->setGeometry(QRect(70, 220, 41, 23));
        buttonDot = new QPushButton(centralWidget);
        buttonDot->setObjectName(QString::fromUtf8("buttonDot"));
        buttonDot->setGeometry(QRect(120, 100, 41, 23));
        buttonAdd = new QPushButton(centralWidget);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));
        buttonAdd->setGeometry(QRect(170, 220, 41, 23));
        buttonEqual = new QPushButton(centralWidget);
        buttonEqual->setObjectName(QString::fromUtf8("buttonEqual"));
        buttonEqual->setGeometry(QRect(170, 250, 41, 23));
        button2 = new QPushButton(centralWidget);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setGeometry(QRect(70, 190, 41, 23));
        button3 = new QPushButton(centralWidget);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setGeometry(QRect(120, 190, 41, 23));
        buttonSubtract = new QPushButton(centralWidget);
        buttonSubtract->setObjectName(QString::fromUtf8("buttonSubtract"));
        buttonSubtract->setGeometry(QRect(170, 190, 41, 23));
        button1 = new QPushButton(centralWidget);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setGeometry(QRect(20, 190, 41, 23));
        button5 = new QPushButton(centralWidget);
        button5->setObjectName(QString::fromUtf8("button5"));
        button5->setGeometry(QRect(70, 160, 41, 23));
        button6 = new QPushButton(centralWidget);
        button6->setObjectName(QString::fromUtf8("button6"));
        button6->setGeometry(QRect(120, 160, 41, 23));
        buttonMultiply = new QPushButton(centralWidget);
        buttonMultiply->setObjectName(QString::fromUtf8("buttonMultiply"));
        buttonMultiply->setGeometry(QRect(170, 160, 41, 23));
        button4 = new QPushButton(centralWidget);
        button4->setObjectName(QString::fromUtf8("button4"));
        button4->setGeometry(QRect(20, 160, 41, 23));
        button8 = new QPushButton(centralWidget);
        button8->setObjectName(QString::fromUtf8("button8"));
        button8->setGeometry(QRect(70, 130, 41, 23));
        button9 = new QPushButton(centralWidget);
        button9->setObjectName(QString::fromUtf8("button9"));
        button9->setGeometry(QRect(120, 130, 41, 23));
        buttonDivide = new QPushButton(centralWidget);
        buttonDivide->setObjectName(QString::fromUtf8("buttonDivide"));
        buttonDivide->setGeometry(QRect(170, 130, 41, 23));
        button7 = new QPushButton(centralWidget);
        button7->setObjectName(QString::fromUtf8("button7"));
        button7->setGeometry(QRect(20, 130, 41, 23));
        buttonParenR = new QPushButton(centralWidget);
        buttonParenR->setObjectName(QString::fromUtf8("buttonParenR"));
        buttonParenR->setGeometry(QRect(120, 220, 41, 23));
        buttonClear = new QPushButton(centralWidget);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));
        buttonClear->setGeometry(QRect(70, 100, 41, 23));
        buttonClearAll = new QPushButton(centralWidget);
        buttonClearAll->setObjectName(QString::fromUtf8("buttonClearAll"));
        buttonClearAll->setGeometry(QRect(20, 100, 41, 23));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonClearAll->sizePolicy().hasHeightForWidth());
        buttonClearAll->setSizePolicy(sizePolicy1);
        buttonParenL = new QPushButton(centralWidget);
        buttonParenL->setObjectName(QString::fromUtf8("buttonParenL"));
        buttonParenL->setGeometry(QRect(20, 220, 41, 23));
        inputDisplay = new QLineEdit(centralWidget);
        inputDisplay->setObjectName(QString::fromUtf8("inputDisplay"));
        inputDisplay->setGeometry(QRect(20, 70, 191, 23));
        inputDisplay->setReadOnly(true);
        inputDisplay->setClearButtonEnabled(false);
        resultDisplay = new QLCDNumber(centralWidget);
        resultDisplay->setObjectName(QString::fromUtf8("resultDisplay"));
        resultDisplay->setGeometry(QRect(100, 40, 111, 23));
        resultDisplay->setFrameShape(QFrame::NoFrame);
        resultDisplay->setFrameShadow(QFrame::Plain);
        resultDisplay->setSmallDecimalPoint(false);
        resultDisplay->setDigitCount(10);
        resultDisplay->setSegmentStyle(QLCDNumber::Flat);
        resultDisplay->setProperty("value", QVariant(0.000000000000000));
        oldInputDisplay = new QLabel(centralWidget);
        oldInputDisplay->setObjectName(QString::fromUtf8("oldInputDisplay"));
        oldInputDisplay->setGeometry(QRect(20, 10, 191, 21));
        oldInputDisplay->setLayoutDirection(Qt::LeftToRight);
        oldInputDisplay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        buttonPower = new QPushButton(centralWidget);
        buttonPower->setObjectName(QString::fromUtf8("buttonPower"));
        buttonPower->setGeometry(QRect(170, 100, 41, 23));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculator", nullptr));
        button0->setText(QApplication::translate("MainWindow", "0", nullptr));
        buttonDot->setText(QApplication::translate("MainWindow", ".", nullptr));
        buttonAdd->setText(QApplication::translate("MainWindow", "+", nullptr));
        buttonEqual->setText(QApplication::translate("MainWindow", "=", nullptr));
        button2->setText(QApplication::translate("MainWindow", "2", nullptr));
        button3->setText(QApplication::translate("MainWindow", "3", nullptr));
        buttonSubtract->setText(QApplication::translate("MainWindow", "-", nullptr));
        button1->setText(QApplication::translate("MainWindow", "1", nullptr));
        button5->setText(QApplication::translate("MainWindow", "5", nullptr));
        button6->setText(QApplication::translate("MainWindow", "6", nullptr));
        buttonMultiply->setText(QApplication::translate("MainWindow", "\303\227", nullptr));
        button4->setText(QApplication::translate("MainWindow", "4", nullptr));
        button8->setText(QApplication::translate("MainWindow", "8", nullptr));
        button9->setText(QApplication::translate("MainWindow", "9", nullptr));
        buttonDivide->setText(QApplication::translate("MainWindow", "\303\267", nullptr));
        button7->setText(QApplication::translate("MainWindow", "7", nullptr));
        buttonParenR->setText(QApplication::translate("MainWindow", ")", nullptr));
        buttonClear->setText(QApplication::translate("MainWindow", "C", nullptr));
        buttonClearAll->setText(QApplication::translate("MainWindow", "AC", nullptr));
        buttonParenL->setText(QApplication::translate("MainWindow", "(", nullptr));
        oldInputDisplay->setText(QString());
        buttonPower->setText(QApplication::translate("MainWindow", "^", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
