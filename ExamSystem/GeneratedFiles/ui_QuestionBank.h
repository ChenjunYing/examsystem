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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionBank
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *keywordSelector;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpinBox *lowerValue;
    QLabel *label_4;
    QSpinBox *upperValue;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLineEdit *authorSelector;
    QSpacerItem *horizontalSpacer;
    QPushButton *selectBtn;
    QTabWidget *tabWidget;
    QWidget *choice;
    QVBoxLayout *verticalLayout_2;
    QTableView *choiceTable;
    QWidget *multichoice;
    QVBoxLayout *verticalLayout_3;
    QTableView *multiTable;
    QWidget *judge;
    QVBoxLayout *verticalLayout_4;
    QTableView *judgeTable;

    void setupUi(QDialog *QuestionBank)
    {
        if (QuestionBank->objectName().isEmpty())
            QuestionBank->setObjectName(QStringLiteral("QuestionBank"));
        QuestionBank->resize(1580, 844);
        verticalLayout = new QVBoxLayout(QuestionBank);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(QuestionBank);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        keywordSelector = new QLineEdit(QuestionBank);
        keywordSelector->setObjectName(QStringLiteral("keywordSelector"));

        horizontalLayout->addWidget(keywordSelector);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_2 = new QLabel(QuestionBank);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        lowerValue = new QSpinBox(QuestionBank);
        lowerValue->setObjectName(QStringLiteral("lowerValue"));

        horizontalLayout->addWidget(lowerValue);

        label_4 = new QLabel(QuestionBank);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        label_4->setFont(font);
        label_4->setStyleSheet(QLatin1String("padding-left:10%;\n"
"padding-right:10%;"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        upperValue = new QSpinBox(QuestionBank);
        upperValue->setObjectName(QStringLiteral("upperValue"));

        horizontalLayout->addWidget(upperValue);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_3 = new QLabel(QuestionBank);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_3);

        authorSelector = new QLineEdit(QuestionBank);
        authorSelector->setObjectName(QStringLiteral("authorSelector"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(authorSelector->sizePolicy().hasHeightForWidth());
        authorSelector->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(authorSelector);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        selectBtn = new QPushButton(QuestionBank);
        selectBtn->setObjectName(QStringLiteral("selectBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(selectBtn->sizePolicy().hasHeightForWidth());
        selectBtn->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(selectBtn);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);
        horizontalLayout->setStretch(6, 1);
        horizontalLayout->setStretch(8, 1);
        horizontalLayout->setStretch(9, 1);
        horizontalLayout->setStretch(10, 1);
        horizontalLayout->setStretch(11, 2);

        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(QuestionBank);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        choice = new QWidget();
        choice->setObjectName(QStringLiteral("choice"));
        verticalLayout_2 = new QVBoxLayout(choice);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        choiceTable = new QTableView(choice);
        choiceTable->setObjectName(QStringLiteral("choiceTable"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(choiceTable->sizePolicy().hasHeightForWidth());
        choiceTable->setSizePolicy(sizePolicy3);
        choiceTable->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        choiceTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        choiceTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        choiceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(choiceTable);

        tabWidget->addTab(choice, QString());
        multichoice = new QWidget();
        multichoice->setObjectName(QStringLiteral("multichoice"));
        verticalLayout_3 = new QVBoxLayout(multichoice);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        multiTable = new QTableView(multichoice);
        multiTable->setObjectName(QStringLiteral("multiTable"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(multiTable->sizePolicy().hasHeightForWidth());
        multiTable->setSizePolicy(sizePolicy4);
        multiTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_3->addWidget(multiTable);

        tabWidget->addTab(multichoice, QString());
        judge = new QWidget();
        judge->setObjectName(QStringLiteral("judge"));
        verticalLayout_4 = new QVBoxLayout(judge);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        judgeTable = new QTableView(judge);
        judgeTable->setObjectName(QStringLiteral("judgeTable"));
        sizePolicy4.setHeightForWidth(judgeTable->sizePolicy().hasHeightForWidth());
        judgeTable->setSizePolicy(sizePolicy4);
        judgeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_4->addWidget(judgeTable);

        tabWidget->addTab(judge, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(QuestionBank);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QuestionBank);
    } // setupUi

    void retranslateUi(QDialog *QuestionBank)
    {
        QuestionBank->setWindowTitle(QApplication::translate("QuestionBank", "\350\257\225\351\242\230\347\256\241\347\220\206", nullptr));
        label->setText(QApplication::translate("QuestionBank", "\350\257\225\351\242\230\345\205\263\351\224\256\345\255\227", nullptr));
        label_2->setText(QApplication::translate("QuestionBank", "\350\257\225\351\242\230\345\210\206\345\200\274", nullptr));
        label_4->setText(QApplication::translate("QuestionBank", "\350\207\263", nullptr));
        label_3->setText(QApplication::translate("QuestionBank", "\350\257\225\351\242\230\344\275\234\350\200\205", nullptr));
        selectBtn->setText(QApplication::translate("QuestionBank", "\347\255\233             \351\200\211", nullptr));
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
