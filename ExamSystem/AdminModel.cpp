#include "AdminModel.h"
Exam splitExam(QSqlQuery query);

AdminModel::AdminModel() {
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
  * @brief:从数据库中拉取考试信息
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
  * @author:应承峻
  * @brief:将查询到的一条考试信息实例化
  * @date:2018/12/23
  * @version:1.0
  */
Exam splitExam(QSqlQuery query) {
	int examCodeIndex = query.record().indexOf("exam_code"); //获取列下标
	int examNameIndex = query.record().indexOf("exam_name");
	int informationIndex = query.record().indexOf("information");
	int durationIndex = query.record().indexOf("duration");
	int examCode = query.record().value(examCodeIndex).toInt(); //通过列下标获取值
	int duration = query.record().value(durationIndex).toInt();
	QString examName = query.record().value(examNameIndex).toString(); 
	QString information = query.record().value(informationIndex).toString();
	return Exam::Exam(examCode , duration , examName , information);
}

int AdminModel::isOpen() {
	return openstatus;
}


AdminModel::~AdminModel() {
	db.close();  //关闭数据库
}
