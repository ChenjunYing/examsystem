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
#include "DetailedScore.h"

class ScoreReport : public QDialog {

	Q_OBJECT

public:
	ScoreReport(QWidget *parent = Q_NULLPTR);
	~ScoreReport();
	void showScore();
	void scoreGet();
	void setScoreTableHeader();
	void setScoreModelItemView();

signals:
	void sendUserName(QString name);

private slots:
	void receiveCode(int code);
	void detailsRequest(const QModelIndex& index);

private:
	Ui::ScoreReport ui;
	int code;
	QList<Score> score;
	DetailedScore* detailedScore;
	QStandardItemModel* scoreModel;
	

};
