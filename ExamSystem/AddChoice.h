#ifndef _ADDCHOICE_H
#define _ADDCHOICE_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QMessagebox>
#include "ui_AddChoice.h"

class AddChoice : public QDialog{

	Q_OBJECT

public:
	AddChoice(QWidget *parent = Q_NULLPTR);
	~AddChoice();
	friend class QuestionBank;

private slots:
	/**
	  * @author:应承峻
	  * @brief:判断添加单选题输入的合法性,若合法则执行插入操作,否则弹出非法操作对话框
	  * @date:2018/12/14
	  * @version:1.0
	  */
	void checkData();
	/**
	  * @author:应承峻
	  * @brief:重置按钮的功能实现
	  * @date:2018/12/14
	  * @version:1.0
	  */
	void resetData();
	/**
	  * @author:应承峻
	  * @brief:将设定答案中获取的数字下标转换成字符串
	  * @param [in] 输入参数1: 数字下标index
	  * @param [out] 输出参数: 返回相应选项的字符串
	  * @date:2018/12/14
	  * @version:1.0
	  */
	QString convertAnswer(int index);

private:
	Ui::AddChoice ui;
};

#endif