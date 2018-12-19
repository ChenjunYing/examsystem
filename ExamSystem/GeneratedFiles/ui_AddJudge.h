/********************************************************************************
** Form generated from reading UI file 'AddJudge.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDJUDGE_H
#define UI_ADDJUDGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddJudge
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *Descriptions;
    QLabel *label_2;
    QTextEdit *description;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *score;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *right;
    QRadioButton *wrong;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *submitBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *resetBtn;

    void setupUi(QDialog *AddJudge)
    {
        if (AddJudge->objectName().isEmpty())
            AddJudge->setObjectName(QStringLiteral("AddJudge"));
        AddJudge->resize(480, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddJudge->sizePolicy().hasHeightForWidth());
        AddJudge->setSizePolicy(sizePolicy);
        AddJudge->setMinimumSize(QSize(480, 500));
        AddJudge->setMaximumSize(QSize(480, 500));
        AddJudge->setSizeGripEnabled(false);
        AddJudge->setModal(false);
        layoutWidget = new QWidget(AddJudge);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 40, 371, 421));
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
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        Descriptions->addWidget(label_2);

        description = new QTextEdit(layoutWidget);
        description->setObjectName(QStringLiteral("description"));
        sizePolicy1.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy1);
        description->setMinimumSize(QSize(300, 100));
        description->setMaximumSize(QSize(300, 100));
        description->setReadOnly(false);

        Descriptions->addWidget(description);


        verticalLayout->addLayout(Descriptions);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setStyleSheet(QStringLiteral(""));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_7);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        score = new QSpinBox(layoutWidget);
        score->setObjectName(QStringLiteral("score"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(score->sizePolicy().hasHeightForWidth());
        score->setSizePolicy(sizePolicy3);
        score->setMaximum(100);

        horizontalLayout->addWidget(score);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(2, 6);
        horizontalLayout->setStretch(3, 8);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(label_8);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        right = new QRadioButton(layoutWidget);
        right->setObjectName(QStringLiteral("right"));

        horizontalLayout_3->addWidget(right);

        wrong = new QRadioButton(layoutWidget);
        wrong->setObjectName(QStringLiteral("wrong"));

        horizontalLayout_3->addWidget(wrong);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(4, 4);

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


        retranslateUi(AddJudge);

        QMetaObject::connectSlotsByName(AddJudge);
    } // setupUi

    void retranslateUi(QDialog *AddJudge)
    {
        AddJudge->setWindowTitle(QApplication::translate("AddJudge", "\346\267\273\345\212\240\345\215\225\351\200\211\351\242\230", nullptr));
        label->setText(QApplication::translate("AddJudge", "\346\267\273\345\212\240\345\210\244\346\226\255\351\242\230", nullptr));
        label_2->setText(QApplication::translate("AddJudge", "\351\242\230\347\233\256\346\217\217\350\277\260", nullptr));
        description->setHtml(QApplication::translate("AddJudge", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        description->setPlaceholderText(QApplication::translate("AddJudge", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\242\230\347\233\256\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207300\345\255\227\357\274\211", nullptr));
        label_7->setText(QApplication::translate("AddJudge", "\345\210\206    \345\200\274", nullptr));
        label_8->setText(QApplication::translate("AddJudge", "\347\255\224    \346\241\210", nullptr));
        right->setText(QApplication::translate("AddJudge", "\346\255\243\347\241\256", nullptr));
        wrong->setText(QApplication::translate("AddJudge", "\351\224\231\350\257\257", nullptr));
        submitBtn->setText(QApplication::translate("AddJudge", "\346\217\220   \344\272\244", nullptr));
        resetBtn->setText(QApplication::translate("AddJudge", "\351\207\215    \347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddJudge: public Ui_AddJudge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDJUDGE_H
