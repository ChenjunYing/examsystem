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
	  * @author:Ӧ�о�
	  * @brief:����ѡ�����������ʾ����
	  * @date:2018/12/15
	  * @version:1.0
	  */
	void showChoice();
	/**
	  * @author:Ӧ�о�
	  * @brief:����ѡ�����������ʾ����
	  * @date:2018/12/15
	  * @version:1.0
	  */
	void showMultichoice();
	/**
	  * @author:Ӧ�о�
	  * @brief:���ж������������ʾ����
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
