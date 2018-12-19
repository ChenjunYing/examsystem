#pragma once

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QMessagebox>
#include "ui_AddMultiChoice.h"
#include "Question.h"

class AddMultiChoice : public QDialog
{
	Q_OBJECT

public:
	AddMultiChoice(QWidget *parent = Q_NULLPTR);
	~AddMultiChoice();
	friend class QuestionBank;
	/**
	  * @author:��˼Ӿ
	  * @brief:��ѡ�������ɺ���QuestionBankҳ�淢����������ź�
	  * @date:2018/12/18
	  * @version:1.0
	  */
signals: void updateOK(int);
	/**
	  * @author:��˼Ӿ
	  * @brief:��MainWindowҳ�淢���޸�ҳ���ָ���Ա�������ź���۵İ�
	  * @date:2018/12/18
	  * @version:1.0
	  */
signals: void sendMultiChoicePage(AddMultiChoice*);

private slots:
	/**
	  * @author:��˼Ӿ
	  * @brief:�ж���Ӷ�ѡ������ĺϷ���,���Ϸ���ִ�в������,���򵯳��Ƿ������Ի���
	  * @date:2018/12/18
	  * @version:1.0
	 */
	void checkData();

	/**
	  * @author:��˼Ӿ
	  * @brief:�ж��޸Ķ�ѡ������ĺϷ���,���Ϸ���ִ���޸Ĳ���,���򵯳��Ƿ������Ի���
	  * @date:2018/12/18
	  * @version:1.0
	 */
	void checkUpdateData();

	/**
	  * @author:��˼Ӿ
	  * @brief:�ж���Ӷ�ѡ������ĺϷ���,���Ϸ���ִ�в������,���򵯳��Ƿ������Ի���
	  * @date:2018/12/18
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
	  * @brief:���շ��͹�����ѡ�ж�ѡ�����Ӧ���ݲ���ʾ
	  * @date:2018/12/18
	  * @version:1.0
	  */
	void receiveData(Choice c);
private:
	Ui::AddMultiChoice ui;
	int tempQuestionId;
};

