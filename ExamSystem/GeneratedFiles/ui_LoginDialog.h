/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *radio_user;
    QRadioButton *radio_admin;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *submitBtn;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->setWindowModality(Qt::NonModal);
        LoginDialog->setEnabled(true);
        LoginDialog->resize(500, 360);
        LoginDialog->setMinimumSize(QSize(500, 360));
        LoginDialog->setMaximumSize(QSize(500, 360));
        LoginDialog->setAcceptDrops(true);
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 30, 264, 43));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(26);
        label->setFont(font);
        layoutWidget = new QWidget(LoginDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 90, 341, 231));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        username = new QLineEdit(layoutWidget);
        username->setObjectName(QStringLiteral("username"));
        username->setMaxLength(20);
        username->setClearButtonEnabled(true);

        horizontalLayout->addWidget(username);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        password = new QLineEdit(layoutWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setMaxLength(20);
        password->setEchoMode(QLineEdit::Password);
        password->setCursorMoveStyle(Qt::LogicalMoveStyle);
        password->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(password);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        radio_user = new QRadioButton(layoutWidget);
        buttonGroup = new QButtonGroup(LoginDialog);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radio_user);
        radio_user->setObjectName(QStringLiteral("radio_user"));
        radio_user->setChecked(true);

        horizontalLayout_3->addWidget(radio_user);

        radio_admin = new QRadioButton(layoutWidget);
        buttonGroup->addButton(radio_admin);
        radio_admin->setObjectName(QStringLiteral("radio_admin"));

        horizontalLayout_3->addWidget(radio_admin);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 4);
        horizontalLayout_3->setStretch(3, 4);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        submitBtn = new QPushButton(layoutWidget);
        submitBtn->setObjectName(QStringLiteral("submitBtn"));

        horizontalLayout_4->addWidget(submitBtn);

        horizontalLayout_4->setStretch(0, 4);

        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("LoginDialog", "\345\255\246\347\224\237\350\200\203\350\257\225\347\263\273\347\273\237", nullptr));
        label_2->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        username->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QApplication::translate("LoginDialog", "\345\257\206  \347\240\201", nullptr));
        password->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_4->setText(QApplication::translate("LoginDialog", "\346\235\203  \351\231\220", nullptr));
        radio_user->setText(QApplication::translate("LoginDialog", "\346\231\256\351\200\232\347\224\250\346\210\267", nullptr));
        radio_admin->setText(QApplication::translate("LoginDialog", "\347\256\241\347\220\206\345\221\230", nullptr));
        submitBtn->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
