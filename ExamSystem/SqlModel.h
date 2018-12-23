#ifndef _SQLMODEL_H
#define _SQLMODEL_H
 
/** 
  * @brief 该类封装了用于对数据库的相关操作
  * @author 应承峻
  */
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

class SqlModel {

public:
	SqlModel();

	/**
	  * @author:应承峻
	  * @brief:提供获得openstatus属性值的接口
	  * @param [out] 输出参数: 返回penstatus属性值
	  * @date:2018/12/13
	  * @version:1.0
	  */
	int isOpen();

	/**
	  * @author:应承峻
	  * @brief:将单选题相关信息插入到数据库中
	  * @param [in] 输入参数1: 问题描述description
	  * @param [in] 输入参数2~5: A~D选项的选项描述choiceA~choiceD
	  * @param [in] 输入参数6: 正确答案answer
	  * @param [in] 输入参数7: 试题分值value
	  * @param [out] 输出参数: 返回是否插入成功,若插入成功则返回true否则返回false
	  * @date:2018/12/14
	  * @version:1.0
	  */
	bool insertChoice(QString description , QString choiceA , QString choiceB , 
		QString choiceC , QString choiceD , QString answer , int value);
	
	/**
      * @author:黄思泳
      * @brief:将多选题相关信息插入到数据库中
      * @param [in] 输入参数1: 问题描述description
      * @param [in] 输入参数2~5: A~D选项的选项描述choiceA~choiceD
      * @param [in] 输入参数6: 正确答案answer
      * @param [in] 输入参数7: 试题分值value
      * @param [out] 输出参数: 返回是否插入成功,若插入成功则返回true否则返回false
      * @date:2018/12/18
      * @version:1.0
      */
	bool insertMultiChoice(QString description, QString choiceA, QString choiceB,
		QString choiceC, QString choiceD, QString answer, int value);

	/**
      * @author:黄思泳
      * @brief:将判断题相关信息插入到数据库中
      * @param [in] 输入参数1: 问题描述description
      * @param [in] 输入参数2: 正确答案answer
      * @param [in] 输入参数3: 试题分值value
      * @param [out] 输出参数: 返回是否插入成功,若插入成功则返回true否则返回false
      * @date:2018/12/19
      * @version:1.0
      */
	bool insertJudge(QString description, QString answer, int value);

	/**
	  * @author:应承峻
	  * @brief:修改单选题操作
	  * @param [in] 输入参数1: 问题描述description
	  * @param [in] 输入参数2~5: A~D选项的选项描述choiceA~choiceD
	  * @param [in] 输入参数6: 正确答案answer
	  * @param [in] 输入参数7: 试题分值value
	  * @param [in] 输入参数8: 试题编号questionId
	  * @param [out] 输出参数: 返回是否修改成功,若修改成功则返回true否则返回false
	  * @date:2018/12/17
	  * @version:1.0
	  */	
	bool updateChoice(QString description , QString choiceA , QString choiceB ,
		QString choiceC , QString choiceD , QString answer , int value , int questionId);

	bool deleteChoice(int questionId);
	
	bool deleteJudge(int questionId);
	
	/**
	  * @author:黄思泳
	  * @brief:修改多选题操作
	  * @param [in] 输入参数1: 问题描述description
	  * @param [in] 输入参数2~5: A~D选项的选项描述choiceA~choiceD
	  * @param [in] 输入参数6: 正确答案answer
	  * @param [in] 输入参数7: 试题分值value
	  * @param [in] 输入参数8: 试题编号questionId
	  * @param [out] 输出参数: 返回是否修改成功,若修改成功则返回true否则返回false
	  * @date:2018/12/17
	  * @version:1.0
	  */
	bool updateMultiChoice(QString description, QString choiceA, QString choiceB,
		QString choiceC, QString choiceD, QString answer, int value, int questionId);
	/**
	  * @author:黄思泳
	  * @brief:将判断题相关信息插入到数据库中
	  * @param [in] 输入参数1: 问题描述description
	  * @param [in] 输入参数2: 正确答案answer
	  * @param [in] 输入参数3: 试题分值value
	  * @param [out] 输出参数: 返回是否插入成功,若插入成功则返回true否则返回false
	  * @date:2018/12/19
	  * @version:1.0
	  */
	bool updateJudge(QString description, QString answer, int value, int questionId);

	/**
	  * @author:应承峻
	  * @brief:从数据库中筛选相应的选择题,并返回选择题对象的集合
	  * @param [in] 输入参数:type,其中0表示单选题,1表示多选题
	  * @param [out] 输出参数:Choice类的一个对象集合
	  * @date:2018/12/15
	  * @version:1.0
	  */		
	QList<Choice> searchChoice(int type);

	QList<Choice> searchChoice(int type , QString keyWord , int lowerValue , int upperValue , QString author);
	
	/**
	  * @author:应承峻
	  * @brief:从数据库中筛选相应的判断题,并返回判断题对象的集合
	  * @param [out] 输出参数:Judge类的一个对象集合
	  * @date:2018/12/16
	  * @version:2.0
	  */
	QList<Judge> searchJudge();

	QList<Judge> searchJudge(QString keyWord , int lowerValue , int upperValue , QString author);
	
	/**
	  * @author:夏林轩
	  * @brief:从数据库中筛选与一场考试相应的信息,并返回考试对象的集合
	  * @param [in] 输入参数:username，当前登录用户的用户名
	  * @param [out] 输出参数:Config类的一个对象集合
	  * @date:2018/12/16
	  * @version:1.0
	  */
	QList<Config> searchExam(QString username);

	/**
	  * @author:夏林轩
	  * @brief:根据当前登录的用户的用户名从数据库中进行筛选并返回一个Student类对象
	  * @param [in] 输入参数:username，当前登录用户的用户名
	  * @param [out] 输出参数:Student类的一个对象
	  * @date:2018/12/18
	  * @version:1.0
	  */
	Student searchStudentInfo(QString username);
	/**
	  * @author:应承峻
	  * @brief:对用户输入的用户名、密码结合其身份与数据库中数据进行比对
	  * @param [in] 输入参数1: 用户名username
	  * @param [in] 输入参数2: 密码password
	  * @param [in] 输入参数3: 身份identity,取值为"普通用户"或"管理员"
	  * @param [out] 输出参数: 返回存放查询结果的QSqlQuery类的一个对象
	  * @date:2018/12/16
	  * @version:2.0
	  */
	QSqlQuery check(QString username , QString password , QString identity);
	
	~SqlModel();

private:
	int openstatus;
	QSqlDatabase db;
};

#endif