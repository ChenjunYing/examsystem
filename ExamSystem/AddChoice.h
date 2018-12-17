#ifndef _ADDCHOICE_H
#define _ADDCHOICE_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QMessagebox>
#include "ui_AddChoice.h"
#include "Question.h"

class AddChoice : public QDialog {

	Q_OBJECT

public:
	AddChoice(QWidget *parent = Q_NULLPTR);
	~AddChoice();
	friend class QuestionBank;

/**
  * @author:Ӧ�о�
  * @brief:��ѡ�������ɺ���QuestionBankҳ�淢����������ź�
  * @date:2018/12/17
  * @version:1.0
  */
signals: void updateOK(int);
/**
  * @author:Ӧ�о�
  * @brief:��MainWindowҳ�淢���޸�ҳ���ָ���Ա�������ź���۵İ�
  * @date:2018/12/17
  * @version:1.0
  */
signals: void sendChoicePage(AddChoice*);

private slots:
	/**
	  * @author:Ӧ�о�
	  * @brief:�ж���ӵ�ѡ������ĺϷ���,���Ϸ���ִ�в������,���򵯳��Ƿ������Ի���
	  * @date:2018/12/14
	  * @version:1.0
	  */
	void checkData();

	/**
	  * @author:Ӧ�о�
	  * @brief:�ж��޸ĵ�ѡ������ĺϷ���,���Ϸ���ִ���޸Ĳ���,���򵯳��Ƿ������Ի���
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void checkUpdateData();

	/**
	  * @author:Ӧ�о�
	  * @brief:�ж���ӵ�ѡ������ĺϷ���,���Ϸ���ִ�в������,���򵯳��Ƿ������Ի���
	  * @date:2018/12/16
	  * @note:���������غ���,���������޸ĺ�ɾ������
	  * @version:1.0
	  */
	void resetData();

	/**
	  * @author:Ӧ�о�
	  * @brief:���趨���л�ȡ�������±�ת�����ַ���
	  * @param [in] �������1: �����±�index
	  * @param [out] �������: ������Ӧѡ����ַ���
	  * @date:2018/12/14
	  * @version:1.0
	  */
	QString convertAnswer(int index);

	/**
	  * @author:Ӧ�о�
	  * @brief:���շ��͹�����ѡ�е�ѡ�����Ӧ���ݲ���ʾ
	  * @date:2018/12/17
	  * @version:2.0
	  */
	void receiveData(Choice c);

private:
	Ui::AddChoice ui;
	int tempQuestionId;
};

#endif