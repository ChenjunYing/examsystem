#ifndef _EXAM_H
#define _EXAM_H

#include <QList>
#include <QString>
#include "Question.h"

class Exam {

public:
	Exam(int examCode , int duration , QString examName , QString information);
	~Exam();
	int getExamCode() const;
	int getDuration() const;
	void addChoiceQuestion(Choice newQuestion);
	void addJudgeQuestion(Judge newQuestion);
	QString getExamName() const;
	QString getInformation() const;
	QList<Choice> getChoice() const;
	QList<Judge> getJudge() const;

private:
	int examCode;
	int duration;
	QString examName;
	QString information;
	QList<Choice> choice;
	QList<Judge> judge;
	Exam();

};

#endif