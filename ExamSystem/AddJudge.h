#ifndef _ADDJUDGE_H
#define _ADDJUDGE_H

#include <QDialog>
#include "ui_AddJudge.h"
#include "Question.h"
#include <QString>
#include <QDebug>
#include <QMessagebox>

class AddJudge : public QDialog {
	Q_OBJECT

public:
	AddJudge(QWidget *parent = Q_NULLPTR);
	~AddJudge();
	friend class QuestionBank;

signals: void updateOK(int);
signals: void sendJudgePage(AddJudge*);

public slots:
	void resetData();

private slots:
	void checkData();
	void checkUpdateData();
	void receiveData(Judge c);
	QString convertAnswer(bool *answer);

private:
	Ui::AddJudge ui;
	int tempQuestionId;
};
#endif