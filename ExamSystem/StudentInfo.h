#ifndef _STUDENTINFO_H
#define _STUDENTINFO_H

#include <QDialog>
#include "SqlModel.h"
#include "ui_StudentInfo.h"

class StudentInfo : public QDialog
{
	Q_OBJECT

public:
	StudentInfo(QWidget *parent = Q_NULLPTR);
	~StudentInfo();

private:
	Ui::StudentInfo ui;
};

#endif