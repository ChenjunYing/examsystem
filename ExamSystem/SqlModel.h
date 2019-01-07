#ifndef _SQLMODEL_H
#define _SQLMODEL_H
 
/** 
  * @brief 该类封装了用于对数据库的相关操作
  * @author 应承峻
  */
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

class SqlModel {

public:
	SqlModel();
	~SqlModel();
	int isOpen();
	bool insertChoice(QString description , QString choiceA , QString choiceB , 
		QString choiceC , QString choiceD , QString answer , int value);
	bool insertMultiChoice(QString description, QString choiceA, QString choiceB,
		QString choiceC, QString choiceD, QString answer, int value);
	bool insertJudge(QString description, QString answer, int value);
	bool updateChoice(QString description , QString choiceA , QString choiceB ,
		QString choiceC , QString choiceD , QString answer , int value , int questionId);
	bool deleteChoice(int questionId);
	bool deleteJudge(int questionId);
	bool updateMultiChoice(QString description, QString choiceA, QString choiceB,
		QString choiceC, QString choiceD, QString answer, int value, int questionId);
	bool updateJudge(QString description, QString answer, int value, int questionId);	
	QList<Choice> searchChoice(int type);
	QList<Choice> searchChoice(int type , QString keyWord , int lowerValue , int upperValue , QString author);
	QList<Judge> searchJudge();
	QList<Judge> searchJudge(QString keyWord , int lowerValue , int upperValue , QString author);
	QList<Config> searchExam(QString username);
	QList<Student> searchStudent();
	Student searchStudentInfo(QString username);
	QSqlQuery check(QString username , QString password , QString identity);
	
private:
	int openstatus;
	QSqlDatabase db;

};

#endif