//#pragma execution_character_set("utf-8")；
#include "SqlModel.h"
#include "Question.h"
Choice splitChoice(QSqlQuery query);
Judge splitJudge(QSqlQuery query);

/**
  * @author:应承峻
  * @brief:构造函数,连接数据库
  * @date:2018/12/13
  * @version:1.0
  */
SqlModel::SqlModel() {
	db = QSqlDatabase::addDatabase("QMYSQL");   //MySQL驱动 
	db.setHostName("localhost");       //数据库地址，一般为localhost
	db.setDatabaseName("examsystem");  //数据库名
	db.setUserName("root");            //用户名，一般为root
	db.setPassword("");                //密码，一般为空
	db.setPort(3300);                  //端口默认的是3306,此处为3300
	openstatus = db.open();            //连接数据库
}

/**
  * @author:应承峻
  * @brief:提供获得openstatus属性值的接口
  * @param [out] 输出参数: 返回penstatus属性值
  * @date:2018/12/13
  * @version:1.0
  */
int SqlModel::isOpen() {
	return openstatus;
}

/**
  * @author:应承峻
  * @brief:对用户输入的用户名、密码结合其身份与数据库中数据进行比对
  * @param [in] 输入参数1: 用户名username
  * @param [in] 输入参数2: 密码password
  * @param [in] 输入参数3: 身份identity,取值为"普通用户"或"管理员"
  * @param [out] 输出参数: 返回存放查询结果的QSqlQuery类的一个对象
  * @date:2018/12/13
  * @version:1.0
  */
QSqlQuery SqlModel::check(QString username , QString password , QString identity) {
	QSqlQuery query;
	if (identity.compare(QStringLiteral("管理员")) == 0) {
		query.prepare("select * from admin where username = :name and password = :pwd");
		query.bindValue(":name" , username);
		query.bindValue(":pwd" , password);
		query.exec();
	} else if (identity.compare(QStringLiteral("普通用户")) == 0) {
		query.prepare("select * from user where username = :name and password = :pwd");
		query.bindValue(":name" , username);
		query.bindValue(":pwd" , password);
		query.exec();
	}
	return query;
}

/**
  * @author:应承峻
  * @brief:将单选题相关信息插入/修改到数据库中
  * @param [in] 输入参数1: 问题描述description
  * @param [in] 输入参数2~5: A~D选项的选项描述choiceA~choiceD
  * @param [in] 输入参数6: 正确答案answer
  * @param [in] 输入参数7: 试题分值value
  * @param [in] 输入参数8: 试题编号questionId
  * @param [out] 输出参数: 返回是否插入/修改成功,若插入成功则返回true否则返回false
  * @date:2018/12/16
  * @version:2.0
  */
bool SqlModel::insertChoice(QString description , QString choiceA ,
	QString choiceB , QString choiceC , QString choiceD , QString answer , int value) {
	QSqlQuery query;
	query.prepare("insert into object_question(description,A,B,C,D,answer,value,author) values(:des,:A,:B,:C,:D,:ans,:val,:author)");
	query.bindValue(":des" , description);
	query.bindValue(":A" , choiceA);
	query.bindValue(":B" , choiceB);
	query.bindValue(":C" , choiceC);
	query.bindValue(":D" , choiceD);
	query.bindValue(":ans" , answer);
	query.bindValue(":val" , value);
	query.bindValue(":author" , "admin");
	return query.exec();
}

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
bool SqlModel::updateChoice(QString description , QString choiceA , QString choiceB ,
	QString choiceC , QString choiceD , QString answer , int value , int questionId) {
	qDebug() << questionId;
	QSqlQuery query;
	query.prepare("update object_question set description=:des,A=:A,B=:B,C=:C,D=:D,answer=:ans,value=:val,author=:author where question_id=:Id");
	query.bindValue(":des" , description);
	query.bindValue(":A" , choiceA);
	query.bindValue(":B" , choiceB);
	query.bindValue(":C" , choiceC);
	query.bindValue(":D" , choiceD);
	query.bindValue(":ans" , answer);
	query.bindValue(":val" , value);
	query.bindValue(":author" , "admin");
	query.bindValue(":Id" , questionId);
	return query.exec();
}

