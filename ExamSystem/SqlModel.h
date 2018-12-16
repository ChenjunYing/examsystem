#ifndef _SQLMODEL_H
#define _SQLMODEL_H
 
/** 
  * @brief �����װ�����ڶ����ݿ����ز���
  * @author Ӧ�о�
  */
#include <QtSql>
#include <QList>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include "Question.h"

class SqlModel {
public:
	SqlModel();
	/**
	  * @author:Ӧ�о�
	  * @brief:�ṩ���openstatus����ֵ�Ľӿ�
	  * @param [out] �������: ����penstatus����ֵ
	  * @date:2018/12/13
	  * @version:1.0
	  */
	int isOpen();
	/**
	  * @author:Ӧ�о�
	  * @brief:����ѡ�������Ϣ���뵽���ݿ���
	  * @param [in] �������1: ��������description
	  * @param [in] �������2~5: A~Dѡ���ѡ������choiceA~choiceD
	  * @param [in] �������6: ��ȷ��answer
	  * @param [in] �������7: �����ֵvalue
	  * @param [out] �������: �����Ƿ����ɹ�,������ɹ��򷵻�true���򷵻�false
	  * @date:2018/12/14
	  * @version:1.0
	  */	
	bool insertChoice(QString description , QString choiceA , QString choiceB , QString choiceC , QString choiceD , QString answer , int value);
	/**
	  * @author:Ӧ�о�
	  * @brief:�����ݿ���ɸѡ��Ӧ��ѡ����,������ѡ�������ļ���
	  * @param [int] �������:type,����0��ʾ��ѡ��,1��ʾ��ѡ��
	  * @param [out] �������:Choice���һ�����󼯺�
	  * @date:2018/12/15
	  * @version:1.0
	  */	
	QList<Choice> searchChoice(int type);
	/**
	  * @author:Ӧ�о�
	  * @brief:�����ݿ���ɸѡ��Ӧ���ж���,�������ж������ļ���
	  * @param [out] �������:Judge���һ�����󼯺�
	  * @date:2018/12/15
	  * @version:1.0
	  */
	QList<Judge> searchJudge();
	/**
	  * @author:Ӧ�о�
	  * @brief:���û�������û���������������������ݿ������ݽ��бȶ�
	  * @param [in] �������1: �û���username
	  * @param [in] �������2: ����password
	  * @param [in] �������3: ���identity,ȡֵΪ"��ͨ�û�"��"����Ա"
	  * @param [out] �������: ���ش�Ų�ѯ�����QSqlQuery���һ������
	  * @date:2018/12/13
	  * @version:1.0
	  */
	QSqlQuery check(QString username , QString password , QString identity);
	~SqlModel();
private:
	int openstatus;
	QSqlDatabase db;
};

#endif