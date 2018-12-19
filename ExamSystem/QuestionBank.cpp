#include "QuestionBank.h"
#include "Question.h"
#include "AddChoice.h"

QuestionBank::QuestionBank(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	this->choicemodel = new QStandardItemModel; //������ѡ����
	this->multimodel = new QStandardItemModel;  //������ѡ����
	this->judgemodel = new QStandardItemModel;  //�����ж�����
	QuestionBank::dataRefresh();  //�����ݿ�����ȡ����
	QuestionBank::onTabChanged(0); //Ĭ����ʾ��ѡ��
	connect(this->ui.choiceTable , SIGNAL(doubleClicked(const QModelIndex&)) , this , SLOT(choiceDoubleClicked(const QModelIndex&)));
	connect(this->ui.choiceTable , SIGNAL(clicked(const QModelIndex&)) , this , SLOT(choiceClicked(const QModelIndex&)));
	connect(this->ui.multiTable , SIGNAL(doubleClicked(const QModelIndex&)) , this , SLOT(multiDoubleClicked(const QModelIndex&)));
	connect(this->ui.judgeTable , SIGNAL(doubleClicked(const QModelIndex&)) , this , SLOT(judgeDoubleClicked(const QModelIndex&)));
	connect(this->ui.tabWidget , SIGNAL(currentChanged(int)) , this , SLOT(onTabChanged(int)));
	connect(this->ui.selectBtn , SIGNAL(clicked(bool)) , this , SLOT(searchQuestion()));
	connect(this->ui.resetBtn , SIGNAL(clicked(bool)) , this , SLOT(reset()));
}

/**
  * @author:Ӧ�о�
  * @brief:ˢ�µ�ѡ�⡢��ѡ����ж��������
  * @date:2018/12/19
  * @version:2.0
  */
void QuestionBank::dataRefresh(QString keyWord, int lowerValue, int upperValue, QString author) {
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("��ʾ") , QStringLiteral("����ʧ��") , QMessageBox::Yes);
	} else {
		this->choice = sql.searchChoice(0 , keyWord , lowerValue , upperValue , author); //��ȡ����������ѡ��
		this->multichoice = sql.searchChoice(1 , keyWord , lowerValue , upperValue , author);  //��ȡ����������ѡ��
		this->judge = sql.searchJudge(keyWord , lowerValue , upperValue , author);          //��ȡ���������ж���
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
		case 0: showChoice(); break;
		case 1: showMultichoice(); break;
		case 2: showJudge(); break;
		default: break;
	}
}

