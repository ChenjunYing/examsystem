#include"StudentExamModel.h"
Choice splitChoice1(QSqlQuery query);
Judge splitJudge1(QSqlQuery query);
StudentExamModel::StudentExamModel() {
	db = QSqlDatabase::addDatabase("QMYSQL");   //MySQL���� 
	db.setHostName("localhost");       //���ݿ��ַ��һ��Ϊlocalhost
	db.setDatabaseName("examsystem");  //���ݿ���
	db.setUserName("root");            //�û�����һ��Ϊroot
	db.setPassword("");                //���룬һ��Ϊ��
	db.setPort(3300);                  //�˿�Ĭ�ϵ���3306,�˴�Ϊ3300
	openstatus = db.open();            //�������ݿ�
}

/**
  * @author:Ӧ�о�
  * @brief:�ṩ���openstatus����ֵ�Ľӿ�
  * @param [out] �������: ����penstatus����ֵ
  * @date:2018/12/13
  * @version:1.0
  * ����SqlModel
  */
int StudentExamModel::isOpen() {
	return openstatus;
}

/**
* @author:�»�
* @brief:��ѯ���Ծ���Ӧ��ѡ���⣨������ѡ�Լ���ѡ�⣩
* @param [in] �������1: ѡ��������
* @param [in] �������2: �Ծ���
* @param [out] �������: Choice���һ�����󼯺�
* @date:2018/12/24
* @version:1.0
*/
QList<Choice> StudentExamModel::searchChoice(int type, int examCode) {
	QSqlQuery query;
	QList<Choice> questionList;   //���ѡ������������
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
* @author:�»�
* @brief:��ѯ���Ծ���Ӧ���ж���
* @param [in] �������1: �Ծ���
* @param [out] �������: Judge���һ�����󼯺�
* @date:2018/12/24
* @version:1.0
*/
QList<Judge> StudentExamModel::searchJudge(int examCode) {
	QSqlQuery query;
	QList<Judge> questionList;  //����ж�����������
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
* @author:�»�
* @brief:�ύ�𰸣�����ش�⣬����config��
* @param [in] �������1~3: ��ѡ�⡢��ѡ�⡢�ж���Ķ��󼯺�
* @param [in] �������4: �Ծ���
* @param [in] �������5~6: ѡ���⡢�ж������
* @param [out] �������: �ж��ύ�Ƿ�ɹ����ɹ�����1��ʧ�ܷ���0
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
	db.close();  //�ر����ݿ�
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
  * @author:Ӧ�о�
  * @brief:�����ݿ��в�ѯ����һ��ѡ�������ݴ����Choice����
  * @param [in] �������: ��ѯ���query
  * @param [out] �������: ���ش��Choice���һ������
  * @date:2018/12/16
  * @version:2.0
  * ����SqlModel
  */
Choice splitChoice1(QSqlQuery query) {
	int questionIdIndex = query.record().indexOf("question_id"); //��ȡ���±�
	int descriptionIndex = query.record().indexOf("description");
	int choiceAIndex = query.record().indexOf("A");
	int choiceBIndex = query.record().indexOf("B");
	int choiceCIndex = query.record().indexOf("C");
	int choiceDIndex = query.record().indexOf("D");
	int answerIndex = query.record().indexOf("answer");
	int valueIndex = query.record().indexOf("value");
	int authorIndex = query.record().indexOf("author");
	QString description = query.record().value(descriptionIndex).toString(); //ͨ�����±��ȡֵ
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
  * @author:Ӧ�о�
  * @brief:�����ݿ��в�ѯ����һ���ж������ݴ����Judge����
  * @param [in] �������: ��ѯ���query
  * @param [out] �������: ���ش��Judge���һ������
  * @date:2018/12/16
  * @version:2.0
  * ����SqlModel
  */
Judge splitJudge1(QSqlQuery query) {
	int questionIdIndex = query.record().indexOf("question_id"); //��ȡ���±�
	int descriptionIndex = query.record().indexOf("description");
	int answerIndex = query.record().indexOf("answer");
	int valueIndex = query.record().indexOf("value");
	int authorIndex = query.record().indexOf("author");
	QString description = query.record().value(descriptionIndex).toString(); //ͨ�����±��ȡֵ
	QString answer = query.record().value(answerIndex).toString();
	QString author = query.record().value(authorIndex).toString();
	int value = query.record().value(valueIndex).toInt();
	int questionId = query.record().value(questionIdIndex).toInt();
	return Judge::Judge(questionId, description, answer, value, author);
}