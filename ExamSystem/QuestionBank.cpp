#include "QuestionBank.h"
#include "SqlModel.h"
#include "Question.h"

QuestionBank::QuestionBank(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	this->choicemodel = new QStandardItemModel;
	this->multimodel = new QStandardItemModel;
	this->judgemodel = new QStandardItemModel;
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("��ʾ") , QStringLiteral("����ʧ��") , QMessageBox::Yes);
		this->close();
	} else {
		//choice = sql.searchChoice(0);   //��ȡ���е�ѡ��
		showChoice();
		showMultichoice();
		showJudge();
	}
	//SIGNAL(this->ui.)

}

/**
  * @author:Ӧ�о�
  * @brief:����ѡ�����������ʾ����
  * @date:2018/12/15
  * @version:1.0
  */
void QuestionBank::showChoice() {
	this->choicemodel->clear();
	this->choicemodel->setHorizontalHeaderItem(0 , new QStandardItem(QStringLiteral("��Ŀ����")));
	this->choicemodel->setHorizontalHeaderItem(1 , new QStandardItem(QStringLiteral("Aѡ������")));
	this->choicemodel->setHorizontalHeaderItem(2 , new QStandardItem(QStringLiteral("Bѡ������")));
	this->choicemodel->setHorizontalHeaderItem(3 , new QStandardItem(QStringLiteral("Cѡ������")));
	this->choicemodel->setHorizontalHeaderItem(4 , new QStandardItem(QStringLiteral("Dѡ������")));
	this->choicemodel->setHorizontalHeaderItem(5 , new QStandardItem(QStringLiteral("��")));
	this->choicemodel->setHorizontalHeaderItem(6 , new QStandardItem(QStringLiteral("��ֵ")));
	this->choicemodel->setHorizontalHeaderItem(7 , new QStandardItem(QStringLiteral("����")));
	this->ui.choiceTable->setModel(choicemodel);
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("��ʾ") , QStringLiteral("����ʧ��") , QMessageBox::Yes);
		this->close();
	} else {
		choice = sql.searchChoice(0); //��ȡ���е�ѡ��
		for (int i = 0; i < choice.size(); i++) {
			QString value = QString::number(choice.at(i).getValue()); //����ֵת�����ַ���
			this->choicemodel->setItem(i , 0 , new QStandardItem(choice.at(i).getDescription()));
			this->choicemodel->setItem(i , 1 , new QStandardItem(choice.at(i).getChoiceA()));
			this->choicemodel->setItem(i , 2 , new QStandardItem(choice.at(i).getChoiceB()));
			this->choicemodel->setItem(i , 3 , new QStandardItem(choice.at(i).getChoiceC()));
			this->choicemodel->setItem(i , 4 , new QStandardItem(choice.at(i).getChoiceD()));
			this->choicemodel->setItem(i , 5 , new QStandardItem(choice.at(i).getAnswer()));
			this->choicemodel->setItem(i , 6 , new QStandardItem(value));
			this->choicemodel->setItem(i , 7 , new QStandardItem(choice.at(i).getAuthor()));
		}
	}
}

/**
  * @author:Ӧ�о�
  * @brief:����ѡ�����������ʾ����
  * @date:2018/12/15
  * @version:1.0
  */
void QuestionBank::showMultichoice() {
	this->multimodel->clear();
	this->multimodel->setHorizontalHeaderItem(0 , new QStandardItem(QStringLiteral("��Ŀ����")));
	this->multimodel->setHorizontalHeaderItem(1 , new QStandardItem(QStringLiteral("Aѡ������")));
	this->multimodel->setHorizontalHeaderItem(2 , new QStandardItem(QStringLiteral("Bѡ������")));
	this->multimodel->setHorizontalHeaderItem(3 , new QStandardItem(QStringLiteral("Cѡ������")));
	this->multimodel->setHorizontalHeaderItem(4 , new QStandardItem(QStringLiteral("Dѡ������")));
	this->multimodel->setHorizontalHeaderItem(5 , new QStandardItem(QStringLiteral("��")));
	this->multimodel->setHorizontalHeaderItem(6 , new QStandardItem(QStringLiteral("��ֵ")));
	this->multimodel->setHorizontalHeaderItem(7 , new QStandardItem(QStringLiteral("����")));
	this->ui.multiTable->setModel(multimodel);
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("��ʾ") , QStringLiteral("����ʧ��") , QMessageBox::Yes);
		this->close();
	} else {
		multichoice = sql.searchChoice(1);  //��ȡ���ж�ѡ��
		for (int i = 0; i < multichoice.size(); i++) {
			QString value = QString::number(multichoice.at(i).getValue()); //����ֵת�����ַ���
			this->multimodel->setItem(i , 0 , new QStandardItem(multichoice.at(i).getDescription()));
			this->multimodel->setItem(i , 1 , new QStandardItem(multichoice.at(i).getChoiceA()));
			this->multimodel->setItem(i , 2 , new QStandardItem(multichoice.at(i).getChoiceB()));
			this->multimodel->setItem(i , 3 , new QStandardItem(multichoice.at(i).getChoiceC()));
			this->multimodel->setItem(i , 4 , new QStandardItem(multichoice.at(i).getChoiceD()));
			this->multimodel->setItem(i , 5 , new QStandardItem(multichoice.at(i).getAnswer()));
			this->multimodel->setItem(i , 6 , new QStandardItem(value));
			this->multimodel->setItem(i , 7 , new QStandardItem(multichoice.at(i).getAuthor()));
		}
	}
}

/**
  * @author:Ӧ�о�
  * @brief:���ж������������ʾ����
  * @date:2018/12/15
  * @version:1.0
  */
void QuestionBank::showJudge() {
	this->judgemodel->clear();
	this->judgemodel->setHorizontalHeaderItem(0 , new QStandardItem(QStringLiteral("��Ŀ����")));
	this->judgemodel->setHorizontalHeaderItem(1 , new QStandardItem(QStringLiteral("��")));
	this->judgemodel->setHorizontalHeaderItem(2 , new QStandardItem(QStringLiteral("��ֵ")));
	this->judgemodel->setHorizontalHeaderItem(3 , new QStandardItem(QStringLiteral("����")));
	this->ui.judgeTable->setModel(judgemodel);
	qDebug() << "judge";
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("��ʾ") , QStringLiteral("����ʧ��") , QMessageBox::Yes);
		this->close();
	} else {
		judge = sql.searchJudge();  //��ȡ�����ж���
		for (int i = 0; i < judge.size(); i++) {
			QString value = QString::number(judge.at(i).getValue()); //����ֵת�����ַ���
			QString answer;  //���ж���Ĵ���������ʾ
			if (judge.at(i).getAnswer() == "T") answer = QStringLiteral("��ȷ");
			else answer = QStringLiteral("����");
			this->judgemodel->setItem(i , 0 , new QStandardItem(judge.at(i).getDescription()));
			this->judgemodel->setItem(i , 1 , new QStandardItem(answer));
			this->judgemodel->setItem(i , 2 , new QStandardItem(value));
			this->judgemodel->setItem(i , 3 , new QStandardItem(judge.at(i).getAuthor()));
		}
	}
	
}

QuestionBank::~QuestionBank() {
	delete choicemodel;
	delete multimodel;
	delete judgemodel;
}