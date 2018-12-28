#pragma once

#include <QList>
#include <QDialog>
#include <QVariant> 
#include <QTabWidget>
#include <QModelIndex>
#include <QStandardItem>
#include <QAbstractItemView>
#include <QStandardItemModel>
#include "ui_StudentWindow.h"
#include "User.h"
#include <QList>
#include <QFile>
#include <QDialog>
#include <QVariant> 
#include <QTabWidget>
#include <QTableView>
#include <QHeaderView>
#include <QModelIndex>
#include <QStandardItem>
#include <QAbstractItemView>
#include <QStandardItemModel>
#include "Question.h"
#include "StudentExam.h"

class StudentWindow : public QDialog
{
	Q_OBJECT

public:
	friend class LoginDialog;

	StudentWindow(QWidget *parent = Q_NULLPTR);
	~StudentWindow();

	void showExam();
	
	void dataGet();

	void showStudent(QString username);

signals: void sendExamInformation(QString , int);

public slots:
	void receiveUserName(QString name);

private slots:
	void examTableClicked(const QModelIndex&);

private:
	Ui::StudentWindow ui;
	QList<Config> exam;
	QString userName;
	QStandardItemModel* examModel;
	StudentExam newExam;
};
