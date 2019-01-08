//#pragma execution_character_set("utf-8")；
#include "SqlModel.h"
#include "Question.h"
Choice splitChoice(QSqlQuery query);
Judge splitJudge(QSqlQuery query);
Config getInformationOfExam(QSqlQuery query);
Student getInformationOfStudent(QSqlQuery query);

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
QSqlQuery SqlModel::check(QString username, QString password, QString identity) {
	QSqlQuery query;
	if (identity.compare(QStringLiteral("管理员")) == 0) {
		query.prepare("select * from admin where username = :name and password = :pwd");
		query.bindValue(":name", username);
		query.bindValue(":pwd", password);
		query.exec();
	}
	else if (identity.compare(QStringLiteral("普通用户")) == 0) {
		query.prepare("select * from user where username = :name and password = :pwd");
		query.bindValue(":name", username);
		query.bindValue(":pwd", password);
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
bool SqlModel::insertChoice(QString description, QString choiceA,
	QString choiceB, QString choiceC, QString choiceD, QString answer, int value) {
	QSqlQuery query;
	query.prepare("insert into object_question(description,A,B,C,D,answer,value,author) values(:des,:A,:B,:C,:D,:ans,:val,:author)");
	query.bindValue(":des", description);
	query.bindValue(":A", choiceA);
	query.bindValue(":B", choiceB);
	query.bindValue(":C", choiceC);
	query.bindValue(":D", choiceD);
	query.bindValue(":ans", answer);
	query.bindValue(":val", value);
	query.bindValue(":author", "admin");
	return query.exec();
}

/**
  * @author:黄思泳
  * @brief:将多选题相关信息插入/修改到数据库中
  * @param [in] 输入参数1: 问题描述description
  * @param [in] 输入参数2~5: A~D选项的选项描述choiceA~choiceD
  * @param [in] 输入参数6: 正确答案answer
  * @param [in] 输入参数7: 试题分值value
  * @param [in] 输入参数8: 试题编号questionId
  * @param [out] 输出参数: 返回是否插入/修改成功,若插入成功则返回true否则返回false
  * @date:2018/12/18
  * @version:1.0
  */
bool SqlModel::insertMultiChoice(QString description, QString choiceA, QString choiceB,
	QString choiceC, QString choiceD, QString answer, int value)
{
	QSqlQuery query;
	int type;
	query.prepare("insert into object_question(description,A,B,C,D,answer,value,type,author) values(:des,:A,:B,:C,:D,:ans,:val,1,:author)");
	query.bindValue(":des", description);
	query.bindValue(":A", choiceA);
	query.bindValue(":B", choiceB);
	query.bindValue(":C", choiceC);
	query.bindValue(":D", choiceD);
	query.bindValue(":ans", answer);
	query.bindValue(":val", value);
	query.bindValue(":author", "admin");
	return query.exec();
}

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
bool SqlModel::insertJudge(QString description, QString answer, int value) {
	QSqlQuery query;
	int type;
	query.prepare("insert into judge_question(description,answer,value,author) values(:des,:ans,:val,:author)");
	query.bindValue(":des", description);
	query.bindValue(":ans", answer);
	query.bindValue(":val", value);
	query.bindValue(":author", "admin");
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
bool SqlModel::updateChoice(QString description, QString choiceA, QString choiceB,
	QString choiceC, QString choiceD, QString answer, int value, int questionId) {
	QSqlQuery query;
	query.prepare("update object_question set description=:des,A=:A,B=:B,C=:C,D=:D,answer=:ans,value=:val,author=:author where question_id=:Id");
	query.bindValue(":des", description);
	query.bindValue(":A", choiceA);
	query.bindValue(":B", choiceB);
	query.bindValue(":C", choiceC);
	query.bindValue(":D", choiceD);
	query.bindValue(":ans", answer);
	query.bindValue(":val", value);
	query.bindValue(":author", "admin");
	query.bindValue(":Id", questionId);
	return query.exec();
}

/**
  * @author:黄思泳
  * @brief:修改多选题操作
  * @param [in] 输入参数1: 问题描述description
  * @param [in] 输入参数2~5: A~D选项的选项描述choiceA~choiceD
  * @param [in] 输入参数6: 正确答案answer
  * @param [in] 输入参数7: 试题分值value
  * @param [in] 输入参数8: 试题编号questionId
  * @param [out] 输出参数: 返回是否修改成功,若修改成功则返回true否则返回false
  * @date:2018/12/18
  * @version:1.0
  */
bool SqlModel::updateMultiChoice(QString description, QString choiceA, QString choiceB,
	QString choiceC, QString choiceD, QString answer, int value, int questionId) {
	QSqlQuery query;
	query.prepare("update object_question set description=:des,A=:A,B=:B,C=:C,D=:D,answer=:ans,value=:val,author=:author where question_id=:Id");
	query.bindValue(":des", description);
	query.bindValue(":A", choiceA);
	query.bindValue(":B", choiceB);
	query.bindValue(":C", choiceC);
	query.bindValue(":D", choiceD);
	query.bindValue(":ans", answer);
	query.bindValue(":val", value);
	query.bindValue(":author", "admin");
	query.bindValue(":Id", questionId);
	return query.exec();
}

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
bool SqlModel::updateJudge(QString description, QString answer, int value, int questionId) {
	QSqlQuery query;
	query.prepare("update judge_question set description=:des,answer=:ans,value=:val,author=:author where question_id=:Id");
	query.bindValue(":des", description);
	query.bindValue(":ans", answer);
	query.bindValue(":val", value);
	query.bindValue(":author", "admin");
	query.bindValue(":Id", questionId);
	return query.exec();
}

/**
  * @author:应承峻
  * @brief:删除选择题
  * @param [in] 输入参数: 选择题编号questionId
  * @param [out] 输出参数: 返回是否删除成功,若修改成功则返回true否则返回false
  * @date:2018/12/19
  * @version:1.0
  */
bool SqlModel::deleteChoice(int questionId) {
	QSqlQuery query;
	query.prepare("delete from object_question where question_id = :id");
	query.bindValue(":id", questionId);
	return query.exec();
}

/**
  * @author:黄思泳
  * @brief:删除判断题
  * @param [in] 输入参数: 选择题编号questionId
  * @param [out] 输出参数: 返回是否删除成功,若修改成功则返回true否则返回false
  * @date:2018/12/20
  * @version:1.0
  */
bool SqlModel::deleteJudge(int questionId) {
	QSqlQuery query;
	query.prepare("delete from judge_question where question_id = :id");
	query.bindValue(":id", questionId);
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
  * @brief:从数据库中筛选相应的选择题,并返回选择题对象的集合
  * @param [int] 输入参数:type,其中0表示单选题,1表示多选题
  * @param [out] 输出参数:Choice类的一个对象集合
  * @date:2018/12/19
  * @note:重载函数
  * @version:1.0
  */
QList<Choice> SqlModel::searchChoice(int type, QString keyWord, int lowerValue, int upperValue, QString author) {
	QSqlQuery query;
	QList<Choice> questionList;   //存放选择题对象的容器
	switch (type) {
	case 0:
		query.prepare("select * from object_question where type = 0 and value>=:low and value<=:up");
		query.bindValue(":low", lowerValue);
		query.bindValue(":up", upperValue);
		query.exec();
		if (query.size()) {
			while (query.next()) {
				QString description = query.record().value(query.record().indexOf("description")).toString();
				QString auth = query.record().value(query.record().indexOf("author")).toString();
				if (description.contains(keyWord, Qt::CaseSensitive) && auth.contains(author, Qt::CaseSensitive))
					questionList.push_back(splitChoice(query));
			}
		}
		break;
	case 1:
		query.prepare("select * from object_question where type = 1 and value>=:low and value<=:up");
		query.bindValue(":low", lowerValue);
		query.bindValue(":up", upperValue);
		query.exec();
		if (query.size()) {
			while (query.next()) {
				QString description = query.record().value(query.record().indexOf("description")).toString();
				QString auth = query.record().value(query.record().indexOf("author")).toString();
				if (description.contains(keyWord, Qt::CaseSensitive) && auth.contains(author, Qt::CaseSensitive))
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
  * @brief:从数据库中筛选相应的判断题,并返回判断题对象的集合
  * @param [out] 输出参数:Judge类的一个对象集合
  * @date:2018/12/19
  * @note:重载函数
  * @version:1.0
  */

QList<Judge> SqlModel::searchJudge(QString keyWord, int lowerValue, int upperValue, QString author) {
	QSqlQuery query;
	QList<Judge> questionList;  //存放判断题对象的容器
	query.prepare("select * from judge_question where value>=:low and value<=:up");
	query.bindValue(":low", lowerValue);
	query.bindValue(":up", upperValue);
	query.exec();
	while (query.next()) {
		QString description = query.record().value(query.record().indexOf("description")).toString();
		QString auth = query.record().value(query.record().indexOf("author")).toString();
		if (description.contains(keyWord, Qt::CaseSensitive) && auth.contains(author, Qt::CaseSensitive))
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
	return Choice::Choice(questionId, description, choiceA, choiceB, choiceC, choiceD, answer, value, author);
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
	return Judge::Judge(questionId, description, answer, value, author);
}

/**
  * @author:夏林轩
  * @brief:将数据库中查询到的一场考试数据存放在Config类中,并根据用户名筛选
  * @param [in] 输入参数: 字符串username
  * @param [out] 输出参数: 返回存放Config类的一个对象
  * @date:2018/12/17
  * @version:2.0
  */
QList<Config> SqlModel::searchExam(QString username) {
	QSqlQuery query;
	QList<Config> examList;  //存放考试对象的容器
	query.exec("select * from exam,config where exam.exam_code = config.exam_code");
	while (query.next())
	{
		int userNameIndex = query.record().indexOf("username");
		QString userName = query.record().value(userNameIndex).toString();
		if (userName.compare(username) == 0) examList.push_back(getInformationOfExam(query));
	}
	return examList;
}

/**
  * @author:夏林轩 应承峻
  * @brief:将数据库中查询到的一个学生数据存放在Exam类中,并根据用户名筛选
  * @param [in] 输入参数: 字符串username
  * @param [out] 输出参数: 返回存放符合条件的信息的一个Student对象
  * @date:2018/12/17
  * @version:2.0
  */
Student SqlModel::searchStudentInfo(QString username) {
	QSqlQuery query;
	query.exec("select * from user");
	while (query.next()) {
		int userNameIndex = query.record().indexOf("username");
		QString userName = query.record().value(userNameIndex).toString();
		if (userName.compare(username) == 0) {
			return getInformationOfStudent(query);
		}
	}
}

/**
  * @author:应承峻
  * @brief:查询学生信息
  * @param [out] 输出参数: 返回存放符合条件的信息的一个Student对象数组
  * @date:2019/1/7
  * @version:1.0
  */
QList<Student> SqlModel::searchStudent() {
	QSqlQuery query;
	QList<Student> studentList;
	query.exec("select * from user");
	while (query.next()) {
		studentList.push_back(getInformationOfStudent(query));
	}
	return studentList;
}

/**
  * @author:应承峻
  * @brief:查询用户名是否已经存在
  * @param [out] 输出参数: 若存在返回1否则返回0
  * @date:2019/1/8
  * @version:1.0
  */
bool SqlModel::isUsernameExist(QString username) {
	bool flag = false;
	QSqlQuery query;
	query.prepare("select * from user where username = :name");
	query.bindValue(":name" , username);
	query.exec();
	if (query.size()) flag = true;
	return flag;
}

/**
  * @author:应承峻
  * @brief:注册学生信息
  * @param [in] 输入参数: 学生对象student
  * @param [out] 输出参数: 返回是否注册成功
  * @date:2019/1/8
  * @version:1.0
  */
bool SqlModel::insertStudent(Student student) {
	QSqlQuery query;
	query.prepare("insert into user(username,password,person_name,major,phone_number,sex,student_id) values(:1,:2,:3,:4,:5,:6,:7)");
	query.bindValue(":1" , student.getUsername());
	query.bindValue(":2" , student.getPassword());
	query.bindValue(":3" , student.getName());
	query.bindValue(":4" , student.getMajor());
	query.bindValue(":5" , student.getPhonenumber());
	query.bindValue(":6" , student.getSex());
	query.bindValue(":7" , student.getId());
	return query.exec();
}

/**
  * @author:应承峻
  * @brief:删除学生信息
  * @param [in] 输入参数: 学生用户名username
  * @date:2019/1/8
  * @version:1.0
  */
bool SqlModel::deleteStudent(QString username) {
	QSqlQuery query;
	int queryUser = 1;
	query.prepare("delete from user where username = :name");
	query.bindValue(":name" , username);
	queryUser = query.exec();
	return queryUser;
}

/**
  * @author:夏林轩
  * @brief:将数据库中查询到的考生参加考试以及该考试本身的信息数据存放在Config类中
  * @param [in] 输入参数: 查询结果query
  * @param [out] 输出参数: 返回一个Config类的对象
  * @date:2019/1/1
  * @version:3.0
  */
Config getInformationOfExam(QSqlQuery query) {
	int examNameIndex = query.record().indexOf("exam_name");
	int examCodeIndex = query.record().indexOf("exam_code");
	int examDurationIndex = query.record().indexOf("duration");
	int choiceScoreIndex = query.record().indexOf("object_score");
	int multiScoreIndex = query.record().indexOf("multi_score");
	int judgeScoreIndex = query.record().indexOf("judge_score");
	int isSubmitIndex = query.record().indexOf("is_submit");
	QString examName = query.record().value(examNameIndex).toString();
	int examCode = query.record().value(examCodeIndex).toInt();
	int examDuration = query.record().value(examDurationIndex).toInt();
	int choiceScore = query.record().value(choiceScoreIndex).toInt();
	int multiScore = query.record().value(multiScoreIndex).toInt();
	int judgeScore = query.record().value(judgeScoreIndex).toInt();
	int isSubmit = query.record().value(isSubmitIndex).toInt();
	return Config::Config(choiceScore, multiScore, judgeScore, isSubmit, examName, examCode, examDuration);
}

/**
  * @author:夏林轩 应承峻
  * @brief:将数据库中查询到的考生数据存放在Student对象中
  * @param [in] 输入参数: 查询结果query
  * @param [out] 输出参数: 返回存放符合条件的学生信息的一个Student对象
  * @date:2019/1/7
  * @version:2.0
  */
Student getInformationOfStudent(QSqlQuery query) {
	int usernameIndex = query.record().indexOf("username");
	int passwordIndex = query.record().indexOf("password");
	int phonenumberIndex = query.record().indexOf("phone_number");
	int sexIndex = query.record().indexOf("sex");
	int personNameIndex = query.record().indexOf("person_name");
	int majorIndex = query.record().indexOf("major");
	int studentIdIndex = query.record().indexOf("student_id");
	int sex = query.record().value(sexIndex).toInt();
	QString username = query.record().value(usernameIndex).toString();
	QString password = query.record().value(passwordIndex).toString();
	QString phonenumber = query.record().value(phonenumberIndex).toString();
	QString personName = query.record().value(personNameIndex).toString();
	QString major = query.record().value(majorIndex).toString();
	QString studentId = query.record().value(studentIdIndex).toString();
	return Student::Student(username, password, phonenumber, personName, major, studentId, sex);
}

SqlModel::~SqlModel() {
	db.close();  //关闭数据库
}