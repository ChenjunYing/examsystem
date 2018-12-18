#pragma once

#include <QList>
#include <QDialog>
#include <QVariant> 
#include <QTabWidget>
#include <QModelIndex>
#include <QStandardItem>
#include <QAbstractItemView>
#include <QStandardItemModel>
#include "ui_StudentWindow.h"
#include "User.h"
#include "Question.h"

class StudentWindow : public QDialog
{
	Q_OBJECT

public:
	StudentWindow(QWidget *parent = Q_NULLPTR);
	~StudentWindow();
	/**
	  * @author:������
	  * @brief:��������Ϣ��ѧ������������ʾ����
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void showExam();
	/**
	  * @author:������
	  * @brief:�Ӷ�����ݱ�����ȡ���������ѧ��������ı��
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void dataGet();
	/**
	  * @author:������
	  * @brief:��ѧ����Ϣ��ѧ������������ʾ����
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void showStudent(QString username);
public slots:
	/**
	  * @author:������
	  * @brief:�����û��ڵ�¼����������û������ں�������Ϣɸѡ
	  * @date:2018/12/17
	  * @version:1.0
	  */
	void receiveUserName(QString name);

private:
	Ui::StudentWindow ui;
	QList<Exam> exam;
	QString userName;
	QStandardItemModel* examModel;
};
