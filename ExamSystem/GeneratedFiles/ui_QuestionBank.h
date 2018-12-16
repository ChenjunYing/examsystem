/********************************************************************************
** Form generated from reading UI file 'QuestionBank.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONBANK_H
#define UI_QUESTIONBANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionBank
{
public:
    QTabWidget *tabWidget;
    QWidget *choice;
    QTableView *choiceTable;
    QWidget *multichoice;
    QTableView *multiTable;
    QWidget *judge;
    QTableView *judgeTable;

    void setupUi(QDialog *QuestionBank)
    {
        if (QuestionBank->objectName().isEmpty())
            QuestionBank->setObjectName(QStringLiteral("QuestionBank"));
        QuestionBank->resize(1580, 840);
        QuestionBank->setMinimumSize(QSize(1580, 840));
        QuestionBank->setMaximumSize(QSize(1580, 840));
        tabWidget = new QTabWidget(QuestionBank);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1580, 840));
        tabWidget->setMinimumSize(QSize(1580, 840));
        tabWidget->setMaximumSize(QSize(1580, 840));
        choice = new QWidget();
        choice->setObjectName(QStringLiteral("choice"));
        choice->setMinimumSize(QSize(1540, 840));
        choice->setMaximumSize(QSize(1540, 840));
        choiceTable = new QTableView(choice);
        choiceTable->setObjectName(QStringLiteral("choiceTable"));
        choiceTable->setGeometry(QRect(0, 0, 1580, 840));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(choiceTable->sizePolicy().hasHeightForWidth());
        choiceTable->setSizePolicy(sizePolicy);
        choiceTable->setMinimumSize(QSize(1580, 840));
        choiceTable->setMaximumSize(QSize(1580, 840));
        choiceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tabWidget->addTab(choice, QString());
        multichoice = new QWidget();
        multichoice->setObjectName(QStringLiteral("multichoice"));
        multichoice->setMinimumSize(QSize(1580, 840));
        multichoice->setMaximumSize(QSize(1580, 840));
        multiTable = new QTableView(multichoice);
        multiTable->setObjectName(QStringLiteral("multiTable"));
        multiTable->setGeometry(QRect(0, 0, 1580, 840));
        sizePolicy.setHeightForWidth(multiTable->sizePolicy().hasHeightForWidth());
        multiTable->setSizePolicy(sizePolicy);
        multiTable->setMinimumSize(QSize(1580, 840));
        multiTable->setMaximumSize(QSize(1580, 840));
        multiTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tabWidget->addTab(multichoice, QString());
        judge = new QWidget();
        judge->setObjectName(QStringLiteral("judge"));
        judge->setMinimumSize(QSize(1540, 840));
        judge->setMaximumSize(QSize(1540, 840));
        judgeTable = new QTableView(judge);
        judgeTable->setObjectName(QStringLiteral("judgeTable"));
        judgeTable->setGeometry(QRect(0, 0, 1580, 840));
        sizePolicy.setHeightForWidth(judgeTable->sizePolicy().hasHeightForWidth());
        judgeTable->setSizePolicy(sizePolicy);
        judgeTable->setMinimumSize(QSize(1580, 840));
        judgeTable->setMaximumSize(QSize(1580, 840));
        judgeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tabWidget->addTab(judge, QString());

        retranslateUi(QuestionBank);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QuestionBank);
    } // setupUi

    void retranslateUi(QDialog *QuestionBank)
    {
        QuestionBank->setWindowTitle(QApplication::translate("QuestionBank", "QuestionBank", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(choice), QApplication::translate("QuestionBank", "\345\215\225\351\200\211\351\242\230", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(multichoice), QApplication::translate("QuestionBank", "\345\244\232\351\200\211\351\242\230", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(judge), QApplication::translate("QuestionBank", "\345\210\244\346\226\255\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionBank: public Ui_QuestionBank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONBANK_H
