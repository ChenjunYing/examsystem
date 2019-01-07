#ifndef _ADMINMODEL_H
#define _ADMINMODEL_H
#include <QList>
#include <QtSql>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include "Exam.h"
#include "User.h"

class AdminModel {

public:
	AdminModel();
	~AdminModel();
	int isOpen();
	QList<Exam> searchExam();
	bool deleteExam(int code);

private:
	int openstatus;
	QSqlDatabase db;

};


#endif