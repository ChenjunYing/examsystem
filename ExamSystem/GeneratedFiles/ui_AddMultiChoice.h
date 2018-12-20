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
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddMultiChoice
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_10;
    QTextEdit *description;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpinBox *score;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QCheckBox *answerA;
    QCheckBox *answerB;
    QCheckBox *answerC;
    QCheckBox *answerD;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *submitBtn;
    QPushButton *resetBtn;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QTextEdit *choiceA;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QTextEdit *choiceB;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QTextEdit *choiceC;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QTextEdit *choiceD;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *AddMultiChoice)
    {
        if (AddMultiChoice->objectName().isEmpty())
            AddMultiChoice->setObjectName(QStringLiteral("AddMultiChoice"));
        AddMultiChoice->resize(760, 460);
        AddMultiChoice->setSizeGripEnabled(false);
        AddMultiChoice->setModal(false);
        verticalLayout_3 = new QVBoxLayout(AddMultiChoice);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        groupBox_2 = new QGroupBox(AddMultiChoice);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox_2->setFont(font);
        horizontalLayout_10 = new QHBoxLayout(groupBox_2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        description = new QTextEdit(groupBox_2);
        description->setObjectName(QStringLiteral("description"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy);
        description->setMinimumSize(QSize(300, 100));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        description->setFont(font1);
        description->setReadOnly(false);

        horizontalLayout_10->addWidget(description);


        horizontalLayout_12->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(AddMultiChoice);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setFont(font1);

        horizontalLayout_2->addWidget(label_7);

        score = new QSpinBox(groupBox_3);
        score->setObjectName(QStringLiteral("score"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(score->sizePolicy().hasHeightForWidth());
        score->setSizePolicy(sizePolicy2);
        score->setMaximum(100);

        horizontalLayout_2->addWidget(score);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setFont(font1);

        horizontalLayout_8->addWidget(label_8);

        answerA = new QCheckBox(groupBox_3);
        buttonGroup = new QButtonGroup(AddMultiChoice);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->setExclusive(false);
        buttonGroup->addButton(answerA);
        answerA->setObjectName(QStringLiteral("answerA"));

        horizontalLayout_8->addWidget(answerA);

        answerB = new QCheckBox(groupBox_3);
        buttonGroup->addButton(answerB);
        answerB->setObjectName(QStringLiteral("answerB"));

        horizontalLayout_8->addWidget(answerB);

        answerC = new QCheckBox(groupBox_3);
        buttonGroup->addButton(answerC);
        answerC->setObjectName(QStringLiteral("answerC"));

        horizontalLayout_8->addWidget(answerC);

        answerD = new QCheckBox(groupBox_3);
        buttonGroup->addButton(answerD);
        answerD->setObjectName(QStringLiteral("answerD"));

        horizontalLayout_8->addWidget(answerD);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        submitBtn = new QPushButton(groupBox_3);
        submitBtn->setObjectName(QStringLiteral("submitBtn"));
        sizePolicy2.setHeightForWidth(submitBtn->sizePolicy().hasHeightForWidth());
        submitBtn->setSizePolicy(sizePolicy2);
        submitBtn->setFont(font1);

        horizontalLayout_9->addWidget(submitBtn);

        resetBtn = new QPushButton(groupBox_3);
        resetBtn->setObjectName(QStringLiteral("resetBtn"));
        sizePolicy2.setHeightForWidth(resetBtn->sizePolicy().hasHeightForWidth());
        resetBtn->setSizePolicy(sizePolicy2);
        resetBtn->setFont(font1);

        horizontalLayout_9->addWidget(resetBtn);


        verticalLayout_2->addLayout(horizontalLayout_9);


        horizontalLayout_12->addWidget(groupBox_3);

        horizontalLayout_12->setStretch(0, 7);
        horizontalLayout_12->setStretch(1, 3);

        verticalLayout_3->addLayout(horizontalLayout_12);

        groupBox = new QGroupBox(AddMultiChoice);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        horizontalLayout_11 = new QHBoxLayout(groupBox);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setStyleSheet(QStringLiteral("font: 75 14pt \"Arial\";"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        choiceA = new QTextEdit(groupBox);
        choiceA->setObjectName(QStringLiteral("choiceA"));
        sizePolicy.setHeightForWidth(choiceA->sizePolicy().hasHeightForWidth());
        choiceA->setSizePolicy(sizePolicy);
        choiceA->setMinimumSize(QSize(300, 80));
        choiceA->setFont(font1);
        choiceA->setReadOnly(false);

        horizontalLayout->addWidget(choiceA);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setStyleSheet(QStringLiteral("font: 75 14pt \"Arial\";"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        choiceB = new QTextEdit(groupBox);
        choiceB->setObjectName(QStringLiteral("choiceB"));
        sizePolicy.setHeightForWidth(choiceB->sizePolicy().hasHeightForWidth());
        choiceB->setSizePolicy(sizePolicy);
        choiceB->setMinimumSize(QSize(300, 80));
        choiceB->setFont(font1);
        choiceB->setReadOnly(false);

        horizontalLayout_3->addWidget(choiceB);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 4);

        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setStyleSheet(QStringLiteral("font: 75 14pt \"Arial\";"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_5);

        choiceC = new QTextEdit(groupBox);
        choiceC->setObjectName(QStringLiteral("choiceC"));
        sizePolicy.setHeightForWidth(choiceC->sizePolicy().hasHeightForWidth());
        choiceC->setSizePolicy(sizePolicy);
        choiceC->setMinimumSize(QSize(300, 80));
        choiceC->setFont(font1);
        choiceC->setReadOnly(false);

        horizontalLayout_4->addWidget(choiceC);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 4);

        horizontalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setStyleSheet(QStringLiteral("font: 75 14pt \"Arial\";"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_6);

        choiceD = new QTextEdit(groupBox);
        choiceD->setObjectName(QStringLiteral("choiceD"));
        sizePolicy.setHeightForWidth(choiceD->sizePolicy().hasHeightForWidth());
        choiceD->setSizePolicy(sizePolicy);
        choiceD->setMinimumSize(QSize(300, 80));
        choiceD->setFont(font1);
        choiceD->setReadOnly(false);

        horizontalLayout_5->addWidget(choiceD);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 4);

        horizontalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout_11->addLayout(verticalLayout);


        verticalLayout_3->addWidget(groupBox);


        retranslateUi(AddMultiChoice);

        QMetaObject::connectSlotsByName(AddMultiChoice);
    } // setupUi

    void retranslateUi(QDialog *AddMultiChoice)
    {
        AddMultiChoice->setWindowTitle(QApplication::translate("AddMultiChoice", "\346\267\273\345\212\240\345\244\232\351\200\211\351\242\230", nullptr));
        groupBox_2->setTitle(QApplication::translate("AddMultiChoice", "\350\257\225\351\242\230\346\217\217\350\277\260", nullptr));
        description->setHtml(QApplication::translate("AddMultiChoice", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        description->setPlaceholderText(QApplication::translate("AddMultiChoice", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\242\230\347\233\256\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207300\345\255\227\357\274\211", nullptr));
        groupBox_3->setTitle(QApplication::translate("AddMultiChoice", "\350\257\225\351\242\230\345\261\236\346\200\247", nullptr));
        label_7->setText(QApplication::translate("AddMultiChoice", "\345\210\206     \345\200\274", nullptr));
        label_8->setText(QApplication::translate("AddMultiChoice", "\347\255\224     \346\241\210", nullptr));
        answerA->setText(QApplication::translate("AddMultiChoice", "A", nullptr));
        answerB->setText(QApplication::translate("AddMultiChoice", "B", nullptr));
        answerC->setText(QApplication::translate("AddMultiChoice", "C", nullptr));
        answerD->setText(QApplication::translate("AddMultiChoice", "D", nullptr));
        submitBtn->setText(QApplication::translate("AddMultiChoice", "\346\217\220  \344\272\244", nullptr));
        resetBtn->setText(QApplication::translate("AddMultiChoice", "\351\207\215  \347\275\256", nullptr));
        groupBox->setTitle(QApplication::translate("AddMultiChoice", "\351\200\211\351\241\271\346\217\217\350\277\260", nullptr));
        label_3->setText(QApplication::translate("AddMultiChoice", "A", nullptr));
        choiceA->setPlaceholderText(QApplication::translate("AddMultiChoice", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\200\211\351\241\271\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207200\345\255\227\357\274\211", nullptr));
        label_4->setText(QApplication::translate("AddMultiChoice", "B", nullptr));
        choiceB->setPlaceholderText(QApplication::translate("AddMultiChoice", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\200\211\351\241\271\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207200\345\255\227\357\274\211", nullptr));
        label_5->setText(QApplication::translate("AddMultiChoice", "C", nullptr));
        choiceC->setPlaceholderText(QApplication::translate("AddMultiChoice", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\200\211\351\241\271\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207200\345\255\227\357\274\211", nullptr));
        label_6->setText(QApplication::translate("AddMultiChoice", "D", nullptr));
        choiceD->setPlaceholderText(QApplication::translate("AddMultiChoice", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\200\211\351\241\271\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207200\345\255\227\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddMultiChoice: public Ui_AddMultiChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMULTICHOICE_H
