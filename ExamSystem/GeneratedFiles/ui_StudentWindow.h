/********************************************************************************
** Form generated from reading UI file 'StudentWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTWINDOW_H
#define UI_STUDENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentWindow
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QTableView *examTable;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabelName;
    QLabel *Name;
    QHBoxLayout *horizontalLayout_6;
    QLabel *LabelId;
    QLabel *Id;
    QHBoxLayout *horizontalLayout_7;
    QLabel *LabelMajor;
    QLabel *Major;
    QPushButton *btnLogout;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *StudentWindow)
    {
        if (StudentWindow->objectName().isEmpty())
            StudentWindow->setObjectName(QStringLiteral("StudentWindow"));
        StudentWindow->resize(950, 450);
        StudentWindow->setMinimumSize(QSize(950, 450));
        StudentWindow->setMaximumSize(QSize(950, 450));
        scrollArea = new QScrollArea(StudentWindow);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(210, 9, 721, 430));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 719, 428));
        examTable = new QTableView(scrollAreaWidgetContents_2);
        examTable->setObjectName(QStringLiteral("examTable"));
        examTable->setGeometry(QRect(0, 0, 721, 430));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(examTable->sizePolicy().hasHeightForWidth());
        examTable->setSizePolicy(sizePolicy);
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        layoutWidget = new QWidget(StudentWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 229, 181, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        LabelName = new QLabel(layoutWidget);
        LabelName->setObjectName(QStringLiteral("LabelName"));

        horizontalLayout_5->addWidget(LabelName);

        Name = new QLabel(layoutWidget);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(Name);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        LabelId = new QLabel(layoutWidget);
        LabelId->setObjectName(QStringLiteral("LabelId"));

        horizontalLayout_6->addWidget(LabelId);

        Id = new QLabel(layoutWidget);
        Id->setObjectName(QStringLiteral("Id"));
        Id->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(Id);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        LabelMajor = new QLabel(layoutWidget);
        LabelMajor->setObjectName(QStringLiteral("LabelMajor"));

        horizontalLayout_7->addWidget(LabelMajor);

        Major = new QLabel(layoutWidget);
        Major->setObjectName(QStringLiteral("Major"));
        Major->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(Major);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_7);

        btnLogout = new QPushButton(layoutWidget);
        btnLogout->setObjectName(QStringLiteral("btnLogout"));

        verticalLayout->addWidget(btnLogout);

        graphicsView = new QGraphicsView(StudentWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 183, 211));

        retranslateUi(StudentWindow);

        QMetaObject::connectSlotsByName(StudentWindow);
    } // setupUi

    void retranslateUi(QDialog *StudentWindow)
    {
        StudentWindow->setWindowTitle(QApplication::translate("StudentWindow", "\345\255\246\347\224\237\344\270\273\347\225\214\351\235\242", nullptr));
        LabelName->setText(QApplication::translate("StudentWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        Name->setText(QString());
        LabelId->setText(QApplication::translate("StudentWindow", "\345\255\246\345\217\267\357\274\232", nullptr));
        Id->setText(QString());
        LabelMajor->setText(QApplication::translate("StudentWindow", "\344\270\223\344\270\232\357\274\232", nullptr));
        Major->setText(QString());
        btnLogout->setText(QApplication::translate("StudentWindow", "\346\263\250\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentWindow: public Ui_StudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
