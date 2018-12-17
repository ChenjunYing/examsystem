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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentWindow
{
public:
    QGraphicsView *graphicsView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabelName_2;
    QLabel *Name_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *LabelId_2;
    QLabel *Id_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *LabelMajor_2;
    QLabel *Major_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *LabelGrade_2;
    QLabel *Grade_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QTableView *examTable;

    void setupUi(QDialog *StudentWindow)
    {
        if (StudentWindow->objectName().isEmpty())
            StudentWindow->setObjectName(QStringLiteral("StudentWindow"));
        StudentWindow->resize(900, 555);
        StudentWindow->setMinimumSize(QSize(900, 555));
        StudentWindow->setMaximumSize(QSize(900, 555));
        graphicsView = new QGraphicsView(StudentWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 171, 211));
        layoutWidget = new QWidget(StudentWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 240, 191, 301));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        LabelName_2 = new QLabel(layoutWidget);
        LabelName_2->setObjectName(QStringLiteral("LabelName_2"));

        horizontalLayout_5->addWidget(LabelName_2);

        Name_2 = new QLabel(layoutWidget);
        Name_2->setObjectName(QStringLiteral("Name_2"));
        Name_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(Name_2);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        LabelId_2 = new QLabel(layoutWidget);
        LabelId_2->setObjectName(QStringLiteral("LabelId_2"));

        horizontalLayout_6->addWidget(LabelId_2);

        Id_2 = new QLabel(layoutWidget);
        Id_2->setObjectName(QStringLiteral("Id_2"));
        Id_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(Id_2);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        LabelMajor_2 = new QLabel(layoutWidget);
        LabelMajor_2->setObjectName(QStringLiteral("LabelMajor_2"));

        horizontalLayout_7->addWidget(LabelMajor_2);

        Major_2 = new QLabel(layoutWidget);
        Major_2->setObjectName(QStringLiteral("Major_2"));
        Major_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(Major_2);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        LabelGrade_2 = new QLabel(layoutWidget);
        LabelGrade_2->setObjectName(QStringLiteral("LabelGrade_2"));

        horizontalLayout_8->addWidget(LabelGrade_2);

        Grade_2 = new QLabel(layoutWidget);
        Grade_2->setObjectName(QStringLiteral("Grade_2"));
        Grade_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(Grade_2);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_8);

        scrollArea = new QScrollArea(StudentWindow);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(210, 20, 661, 521));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 659, 519));
        examTable = new QTableView(scrollAreaWidgetContents_2);
        examTable->setObjectName(QStringLiteral("examTable"));
        examTable->setGeometry(QRect(0, 0, 671, 521));
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        retranslateUi(StudentWindow);

        QMetaObject::connectSlotsByName(StudentWindow);
    } // setupUi

    void retranslateUi(QDialog *StudentWindow)
    {
        StudentWindow->setWindowTitle(QApplication::translate("StudentWindow", "\345\255\246\347\224\237\344\270\273\347\225\214\351\235\242", nullptr));
        LabelName_2->setText(QApplication::translate("StudentWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        Name_2->setText(QApplication::translate("StudentWindow", "\350\212\261\347\224\237\346\262\271", nullptr));
        LabelId_2->setText(QApplication::translate("StudentWindow", "\345\255\246\345\217\267\357\274\232", nullptr));
        Id_2->setText(QApplication::translate("StudentWindow", "3180106666", nullptr));
        LabelMajor_2->setText(QApplication::translate("StudentWindow", "\344\270\223\344\270\232\357\274\232", nullptr));
        Major_2->setText(QApplication::translate("StudentWindow", "\350\206\234\346\263\225\347\247\221\345\255\246\344\270\216\346\212\200\346\234\257", nullptr));
        LabelGrade_2->setText(QApplication::translate("StudentWindow", "\345\271\264\347\272\247\357\274\232", nullptr));
        Grade_2->setText(QApplication::translate("StudentWindow", "\345\244\247\344\270\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentWindow: public Ui_StudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
