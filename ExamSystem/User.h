#pragma once
#include<QString>

/*
 * Student类封装了学生的相关信息以及操作
 */
class Student{

public:
	Student(QString name , QString major , QString id);
	Student(QString username , QString password , QString phonenumber , QString name , QString major , QString id , int sex);
	~Student();
	int getSex() const;
	QString getName() const;
	QString getMajor() const;
	QString getId() const;
	QString getUsername() const;
	QString getPassword() const;
	QString getPhonenumber() const;

private:
	int sex;
	QString username;
	QString password;
	QString phonenumber;
	QString name;
	QString major;
	QString id;
	Student();

};