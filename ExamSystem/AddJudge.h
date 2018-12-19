#pragma once

#include <QDialog>
#include "ui_AddJudge.h"
#include "Question.h"
#include <QString>
#include <QDebug>
#include <QMessagebox>

class AddJudge : public QDialog
{
	Q_OBJECT

public:
	AddJudge(QWidget *parent = Q_NULLPTR);
	~AddJudge();
	friend class QuestionBank;

/**
  * @author:��˼Ӿ
  * @brief:��MainWindowҳ�淢���޸�ҳ���ָ���Ա�������ź���۵İ�
  * @date:2018/12/19
  * @version:1.0
  */
signals: void updateOK(int);
/**
  * @author:��˼Ӿ
  * @brief:��MainWindowҳ�淢���޸�ҳ���ָ���Ա�������ź���۵İ�
  * @date:2018/12/19
  * @version:1.0
  */
signals: void sendJudgePage(AddJudge*);

private slots:
	/**
      * @author:��˼Ӿ
      * @brief:�ж�����ж�������ĺϷ���,���Ϸ���ִ�в������,���򵯳��Ƿ������Ի���
      * @date:2018/12/19
      * @version:1.0
      */
	void checkData();

	/**
	  * @author:��˼Ӿ
	  * @brief:�ж��޸��ж�������ĺϷ���,���Ϸ���ִ���޸Ĳ���,���򵯳��Ƿ������Ի���
	  * @date:2018/12/19
	  * @version:1.0
	 */
	void checkUpdateData();

	/**
	  * @author:��˼Ӿ
	  * @brief:�ж�����ж�������ĺϷ���,���Ϸ���ִ�в������,���򵯳��Ƿ������Ի���
	  * @date:2018/12/19
	  * @note:���������غ���,���������޸ĺ�ɾ������
	  * @version:1.0
	  */
	void resetData();

	/**
	   * @author:��˼Ӿ
	   * @brief:��ÿ��ѡ���Ƿ�ѡΪ�𰸵�bool����ת��Ϊ�ַ���
	   * @param [in] �������1: ����Ϊ4��bool����
	   * @param [out] �������: ����ѡΪ�𰸵��ַ���
	   * @date:2018/12/18
	   * @version:1.0
	   */
	QString convertAnswer(bool *answer);

	/**
	  * @author:��˼Ӿ
	  * @brief:���շ��͹�����ѡ���ж������Ӧ���ݲ���ʾ
	  * @date:2018/12/18
	  * @version:1.0
	  */
	void receiveData(Judge c);

private:
	Ui::AddJudge ui;
	int tempQuestionId;
};
