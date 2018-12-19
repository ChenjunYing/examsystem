#pragma once

#include <QDialog>
#include "ui_AddJudge.h"
#include "Question.h"
#include <QString>
#include <QDebug>
#include <QMessagebox>

class AddJudge : public QDialog
{
	Q_OBJECT

public:
	AddJudge(QWidget *parent = Q_NULLPTR);
	~AddJudge();
	friend class QuestionBank;

/**
  * @author:黄思泳
  * @brief:向MainWindow页面发送修改页面的指针以便其进行信号与槽的绑定
  * @date:2018/12/19
  * @version:1.0
  */
signals: void updateOK(int);
/**
  * @author:黄思泳
  * @brief:向MainWindow页面发送修改页面的指针以便其进行信号与槽的绑定
  * @date:2018/12/19
  * @version:1.0
  */
signals: void sendJudgePage(AddJudge*);

private slots:
	/**
      * @author:黄思泳
      * @brief:判断添加判断题输入的合法性,若合法则执行插入操作,否则弹出非法操作对话框
      * @date:2018/12/19
      * @version:1.0
      */
	void checkData();

	/**
	  * @author:黄思泳
	  * @brief:判断修改判断题输入的合法性,若合法则执行修改操作,否则弹出非法操作对话框
	  * @date:2018/12/19
	  * @version:1.0
	 */
	void checkUpdateData();

	/**
	  * @author:黄思泳
	  * @brief:判断添加判断题输入的合法性,若合法则执行插入操作,否则弹出非法操作对话框
	  * @date:2018/12/19
	  * @note:定义了重载函数,用于区分修改和删除操作
	  * @version:1.0
	  */
	void resetData();

	/**
	   * @author:黄思泳
	   * @brief:将每个选项是否选为答案的bool数组转换为字符串
	   * @param [in] 输入参数1: 长度为4的bool数组
	   * @param [out] 输出参数: 返回选为答案的字符串
	   * @date:2018/12/18
	   * @version:1.0
	   */
	QString convertAnswer(bool *answer);

	/**
	  * @author:黄思泳
	  * @brief:接收发送过来的选中判断题的相应数据并显示
	  * @date:2018/12/18
	  * @version:1.0
	  */
	void receiveData(Judge c);

private:
	Ui::AddJudge ui;
	int tempQuestionId;
};
