/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *goQuestionBank;
    QAction *createExam;
    QAction *examInformation;
    QAction *examData;
    QAction *choice;
    QAction *judge;
    QAction *multichoice;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *QuestionBankMenu;
    QMenu *menu;
    QMenu *ExamMenu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1200, 800);
        MainWindowClass->setMinimumSize(QSize(1200, 800));
        MainWindowClass->setMaximumSize(QSize(1200, 800));
        goQuestionBank = new QAction(MainWindowClass);
        goQuestionBank->setObjectName(QStringLiteral("goQuestionBank"));
        createExam = new QAction(MainWindowClass);
        createExam->setObjectName(QStringLiteral("createExam"));
        examInformation = new QAction(MainWindowClass);
        examInformation->setObjectName(QStringLiteral("examInformation"));
        examData = new QAction(MainWindowClass);
        examData->setObjectName(QStringLiteral("examData"));
        choice = new QAction(MainWindowClass);
        choice->setObjectName(QStringLiteral("choice"));
        judge = new QAction(MainWindowClass);
        judge->setObjectName(QStringLiteral("judge"));
        multichoice = new QAction(MainWindowClass);
        multichoice->setObjectName(QStringLiteral("multichoice"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 26));
        QuestionBankMenu = new QMenu(menuBar);
        QuestionBankMenu->setObjectName(QStringLiteral("QuestionBankMenu"));
        QuestionBankMenu->setSeparatorsCollapsible(false);
        menu = new QMenu(QuestionBankMenu);
        menu->setObjectName(QStringLiteral("menu"));
        ExamMenu = new QMenu(menuBar);
        ExamMenu->setObjectName(QStringLiteral("ExamMenu"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(QuestionBankMenu->menuAction());
        menuBar->addAction(ExamMenu->menuAction());
        QuestionBankMenu->addAction(menu->menuAction());
        QuestionBankMenu->addAction(goQuestionBank);
        menu->addAction(choice);
        menu->addAction(multichoice);
        menu->addAction(judge);
        ExamMenu->addAction(createExam);
        ExamMenu->addAction(examInformation);
        ExamMenu->addAction(examData);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "\347\256\241\347\220\206\345\221\230\344\270\273\347\225\214\351\235\242", nullptr));
        goQuestionBank->setText(QApplication::translate("MainWindowClass", "\350\277\233\345\205\245\351\242\230\345\272\223", nullptr));
        createExam->setText(QApplication::translate("MainWindowClass", "\345\210\233\345\273\272\350\257\225\345\215\267", nullptr));
        examInformation->setText(QApplication::translate("MainWindowClass", "\346\237\245\347\234\213\345\267\262\346\234\211\350\257\225\345\215\267", nullptr));
        examData->setText(QApplication::translate("MainWindowClass", "\346\237\245\347\234\213\350\200\203\350\257\225\346\225\260\346\215\256", nullptr));
        choice->setText(QApplication::translate("MainWindowClass", "\345\215\225\351\200\211\351\242\230", nullptr));
        judge->setText(QApplication::translate("MainWindowClass", "\345\210\244\346\226\255\351\242\230", nullptr));
        multichoice->setText(QApplication::translate("MainWindowClass", "\345\244\232\351\200\211\351\242\230", nullptr));
        QuestionBankMenu->setTitle(QApplication::translate("MainWindowClass", "\351\242\230\345\272\223\347\256\241\347\220\206", nullptr));
        menu->setTitle(QApplication::translate("MainWindowClass", "\346\267\273\345\212\240\350\257\225\351\242\230", nullptr));
        ExamMenu->setTitle(QApplication::translate("MainWindowClass", "\350\257\225\345\215\267\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
