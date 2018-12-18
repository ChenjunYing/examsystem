#include "User.h"

Student::Student(QString name, QString major, QString id) :name(name), major(major), id(id)
{
}

Student::~Student()
{
}

QString Student::getName() const
{
	return name;
}

QString Student::getMajor() const
{
	return major;
}

QString Student::getId() const
{
	return id;
}

