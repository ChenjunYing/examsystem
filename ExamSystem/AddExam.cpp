#include "AddExam.h"
#include "AddExamModel.h"

AddExam::AddExam(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	AddExam::refreshQuestionBank();
	AddExam::refreshComboBox();
	this->examchoicemodel = new QStandardItemModel; 
	this->exammultimodel = new QStandardItemModel;  
	this->examjudgemodel = new QStandardItemModel;
	showMulti();
	showJudge();
	showChoice();
	connect(this->ui.addQuestion, SIGNAL(clicked(bool)), this, SLOT(addQuestion()));
	connect(this->ui.choiceTable, SIGNAL(clicked(const QModelIndex&)), this, SLOT(choiceClicked(const QModelIndex&)));
	connect(this->ui.multiTable, SIGNAL(clicked(const QModelIndex&)), this, SLOT(multiClicked(const QModelIndex&)));
	connect(this->ui.judgeTable, SIGNAL(clicked(const QModelIndex&)), this, SLOT(judgeClicked(const QModelIndex&)));
	connect(this->ui.submitBtn, SIGNAL(clicked(bool)), this, SLOT(NewExam()));
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
  * @date:2019/1/2
  * @version:2.0
  */
void AddExam::setChoiceModelItemView(QStandardItemModel* model, QList<Choice>& choiceQuestionBank, QList<int> chosenChoice) {
	for (int i = 0; i < chosenChoice.size(); i++) {
		for (int j = 0; j < choiceQuestionBank.size(); j++)
		{
			if (choiceQuestionBank.at(j).getQuestionId() == chosenChoice.at(i))
			{
				QString questionId = QString::number(choiceQuestionBank.at(j).getQuestionId()); //��IDת�����ַ���
				QString value = QString::number(choiceQuestionBank.at(j).getValue()); //����ֵת�����ַ���
				model->setItem(i, 0, new QStandardItem(questionId));
				model->setItem(i, 1, new QStandardItem(choiceQuestionBank.at(j).getDescription()));
				model->setItem(i, 2, new QStandardItem(value));
				model->setItem(i, 3, new QStandardItem(QStringLiteral("ɾ��")));
				model->item(i, 0)->setTextAlignment(Qt::AlignCenter); //���þ���
				model->item(i, 1)->setTextAlignment(Qt::AlignCenter);
				model->item(i, 2)->setTextAlignment(Qt::AlignCenter);
				model->item(i, 3)->setTextAlignment(Qt::AlignCenter);
				break;
			}
		}
	}
}

/**
  * @author:��˼Ӿ
  * @brief:��Ⱦ��ѡ������
  * @date:2019/1/2
  * @version:2.0
  */
void AddExam::setMultiModelItemView(QStandardItemModel* model, QList<Choice>& multiQuestionBank, QList<int> chosenMulti) {
	for (int i = 0; i < chosenMulti.size(); i++) {
		for (int j = 0; j < multiQuestionBank.size(); j++)
		{
			if (multiQuestionBank.at(j).getQuestionId() == chosenMulti.at(i))
			{
				QString questionId = QString::number(multiQuestionBank.at(j).getQuestionId()); //��IDת�����ַ���
				QString value = QString::number(multiQuestionBank.at(j).getValue()); //����ֵת�����ַ���
				model->setItem(i, 0, new QStandardItem(questionId));
				model->setItem(i, 1, new QStandardItem(multiQuestionBank.at(j).getDescription()));
				model->setItem(i, 2, new QStandardItem(value));
				model->setItem(i, 3, new QStandardItem(QStringLiteral("ɾ��")));
				model->item(i, 0)->setTextAlignment(Qt::AlignCenter); //���þ���
				model->item(i, 1)->setTextAlignment(Qt::AlignCenter);
				model->item(i, 2)->setTextAlignment(Qt::AlignCenter);
				model->item(i, 3)->setTextAlignment(Qt::AlignCenter);
				break;
			}
		}
	}
}

/**
  * @author:��˼Ӿ
  * @brief:��Ⱦ�ж�������
  * @date:2019/1/2
  * @version:2.0
  */
void AddExam::setJudgeModelItemView(QStandardItemModel* model, QList<Judge>& judgeQuestionBank, QList<int> chosenJudge) {
	for (int i = 0; i < chosenJudge.size(); i++) {
		for (int j = 0; j < judgeQuestionBank.size(); j++)
		{
			if (judgeQuestionBank.at(j).getQuestionId() == chosenJudge.at(i))
			{
				QString questionId = QString::number(judgeQuestionBank.at(j).getQuestionId()); //��IDת�����ַ���
				QString value = QString::number(judgeQuestionBank.at(j).getValue()); //����ֵת�����ַ���
				model->setItem(i, 0, new QStandardItem(questionId));
				model->setItem(i, 1, new QStandardItem(judgeQuestionBank.at(j).getDescription()));
				model->setItem(i, 2, new QStandardItem(value));
				model->setItem(i, 3, new QStandardItem(QStringLiteral("ɾ��")));
				model->item(i, 0)->setTextAlignment(Qt::AlignCenter); //���þ���
				model->item(i, 1)->setTextAlignment(Qt::AlignCenter);
				model->item(i, 2)->setTextAlignment(Qt::AlignCenter);
				model->item(i, 3)->setTextAlignment(Qt::AlignCenter);
				break;
			}
		}
	}
}

/**
  * @author:��˼Ӿ
  * @brief:����ӵĵ�ѡ�����б�����ʾ����
  * @date:2019/1/2
  * @version:2.0
  */
void AddExam::showChoice() {
	this->examchoicemodel->clear();
	AddExam::setTableHeader(this->examchoicemodel); //��ʼ����ͷ
	this->ui.choiceTable->setModel(examchoicemodel);
	this->ui.choiceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.choiceTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed); //���õ��п��Ҳ����϶�
	AddExam::setChoiceModelItemView(this->examchoicemodel, choiceQuestionBank, chosenChoice); //��Ⱦ��ѡ��
	if (chosenChoice.size() == 0)
	{
		this->ui.choiceTable->setColumnWidth(0, 100);
		this->ui.choiceTable->setColumnWidth(1, 400);
		this->ui.choiceTable->setColumnWidth(2, 100);
		this->ui.choiceTable->setColumnWidth(3, 113);
	}
	else
	{
		this->ui.choiceTable->setColumnWidth(0, 100);
		this->ui.choiceTable->setColumnWidth(1, 400);
		this->ui.choiceTable->setColumnWidth(2, 100);
		this->ui.choiceTable->setColumnWidth(3, 88);
	}
}

