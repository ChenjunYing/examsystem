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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddJudge
{
public:
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *description;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QSpinBox *score;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QRadioButton *right;
    QRadioButton *wrong;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *submitBtn;
    QPushButton *resetBtn;

    void setupUi(QDialog *AddJudge)
    {
        if (AddJudge->objectName().isEmpty())
            AddJudge->setObjectName(QStringLiteral("AddJudge"));
        AddJudge->resize(680, 200);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddJudge->sizePolicy().hasHeightForWidth());
        AddJudge->setSizePolicy(sizePolicy);
        AddJudge->setMinimumSize(QSize(680, 200));
        AddJudge->setSizeGripEnabled(false);
        AddJudge->setModal(false);
        horizontalLayout_5 = new QHBoxLayout(AddJudge);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox = new QGroupBox(AddJudge);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        groupBox->setFont(font);
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        description = new QTextEdit(groupBox);
        description->setObjectName(QStringLiteral("description"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy1);
        description->setMinimumSize(QSize(300, 100));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        description->setFont(font1);
        description->setReadOnly(false);

        horizontalLayout_4->addWidget(description);


        horizontalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(AddJudge);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setFont(font1);
        label_7->setStyleSheet(QStringLiteral(""));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_7);

        score = new QSpinBox(groupBox_2);
        score->setObjectName(QStringLiteral("score"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(score->sizePolicy().hasHeightForWidth());
        score->setSizePolicy(sizePolicy3);
        score->setFont(font1);
        score->setMaximum(100);

        horizontalLayout->addWidget(score);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);
        label_8->setFont(font1);

        horizontalLayout_3->addWidget(label_8);

        right = new QRadioButton(groupBox_2);
        right->setObjectName(QStringLiteral("right"));
        right->setFont(font1);

        horizontalLayout_3->addWidget(right);

        wrong = new QRadioButton(groupBox_2);
        wrong->setObjectName(QStringLiteral("wrong"));
        wrong->setFont(font1);

        horizontalLayout_3->addWidget(wrong);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        submitBtn = new QPushButton(groupBox_2);
        submitBtn->setObjectName(QStringLiteral("submitBtn"));
        submitBtn->setFont(font1);

        horizontalLayout_2->addWidget(submitBtn);

        resetBtn = new QPushButton(groupBox_2);
        resetBtn->setObjectName(QStringLiteral("resetBtn"));
        resetBtn->setFont(font1);

        horizontalLayout_2->addWidget(resetBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_5->addWidget(groupBox_2);


        retranslateUi(AddJudge);

        QMetaObject::connectSlotsByName(AddJudge);
    } // setupUi

    void retranslateUi(QDialog *AddJudge)
    {
        AddJudge->setWindowTitle(QApplication::translate("AddJudge", "\346\267\273\345\212\240\345\210\244\346\226\255\351\242\230", nullptr));
        groupBox->setTitle(QApplication::translate("AddJudge", "\350\257\225\351\242\230\346\217\217\350\277\260", nullptr));
        description->setHtml(QApplication::translate("AddJudge", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p></body></html>", nullptr));
        description->setPlaceholderText(QApplication::translate("AddJudge", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\351\242\230\347\233\256\346\217\217\350\277\260\357\274\210\344\270\215\350\266\205\350\277\207300\345\255\227\357\274\211", nullptr));
        groupBox_2->setTitle(QApplication::translate("AddJudge", "\350\257\225\351\242\230\345\261\236\346\200\247", nullptr));
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
