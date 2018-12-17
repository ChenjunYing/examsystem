#include "User.h"

Student::Student(int oScore, int jScore, int flag, QString name, int code, int duration) :Exam(name, code, duration)
{
	isSubmit = flag;
	if (flag == 1) {
		this->score += oScore + jScore;
	}
	else
	{
		score = 0;
	}
}

Student::~Student()
{
}

int Student::getObjectScore() const
{
	return objectScore;
}

int Student::getJudgeScore() const
{
	return judgeScore;
}

int Student::getScore() const
{
	return score;
}

int Student::getIsSubmit() const
{
	return isSubmit;
}