/**
  * @author:��˼Ӿ
  * @brief:����ӵĶ�ѡ�����б�����ʾ����
  * @date:2019/1/2
  * @version:2.0
  */
void AddExam::showMulti() {
	this->exammultimodel->clear();
	AddExam::setTableHeader(this->exammultimodel); //��ʼ����ͷ
	this->ui.multiTable->setModel(exammultimodel);
	this->ui.multiTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.multiTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed); //���õ��п��Ҳ����϶�
	AddExam::setMultiModelItemView(this->exammultimodel, multiQuestionBank, chosenMulti); //��Ⱦ��ѡ��
	if (chosenMulti.size() == 0)
	{
		this->ui.multiTable->setColumnWidth(0, 100);
		this->ui.multiTable->setColumnWidth(1, 400);
		this->ui.multiTable->setColumnWidth(2, 100);
		this->ui.multiTable->setColumnWidth(3, 113);
	}
	else
	{
		this->ui.multiTable->setColumnWidth(0, 100);
		this->ui.multiTable->setColumnWidth(1, 400);
		this->ui.multiTable->setColumnWidth(2, 100);
		this->ui.multiTable->setColumnWidth(3, 88);
	}
}

/**
  * @author:��˼Ӿ
  * @brief:����ӵ��ж������б�����ʾ����
  * @date:2019/1/2
  * @version:2.0
  */
void AddExam::showJudge() {
	this->examjudgemodel->clear();
	AddExam::setTableHeader(this->examjudgemodel); //��ʼ����ͷ
	this->ui.judgeTable->setModel(examjudgemodel);
	this->ui.judgeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.judgeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed); //���ò����϶�
	AddExam::setJudgeModelItemView(this->examjudgemodel, judgeQuestionBank, chosenJudge); //��Ⱦ�ж���
	if (chosenJudge.size()==0)
	{
		this->ui.judgeTable->setColumnWidth(0, 100);
		this->ui.judgeTable->setColumnWidth(1, 400);
		this->ui.judgeTable->setColumnWidth(2, 100);
		this->ui.judgeTable->setColumnWidth(3, 113);
	}
	else
	{
		this->ui.judgeTable->setColumnWidth(0, 100);
		this->ui.judgeTable->setColumnWidth(1, 400);
		this->ui.judgeTable->setColumnWidth(2, 100);
		this->ui.judgeTable->setColumnWidth(3, 88);
	}
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
  * @date:2019/1/2
  * @version:2.0
  */
