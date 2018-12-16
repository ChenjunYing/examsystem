#include "QuestionBank.h"
#include "SqlModel.h"
#include "Question.h"
#include "AddChoice.h"

QuestionBank::QuestionBank(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	this->choicemodel = new QStandardItemModel; //������ѡ����
	this->multimodel = new QStandardItemModel;  //������ѡ����
	this->judgemodel = new QStandardItemModel;  //�����ж�����
	
	QuestionBank::dataRefresh();  //�����ݿ�����ȡ����
	QuestionBank::onTabChanged(0); //Ĭ����ʾ��ѡ��
	connect(this->ui.choiceTable , SIGNAL(doubleClicked(const QModelIndex&)) , this , SLOT(choiceDoubleClicked()));
	connect(this->ui.tabWidget , SIGNAL(currentChanged(int)) , this , SLOT(onTabChanged(int)));
}


/**
  * @author:Ӧ�о�
  * @brief:ʵ�ֵ�ѡ����˫���޸ĵĹ���
  * @date:2018/12/16
  * @version:1.0
  */
void QuestionBank::choiceDoubleClicked() {
	QModelIndex index = this->ui.choiceTable->currentIndex();
	int row = index.row();
	int col = index.column();
	QString Data = index.data().toString();
	
	if (index.isValid()) {
		AddChoice a;
		a.ui.label->setText(QStringLiteral("�޸ĵ�ѡ��"));   //�޸ı�������
		a.ui.submitBtn->setText(QStringLiteral("��   ��"));  //�޸İ�ť����

		a.exec();  //���޸�ģ̬��
	}
}

/**
  * @author:Ӧ�о�
  * @brief:����ѡ�����������ʾ����
  * @date:2018/12/16
  * @version:2.0
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
	QuestionBank::dataRefresh();
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

/**
  * @author:Ӧ�о�
  * @brief:����ѡ�����������ʾ����
  * @date:2018/12/16
  * @version:2.0
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
	QuestionBank::dataRefresh();
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

/**
  * @author:Ӧ�о�
  * @brief:���ж������������ʾ����
  * @date:2018/12/16
  * @version:2.0
  */
void QuestionBank::showJudge() {
	this->judgemodel->clear();
	this->judgemodel->setHorizontalHeaderItem(0 , new QStandardItem(QStringLiteral("��Ŀ����")));
	this->judgemodel->setHorizontalHeaderItem(1 , new QStandardItem(QStringLiteral("��")));
	this->judgemodel->setHorizontalHeaderItem(2 , new QStandardItem(QStringLiteral("��ֵ")));
	this->judgemodel->setHorizontalHeaderItem(3 , new QStandardItem(QStringLiteral("����")));
	this->ui.judgeTable->setModel(judgemodel);
	QuestionBank::dataRefresh();
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

/**
  * @author:Ӧ�о�
  * @brief:ˢ�µ�ѡ�⡢��ѡ����ж��������
  * @date:2018/12/16
  * @version:1.0
  */
void QuestionBank::dataRefresh() {
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("��ʾ") , QStringLiteral("����ʧ��") , QMessageBox::Yes);
		this->close();
	} else {
		this->choice = sql.searchChoice(0);       //��ȡ���е�ѡ��
		this->multichoice = sql.searchChoice(1);  //��ȡ���ж�ѡ��
		this->judge = sql.searchJudge();          //��ȡ�����ж���
	}
}

/**
  * @author:Ӧ�о�
  * @brief:���ݵ����TabBar��ʾ��Ӧ������,0Ϊ��ѡ��,1Ϊ��ѡ��,2Ϊ�ж���
  * @date:2018/12/16
  * @version:1.0
  */
void QuestionBank::onTabChanged(int index) {
	switch (index) {
		case 0:
			showChoice();
			break;
		case 1:
			showMultichoice();
			break;
		case 2:
			showJudge();
			break;
		default:
			break;
	}
}

QuestionBank::~QuestionBank() {
	delete choicemodel;
	delete multimodel;
	delete judgemodel;
}