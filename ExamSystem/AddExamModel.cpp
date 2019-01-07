#include "AddExamModel.h"

AddExamModel::AddExamModel() {
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
*/
int AddExamModel::isOpen() {
	return openstatus;

}
/**
  * @author:��˼Ӿ
  * @brief:�����Ծ�
  * @date:2019/1/1
  * @version:1.0
  */
bool AddExamModel::insertExam(QString examName, int examTime, QString examInformation) {
	QSqlQuery query;
	query.prepare("insert into exam(exam_name,duration,information) values(:examName,:duration,:information)");
	query.bindValue(":examName", examName);
	query.bindValue(":duration", examTime);
	query.bindValue(":information", examInformation);
	return query.exec();
}

/**
  * @author:��˼Ӿ
  * @brief:�õ�examcode
  * @date:2019/1/1
  * @version:1.0
  */
int AddExamModel::searchExam(QString examName) {
	QSqlQuery query;
	int examCode = 0;
	query.prepare("select * from exam where exam_name = :name");
	query.bindValue(":name", examName);
	query.exec();
	if (query.size())
	{
		while (query.next()) {
			examCode = query.record().value(query.record().indexOf("exam_code")).toInt();
		}
	}
	return examCode;
}

/**
  * @author:��˼Ӿ
  * @brief:����ѡ����
  * @date:2019/1/1
  * @version:1.0
  */
bool AddExamModel::insertChoice(int examCode, int questionId) {
	QSqlQuery query;
	query.prepare("insert into exam_content(object_id,exam_code) values(:questionId,:examCode)");
	query.bindValue(":questionId", questionId);
	query.bindValue(":examCode", examCode);
	return query.exec();
}

/**
  * @author:��˼Ӿ
  * @brief:�����ж���
  * @date:2019/1/1
  * @version:1.0
  */
bool AddExamModel::insertJudge(int examCode, int questionId) {
	QSqlQuery query;
	query.prepare("insert into exam_content(judge_id,exam_code) values(:questionId,:examCode)");
	query.bindValue(":questionId", questionId);
	query.bindValue(":examCode", examCode);
	return query.exec();
}

/**
  * @author:��˼Ӿ
  * @brief:�����п���������½��Ŀ���
  * @date:2019/1/2
  * @version:1.0
  */
void AddExamModel::insertStudent(int examCode) {
	QSqlQuery query1;
	QSqlQuery query2;
	query1.exec("select username from user");
	if (query1.size())
	{
		while (query1.next()) {
			query2.prepare("insert into config(username,exam_code) values(:username,:examCode)");
			query2.bindValue(":username", query1.record().value(0).toString());
			query2.bindValue(":examCode", examCode);
			query2.exec();
		}
	}
}

AddExamModel::~AddExamModel() {
	db.close();
}
