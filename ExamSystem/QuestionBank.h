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
  * @author:应承峻
  * @brief:向修改单选题页面发送单选题的数据
  * @date:2018/12/16
  * @version:1.0
  */
signals: void sendChoiceData(Choice c);

private slots:
	/**
	  * @author:应承峻
	  * @brief:将单选题在题库上显示出来
	  * @date:2018/12/16
	  * @version:2.0
	  */
	void showChoice();

	/**
	  * @author:应承峻
	  * @brief:将多选题在题库上显示出来
	  * @date:2018/12/16
	  * @version:2.0
	  */
	void showMultichoice();

	/**
	  * @author:应承峻
	  * @brief:将判断题在题库上显示出来
	  * @date:2018/12/16
	  * @version:2.0
	  */
	void showJudge();

	/**
	  * @author:应承峻
	  * @brief:根据点击的TabBar显示相应的题型,0为单选题,1为多选题,2为判断题
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void onTabChanged(int index);

	/**
	  * @author:应承峻
	  * @brief:实现单选题表格双击修改的功能
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void choiceDoubleClicked();

	/**
	  * @author:应承峻
	  * @brief:刷新单选题、多选题和判断题的数据
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void dataRefresh();

	/**
	  * @author:应承峻
	  * @brief:修改完成后在页面刷新
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