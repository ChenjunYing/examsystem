#ifndef _ADDEXAM_H
#define _ADDEXAM_H

#include <QList>
#include <QWidget>
#include <QCombobox>
#include "ui_AddExam.h"
#include "SqlModel.h"
#include "Question.h"

class AddExam : public QWidget {
	
	Q_OBJECT

public:
	AddExam(QWidget *parent = Q_NULLPTR);
	void refreshQuestionBank();
	void refreshComboBox();
	void refreshComboBox(int type);
	~AddExam();

private:
	Ui::AddExam ui;
	QList<Choice> choiceQuestionBank;
	QList<Choice> multiQuestionBank;
	QList<Judge> judgeQuestionBank;
};

#endif