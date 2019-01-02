#pragma once
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
#include "Exam.h"

/**
  * @brief �����װ�˿��Խ����ж����ݿ����ز���
  * @author �»�
  */

class StudentExamModel {

public:
	StudentExamModel();
	/**
  * @author:Ӧ�о�
  * @brief:�ṩ���openstatus����ֵ�Ľӿ�
  * @param [out] �������: ����penstatus����ֵ
  * @date:2018/12/13
  * @version:1.0
  * @����SqlModel
  */
	int isOpen();

	/**
  * @author:�»�
  * @brief:��ѯ���Ծ���Ӧ��ѡ���⣨������ѡ�Լ���ѡ�⣩
  * @param [in] �������1: ѡ��������
  * @param [in] �������2: �Ծ���
  * @param [out] �������: Choice���һ�����󼯺�
  * @date:2018/12/24
  * @version:1.0
  */
	QList<Choice> searchChoice(int type,int examCode);

	/**
* @author:�»�
* @brief:��ѯ���Ծ���Ӧ���ж���
* @param [in] �������1: �Ծ���
* @param [out] �������: Judge���һ�����󼯺�
* @date:2018/12/24
* @version:1.0
*/
	QList<Judge> searchJudge(int examCode);

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
	int submit(QList<Choice> choiceAns, QList<Choice> multichoiceAns, QList<Judge> judgeAns,int examCode,int objectScore,int multiScore,int judgeScore);

	/**
* @author:�»�
* @brief:���ҵ�ǰ�Ծ���Ϣ
* @param [in] �������1: �Ծ����
* @param [out] �������: ����Exam�� ����Ծ���Ϣ
* @date:2019/1/2
* @version:1.0
*/
	Exam getInformation(int examCode);
	~StudentExamModel();

private:
	int openstatus;
	QSqlDatabase db;
};