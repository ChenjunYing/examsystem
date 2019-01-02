#include "ScoreModel.h"



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

QList<Score> ScoreModel::searchScore(int code)
{
	QSqlQuery query;
	QList<Score> scoreList;
	query.prepare("select * from config order by ");
	return ;
}
