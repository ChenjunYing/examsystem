#ifndef _ADDCHOICE_H
#define _ADDCHOICE_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QMessagebox>
#include "ui_AddChoice.h"

class AddChoice : public QDialog{

	Q_OBJECT

public:
	AddChoice(QWidget *parent = Q_NULLPTR);
	~AddChoice();
	friend class QuestionBank;

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
	  * @brief:���ð�ť�Ĺ���ʵ��
	  * @date:2018/12/14
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

private:
	Ui::AddChoice ui;
};

#endif