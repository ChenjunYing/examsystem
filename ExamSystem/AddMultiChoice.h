#pragma once

#include <QDialog>
#include "ui_AddMultiChoice.h"

class AddMultiChoice : public QDialog
{
	Q_OBJECT

public:
	AddMultiChoice(QWidget *parent = Q_NULLPTR);
	~AddMultiChoice();

private:
	Ui::AddMultiChoice ui;
};