void AddExam::choiceClicked(const QModelIndex & index)
{
	if (index.isValid() && index.column() == 3)	//���ɾ����
	{
		int row=index.row();
		//QModelIndex index = examchoicemodel->index(row, 0);
		//int questionId = examchoicemodel->data(index).toInt();
		chosenChoice.removeAt(row);
		showChoice();
	}
}

/**
  * @author:��˼Ӿ
  * @brief:����ɾ����ѡ��
  * @date:2019/1/2
  * @version:2.0
  */
void AddExam::multiClicked(const QModelIndex & index)
{
	if (index.isValid() && index.column() == 3) //���ɾ��
	{
		int row = index.row();
		//QModelIndex index = exammultimodel->index(row, 0);
		//int questionId = exammultimodel->data(index).toInt();
		chosenMulti.removeAt(row);
		showMulti();
	}
}

/**
  * @author:��˼Ӿ
  * @brief:����ɾ���ж���
  * @date:2019/1/2
  * @version:2.0
  */
void AddExam::judgeClicked(const QModelIndex & index)
{
	if (index.isValid() && index.column() == 3)	//���ɾ��
	{
		int row = index.row();
		//QModelIndex index = examjudgemodel->index(row, 0);
		//int questionId = examjudgemodel->data(index).toInt();
		chosenJudge.removeAt(row);
		showJudge();
	}
}
/**
  * @author:��˼Ӿ
  * @brief:��������
  * @date:2019/1/2
  * @version:2.0
  */
void AddExam::NewExam()
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
			for (int i = 0; i < chosenChoice.size(); i++)
			{
				int questionId = chosenChoice.at(i);
				sql.insertChoice(exam_code,questionId);
			}
			for (int i = 0; i < chosenMulti.size(); i++)
			{
				int questionId = chosenMulti.at(i);
				sql.insertChoice(exam_code, questionId);
			}
			for (int i = 0; i < chosenJudge.size(); i++)
			{
				int questionId = chosenJudge.at(i);
				sql.insertJudge(exam_code, questionId);
			}
			sql.insertStudent(exam_code);
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
	int i = 0;
	if (type == 0)	//��ӵ�ѡ��
	{
		int index = this->ui.choiceBox->currentIndex();
		int questionId = choiceQuestionBank.at(index).getQuestionId();
		for (i = 0; i < chosenChoice.size() && chosenChoice.at(i)!=questionId; i++);
		if (i == chosenChoice.size())
		{
			chosenChoice.append(questionId);
			showChoice();
		}
		else
			QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("��������ӹ���"), QMessageBox::Yes);
	}
	else if (type == 1)	//��Ӷ�ѡ��
	{
		int index = this->ui.multiBox->currentIndex();
		int questionId = multiQuestionBank.at(index).getQuestionId();
		for (i = 0; i < chosenMulti.size() && chosenMulti.at(i) != questionId; i++);
		if (i == chosenMulti.size())
		{
			chosenMulti.append(multiQuestionBank.at(index).getQuestionId());
			showMulti();
		}
		else
			QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("��������ӹ���"), QMessageBox::Yes);
	}
	else if (type == 2)	//����ж���
	{
		int index = this->ui.judgeBox->currentIndex();
		int questionId = judgeQuestionBank.at(index).getQuestionId();
		for (i = 0; i < chosenJudge.size() && chosenJudge.at(i) != questionId; i++);
		if (i == chosenJudge.size())
		{
			chosenJudge.append(judgeQuestionBank.at(index).getQuestionId());
			showJudge();
		}
		else
			QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("��������ӹ���"), QMessageBox::Yes);
	}
}


AddExam::~AddExam() {
	delete examchoicemodel;
	delete exammultimodel;
	delete examjudgemodel;
}
