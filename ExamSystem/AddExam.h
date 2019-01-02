#ifndef _ADDEXAM_H
#define _ADDEXAM_H

#include <QList>
#include <QWidget>
#include <QCombobox>
#include <QTableView>
#include <QHeaderView>
#include <QModelIndex>
#include <QAbstractItemView>
#include <QStandardItemModel>
#include "ui_AddExam.h"
#include "SqlModel.h"
#include "Question.h"
#include "AddExamModel.h"

class AddExam : public QWidget {
	
	Q_OBJECT

public:
	AddExam(QWidget *parent = Q_NULLPTR);
	void refreshQuestionBank();
	void refreshComboBox();
	~AddExam();
	void setChoiceModelItemView(QStandardItemModel* model, QList<Choice>& choiceQuestionBank, QList<int> chosenChoice);
	void setMultiModelItemView(QStandardItemModel* model, QList<Choice>& multiQuestionBank, QList<int> chosenMulti);
	void setJudgeModelItemView(QStandardItemModel* model, QList<Judge>& judgeQuestionBank, QList<int> chosenJudge);
	void showChoice();
	void showMulti();
	void showJudge();
	void setTableHeader(QStandardItemModel* model);
private slots:
	void addQuestion();
	void choiceClicked(const QModelIndex& index);
	void multiClicked(const QModelIndex& index);
	void judgeClicked(const QModelIndex& index);
	void NewExam();

private:
	Ui::AddExam ui;
	QList<Choice> choiceQuestionBank;
	QList<Choice> multiQuestionBank;
	QList<Judge> judgeQuestionBank;
	QList<int> chosenChoice;
	QList<int> chosenMulti;
	QList<int> chosenJudge;
	QStandardItemModel* examchoicemodel;
	QStandardItemModel* exammultimodel;
	QStandardItemModel* examjudgemodel;
};

#endif