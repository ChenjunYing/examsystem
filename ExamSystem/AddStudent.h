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

signals:void userUpdateOk();

private slots:
	void regist();
	void reset();
	void check();
	void update();
	int checkdata();
	int checkdata(int);
	friend class StudentInfo;

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