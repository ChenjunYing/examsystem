#include "MainWindow.h"

/* MainWindow中应当具备以下功能
 * (1)显示管理员的信息
 * (2)显示当前正在运行的试卷,同时可以进行修改、删除等操作
 * (3)具有进入题库、添加试题(单选、多选、判断)、创建试卷、查看考生数据的接口
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置最小最大化按钮和关闭按钮
	this->choice = new AddChoice;
	this->multichoice = new AddMultiChoice;
	this->judge = new AddJudge;
	this->scoreReport = new ScoreReport;
	this->exammodel = new QStandardItemModel;
	MainWindow::dataRefresh();
	MainWindow::showExamTable();
	connect(this->ui.choice, SIGNAL(triggered()), this, SLOT(choiceTriggered()));
	connect(this->ui.judge, SIGNAL(triggered()), this, SLOT(judgeTriggered()));
	connect(this->ui.multichoice, SIGNAL(triggered()), this, SLOT(multichoiceTriggered()));
	connect(this->ui.goQuestionBank, SIGNAL(triggered()), this, SLOT(goQuestionBankTriggered()));
	connect(this->ui.createExam, SIGNAL(triggered()), this, SLOT(createExamTriggered()));
	connect(this->ui.createExam , SIGNAL(triggered()) , this , SLOT(createExamTriggered()));
	connect(this->ui.user , SIGNAL(triggered()) , this , SLOT(userTriggered()));
	connect(this, SIGNAL(sendExamCode(int)), this->scoreReport, SLOT(receiveCode(int)));
	connect(this->ui.examTable, SIGNAL(clicked(const QModelIndex&)), this, SLOT(examClicked(const QModelIndex&)));
	connect(this->ui.examTable, SIGNAL(clicked(const QModelIndex&)), this, SLOT(deleteClicked(const QModelIndex&)));
}

/**
  * @author:应承峻
  * @brief:刷新考试信息
  * @date:2018/12/23
  * @version:1.0
  */
void MainWindow::dataRefresh() {
	AdminModel admin;
	if (!admin.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("提示"), QStringLiteral("连接失败"), QMessageBox::Yes);
	}
	else {
		this->exam = admin.searchExam();
	}
}
/**
  * @author:夏林轩
  * @brief:查看参加一场考试的考生成绩的触发信号
  * @date:2019/1/1
  * @version:1.0
  */
void MainWindow::examClicked(const QModelIndex& index) {
	if (index.isValid() && index.column() == 3) {
		emit sendExamCode(this->exam.at(index.row()).getExamCode());
		this->scoreReport->exec();
	}
}

/**
  * @author:夏林轩
  * @brief:删除一场考试及其所有相关信息的接口
  * @date:2019/1/1
  * @version:1.0
  */
void MainWindow::deleteClicked(const QModelIndex & index) {
	AdminModel admin;
	if (index.isValid() && index.column() == 5) {
		int ret = QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("确定删除这场考试吗？将删除许多信息且删除后无法恢复！"), QMessageBox::Yes | QMessageBox::Cancel);
		if (ret == QMessageBox::Yes) {
			int code = exam.at(index.row()).getExamCode();
			if (admin.isOpen() && admin.deleteExam(code)) {
				QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("删除成功！"), QMessageBox::Ok);
				MainWindow::dataRefresh();//刷新页面
				MainWindow::showExamTable();
			}
			else {
				QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("删除失败！"), QMessageBox::Ok);
			}
		}
	}
}

void MainWindow::refreshAfterCreat() {
	MainWindow::dataRefresh();
	MainWindow::showExamTable();
}


/**
  * @author:应承峻
  * @brief:在管理员界面中显示考试信息
  * @date:2018/12/23
  * @version:1.0
  */
void MainWindow::showExamTable() {
	this->exammodel->clear();
	MainWindow::setTableHeader(this->exammodel); //初始化表头
	this->ui.examTable->setModel(this->exammodel);
	this->ui.examTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.examTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //设置等列宽且不可拖动
	MainWindow::setExamTableItemView(this->exammodel);
}


/**
  * @author:应承峻
  * @brief:设置考试信息表格的表头
  * @date:2018/12/23
  * @version:1.0
  */
void MainWindow::setTableHeader(QStandardItemModel* model) {
	model->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("考试名称")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("考试时间")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("考试信息")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("查询成绩")));
	model->setHorizontalHeaderItem(4, new QStandardItem(QStringLiteral("编辑考试")));
	model->setHorizontalHeaderItem(5, new QStandardItem(QStringLiteral("删除考试")));
}


/**
  * @author:应承峻
  * @brief:渲染考试信息
  * @date:2018/12/23
  * @version:1.0
  */
