#include "ScoreModel.h"
Score getInfoOfScore(QSqlQuery query);
Details getInfoOfJudgeDetail(QSqlQuery query);
Details getInfoOfObjectDetail(QSqlQuery query);

ScoreModel::ScoreModel()
{
	db = QSqlDatabase::addDatabase("QMYSQL");   //MySQL���� 
	db.setHostName("localhost");       //���ݿ��ַ��һ��Ϊlocalhost
	db.setDatabaseName("examsystem");  //���ݿ���
	db.setUserName("root");            //�û�����һ��Ϊroot
	db.setPassword("");                //���룬һ��Ϊ��
	db.setPort(3300);                  //�˿�Ĭ�ϵ���3306,�˴�Ϊ3300
	openstatus = db.open();            //�������ݿ�
}


ScoreModel::~ScoreModel()
{
	db.close();  //�ر����ݿ�
}

int ScoreModel::isOpen()
{
	return openstatus;
}

/*
  * @author:������
  * @brief:�����ݿ��в�ѯ����һ���ɼ����ݴ����Score����,�������û���ɸѡ
  * @param [in] �������: ���Ա��
  * @param [out] �������: ���ش��Score���һ������
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
  * @author:������
  * @brief:�����ݿ��в�ѯ����һ�����������ݴ����Details����,�������û���ɸѡ
  * @param [in] �������: ���Ա�ţ��û���
  * @param [out] �������: ���ش��Details���һ������
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
  * @author:������
  * @brief:�����ݿ��в�ѯ���ĳɼ����ݴ����Score������
  * @param [in] �������: ��ѯ���query
  * @param [out] �������: ���ش�ŷ���������ѧ����Ϣ��һ��Student����
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
  * @author:������
  * @brief:�����ݿ��в�ѯ����һ��ѧ�����ж���С������ݴ����Details����
  * @param [in] �������: ��ѯ���query
  * @param [out] �������: ����һ��Details��Ķ���
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
  * @author:������
  * @brief:�����ݿ��в�ѯ����һ��ѧ����ѡ����С������ݴ����Details����
  * @param [in] �������: ��ѯ���query
  * @param [out] �������: ����һ��Details��Ķ���
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
