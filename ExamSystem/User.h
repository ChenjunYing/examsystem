#pragma once
#include<QString>

/*
 * Student���װ��ѧ���������Ϣ�Լ�����
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