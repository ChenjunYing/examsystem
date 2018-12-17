#pragma once
#include "Question.h"

/*
 * Student��̳���Exam�࣬��װ��ѧ���������Ϣ�Լ�����
 */
class Student :public Exam {
public:
	Student(int oScore,int jScore, int flag, QString name, int code ,int duration);
	~Student();
	int getObjectScore() const;
	int getJudgeScore() const;
	int getScore() const;
	int getIsSubmit() const;
private:
	Student();
	int objectScore;
	int judgeScore;
	int score;
	int isSubmit;
};