#include"StudentExamModel.h"
Choice splitChoice1(QSqlQuery query);
Judge splitJudge1(QSqlQuery query);
StudentExamModel::StudentExamModel() {
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
  * 引用SqlModel
  */
int StudentExamModel::isOpen() {
	return openstatus;
}

/**
* @author:陈欢
* @brief:查询该试卷相应的选择题（包括多选以及单选题）
* @param [in] 输入参数1: 选择题类型
* @param [in] 输入参数2: 试卷编号
* @param [out] 输出参数: Choice类的一个对象集合
* @date:2018/12/24
* @version:1.0
*/
QList<Choice> StudentExamModel::searchChoice(int type, int examCode) {
	QSqlQuery query;
	QList<Choice> questionList;   //存放选择题对象的容器
	QList<int> num;
	int i;
	query.prepare("select object_id from exam_content where object_id > 0 and exam_code = :Code");
	query.bindValue(":Code", examCode);
	query.exec();
	if (query.size()) {
		while (query.next()) {
			num.push_back(query.record().value(0).toInt());
		}
	}
	switch (type) {
	case 0:
		for (i = 0; i < num.size(); i++) {
			query.prepare("select * from object_question where type = 0 and question_id = :id");
			query.bindValue(":id", num.at(i));
			query.exec();
			if (query.size()) {
				while (query.next()) {
					questionList.push_back(splitChoice1(query));
				}
			}
		}
		break;
	case 1:
		for (i = 0; i < num.size(); i++) {
			query.prepare("select * from object_question where type = 1 and question_id = :id");
			query.bindValue(":id", num.at(i));
			query.exec();
			if (query.size()) {
				while (query.next()) {
					questionList.push_back(splitChoice1(query));
				}
			}
		}
		break;
	default:
		break;
	}
	return questionList;
}

/**
* @author:陈欢
* @brief:查询该试卷相应的判断题
* @param [in] 输入参数1: 试卷编号
* @param [out] 输出参数: Judge类的一个对象集合
* @date:2018/12/24
* @version:1.0
*/
QList<Judge> StudentExamModel::searchJudge(int examCode) {
	QSqlQuery query;
	QList<Judge> questionList;  //存放判断题对象的容器
	QList<int> num;
	int i; 
	query.prepare("select judge_id from exam_content where judge_id > 0 and exam_code = :Code");
	query.bindValue(":Code", examCode);
	query.exec();
	if (query.size()) {
		while (query.next()) {
			num.push_back(query.record().value(0).toInt());
		}
	}

	for (i = 0; i < num.size(); i++) {
		query.prepare("select * from judge_question where question_id = :id");
		query.bindValue(":id", num.at(i));
		query.exec();
		if (query.size()) {
			while (query.next()) {
				questionList.push_back(splitJudge1(query));
			}
		}
	}

	return questionList;
}

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
int StudentExamModel::submit(QString username, QList<Choice> choiceAns, QList<Choice> multichoiceAns, QList<Judge> judgeAns, int examCode, int objectScore, int multiScore, int judgeScore) {
	int i;
	int choiceFlag;
	int multichoiceFlag;
	int judgeFlag;
	int scoreFlag;
	for (i = 0; i < choiceAns.size(); i++) {
		if (!choiceAns.at(i).getAnswer().isEmpty()) {
			QSqlQuery query;
			query.prepare("insert into object_answer(username,exam_code,question_id,answer) values(:user,:exam,:id,:ans)");
			query.bindValue(":user", username);
			query.bindValue(":exam", examCode);
			query.bindValue(":id", choiceAns.at(i).getQuestionId());
			query.bindValue(":ans", choiceAns.at(i).getAnswer());
			choiceFlag = query.exec();
		}
	}
	for (i = 0; i < multichoiceAns.size(); i++) {
		if (!multichoiceAns.at(i).getAnswer().isEmpty()) {
			QSqlQuery query;
			query.prepare("insert into object_answer(username,exam_code,question_id,answer) values(:user,:exam,:id,:ans)");
			query.bindValue(":user", username);
			query.bindValue(":exam", examCode);
			query.bindValue(":id", multichoiceAns.at(i).getQuestionId());
			query.bindValue(":ans", multichoiceAns.at(i).getAnswer());
			multichoiceFlag = query.exec();
		}
	}

	for (i = 0; i < judgeAns.size(); i++) {
		if (!judgeAns.at(i).getAnswer().isEmpty()) {
			QSqlQuery query;
			query.prepare("insert into judge_answer(username,exam_code,question_id,answer) values(:user,:exam,:id,:ans)");
			query.bindValue(":user", username);
			query.bindValue(":exam", examCode);
			query.bindValue(":id", judgeAns.at(i).getQuestionId());
			query.bindValue(":ans", judgeAns.at(i).getAnswer());
			judgeFlag = query.exec();
		}
	}
	QSqlQuery query;

	query.prepare("update config set object_score=:objectScore, multi_score=:multiScore,judge_score=:judgeScore, is_submit=1 where username=:username and exam_code=:examCode");
	query.bindValue(":objectScore", objectScore);
	query.bindValue(":multiScore", multiScore);
	query.bindValue(":judgeScore", judgeScore);
	query.bindValue(":username", username);
	query.bindValue(":examCode", examCode);

	scoreFlag = query.exec();

	return choiceFlag && multichoiceFlag &&judgeFlag;
}
StudentExamModel::~StudentExamModel() {
	db.close();  //关闭数据库
}

Exam StudentExamModel::getInformation(int examCode) {
	QSqlQuery query;
	query.prepare("select * from exam where exam_code=:examCode");
	query.bindValue(":examCode", examCode);
	query.exec();
	if (query.size()) {
		if (query.next()) {
			int nameIndex = query.record().indexOf("exam_name");
			int durationIndex = query.record().indexOf("duration");
			int informationIndex = query.record().indexOf("information");
			QString examName = query.record().value(nameIndex).toString();
			int duration = query.record().value(durationIndex).toInt();
			QString information = query.record().value(informationIndex).toString();
			Exam exam(examCode, duration, examName, information);
			return exam;
		}
	}
}

/**
  * @author:应承峻
  * @brief:将数据库中查询到的一条选择题数据存放在Choice类中
  * @param [in] 输入参数: 查询结果query
  * @param [out] 输出参数: 返回存放Choice类的一个对象
  * @date:2018/12/16
  * @version:2.0
  * 引用SqlModel
  */
Choice splitChoice1(QSqlQuery query) {
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
  * 引用SqlModel
  */
Judge splitJudge1(QSqlQuery query) {
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