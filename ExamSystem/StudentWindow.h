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

private:
	Ui::StudentWindow ui;
	QList<Student> student;
	QStandardItemModel* examModel;
};
