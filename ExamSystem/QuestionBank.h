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
  * @author:Ӧ�о�
  * @brief:���޸ĵ�ѡ��ҳ�淢�͵�ѡ�������
  * @date:2018/12/16
  * @version:1.0
  */
signals: void sendChoiceData(Choice c);

/**
  * @author:��˼Ӿ
  * @brief:���޸Ķ�ѡ��ҳ�淢�Ͷ�ѡ�������
  * @date:2018/12/16
  * @version:1.0
  */
signals: void sendMultiChoiceData(Choice c);

/**
  * @author:��˼Ӿ
  * @brief:���޸��ж���ҳ�淢�Ͷ�ѡ�������
  * @date:2018/12/16
  * @version:1.0
  */
signals: void sendJudgeData(Judge c);

private slots:

	void showChoice();

	void showMultichoice();

	void showJudge();

	void onTabChanged(int index);

	void choiceClicked(const QModelIndex& index);

	void choiceDoubleClicked(const QModelIndex& index);

	/**
      * @author:��˼Ӿ
      * @brief:ʵ�ֶ�ѡ����˫���޸ĵĹ���
      * @date:2018/12/18
      * @version:1.0
      */
	void multiDoubleClicked(const QModelIndex&);

	void multiClicked(const QModelIndex& index);

	/**
	  * @author:��˼Ӿ
	  * @brief:ʵ���ж�����˫���޸ĵĹ���
	  * @date:2018/12/18
	  * @version:1.0
	  */
	void judgeDoubleClicked(const QModelIndex&);

	void judgeClicked(const QModelIndex& index);

	/**
	  * @author:Ӧ�о�
	  * @brief:ˢ�µ�ѡ�⡢��ѡ����ж��������
	  * @date:2018/12/16
	  * @version:1.0
	  */
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