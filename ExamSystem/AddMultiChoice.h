#ifndef _ADDMULTICHOICE_H
#define _ADDMULTICHOICE_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QMessagebox>
#include "ui_AddMultiChoice.h"
#include "Question.h"

class AddMultiChoice : public QDialog {

	Q_OBJECT

public:
	AddMultiChoice(QWidget *parent = Q_NULLPTR);
	~AddMultiChoice();
	friend class QuestionBank;

signals: void updateOK(int);
signals: void sendMultiChoicePage(AddMultiChoice*);

public slots:
	void resetData();

private slots:
	void checkData();
	void checkUpdateData();
	void receiveData(Choice c);
	QString convertAnswer(bool *answer);
	
private:
	Ui::AddMultiChoice ui;
	int tempQuestionId;

};

#endif