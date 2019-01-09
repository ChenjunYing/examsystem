#include "AddExamModel.h"

AddExamModel::AddExamModel() {
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
int AddExamModel::isOpen() {
	return openstatus;

}
/**
  * @author:黄思泳
  * @brief:创建试卷
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
  * @author:黄思泳
  * @brief:得到examcode
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
  * @author:黄思泳
  * @brief:插入选择题
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
  * @author:黄思泳
  * @brief:插入判断题
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
  * @author:黄思泳
  * @brief:将所有考生添加入新建的考试
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
/**
  * @author:黄思泳
  * @brief:将原考试的相关内容修改
  * @date:2019/1/9
  * @version:1.0
  */
bool AddExamModel::modifyExam(QString examName, int examTime, QString examInformation, int examCode)
{
	QSqlQuery query;
	query.prepare("update exam set exam_name=:examname,duration=:time,information=:examinf where exam_code=:examcode");	//更新考试信息
	query.bindValue(":examname", examName);
	query.bindValue(":time", examTime);
	query.bindValue(":examinf", examInformation);
	query.bindValue(":examcode", examCode);
	query.exec();
	QSqlQuery query1;
	query1.prepare("delete from exam_content where exam_code = :examcode");	//删除原有题目
	query1.bindValue(":examcode", examCode);
	return query1.exec();

}

QList<int> AddExamModel::searchChosenChoice(int examCode, int type)
{
	QSqlQuery query;
	QList<int> chosenChoiceQuestion;
	query.prepare("select * from exam_content,object_question where exam_content.object_id = object_question.question_id and exam_content.exam_code = :code");
	query.bindValue(":code", examCode);
	query.exec();
	while (query.next()) {
		int questionTypeIndex = query.record().indexOf("type");
		int questionType = query.record().value(questionTypeIndex).toInt();
		if (questionType == type) {
			int questionIdIndex = query.record().indexOf("object_id");
			int questionId = query.record().value(questionIdIndex).toInt();
			chosenChoiceQuestion.push_back(questionId);
		}
	}
	return chosenChoiceQuestion;
}

QList<int> AddExamModel::searchChosenJudge(int examCode)
{
	QSqlQuery query;
	QList<int> chosenJudge;
	query.prepare("select judge_id from exam_content where exam_code = :code and judge_id is not null");
	query.bindValue(":code", examCode);
	query.exec();
	while (query.next()) {
		int judgeId = query.record().value(0).toInt();
		chosenJudge.push_back(judgeId);
	}
	return chosenJudge;
}

Exam AddExamModel::searchExam(int examCode)
{
	QSqlQuery query;
	query.prepare("select * from exam where exam_code = :code");
	query.bindValue(":code", examCode);
	query.exec();
	query.next();
	int CodeIndex = query.record().indexOf("exam_code");
	int examNameIndex = query.record().indexOf("exam_name");
	int durationIndex = query.record().indexOf("duration");
	int informationIndex = query.record().indexOf("information");
	int Code = query.record().value(CodeIndex).toInt();
	int duration = query.record().value(durationIndex).toInt();
	QString examName = query.record().value(examNameIndex).toString();
	QString information = query.record().value(informationIndex).toString();
	return Exam(Code, duration, examName, information);
}

AddExamModel::~AddExamModel() {
	db.close();
}
