#include "ScoreModel.h"
Score getInfoOfScore(QSqlQuery query);
Details getInfoOfJudgeDetail(QSqlQuery query);
Details getInfoOfObjectDetail(QSqlQuery query);

ScoreModel::ScoreModel()
{
	db = QSqlDatabase::addDatabase("QMYSQL");   //MySQL驱动 
	db.setHostName("localhost");       //数据库地址，一般为localhost
	db.setDatabaseName("examsystem");  //数据库名
	db.setUserName("root");            //用户名，一般为root
	db.setPassword("");                //密码，一般为空
	db.setPort(3300);                  //端口默认的是3306,此处为3300
	openstatus = db.open();            //连接数据库
}


ScoreModel::~ScoreModel()
{
	db.close();  //关闭数据库
}

int ScoreModel::isOpen()
{
	return openstatus;
}

/*
  * @author:夏林轩
  * @brief:将数据库中查询到的一条成绩数据存放在Score类中,并根据用户名筛选
  * @param [in] 输入参数: 考试编号
  * @param [out] 输出参数: 返回存放Score类的一个对象
  * @date:2019/1/2
  * @version:1.0
  */
QList<Score> ScoreModel::searchScore(int code)
{
	QSqlQuery query;
	QList<Score> scoreList;
	query.prepare("select * from config where exam_code = :code");
	query.bindValue(":code",code);
	query.exec();
	if (query.size()) {
		while (query.next()) {
			scoreList.push_back(getInfoOfScore(query));
		}
	}
	return scoreList;
}

/*
  * @author:夏林轩
  * @brief:将数据库中查询到的一条考生答案数据存放在Details类中,并根据用户名筛选
  * @param [in] 输入参数: 考试编号，用户名
  * @param [out] 输出参数: 返回存放Details类的一个对象
  * @date:2019/1/2
  * @version:1.0
  */
QList<Details> ScoreModel::searchDetails(int code, QString name)
{
	QSqlQuery queryForJudge,queryForObject;
	QList<Details> detailsList;
	queryForObject.prepare("select * from object_answer where exam_code = :code and username = :name");
	queryForObject.bindValue(":code", code);
	queryForObject.bindValue(":name", name);
	queryForObject.exec();
	if (queryForObject.size()) {
		while (queryForObject.next()) {
			detailsList.push_back(getInfoOfObjectDetail(queryForObject));
		}
	}
	queryForJudge.prepare("select * from judge_answer where exam_code = :code and username = :name");
	queryForJudge.bindValue(":code", code);
	queryForJudge.bindValue(":name", name);
	queryForJudge.exec();
	if (queryForJudge.size()) {
		while (queryForJudge.next()) {
			detailsList.push_back(getInfoOfJudgeDetail(queryForJudge));
		}
	}
	
	return detailsList;
}

/**
  * @author:夏林轩
  * @brief:将数据库中查询到的成绩数据存放在Score对象中
  * @param [in] 输入参数: 查询结果query
  * @param [out] 输出参数: 返回存放符合条件的学生信息的一个Student对象
  * @date:2019/1/2
  * @version:1.0
  */
Score getInfoOfScore(QSqlQuery query)
{
	QSqlQuery queryForName;
	int userNameIndex = query.record().indexOf("username");
	QString userName = query.record().value(userNameIndex).toString();
	queryForName.prepare("select person_name from user where username = :userName");
	queryForName.bindValue(":userName",userName);
	queryForName.exec();
	queryForName.next();
	QString studentName = queryForName.record().value(0).toString();
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
	return Score::Score(studentName, userName, choiceScore, multiScore, judgeScore, isSubmit, examName, examCode, examDuration);
}

/*
  * @author:夏林轩
  * @brief:将数据库中查询到的一个学生的判断题小题分数据存放在Details类中
  * @param [in] 输入参数: 查询结果query
  * @param [out] 输出参数: 返回一个Details类的对象
  * @date:2019/1/2
  * @version:1.0
  */
Details getInfoOfJudgeDetail(QSqlQuery query)
{
	int questionIdIndex = query.record().indexOf("question_id");
	int studentAnswerIndex = query.record().indexOf("answer");
	int answerIndex = query.record().indexOf("canswer");
	int questionId = query.record().value(questionIdIndex).toInt();
	int scoreIndex = query.record().indexOf("score");
	QString answer = query.record().value(answerIndex).toString();
	QString studentAnswer = query.record().value(studentAnswerIndex).toString();
	int score = query.record().value(scoreIndex).toInt();
	return Details::Details(studentAnswer, answer, score);
}

/*
  * @author:夏林轩
  * @brief:将数据库中查询到的一个学生的选择题小题分数据存放在Details类中
  * @param [in] 输入参数: 查询结果query
  * @param [out] 输出参数: 返回一个Details类的对象
  * @date:2019/1/2
  * @version:1.0
  */
Details getInfoOfObjectDetail(QSqlQuery query)
{
	QSqlQuery queryForAnswer;
	int questionIdIndex = query.record().indexOf("question_id");
	int studentAnswerIndex = query.record().indexOf("answer");
	int answerIndex = query.record().indexOf("canswer");
	int questionId = query.record().value(questionIdIndex).toInt();
	int scoreIndex = query.record().indexOf("score");
	QString answer = queryForAnswer.record().value(answerIndex).toString();
	QString studentAnswer = query.record().value(studentAnswerIndex).toString();
	int score = query.record().value(scoreIndex).toInt();
	return Details::Details(studentAnswer, answer, score);
}
