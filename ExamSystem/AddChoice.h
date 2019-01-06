#ifndef _ADDCHOICE_H
#define _ADDCHOICE_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QMessagebox>
#include "ui_AddChoice.h"
#include "Question.h"

class AddChoice : public QDialog{

	Q_OBJECT

public:
	AddChoice(QWidget *parent = Q_NULLPTR);
	~AddChoice();
	friend class QuestionBank;

signals: void updateOK(int);
signals: void sendChoicePage(AddChoice*);

public slots:
	void resetData();

private slots:
	void checkData();
	void checkUpdateData();
	void receiveData(Choice c);
	QString convertAnswer(int index);

private:
	Ui::AddChoice ui;
	int tempQuestionId;
};

#endif