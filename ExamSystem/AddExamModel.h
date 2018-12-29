#ifndef _ADDEXAMMODEL_H
#define _ADDEXAMMODEL_H

#include <QtSql>
#include <QList>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QMessageBox>

class AddExamModel {

public:
	AddExamModel();
	int isOpen();
	~AddExamModel();

private:
	int openstatus;
	QSqlDatabase db;


};

#endif