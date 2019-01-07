#include "User.h"

Student::Student(QString username , QString password , QString phonenumber , 
	QString name , QString major , QString id , int sex) {
	this->username = username;
	this->password = password;
	this->phonenumber = phonenumber;
	this->name = name;
	this->major = major;
	this->id = id;
	this->sex = sex;
}


Student::~Student() {

}

int Student::getSex() const {
	return sex;
}

QString Student::getUsername() const {
	return username;
}

QString Student::getPassword() const {
	return password;
}

QString Student::getPhonenumber() const {
	return phonenumber;
}

QString Student::getName() const {
	return name;
}

QString Student::getMajor() const {
	return major;
}

QString Student::getId() const {
	return id;
}