/**
  * @author:��˼Ӿ
  * @brief:ʵ�ֶ�ѡ����˫���޸ĵĹ���
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::multiDoubleClicked(const QModelIndex& index) {
	if (index.isValid() && index.column() != 7 && index.column() != 8) {
		emit sendMultiChoiceData(this->multichoice.at(index.row())); //��������
	}
}

/**
  * @author:��˼Ӿ
  * @brief:ʵ�ֶ�ѡ����˫���޸ĵĹ���
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::judgeDoubleClicked(const QModelIndex& index) {
	if (index.isValid()) {
		emit sendJudgeData(this->judge.at(index.row())); //��������
	}
}

/**
  * @author:Ӧ�о�
  * @brief:��ʼ����ѡ��Ͷ�ѡ���ͷ
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::setChoiceTableHeader(QStandardItemModel* model) {
	model->setHorizontalHeaderItem(0 , new QStandardItem(QStringLiteral("��Ŀ����")));
	model->setHorizontalHeaderItem(1 , new QStandardItem(QStringLiteral("Aѡ������")));
	model->setHorizontalHeaderItem(2 , new QStandardItem(QStringLiteral("Bѡ������")));
	model->setHorizontalHeaderItem(3 , new QStandardItem(QStringLiteral("Cѡ������")));
	model->setHorizontalHeaderItem(4 , new QStandardItem(QStringLiteral("Dѡ������")));
	model->setHorizontalHeaderItem(5 , new QStandardItem(QStringLiteral("��")));
	model->setHorizontalHeaderItem(6 , new QStandardItem(QStringLiteral("��ֵ")));
	model->setHorizontalHeaderItem(7 , new QStandardItem(QStringLiteral("����")));
	model->setHorizontalHeaderItem(8 , new QStandardItem(QStringLiteral("����")));
}

/**
  * @author:Ӧ�о�
  * @brief:��ʼ���ж����ͷ
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::setJudgeTableHeader(QStandardItemModel* model) {
	model->setHorizontalHeaderItem(0 , new QStandardItem(QStringLiteral("��Ŀ����")));
	model->setHorizontalHeaderItem(1 , new QStandardItem(QStringLiteral("��")));
	model->setHorizontalHeaderItem(2 , new QStandardItem(QStringLiteral("��ֵ")));
	model->setHorizontalHeaderItem(3 , new QStandardItem(QStringLiteral("����")));
	model->setHorizontalHeaderItem(4 , new QStandardItem(QStringLiteral("����")));
}

/**
  * @author:Ӧ�о�
  * @brief:��Ⱦ��ѡ��Ͷ�ѡ�������
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::setChoiceModelItemView(QStandardItemModel* model, QList<Choice>& choice) {
	for (int i = 0; i < choice.size(); i++) {
		QString value = QString::number(choice.at(i).getValue()); //����ֵת�����ַ���
		model->setItem(i , 0 , new QStandardItem(choice.at(i).getDescription()));
		model->setItem(i , 1 , new QStandardItem(choice.at(i).getChoiceA()));
		model->setItem(i , 2 , new QStandardItem(choice.at(i).getChoiceB()));
		model->setItem(i , 3 , new QStandardItem(choice.at(i).getChoiceC()));
		model->setItem(i , 4 , new QStandardItem(choice.at(i).getChoiceD()));
		model->setItem(i , 5 , new QStandardItem(choice.at(i).getAnswer()));
		model->setItem(i , 6 , new QStandardItem(value));
		model->setItem(i , 7 , new QStandardItem(choice.at(i).getAuthor()));
		model->setItem(i , 8 , new QStandardItem(QStringLiteral("ɾ��")));
		model->item(i , 5)->setTextAlignment(Qt::AlignCenter); //���þ���
		model->item(i , 6)->setTextAlignment(Qt::AlignCenter);
		model->item(i , 7)->setTextAlignment(Qt::AlignCenter);
		model->item(i , 8)->setTextAlignment(Qt::AlignCenter);
	}
}

/**
  * @author:Ӧ�о�
  * @brief:��Ⱦ�ж��������
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::setJudgeModelItemView(QStandardItemModel* model, QList<Judge>& judge) {
	for (int i = 0; i < judge.size(); i++) {
		QString value = QString::number(judge.at(i).getValue()); //����ֵת�����ַ���
		QString answer;  //���ж���Ĵ���������ʾ
		if (judge.at(i).getAnswer() == "T") answer = QStringLiteral("��ȷ");
		else answer = QStringLiteral("����");
		model->setItem(i , 0 , new QStandardItem(judge.at(i).getDescription()));
		model->setItem(i , 1 , new QStandardItem(answer));
		model->setItem(i , 2 , new QStandardItem(value));
		model->setItem(i , 3 , new QStandardItem(judge.at(i).getAuthor()));
		model->setItem(i , 4 , new QStandardItem(QStringLiteral("ɾ��")));
		model->item(i , 1)->setTextAlignment(Qt::AlignCenter); //���þ���
		model->item(i , 2)->setTextAlignment(Qt::AlignCenter);
		model->item(i , 3)->setTextAlignment(Qt::AlignCenter);
		model->item(i , 4)->setTextAlignment(Qt::AlignCenter);
	}
}

/**
  * @author:Ӧ�о�
  * @brief:����ѡ�����������ʾ����
  * @date:2018/12/18
  * @version:3.0
  */
void QuestionBank::showChoice() {
	this->choicemodel->clear();
	QuestionBank::setChoiceTableHeader(this->choicemodel); //��ʼ����ͷ
	this->ui.choiceTable->setModel(choicemodel);
	this->ui.choiceTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //���õ��п��Ҳ����϶�
	QuestionBank::setChoiceModelItemView(this->choicemodel , choice); //��Ⱦ��ѡ��
}


/**
  * @author:Ӧ�о�
  * @brief:����ѡ�����������ʾ����
  * @date:2018/12/18
  * @version:3.0
  */
