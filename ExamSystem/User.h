#ifndef _USER_H
#define _USER_H
#include<QString>

/*
 * Student���װ��ѧ���������Ϣ�Լ�����
 */
class Student{

public:
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
#endif