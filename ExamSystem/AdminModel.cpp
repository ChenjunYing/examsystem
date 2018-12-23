#include "AdminModel.h"
Exam splitExam(QSqlQuery query);

AdminModel::AdminModel() {
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
  * @brief:�����ݿ�����ȡ������Ϣ
  * @date:2018/12/23
  * @version:1.0
  */
QList<Exam> AdminModel::searchExam() {
	QList<Exam> examList;
	QSqlQuery query;
	query.exec("select * from exam");
	while (query.next()) {
		examList.push_back(splitExam(query));
	}
	return examList;
}

/**
  * @author:Ӧ�о�
  * @brief:����ѯ����һ��������Ϣʵ����
  * @date:2018/12/23
  * @version:1.0
  */
Exam splitExam(QSqlQuery query) {
	int examCodeIndex = query.record().indexOf("exam_code"); //��ȡ���±�
	int examNameIndex = query.record().indexOf("exam_name");
	int informationIndex = query.record().indexOf("information");
	int durationIndex = query.record().indexOf("duration");
	int examCode = query.record().value(examCodeIndex).toInt(); //ͨ�����±��ȡֵ
	int duration = query.record().value(durationIndex).toInt();
	QString examName = query.record().value(examNameIndex).toString(); 
	QString information = query.record().value(informationIndex).toString();
	return Exam::Exam(examCode , duration , examName , information);
}

int AdminModel::isOpen() {
	return openstatus;
}


AdminModel::~AdminModel() {
	db.close();  //�ر����ݿ�
}