void QuestionBank::showMultichoice() {
	this->multimodel->clear();
	QuestionBank::setChoiceTableHeader(this->multimodel); //��ʼ����ͷ
	this->ui.multiTable->setModel(multimodel);
	this->ui.multiTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //���õ��п��Ҳ����϶�
	QuestionBank::setChoiceModelItemView(this->multimodel , multichoice); //��Ⱦ��ѡ��
}

/**
  * @author:Ӧ�о�
  * @brief:���ж������������ʾ����
  * @date:2018/12/16
  * @version:2.0
  */
void QuestionBank::showJudge() {
	this->judgemodel->clear();
	QuestionBank::setJudgeTableHeader(this->judgemodel); //��ʼ����ͷ
	this->ui.judgeTable->setModel(judgemodel);
	this->ui.judgeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //���õ��п��Ҳ����϶�
	QuestionBank::setJudgeModelItemView(this->judgemodel , judge); //��Ⱦ�ж���
}

/**
  * @author:Ӧ�о�
  * @brief:ʵ�ֵ�ѡ����˫���޸ĵĹ���
  * @date:2018/12/16
  * @version:1.0
  */
void QuestionBank::choiceDoubleClicked(const QModelIndex& index) {
	if (index.isValid() && index.column() != 7 && index.column() != 8) {  //����Ϸ�
		emit sendChoiceData(this->choice.at(index.row())); //��������
	}
}

/**
  * @author:Ӧ�о�
  * @brief:ʵ�ֵ�ѡ����ɾ���񴦵���ɾ���Ĺ���
  * @date:2018/12/19
  * @version:1.0
  */
void QuestionBank::choiceClicked(const QModelIndex& index) {
	SqlModel sql;
	if (index.isValid() && index.column() == 8) {  //�����ɾ����ť
		int ret = QMessageBox::warning(this , QStringLiteral("��ʾ") , QStringLiteral("ȷ��ɾ���������ɾ�����޷��ָ���") , QMessageBox::Yes | QMessageBox::Cancel);
		if (ret == QMessageBox::Yes) {
			int id = choice.at(index.row()).getQuestionId();
			if (sql.isOpen() && sql.deleteChoice(id)) {
				QMessageBox::information(this , QStringLiteral("��ʾ") , QStringLiteral("ɾ���ɹ���") , QMessageBox::Ok);
				QuestionBank::searchQuestion(); //ˢ��ҳ��
			} else {
				QMessageBox::information(this , QStringLiteral("��ʾ") , QStringLiteral("ɾ��ʧ�ܣ�") , QMessageBox::Ok);
			}
		}
	}
}

/**
  * @author:Ӧ�о�
  * @brief:����������
  * @date:2018/12/19
  * @version:1.0
  */
void QuestionBank::searchQuestion() {
	int lowerValue = this->ui.lowerValue->value();
	int upperValue = this->ui.upperValue->value();
	QString keyWord = this->ui.keywordSelector->text();
	QString author = this->ui.authorSelector->text();
	QuestionBank::dataRefresh(keyWord , lowerValue , upperValue , author);
	QuestionBank::onTabChanged(this->ui.tabWidget->currentIndex());
}

/**
  * @author:Ӧ�о�
  * @brief:����ɸѡ��
  * @date:2018/12/19
  * @version:1.0
  */
void QuestionBank::reset() {
	this->ui.lowerValue->setValue(0);
	this->ui.upperValue->setValue(100);
	this->ui.keywordSelector->clear();
	this->ui.authorSelector->clear();
}

/**
  * @author:Ӧ�о�
  * @brief:�޸���ɺ���ҳ��ˢ��
  * @date:2018/12/17
  * @version:1.0
  */
void QuestionBank::receiveOK(int index) {
	QuestionBank::reset(); //����ɸѡ����
	QuestionBank::dataRefresh();  //ˢ��ҳ������
	switch (index) {
		case 0: QuestionBank::showChoice(); break;
		case 1: QuestionBank::showMultichoice(); break;
		case 2: QuestionBank::showJudge(); break;
		default: break;
	}
}

QuestionBank::~QuestionBank() {
	delete choicemodel;
	delete multimodel;
	delete judgemodel;
}