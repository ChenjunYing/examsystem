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
#include "User.h"

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
	bool insertChoice(QString description , QString choiceA , QString choiceB , 
		QString choiceC , QString choiceD , QString answer , int value);
	
	/**
      * @author:��˼Ӿ
      * @brief:����ѡ�������Ϣ���뵽���ݿ���
      * @param [in] �������1: ��������description
      * @param [in] �������2~5: A~Dѡ���ѡ������choiceA~choiceD
      * @param [in] �������6: ��ȷ��answer
      * @param [in] �������7: �����ֵvalue
      * @param [out] �������: �����Ƿ����ɹ�,������ɹ��򷵻�true���򷵻�false
      * @date:2018/12/18
      * @version:1.0
      */
	bool insertMultiChoice(QString description, QString choiceA, QString choiceB,
		QString choiceC, QString choiceD, QString answer, int value);

	/**
      * @author:��˼Ӿ
      * @brief:���ж��������Ϣ���뵽���ݿ���
      * @param [in] �������1: ��������description
      * @param [in] �������2: ��ȷ��answer
      * @param [in] �������3: �����ֵvalue
      * @param [out] �������: �����Ƿ����ɹ�,������ɹ��򷵻�true���򷵻�false
      * @date:2018/12/19
      * @version:1.0
      */
	bool insertJudge(QString description, QString answer, int value);

	/**
	  * @author:Ӧ�о�
	  * @brief:�޸ĵ�ѡ�����
	  * @param [in] �������1: ��������description
	  * @param [in] �������2~5: A~Dѡ���ѡ������choiceA~choiceD
	  * @param [in] �������6: ��ȷ��answer
	  * @param [in] �������7: �����ֵvalue
	  * @param [in] �������8: ������questionId
	  * @param [out] �������: �����Ƿ��޸ĳɹ�,���޸ĳɹ��򷵻�true���򷵻�false
	  * @date:2018/12/17
	  * @version:1.0
	  */	
	bool updateChoice(QString description , QString choiceA , QString choiceB ,
		QString choiceC , QString choiceD , QString answer , int value , int questionId);

	bool deleteChoice(int questionId);
	
	bool deleteJudge(int questionId);
	
	/**
	  * @author:��˼Ӿ
	  * @brief:�޸Ķ�ѡ�����
	  * @param [in] �������1: ��������description
	  * @param [in] �������2~5: A~Dѡ���ѡ������choiceA~choiceD
	  * @param [in] �������6: ��ȷ��answer
	  * @param [in] �������7: �����ֵvalue
	  * @param [in] �������8: ������questionId
	  * @param [out] �������: �����Ƿ��޸ĳɹ�,���޸ĳɹ��򷵻�true���򷵻�false
	  * @date:2018/12/17
	  * @version:1.0
	  */
	bool updateMultiChoice(QString description, QString choiceA, QString choiceB,
		QString choiceC, QString choiceD, QString answer, int value, int questionId);
	/**
	  * @author:��˼Ӿ
	  * @brief:���ж��������Ϣ���뵽���ݿ���
	  * @param [in] �������1: ��������description
	  * @param [in] �������2: ��ȷ��answer
	  * @param [in] �������3: �����ֵvalue
	  * @param [out] �������: �����Ƿ����ɹ�,������ɹ��򷵻�true���򷵻�false
	  * @date:2018/12/19
	  * @version:1.0
	  */
	bool updateJudge(QString description, QString answer, int value, int questionId);

	/**
	  * @author:Ӧ�о�
	  * @brief:�����ݿ���ɸѡ��Ӧ��ѡ����,������ѡ�������ļ���
	  * @param [in] �������:type,����0��ʾ��ѡ��,1��ʾ��ѡ��
	  * @param [out] �������:Choice���һ�����󼯺�
	  * @date:2018/12/15
	  * @version:1.0
	  */		
	QList<Choice> searchChoice(int type);

	QList<Choice> searchChoice(int type , QString keyWord , int lowerValue , int upperValue , QString author);
	
	/**
	  * @author:Ӧ�о�
	  * @brief:�����ݿ���ɸѡ��Ӧ���ж���,�������ж������ļ���
	  * @param [out] �������:Judge���һ�����󼯺�
	  * @date:2018/12/16
	  * @version:2.0
	  */
	QList<Judge> searchJudge();

	QList<Judge> searchJudge(QString keyWord , int lowerValue , int upperValue , QString author);
	
	/**
	  * @author:������
	  * @brief:�����ݿ���ɸѡ��һ��������Ӧ����Ϣ,�����ؿ��Զ���ļ���
	  * @param [in] �������:username����ǰ��¼�û����û���
	  * @param [out] �������:Config���һ�����󼯺�
	  * @date:2018/12/16
	  * @version:1.0
	  */
	QList<Config> searchExam(QString username);

	/**
	  * @author:������
	  * @brief:���ݵ�ǰ��¼���û����û��������ݿ��н���ɸѡ������һ��Student�����
	  * @param [in] �������:username����ǰ��¼�û����û���
	  * @param [out] �������:Student���һ������
	  * @date:2018/12/18
	  * @version:1.0
	  */
	Student searchStudentInfo(QString username);
	/**
	  * @author:Ӧ�о�
	  * @brief:���û�������û���������������������ݿ������ݽ��бȶ�
	  * @param [in] �������1: �û���username
	  * @param [in] �������2: ����password
	  * @param [in] �������3: ���identity,ȡֵΪ"��ͨ�û�"��"����Ա"
	  * @param [out] �������: ���ش�Ų�ѯ�����QSqlQuery���һ������
	  * @date:2018/12/16
	  * @version:2.0
	  */
	QSqlQuery check(QString username , QString password , QString identity);
	
	~SqlModel();

private:
	int openstatus;
	QSqlDatabase db;
};

#endif