#pragma once
#include<QString>

/*
 * Student类封装了学生的相关信息以及操作
 */
class Student{
public:
	Student(QString name, QString major, QString id);
	~Student();
	QString getName() const;
	QString getMajor() const;
	QString getId() const;
private:
	QString name;
	QString major;
	QString id;
	Student();
};