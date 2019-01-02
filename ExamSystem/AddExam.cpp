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
  * @author:应承峻
  * @brief:从题库中拉取试题
  * @date:2018/12/29
  * @version:1.0
  */
void AddExam::refreshQuestionBank() {
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("提示") , QStringLiteral("连接失败") , QMessageBox::Yes);
		this->close();
	} else {
		choiceQuestionBank = sql.searchChoice(0);
		multiQuestionBank = sql.searchChoice(1);
		judgeQuestionBank = sql.searchJudge();
	}
}

/**
  * @author:应承峻
  * @brief:将题库中内容显示在Combobox中
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
  * @author:黄思泳
  * @brief:渲染单选题内容
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::setChoiceModelItemView(QStandardItemModel* model, QList<Choice>& choiceQuestionBank, int* chosenChoice) {
	int j = 0;
	for (int i = 0; i < choiceQuestionBank.size(); i++) {
		QString questionId = QString::number(choiceQuestionBank.at(i).getQuestionId()); //将ID转换成字符串
		if (chosenChoice[choiceQuestionBank.at(i).getQuestionId()] == 1)
		{
			QString value = QString::number(choiceQuestionBank.at(i).getValue()); //将分值转换成字符串
			model->setItem(j, 0, new QStandardItem(questionId));
			model->setItem(j, 1, new QStandardItem(choiceQuestionBank.at(i).getDescription()));
			model->setItem(j, 2, new QStandardItem(value));
			model->setItem(j, 3,new QStandardItem(QStringLiteral("删除")));
			j++;
		}
	}
}

/**
  * @author:黄思泳
  * @brief:渲染多选题内容
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::setMultiModelItemView(QStandardItemModel* model, QList<Choice>& multiQuestionBank, int* chosenMulti) {
	int j = 0;
	for (int i = 0; i < multiQuestionBank.size(); i++) {
		QString questionId = QString::number(multiQuestionBank.at(i).getQuestionId()); //将ID转换成字符串
		if (chosenMulti[multiQuestionBank.at(i).getQuestionId()] == 1)
		{
			QString value = QString::number(multiQuestionBank.at(i).getValue()); //将分值转换成字符串
			model->setItem(j, 0, new QStandardItem(questionId));
			model->setItem(j, 1, new QStandardItem(multiQuestionBank.at(i).getDescription()));
			model->setItem(j, 2, new QStandardItem(value));
			model->setItem(j, 3, new QStandardItem(QStringLiteral("删除")));
			j++;
		}
	}
}

/**
  * @author:黄思泳
  * @brief:渲染判断题内容
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::setJudgeModelItemView(QStandardItemModel* model, QList<Judge>& judgeQuestionBank,int* chosenJudge) {
	int j = 0;
	for (int i = 0; i < judgeQuestionBank.size(); i++) {
		QString questionId = QString::number(judgeQuestionBank.at(i).getQuestionId()); //将ID转换成字符串
		if (chosenJudge[judgeQuestionBank.at(i).getQuestionId()] == 1)
		{
			QString value = QString::number(judgeQuestionBank.at(i).getValue()); //将分值转换成字符串
			model->setItem(j, 0, new QStandardItem(questionId));
			model->setItem(j, 1, new QStandardItem(judgeQuestionBank.at(i).getDescription()));
			model->setItem(j, 2, new QStandardItem(value));
			model->setItem(j, 3, new QStandardItem(QStringLiteral("删除")));
			j++;
		}
	}
}

/**
  * @author:黄思泳
  * @brief:将添加的单选题在列表上显示出来
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::showChoice() {
	this->examchoicemodel->clear();
	AddExam::setTableHeader(this->examchoicemodel); //初始化表头
	this->ui.choiceTable->setModel(examchoicemodel);
	this->ui.choiceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.choiceTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //设置等列宽且不可拖动
	AddExam::setChoiceModelItemView(this->examchoicemodel, choiceQuestionBank, chosenChoice); //渲染单选题
}

/**
  * @author:黄思泳
  * @brief:将添加的多选题在列表上显示出来
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::showMulti() {
	this->exammultimodel->clear();
	AddExam::setTableHeader(this->exammultimodel); //初始化表头
	this->ui.multiTable->setModel(exammultimodel);
	this->ui.multiTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.multiTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //设置等列宽且不可拖动
	AddExam::setMultiModelItemView(this->exammultimodel, multiQuestionBank, chosenMulti); //渲染多选题
}

/**
  * @author:黄思泳
  * @brief:将添加的判断题在列表上显示出来
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::showJudge() {
	this->examjudgemodel->clear();
	AddExam::setTableHeader(this->examjudgemodel); //初始化表头
	this->ui.judgeTable->setModel(examjudgemodel);
	this->ui.judgeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.judgeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //设置等列宽且不可拖动
	AddExam::setJudgeModelItemView(this->examjudgemodel, judgeQuestionBank, chosenJudge); //渲染判断题
}

/**
  * @author:黄思泳
  * @brief:初始化表头
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::setTableHeader(QStandardItemModel* model) {
	model->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("QuestionID")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("题目描述")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("分值")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("操作")));
}

/**
  * @author:黄思泳
  * @brief:单击删除单选题
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::choiceClicked(const QModelIndex & index)
{
	if (index.isValid() && index.column() == 3)	//点击删除键
	{
		int row=index.row();
		QModelIndex index = examchoicemodel->index(row, 0);
		int questionId = examchoicemodel->data(index).toInt();
		chosenChoice[questionId] = 0;
		showChoice();
	}
}

/**
  * @author:黄思泳
  * @brief:单击删除多选题
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::multiClicked(const QModelIndex & index)
{
	if (index.isValid() && index.column() == 3) //点击删除
	{
		int row = index.row();
		QModelIndex index = exammultimodel->index(row, 0);
		int questionId = exammultimodel->data(index).toInt();
		chosenMulti[questionId] = 0;
		showMulti();
	}
}

/**
  * @author:黄思泳
  * @brief:单击删除判断题
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::judgeClicked(const QModelIndex & index)
{
	if (index.isValid() && index.column() == 3)	//点击删除
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
	QString examName = this->ui.examName->text(); //获取试卷名称
	int examTime = this->ui.examTime->value(); //获取考试时间
	QString examInformation = this->ui.examInformation->toPlainText(); //获取试卷说明
	if (!examName.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("试卷名称不能为空！"), QMessageBox::Yes);
	}
	else if (!examTime) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("考试时间不能为零！"), QMessageBox::Yes);
	}
	else if (!examInformation.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("试卷说明不能为空！"), QMessageBox::Yes);
	}
	else {
		AddExamModel sql;
		bool information; //插入成功返回true,否则返回false
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
			QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("创建成功！"), QMessageBox::Yes);
			this->close();
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("创建失败！"), QMessageBox::Yes);
		}
	}
}

/**
  * @author:黄思泳
  * @brief:添加题目
  * @date:2019/1/1
  * @version:1.0
  */
void AddExam::addQuestion()
{
	int type = this->ui.tabWidget->currentIndex();
	if (type == 0)	//添加单选题
	{
		int index = this->ui.choiceBox->currentIndex();
		chosenChoice[choiceQuestionBank.at(index).getQuestionId()] = 1;
		showChoice();
	}
	else if (type == 1)	//添加多选题
	{
		int index = this->ui.multiBox->currentIndex();
		chosenMulti[multiQuestionBank.at(index).getQuestionId()] = 1;
		showMulti();
	}
	else if (type == 2)	//添加判断题
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
