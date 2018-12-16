#ifndef _QUESTION_H
#define _QUESTION_H

/*
 * Qustion���װ������������Ϣ�Լ�����
 */
#include<QString>
#include<QSqlQuery>

class Question{
public:
	Question(QString description , QString answer , int value , QString author = "admin");
	int getValue() const;
	QString getDescription() const;
	QString getAnswer() const;
	QString getAuthor() const;
	~Question();
private:
	int value;
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
	Choice(QString description , QString choiceA , QString choiceB , QString choiceC ,
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
	Judge(QString description , QString answer , int value , QString author = "admin");
	QString getChoiceA() const;
	QString getChoiceB() const;
	~Judge();
private:
	QString choiceA;
	QString choiceB;
	Judge(); //������ʹ��Ĭ���޲ι��캯��
};

#endif