#ifndef _STUDENTEXAMMODEL_H
#define _STUDENTEXAMMODEL_H

#include <QtSql>
#include <QList>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include "Question.h"
#include "User.h"
#include "Exam.h"

class StudentExamModel {

public:
	StudentExamModel();
	~StudentExamModel();
	int isOpen();
	int submit(QString username , QList<Choice> choiceAns , QList<Choice> multichoiceAns , 
		QList<Judge> judgeAns , int examCode , int objectScore , int multiScore , int judgeScore);
	QList<Choice> searchChoice(int type,int examCode);
	QList<Judge> searchJudge(int examCode);
	Exam getInformation(int examCode);
	
private:
	int openstatus;
	QSqlDatabase db;
};

#endif