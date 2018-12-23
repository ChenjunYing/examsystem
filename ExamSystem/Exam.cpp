#include "Exam.h"

Exam::Exam(int examCode , int duration , QString examName , QString information) {
	this->examCode = examCode;
	this->duration = duration;
	this->examName = examName;
	this->information = information;
}

void Exam::addChoiceQuestion(Choice newQuestion) {
	this->choice.push_back(newQuestion);
}

void Exam::addJudgeQuestion(Judge newQuestion) {
	this->judge.push_back(newQuestion);
}

int Exam::getExamCode() const {
	return examCode;
}

int Exam::getDuration() const {
	return duration;
}

QString Exam::getExamName() const {
	return examName;
}

QString Exam::getInformation() const {
	return information;
}

QList<Choice> Exam::getChoice() const {
	return choice;
}

QList<Judge> Exam::getJudge() const {
	return judge;
}

Exam::~Exam() {

}
