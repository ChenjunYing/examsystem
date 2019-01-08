#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>
#include <QString>
#include "User.h"
#include "SqlModel.h"
#include "ui_AddStudent.h"

class AddStudent : public QDialog {

	Q_OBJECT

public:
	AddStudent(QWidget *parent = Q_NULLPTR);
	~AddStudent();

private slots:
	void regist();
	void reset();
	void check();
	int checkdata();

private:
	Ui::AddStudent ui;
	int sex = 0;
	SqlModel sql;
	QString username;
	QString password;
	QString name;
	QString id;
	QString major;
	QString phonenumber;
};

#endif