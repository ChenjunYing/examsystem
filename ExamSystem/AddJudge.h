#pragma once

#include <QDialog>
#include "ui_AddJudge.h"

class AddJudge : public QDialog
{
	Q_OBJECT

public:
	AddJudge(QWidget *parent = Q_NULLPTR);
	~AddJudge();

private slots:


private:
	Ui::AddJudge ui;
};
