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
	  * @author:夏林轩
	  * @brief:将考试信息在学生主界面上显示出来
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void showExam();
	/**
	  * @author:夏林轩
	  * @brief:从多个数据表中拉取数据以填充学生主界面的表格
	  * @date:2018/12/16
	  * @version:1.0
	  */
	void dataGet();

private:
	Ui::StudentWindow ui;
	QList<Student> student;
	QStandardItemModel* examModel;
};
