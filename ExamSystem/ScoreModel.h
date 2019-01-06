#pragma once

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

class ScoreModel {

public:
	ScoreModel();
	~ScoreModel();
	int isOpen();
	QList<Score> searchScore(int code);
	QList<Details> searchDetails(int code, QString name);

private:
	int openstatus;
	QSqlDatabase db;

};

