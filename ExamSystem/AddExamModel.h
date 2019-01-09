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
#include "User.h"
#include "Exam.h"

class AddExamModel {

public:
	AddExamModel();
	~AddExamModel();
	int isOpen();
	bool AddExamModel::insertExam(QString examName, int examTime, QString examInformation);
	int AddExamModel::searchExam(QString examName);
	bool AddExamModel::insertChoice(int examCode, int questionId);
	bool AddExamModel::insertJudge(int examCode, int questionId);
	void AddExamModel::insertStudent(int examCode);
	bool AddExamModel::modifyExam(QString examName, int examTime, QString examInformation,int examCode);
	QList<int> AddExamModel::searchChosenChoice(int examCode, int type);
	QList<int> AddExamModel::searchChosenJudge(int examCode);
	Exam searchExam(int examCode);
private:
	int openstatus;
	QSqlDatabase db;

};

#endif