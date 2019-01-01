#include "AddExam.h"
#include "AddExamModel.h"

AddExam::AddExam(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	AddExam::refreshQuestionBank();
	AddExam::refreshComboBox();
	this->examchoicemodel = new QStandardItemModel; 
	this->exammultimodel = new QStandardItemModel;  
	this->examjudgemodel = new QStandardItemModel;
	this->chosenChoice = new int[choiceQuestionBank.size()];
	this->chosenMulti = new int[multiQuestionBank.size()];
	this->chosenJudge = new int[judgeQuestionBank.size()];
	showMulti();
	showJudge();
	showChoice();
	connect(this->ui.addQuestion, SIGNAL(clicked(bool)), this, SLOT(addQuestion()));
	connect(this->ui.choiceTable, SIGNAL(clicked(const QModelIndex&)), this, SLOT(choiceClicked(const QModelIndex&)));
	connect(this->ui.multiTable, SIGNAL(clicked(const QModelIndex&)), this, SLOT(multiClicked(const QModelIndex&)));
	connect(this->ui.judgeTable, SIGNAL(clicked(const QModelIndex&)), this, SLOT(judgeClicked(const QModelIndex&)));
	connect(this->ui.submitBtn, SIGNAL(clicked(bool)), this, SLOT(creatExam()));
}

/**
  * @author:Ӧ�о�
  * @brief:���������ȡ����
  * @date:2018/12/29
  * @version:1.0
  */
void AddExam::refreshQuestionBank() {
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("��ʾ") , QStringLiteral("����ʧ��") , QMessageBox::Yes);
		this->close();
	} else {
		choiceQuestionBank = sql.searchChoice(0);
		multiQuestionBank = sql.searchChoice(1);
		judgeQuestionBank = sql.searchJudge();
	}
}

/**
  * @author:Ӧ�о�
  * @brief:�������������ʾ��Combobox��
  * @date:2018/12/29
  * @version:1.0
  */
void AddExam::refreshComboBox() {
	int index;
	QString questionId;
	for (index = 0; index < choiceQuestionBank.length(); index++) {
		questionId = "[" + QString::number(choiceQuestionBank.at(index).getQuestionId()) + "] ";
		this->ui.choiceBox->insertItem(index , questionId + choiceQuestionBank.at(index).getDescription());
	}
	for (index = 0; index < multiQuestionBank.length(); index++) {
		questionId = "[" + QString::number(multiQuestionBank.at(index).getQuestionId())+ "] ";
		this->ui.multiBox->insertItem(index , questionId + multiQuestionBank.at(index).getDescription());
	}
	for (index = 0; index < judgeQuestionBank.length(); index++) {
		questionId = "[" + QString::number(judgeQuestionBank.at(index).getQuestionId()) + "] ";
		this->ui.judgeBox->insertItem(index , questionId + judgeQuestionBank.at(index).getDescription());
	}
}

