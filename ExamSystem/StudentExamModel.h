#pragma once
#include <QtSql>
#include <QList>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include "Question.h"
#include "User.h"
#include "Exam.h"

/**
  * @brief 该类封装了考试界面中对数据库的相关操作
  * @author 陈欢
  */

class StudentExamModel {

public:
	StudentExamModel();
	/**
  * @author:应承峻
  * @brief:提供获得openstatus属性值的接口
  * @param [out] 输出参数: 返回penstatus属性值
  * @date:2018/12/13
  * @version:1.0
  * @引用SqlModel
  */
	int isOpen();

	/**
  * @author:陈欢
  * @brief:查询该试卷相应的选择题（包括多选以及单选题）
  * @param [in] 输入参数1: 选择题类型
  * @param [in] 输入参数2: 试卷编号
  * @param [out] 输出参数: Choice类的一个对象集合
  * @date:2018/12/24
  * @version:1.0
  */
	QList<Choice> searchChoice(int type,int examCode);

	/**
* @author:陈欢
* @brief:查询该试卷相应的判断题
* @param [in] 输入参数1: 试卷编号
* @param [out] 输出参数: Judge类的一个对象集合
* @date:2018/12/24
* @version:1.0
*/
	QList<Judge> searchJudge(int examCode);

	/**
* @author:陈欢
* @brief:提交答案，插入回答库，更新config库
* @param [in] 输入参数1~3: 单选题、多选题、判断题的对象集合
* @param [in] 输入参数4: 试卷编号
* @param [in] 输入参数5~6: 选择题、判断题分数
* @param [out] 输出参数: 判断提交是否成功，成功返回1，失败返回0
* @date:2018/12/24
* @version:1.0
*/
	int submit(QList<Choice> choiceAns, QList<Choice> multichoiceAns, QList<Judge> judgeAns,int examCode,int objectScore,int multiScore,int judgeScore);

	/**
* @author:陈欢
* @brief:查找当前试卷信息
* @param [in] 输入参数1: 试卷代号
* @param [out] 输出参数: 返回Exam类 存放试卷信息
* @date:2019/1/2
* @version:1.0
*/
	Exam getInformation(int examCode);
	~StudentExamModel();

private:
	int openstatus;
	QSqlDatabase db;
};