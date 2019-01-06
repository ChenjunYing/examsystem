#ifndef _DETAILEDSCORE_H
#define _DETAILEDSCORE_H

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

class DetailedScore : public QDialog {
	
	Q_OBJECT

public:
	DetailedScore(QWidget *parent = Q_NULLPTR);
	~DetailedScore();
	void showDetails();
	void setDetailsTableHeader();
	void setDetailModelItemView();
	void dataGet();
	friend class ScoreReport;

private slots:
	void receiveName(QString name);

private:
	Ui::DetailedScore ui;
	int code;
	QString userName;
	QList<Details> details;
	QStandardItemModel* detailModel;

};

#endif
