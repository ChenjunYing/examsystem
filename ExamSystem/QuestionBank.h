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

private slots:
	/**
	  * @author:Ӧ�о�
	  * @brief:����ѡ�����������ʾ����
	  * @date:2018/12/16
	  * @version:2.0
	  */
	void showChoice();

	/**
	  * @author:Ӧ�о�
	  * @brief:����ѡ�����������ʾ����
	  * @date:2018/12/16
	  * @version:2.0
	  */
	void showMultichoice();

	/**
	  * @author:Ӧ�о�
	  * @brief:���ж������������ʾ����
	  * @date:2018/12/16
	  * @version:2.0
	  */
	void showJudge();

	/**
	  * @author:Ӧ�о�
	  * @brief:���ݵ����TabBar��ʾ��Ӧ������,0Ϊ��ѡ��,1Ϊ��ѡ��,2Ϊ�ж���
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void onTabChanged(int index);

	/**
	  * @author:Ӧ�о�
	  * @brief:ʵ�ֵ�ѡ����˫���޸ĵĹ���
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void choiceDoubleClicked();

	/**
	  * @author:Ӧ�о�
	  * @brief:ˢ�µ�ѡ�⡢��ѡ����ж��������
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void dataRefresh();

	/**
	  * @author:Ӧ�о�
	  * @brief:�޸���ɺ���ҳ��ˢ��
	  * @date:2018/12/17
	  * @version:1.0
	  */
	void receiveOK(int index);

	void initStyle();

	void setChoiceTableStyle(QStandardItemModel* model);

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