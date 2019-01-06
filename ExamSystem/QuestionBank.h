#ifndef _QUESTIONBANK_H
#define _QUESTIONBANK_H

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
#include "ui_QuestionBank.h"
#include "Question.h"
#include "SqlModel.h"

class QuestionBank : public QDialog {

	Q_OBJECT

public:
	QuestionBank(QWidget *parent = Q_NULLPTR);
	~QuestionBank();

signals: void sendChoiceData(Choice c);
signals: void sendMultiChoiceData(Choice c);
signals: void sendJudgeData(Judge c);

private slots:
	void showChoice();
	void showMultichoice();
	void showJudge();
	void onTabChanged(int index);
	void choiceClicked(const QModelIndex& index);
	void choiceDoubleClicked(const QModelIndex& index);
	void multiDoubleClicked(const QModelIndex& index);
	void multiClicked(const QModelIndex& index);
	void judgeDoubleClicked(const QModelIndex&);
	void judgeClicked(const QModelIndex& index);
	void dataRefresh(QString keyWord = "" , int lowerValue = 0 , int upperValue = 100 , QString author = "");
	void receiveOK(int index);
	void setChoiceTableHeader(QStandardItemModel* model);
	void setJudgeTableHeader(QStandardItemModel* model);
	void setChoiceModelItemView(QStandardItemModel* model , QList<Choice>& choice);
	void setJudgeModelItemView(QStandardItemModel* model , QList<Judge>& judge);
	void searchQuestion();
	void reset();

private:
	Ui::QuestionBank ui;
	QList<Choice> choice;
	QList<Choice> multichoice;
	QList<Judge> judge;
	QStandardItemModel* choicemodel;
	QStandardItemModel* multimodel;
	QStandardItemModel* judgemodel;

};

#endif