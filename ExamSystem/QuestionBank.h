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

/**
  * @author:应承峻
  * @brief:向修改单选题页面发送单选题的数据
  * @date:2018/12/16
  * @version:1.0
  */
signals: void sendChoiceData(Choice c);

private slots:

	void showChoice();

	void showMultichoice();

	void showJudge();

	void onTabChanged(int index);

	void choiceClicked(const QModelIndex& index);

	void choiceDoubleClicked(const QModelIndex& index);

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