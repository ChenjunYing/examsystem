#pragma once

#include <QDialog>
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
#include "ui_DetailedScore.h"
#include "Question.h"

class DetailedScore : public QDialog
{
	Q_OBJECT

public:
	friend class ScoreReport;
	DetailedScore(QWidget *parent = Q_NULLPTR);
	~DetailedScore();
	void showDetails();
	void setDetailsTableHeader();
	void setDetailModelItemView();
	void dataGet();
private slots:
	void receiveName(QString name);

private:
	Ui::DetailedScore ui;
	QList<Details> details;
	QStandardItemModel* detailModel;
	int code;
	QString userName;
};
