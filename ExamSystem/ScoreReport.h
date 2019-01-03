#pragma once

#include <QList>
#include <QFile>
#include <QDialog>
#include <QVariant> 
#include <QTabWidget>
#include <QTableView>
#include <QHeaderView>
#include <QModelIndex>
#include <QStandardItem>
#include <QAbstractItemView>
#include <QStandardItemModel>
#include "ui_ScoreReport.h"
#include "Question.h"

class ScoreReport : public QDialog
{
	Q_OBJECT

public:
	ScoreReport(QWidget *parent = Q_NULLPTR);
	~ScoreReport();
	void showScore();
	void scoreGet();
	void setScoreTableHeader();
	void setScoreModelItemView();
private slots:
	void receiveCode(int code);

private:
	Ui::ScoreReport ui;
	QList<Score> score;
	QStandardItemModel* scoreModel;
	int code;
};
