/********************************************************************************
** Form generated from reading UI file 'AddMultiChoice.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMULTICHOICE_H
#define UI_ADDMULTICHOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddMultiChoice
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *Descriptions;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QTextEdit *description;
    QHBoxLayout *A;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_7;
    QTextEdit *choiceA;
    QHBoxLayout *B;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_8;
    QTextEdit *choiceB;
    QHBoxLayout *C;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_9;
    QTextEdit *choiceC;
    QHBoxLayout *D;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_10;
    QTextEdit *choiceD;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_11;
    QSpinBox *score;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *answerA;
    QCheckBox *answerB;
    QCheckBox *answerC;
    QCheckBox *answerD;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *submitBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *resetBtn;

    void setupUi(QDialog *AddMultiChoice)
    {
        if (AddMultiChoice->objectName().isEmpty())
            AddMultiChoice->setObjectName(QStringLiteral("AddMultiChoice"));
        AddMultiChoice->resize(480, 725);
        AddMultiChoice->setMinimumSize(QSize(480, 725));
        AddMultiChoice->setMaximumSize(QSize(480, 725));
        AddMultiChoice->setSizeGripEnabled(false);
        AddMultiChoice->setModal(false);
        layoutWidget = new QWidget(AddMultiChoice);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 401, 671));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(26);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Descriptions = new QHBoxLayout();
        Descriptions->setSpacing(6);
        Descriptions->setObjectName(QStringLiteral("Descriptions"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        Descriptions->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        Descriptions->addItem(horizontalSpacer_4);

        description = new QTextEdit(layoutWidget);
        description->setObjectName(QStringLiteral("description"));
        sizePolicy.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy);
        description->setMinimumSize(QSize(300, 100));
        description->setMaximumSize(QSize(300, 100));
        description->setReadOnly(false);

        Descriptions->addWidget(description);


        verticalLayout->addLayout(Descriptions);

        A = new QHBoxLayout();
        A->setSpacing(6);
        A->setObjectName(QStringLiteral("A"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        A->addWidget(label_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        A->addItem(horizontalSpacer_7);

        choiceA = new QTextEdit(layoutWidget);
        choiceA->setObjectName(QStringLiteral("choiceA"));
        sizePolicy.setHeightForWidth(choiceA->sizePolicy().hasHeightForWidth());
        choiceA->setSizePolicy(sizePolicy);
        choiceA->setMinimumSize(QSize(300, 80));
        choiceA->setMaximumSize(QSize(300, 80));
        choiceA->setReadOnly(false);

        A->addWidget(choiceA);

        A->setStretch(0, 1);
        A->setStretch(2, 8);

        verticalLayout->addLayout(A);

        B = new QHBoxLayout();
        B->setSpacing(6);
        B->setObjectName(QStringLiteral("B"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        B->addWidget(label_4);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        B->addItem(horizontalSpacer_8);

        choiceB = new QTextEdit(layoutWidget);
        choiceB->setObjectName(QStringLiteral("choiceB"));
        sizePolicy.setHeightForWidth(choiceB->sizePolicy().hasHeightForWidth());
        choiceB->setSizePolicy(sizePolicy);
        choiceB->setMinimumSize(QSize(300, 80));
        choiceB->setMaximumSize(QSize(300, 80));
        choiceB->setReadOnly(false);

        B->addWidget(choiceB);

        B->setStretch(0, 1);
        B->setStretch(2, 8);

        verticalLayout->addLayout(B);

        C = new QHBoxLayout();
        C->setSpacing(6);
        C->setObjectName(QStringLiteral("C"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        C->addWidget(label_5);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        C->addItem(horizontalSpacer_9);

        choiceC = new QTextEdit(layoutWidget);
        choiceC->setObjectName(QStringLiteral("choiceC"));
        sizePolicy.setHeightForWidth(choiceC->sizePolicy().hasHeightForWidth());
        choiceC->setSizePolicy(sizePolicy);
        choiceC->setMinimumSize(QSize(300, 80));
        choiceC->setMaximumSize(QSize(300, 80));
        choiceC->setReadOnly(false);

        C->addWidget(choiceC);

        C->setStretch(0, 1);
        C->setStretch(2, 8);

        verticalLayout->addLayout(C);

        D = new QHBoxLayout();
        D->setSpacing(6);
        D->setObjectName(QStringLiteral("D"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        D->addWidget(label_6);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        D->addItem(horizontalSpacer_10);

        choiceD = new QTextEdit(layoutWidget);
        choiceD->setObjectName(QStringLiteral("choiceD"));
        sizePolicy.setHeightForWidth(choiceD->sizePolicy().hasHeightForWidth());
        choiceD->setSizePolicy(sizePolicy);
        choiceD->setMinimumSize(QSize(300, 80));
        choiceD->setMaximumSize(QSize(300, 80));
        choiceD->setReadOnly(false);

        D->addWidget(choiceD);

        D->setStretch(0, 1);
        D->setStretch(2, 8);

        verticalLayout->addLayout(D);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_7);

        horizontalSpacer_11 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        score = new QSpinBox(layoutWidget);
        score->setObjectName(QStringLiteral("score"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(score->sizePolicy().hasHeightForWidth());
        score->setSizePolicy(sizePolicy2);
        score->setMaximum(100);

        horizontalLayout->addWidget(score);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 8);
        horizontalLayout->setStretch(3, 16);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_8);

        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        answerA = new QCheckBox(layoutWidget);
        answerA->setObjectName(QStringLiteral("answerA"));

        horizontalLayout_3->addWidget(answerA);

        answerB = new QCheckBox(layoutWidget);
        answerB->setObjectName(QStringLiteral("answerB"));

        horizontalLayout_3->addWidget(answerB);

        answerC = new QCheckBox(layoutWidget);
        answerC->setObjectName(QStringLiteral("answerC"));

        horizontalLayout_3->addWidget(answerC);

        answerD = new QCheckBox(layoutWidget);
        answerD->setObjectName(QStringLiteral("answerD"));

        horizontalLayout_3->addWidget(answerD);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(6, 5);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        submitBtn = new QPushButton(layoutWidget);
        submitBtn->setObjectName(QStringLiteral("submitBtn"));

        horizontalLayout_2->addWidget(submitBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        resetBtn = new QPushButton(layoutWidget);
        resetBtn->setObjectName(QStringLiteral("resetBtn"));

        horizontalLayout_2->addWidget(resetBtn);

        horizontalLayout_2->setStretch(0, 8);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AddMultiChoice);

        QMetaObject::connectSlotsByName(AddMultiChoice);
    } // setupUi

    void retranslateUi(QDialog *AddMultiChoice)
    {
        AddMultiChoice->setWindowTitle(QApplication::translate("AddMultiChoice", "\346\267\273\345\212\240\345\244\232\351\200\211\351\242\230", nullptr));
        label->setText(QApplication::translate("AddMultiChoice", "\346\267\273\345\212\240\345\244\232\351\200\211\351\242\230", nullptr));
        label_2->setText(QApplication::translate("AddMultiChoice", "\351\242\230\347\233\256\346\217\217\350\277\260", nullptr));
        description->setHtml(QApplication::translate("AddMultiChoice", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        description->setPlaceholderText(QApplication::translate("AddMultiChoice", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\242\230\347\233\256\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207300\345\255\227)", nullptr));
        label_3->setText(QApplication::translate("AddMultiChoice", "A\351\200\211\351\241\271\346\217\217\350\277\260", nullptr));
        choiceA->setPlaceholderText(QApplication::translate("AddMultiChoice", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\200\211\351\241\271\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207200\345\255\227\357\274\211", nullptr));
        label_4->setText(QApplication::translate("AddMultiChoice", "B\351\200\211\351\241\271\346\217\217\350\277\260", nullptr));
        choiceB->setPlaceholderText(QApplication::translate("AddMultiChoice", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\200\211\351\241\271\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207200\345\255\227\357\274\211", nullptr));
        label_5->setText(QApplication::translate("AddMultiChoice", "C\351\200\211\351\241\271\346\217\217\350\277\260", nullptr));
        choiceC->setPlaceholderText(QApplication::translate("AddMultiChoice", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\200\211\351\241\271\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207200\345\255\227\357\274\211", nullptr));
        label_6->setText(QApplication::translate("AddMultiChoice", "D\351\200\211\351\241\271\346\217\217\350\277\260", nullptr));
        choiceD->setPlaceholderText(QApplication::translate("AddMultiChoice", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\200\211\351\241\271\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207200\345\255\227\357\274\211", nullptr));
        label_7->setText(QApplication::translate("AddMultiChoice", "\345\210\206     \345\200\274", nullptr));
        label_8->setText(QApplication::translate("AddMultiChoice", "\347\255\224     \346\241\210", nullptr));
        answerA->setText(QApplication::translate("AddMultiChoice", "A", nullptr));
        answerB->setText(QApplication::translate("AddMultiChoice", "B", nullptr));
        answerC->setText(QApplication::translate("AddMultiChoice", "C", nullptr));
        answerD->setText(QApplication::translate("AddMultiChoice", "D", nullptr));
        submitBtn->setText(QApplication::translate("AddMultiChoice", "\346\217\220   \344\272\244", nullptr));
        resetBtn->setText(QApplication::translate("AddMultiChoice", "\351\207\215    \347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddMultiChoice: public Ui_AddMultiChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMULTICHOICE_H
