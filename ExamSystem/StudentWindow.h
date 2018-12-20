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
#include "Question.h"

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
public slots:
	
	void receiveUserName(QString name);

private:
	Ui::StudentWindow ui;
	QList<Exam> exam;
	QString userName;
	QStandardItemModel* examModel;
};
