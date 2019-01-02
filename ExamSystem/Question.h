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
	void writeAnswer(QString answer);
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
 * Config���װ��һ�����Ե������Ϣ�Լ�����
 */
class Config {
public:
	Config::Config(int cScore , int mScore , int jScore , int flag , QString Name , int Code , int Duration);
	QString getName() const;
	int getCode() const;
	int getDuration() const;
	int getChoiceScore() const;
	int getMultiScore() const;
	int getJudgeScore() const;
	int getScore() const;
	int getIsSubmit() const;
	~Config();
private:
	QString name;
	int code;
	int duration;
	int choiceScore;
	int multiScore;
	int judgeScore;
	int score;
	int isSubmit;
	Config();//������ʹ��Ĭ���޲ι��캯��
};

class Score :public Config {
public:
	Score(QString name, int oScore, int jScore, int flag, QString Name, int Code, int Duration);
	~Score();
	QString getstudentName() const;
private:
	Score();
	QString studentName;
};
#endif