void MainWindow::setExamTableItemView(QStandardItemModel* model) {
	for (int i = 0; i < exam.size(); i++) {
		QString duration = QString::number(exam.at(i).getDuration());
		model->setItem(i, 0, new QStandardItem(exam.at(i).getExamName()));
		model->setItem(i, 1, new QStandardItem(QString::number(exam.at(i).getDuration()) + QStringLiteral("分钟")));
		model->setItem(i, 2, new QStandardItem(exam.at(i).getInformation()));
		model->setItem(i, 3, new QStandardItem(QStringLiteral("查询")));
		model->setItem(i, 4, new QStandardItem(QStringLiteral("查看")));
		model->setItem(i, 5, new QStandardItem(QStringLiteral("删除")));
		model->item(i, 0)->setTextAlignment(Qt::AlignCenter); //设置居中
		model->item(i, 1)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 2)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 3)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 4)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 5)->setTextAlignment(Qt::AlignCenter);
	}
}

/*添加单选题接口*/
void MainWindow::choiceTriggered() {
	choice->resetData();
	choice->exec();  //弹出添加单选题模态框，此时用户不能对主界面进行操作
}

/*添加多选题接口*/
void MainWindow::multichoiceTriggered() {
	multichoice->resetData();
	multichoice->exec();  //弹出添加多选题模态框，此时用户不能对主界面进行操作
}

/*添加判断题接口*/
void MainWindow::judgeTriggered() {
	judge->resetData();
	judge->exec();  //弹出添加判断题模态框，此时用户不能对主界面进行操作
}

/*考生管理接口*/
void MainWindow::userTriggered() {
	if (info != NULL) {
		delete info;
		info = NULL;
	}
	info = new StudentInfo;
	info->exec();
}

/*创建考试接口*/
void MainWindow::createExamTriggered() {
	if (newexam) {
		delete newexam;
		newexam = NULL;
	}
	newexam = new AddExam;
	qDebug() << connect(this->newexam, SIGNAL(creatFinished()), this, SLOT(refreshAfterCreat()));
	newexam->show();
}

/*题库接口*/
void MainWindow::goQuestionBankTriggered() {
	questionbank = new QuestionBank;
	connect(questionbank, SIGNAL(sendChoiceData(Choice)), choice, SLOT(receiveData(Choice)));  //题库和修改单选题页面传递数据
	connect(questionbank, SIGNAL(sendMultiChoiceData(Choice)), multichoice, SLOT(receiveData(Choice)));  //题库和修改多选题页面传递数据
	connect(questionbank, SIGNAL(sendJudgeData(Judge)), judge, SLOT(receiveData(Judge)));  //题库和修改判断题页面传递数据
	connect(choice, SIGNAL(sendChoicePage(AddChoice*)), this, SLOT(receiveAddChoicePage(AddChoice*)));
	connect(multichoice, SIGNAL(sendMultiChoicePage(AddMultiChoice*)), this, SLOT(receiveAddMultiChoicePage(AddMultiChoice*)));
	connect(judge, SIGNAL(sendJudgePage(AddJudge*)), this, SLOT(receiveAddJudgePage(AddJudge*)));
	questionbank->exec(); //弹出查看题库模态框，此时用户不能对主界面进行操作
	if (questionbank) delete questionbank;
}

/**
  * @author:应承峻
  * @brief:接收AddChoice页面发送的新建修改页面的地址并进行信号槽绑定
  * @date:2018/12/17
  * @version:1.0
  * @note:与题库修改完成刷新事件绑定
  */
void MainWindow::receiveAddChoicePage(AddChoice* a) {
	connect(a, SIGNAL(updateOK(int)), questionbank, SLOT(receiveOK(int)));
}

/**
  * @author:黄思泳
  * @brief:接收AddMultiChoice页面发送的新建修改页面的地址并进行信号槽绑定
  * @date:2018/12/18
  * @version:1.0
  * @note:与题库修改完成刷新事件绑定
  */
void MainWindow::receiveAddMultiChoicePage(AddMultiChoice* a) {
	connect(a, SIGNAL(updateOK(int)), questionbank, SLOT(receiveOK(int)));
}

/**
  * @author:黄思泳
  * @brief:接收AddJudge页面发送的新建修改页面的地址并进行信号槽绑定
  * @date:2018/12/19
  * @version:1.0
  * @note:与题库修改完成刷新事件绑定
  */
void MainWindow::receiveAddJudgePage(AddJudge* a) {
	connect(a, SIGNAL(updateOK(int)), questionbank, SLOT(receiveOK(int)));
}

/*
 * @note:修复了questionbank为空时删除出现的bug
 */
MainWindow::~MainWindow() {
	delete choice;
	delete multichoice;
	delete judge;
	delete exammodel;
	delete scoreReport;
	delete info;
	delete newexam;
}