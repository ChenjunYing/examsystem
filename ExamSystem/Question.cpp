#include "Question.h"
#include <QSqlQuery>
#include <QString>

Question::Question(int id , QString description , QString answer , int value , QString author) {
	this->questionId = id;
	this->description = description;
	this->answer = answer;
	this->value = value;
	this->author = author;
}

int Question::getValue() const {
	return value;
}

int Question::getQuestionId() const {
	return questionId;
}

QString Question::getDescription() const {
	return description;
}

QString Question::getAnswer() const {
	return answer;
}

QString Question::getAuthor() const {
	return author;
}

Question::~Question() {

}

Choice::Choice(int id , QString description , QString choiceA , QString choiceB , QString choiceC ,
	QString choiceD , QString answer , int value , QString author) :
	Question(id , description , answer , value , author) {
	this->choiceA = choiceA;
	this->choiceB = choiceB;
	this->choiceC = choiceC;
	this->choiceD = choiceD;
}

QString Choice::getChoiceA() const {
	return choiceA;
}

QString Choice::getChoiceB() const {
	return choiceB;
}

QString Choice::getChoiceC() const {
	return choiceC;
}

QString Choice::getChoiceD() const {
	return choiceD;
}

Choice::~Choice() {

}

Judge::Judge(int id , QString description , QString answer , int value , QString author)
	: Question(id , description , answer , value , author) {

}

QString Judge::getChoiceA() const {
	return choiceA;
}
QString Judge::getChoiceB() const {
	return choiceB;
}

Judge::~Judge() {

}