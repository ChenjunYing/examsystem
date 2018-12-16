#pragma once

#include <QList>
#include <QDialog>
#include <QTabWidget>
#include <QStandardItem>
#include <QStandardItemModel>
#include "ui_QuestionBank.h"
#include "Question.h"

class QuestionBank : public QDialog {
	Q_OBJECT

public:
	QuestionBank(QWidget *parent = Q_NULLPTR);
	~QuestionBank();

private slots:
	/**
	  * @author:应承峻
	  * @brief:将单选题在题库上显示出来
	  * @date:2018/12/15
	  * @version:1.0
	  */
	void showChoice();
	/**
	  * @author:应承峻
	  * @brief:将多选题在题库上显示出来
	  * @date:2018/12/15
	  * @version:1.0
	  */
	void showMultichoice();
	/**
	  * @author:应承峻
	  * @brief:将判断题在题库上显示出来
	  * @date:2018/12/15
	  * @version:1.0
	  */
	void showJudge();

private:
	Ui::QuestionBank ui;
	QList<Choice> choice;
	QList<Choice> multichoice;
	QList<Judge> judge;
	QStandardItemModel* choicemodel;
	QStandardItemModel* multimodel;
	QStandardItemModel* judgemodel;
};
