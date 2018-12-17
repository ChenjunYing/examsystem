#ifndef _ADDCHOICE_H
#define _ADDCHOICE_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QMessagebox>
#include "ui_AddChoice.h"
#include "Question.h"

class AddChoice : public QDialog {

	Q_OBJECT

public:
	AddChoice(QWidget *parent = Q_NULLPTR);
	~AddChoice();
	friend class QuestionBank;

/**
  * @author:应承峻
  * @brief:单选题更新完成后，向QuestionBank页面发出更新完成信号
  * @date:2018/12/17
  * @version:1.0
  */
signals: void updateOK(int);
/**
  * @author:应承峻
  * @brief:向MainWindow页面发送修改页面的指针以便其进行信号与槽的绑定
  * @date:2018/12/17
  * @version:1.0
  */
signals: void sendChoicePage(AddChoice*);

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
	  * @brief:判断修改单选题输入的合法性,若合法则执行修改操作,否则弹出非法操作对话框
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void checkUpdateData();

	/**
	  * @author:应承峻
	  * @brief:判断添加单选题输入的合法性,若合法则执行插入操作,否则弹出非法操作对话框
	  * @date:2018/12/16
	  * @note:定义了重载函数,用于区分修改和删除操作
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

	/**
	  * @author:应承峻
	  * @brief:接收发送过来的选中单选题的相应数据并显示
	  * @date:2018/12/17
	  * @version:2.0
	  */
	void receiveData(Choice c);

private:
	Ui::AddChoice ui;
	int tempQuestionId;
};

#endif