/**
  * @author:��˼Ӿ
  * @brief:��Ⱦ��ѡ������
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::setChoiceModelItemView(QStandardItemModel* model, QList<Choice>& choiceQuestionBank, int* chosenChoice) {
	int j = 0;
	for (int i = 0; i < choiceQuestionBank.size(); i++) {
		QString questionId = QString::number(choiceQuestionBank.at(i).getQuestionId()); //��IDת�����ַ���
		if (chosenChoice[choiceQuestionBank.at(i).getQuestionId()] == 1)
		{
			QString value = QString::number(choiceQuestionBank.at(i).getValue()); //����ֵת�����ַ���
			model->setItem(j, 0, new QStandardItem(questionId));
			model->setItem(j, 1, new QStandardItem(choiceQuestionBank.at(i).getDescription()));
			model->setItem(j, 2, new QStandardItem(value));
			model->setItem(j, 3,new QStandardItem(QStringLiteral("ɾ��")));
			j++;
		}
	}
}

/**
  * @author:��˼Ӿ
  * @brief:��Ⱦ��ѡ������
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::setMultiModelItemView(QStandardItemModel* model, QList<Choice>& multiQuestionBank, int* chosenMulti) {
	int j = 0;
	for (int i = 0; i < multiQuestionBank.size(); i++) {
		QString questionId = QString::number(multiQuestionBank.at(i).getQuestionId()); //��IDת�����ַ���
		if (chosenMulti[multiQuestionBank.at(i).getQuestionId()] == 1)
		{
			QString value = QString::number(multiQuestionBank.at(i).getValue()); //����ֵת�����ַ���
			model->setItem(j, 0, new QStandardItem(questionId));
			model->setItem(j, 1, new QStandardItem(multiQuestionBank.at(i).getDescription()));
			model->setItem(j, 2, new QStandardItem(value));
			model->setItem(j, 3, new QStandardItem(QStringLiteral("ɾ��")));
			j++;
		}
	}
}

/**
  * @author:��˼Ӿ
  * @brief:��Ⱦ�ж�������
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::setJudgeModelItemView(QStandardItemModel* model, QList<Judge>& judgeQuestionBank,int* chosenJudge) {
	int j = 0;
	for (int i = 0; i < judgeQuestionBank.size(); i++) {
		QString questionId = QString::number(judgeQuestionBank.at(i).getQuestionId()); //��IDת�����ַ���
		if (chosenJudge[judgeQuestionBank.at(i).getQuestionId()] == 1)
		{
			QString value = QString::number(judgeQuestionBank.at(i).getValue()); //����ֵת�����ַ���
			model->setItem(j, 0, new QStandardItem(questionId));
			model->setItem(j, 1, new QStandardItem(judgeQuestionBank.at(i).getDescription()));
			model->setItem(j, 2, new QStandardItem(value));
			model->setItem(j, 3, new QStandardItem(QStringLiteral("ɾ��")));
			j++;
		}
	}
}

/**
  * @author:��˼Ӿ
  * @brief:����ӵĵ�ѡ�����б�����ʾ����
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::showChoice() {
	this->examchoicemodel->clear();
	AddExam::setTableHeader(this->examchoicemodel); //��ʼ����ͷ
	this->ui.choiceTable->setModel(examchoicemodel);
	this->ui.choiceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.choiceTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //���õ��п��Ҳ����϶�
	AddExam::setChoiceModelItemView(this->examchoicemodel, choiceQuestionBank, chosenChoice); //��Ⱦ��ѡ��
}

/**
  * @author:��˼Ӿ
  * @brief:����ӵĶ�ѡ�����б�����ʾ����
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::showMulti() {
	this->exammultimodel->clear();
	AddExam::setTableHeader(this->exammultimodel); //��ʼ����ͷ
	this->ui.multiTable->setModel(exammultimodel);
	this->ui.multiTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.multiTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //���õ��п��Ҳ����϶�
	AddExam::setMultiModelItemView(this->exammultimodel, multiQuestionBank, chosenMulti); //��Ⱦ��ѡ��
}

/**
  * @author:��˼Ӿ
  * @brief:����ӵ��ж������б�����ʾ����
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::showJudge() {
	this->examjudgemodel->clear();
	AddExam::setTableHeader(this->examjudgemodel); //��ʼ����ͷ
	this->ui.judgeTable->setModel(examjudgemodel);
	this->ui.judgeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.judgeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //���õ��п��Ҳ����϶�
	AddExam::setJudgeModelItemView(this->examjudgemodel, judgeQuestionBank, chosenJudge); //��Ⱦ�ж���
}

/**
  * @author:��˼Ӿ
  * @brief:��ʼ����ͷ
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::setTableHeader(QStandardItemModel* model) {
	model->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("QuestionID")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("��Ŀ����")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("��ֵ")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("����")));
}

/**
  * @author:��˼Ӿ
  * @brief:����ɾ����ѡ��
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::choiceClicked(const QModelIndex & index)
{
	if (index.isValid() && index.column() == 3)	//���ɾ����
	{
		int row=index.row();
		QModelIndex index = examchoicemodel->index(row, 0);
		int questionId = examchoicemodel->data(index).toInt();
		chosenChoice[questionId] = 0;
		showChoice();
	}
}

/**
  * @author:��˼Ӿ
  * @brief:����ɾ����ѡ��
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::multiClicked(const QModelIndex & index)
{
	if (index.isValid() && index.column() == 3) //���ɾ��
	{
		int row = index.row();
		QModelIndex index = exammultimodel->index(row, 0);
		int questionId = exammultimodel->data(index).toInt();
		chosenMulti[questionId] = 0;
		showMulti();
	}
}

/**
  * @author:��˼Ӿ
  * @brief:����ɾ���ж���
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::judgeClicked(const QModelIndex & index)
{
	if (index.isValid() && index.column() == 3)	//���ɾ��
	{
		int row = index.row();
		QModelIndex index = examjudgemodel->index(row, 0);
		int questionId = examjudgemodel->data(index).toInt();
		chosenJudge[questionId] = 0;
		showJudge();
	}
}

void AddExam::creatExam()
{
	QString examName = this->ui.examName->text(); //��ȡ�Ծ�����
	int examTime = this->ui.examTime->value(); //��ȡ����ʱ��
	QString examInformation = this->ui.examInformation->toPlainText(); //��ȡ�Ծ�˵��
	if (!examName.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("�Ծ����Ʋ���Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (!examTime) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("����ʱ�䲻��Ϊ�㣡"), QMessageBox::Yes);
	}
	else if (!examInformation.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("�Ծ�˵������Ϊ�գ�"), QMessageBox::Yes);
	}
	else {
		AddExamModel sql;
		bool information; //����ɹ�����true,���򷵻�false
		information = sql.insertExam(examName, examTime, examInformation);
		if (information) {
			int exam_code = sql.searchExam(examName);
			for (int i = 0; i < choiceQuestionBank.size(); i++)
			{
				int questionId = choiceQuestionBank.at(i).getQuestionId();
				if (chosenChoice[questionId] == 1)
				{
					sql.insertChoice(exam_code,questionId);
				}
			}
			for (int i = 0; i < multiQuestionBank.size(); i++)
			{
				int questionId = multiQuestionBank.at(i).getQuestionId();
				if (chosenMulti[questionId] == 1)
				{
					sql.insertChoice(exam_code, questionId);
				}
			}
			for (int i = 0; i < judgeQuestionBank.size(); i++)
			{
				int questionId = judgeQuestionBank.at(i).getQuestionId();
				if (chosenJudge[questionId] == 1)
				{
					sql.insertJudge(exam_code, questionId);
				}
			}
			QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("�����ɹ���"), QMessageBox::Yes);
			this->close();
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("����ʧ�ܣ�"), QMessageBox::Yes);
		}
	}
}

/**
  * @author:��˼Ӿ
  * @brief:�����Ŀ
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::addQuestion()
{
	int type = this->ui.tabWidget->currentIndex();
	if (type == 0)	//��ӵ�ѡ��
	{
		int index = this->ui.choiceBox->currentIndex();
		chosenChoice[choiceQuestionBank.at(index).getQuestionId()] = 1;
		showChoice();
	}
	else if (type == 1)	//��Ӷ�ѡ��
	{
		int index = this->ui.multiBox->currentIndex();
		chosenMulti[multiQuestionBank.at(index).getQuestionId()] = 1;
		showMulti();
	}
	else if (type == 2)	//����ж���
	{
		int index = this->ui.judgeBox->currentIndex();
		chosenJudge[judgeQuestionBank.at(index).getQuestionId()] = 1;
		showJudge();
	}
}


AddExam::~AddExam() {
	if (chosenChoice)
		delete[] chosenChoice;
	if (chosenMulti)
		delete[] chosenMulti;
	if (chosenJudge)
		delete[] chosenJudge;
	delete examchoicemodel;
	delete exammultimodel;
	delete examjudgemodel;
}
