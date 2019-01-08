#ifndef _STUDENTINFO_H
#define _STUDENTINFO_H

#include <QList>
#include <QDialog>
#include <QStandardItemModel>
#include "User.h"
#include "SqlModel.h"
#include "ui_StudentInfo.h"

class StudentInfo : public QDialog {

	Q_OBJECT

public:
	StudentInfo(QWidget *parent = Q_NULLPTR);
	~StudentInfo();
	void refreshData();
	void showStudentTable();
	void setTableHeader(QStandardItemModel* model);
	void setStudentTableItemView(QStandardItemModel* model);

private slots:
	void tableClicked(const QModelIndex&);

private:
	Ui::StudentInfo ui;
	QList<Student> student;
	QStandardItemModel* table;

};

#endif