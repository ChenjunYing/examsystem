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



AddExamModel::~AddExamModel() {

}
