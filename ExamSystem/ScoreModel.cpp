#include "ScoreModel.h"
Score getInfoOfScore(QSqlQuery query);


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
	return Score(studentName, choiceScore, multiScore, judgeScore, isSubmit, examName, examCode, examDuration);
}