/**
  * @author:应承峻
  * @brief:从数据库中筛选相应的选择题,并返回选择题对象的集合
  * @param [int] 输入参数:type,其中0表示单选题,1表示多选题
  * @param [out] 输出参数:Choice类的一个对象集合
  * @date:2018/12/15
  * @version:1.0
  */
QList<Choice> SqlModel::searchChoice(int type) {
	QSqlQuery query;
	QList<Choice> questionList;   //存放选择题对象的容器
	switch (type) {
		case 0: 
			query.exec("select * from object_question where type = 0"); 
			if (query.size()) {
				while (query.next()) {
					questionList.push_back(splitChoice(query));
				}
			}
			break;
		case 1: 
			query.exec("select * from object_question where type = 1"); 
			if (query.size()) {
				while (query.next()) {
					questionList.push_back(splitChoice(query));
				}
			}
			break;
		default: 
			break;
	}
	return questionList;
}

/**
  * @author:应承峻
  * @brief:从数据库中筛选相应的判断题,并返回判断题对象的集合
  * @param [out] 输出参数:Judge类的一个对象集合
  * @date:2018/12/15
  * @version:1.0
  */
QList<Judge> SqlModel::searchJudge() {
	QSqlQuery query;
	QList<Judge> questionList;  //存放判断题对象的容器
	query.exec("select * from judge_question");
	while (query.next()) {
		questionList.push_back(splitJudge(query));
	}
	return questionList;
}

/**
  * @author:应承峻
  * @brief:将数据库中查询到的一条选择题数据存放在Choice类中
  * @param [in] 输入参数: 查询结果query
  * @param [out] 输出参数: 返回存放Choice类的一个对象
  * @date:2018/12/16
  * @version:2.0
  */
Choice splitChoice(QSqlQuery query) {
	int questionIdIndex = query.record().indexOf("question_id"); //获取列下标
	int descriptionIndex = query.record().indexOf("description"); 
	int choiceAIndex = query.record().indexOf("A");
	int choiceBIndex = query.record().indexOf("B");
	int choiceCIndex = query.record().indexOf("C");
	int choiceDIndex = query.record().indexOf("D");
	int answerIndex = query.record().indexOf("answer");
	int valueIndex = query.record().indexOf("value");
	int authorIndex = query.record().indexOf("author");
	QString description = query.record().value(descriptionIndex).toString(); //通过列下标获取值
	QString choiceA = query.record().value(choiceAIndex).toString();
	QString choiceB = query.record().value(choiceBIndex).toString();
	QString choiceC = query.record().value(choiceCIndex).toString();
	QString choiceD = query.record().value(choiceDIndex).toString();
	QString answer = query.record().value(answerIndex).toString();
	QString author = query.record().value(authorIndex).toString();
	int value = query.record().value(valueIndex).toInt();
	int questionId = query.record().value(questionIdIndex).toInt();
	return Choice::Choice(questionId , description , choiceA , choiceB , choiceC , choiceD , answer , value , author);
}


/**
  * @author:应承峻
  * @brief:将数据库中查询到的一条判断题数据存放在Judge类中
  * @param [in] 输入参数: 查询结果query
  * @param [out] 输出参数: 返回存放Judge类的一个对象
  * @date:2018/12/16
  * @version:2.0
  */
Judge splitJudge(QSqlQuery query) {
	int questionIdIndex = query.record().indexOf("question_id"); //获取列下标
	int descriptionIndex = query.record().indexOf("description");
	int answerIndex = query.record().indexOf("answer");
	int valueIndex = query.record().indexOf("value");
	int authorIndex = query.record().indexOf("author");
	QString description = query.record().value(descriptionIndex).toString(); //通过列下标获取值
	QString answer = query.record().value(answerIndex).toString();
	QString author = query.record().value(authorIndex).toString();
	int value = query.record().value(valueIndex).toInt();
	int questionId = query.record().value(questionIdIndex).toInt();
	return Judge::Judge(questionId , description , answer , value , author);
}


SqlModel::~SqlModel() {
	db.close();  //关闭数据库
}