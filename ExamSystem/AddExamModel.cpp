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



AddExamModel::~AddExamModel() {

}
