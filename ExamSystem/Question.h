#ifndef _QUESTION_H
#define _QUESTION_H

/*
 * Qustion���װ������������Ϣ�Լ�����
 */
#include<QString>
#include<QSqlQuery>

class Question{
public:
	Question(int id , QString description , QString answer , int value , QString author = "admin");
	int getValue() const;
	int getQuestionId() const;
	QString getDescription() const;
	QString getAnswer() const;
	QString getAuthor() const;
	~Question();
private:
	int value;
	int questionId;
	QString description;
	QString answer;
	QString author;
	Question() {}; //������ʹ��Ĭ���޲ι��캯��
};

/*
 * Choice���װ��ѡ����(��ѡ�Ͷ�ѡ)�������Ϣ�Լ�����
 */
class Choice :public Question {
public:
	Choice(int id , QString description , QString choiceA , QString choiceB , QString choiceC ,
		QString choiceD , QString answer , int value , QString author = "admin");
	QString getChoiceA() const;
	QString getChoiceB() const;
	QString getChoiceC() const;
	QString getChoiceD() const;
	~Choice();
private:
	Choice(); //������ʹ��Ĭ���޲ι��캯��
	QString choiceA;
	QString choiceB;
	QString choiceC;
	QString choiceD;
};

/*
 * Jugde���װ���ж���������Ϣ�Լ�����
 */
class Judge :public Question {
public:
	Judge(int id , QString description , QString answer , int value , QString author = "admin");
	QString getChoiceA() const;
	QString getChoiceB() const;
	~Judge();
private:
	QString choiceA;
	QString choiceB;
	Judge(); //������ʹ��Ĭ���޲ι��캯��
};

/*
 * Exam���װ��һ�����Ե������Ϣ�Լ�����
 */
class Exam {
public:
	Exam(QString Name,  int Code, int Duration);
	QString getName() const;
	int getCode() const;
	int getDuration() const;
	~Exam(); 
private:
	QString name;
	int code;
	int duration;
	Exam();//������ʹ��Ĭ���޲ι��캯��
};
#endif