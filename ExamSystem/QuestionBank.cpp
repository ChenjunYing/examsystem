#include "QuestionBank.h"
#include "Question.h"
#include "AddChoice.h"

QuestionBank::QuestionBank(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	this->choicemodel = new QStandardItemModel; //创建单选题表格
	this->multimodel = new QStandardItemModel;  //创建多选题表格
	this->judgemodel = new QStandardItemModel;  //创建判断题表格
	QuestionBank::dataRefresh();  //从数据库中拉取数据
	QuestionBank::onTabChanged(0); //默认显示单选题
	connect(this->ui.choiceTable , SIGNAL(doubleClicked(const QModelIndex&)) , this , SLOT(choiceDoubleClicked(const QModelIndex&)));
	connect(this->ui.choiceTable , SIGNAL(clicked(const QModelIndex&)) , this , SLOT(choiceClicked(const QModelIndex&)));
	connect(this->ui.multiTable , SIGNAL(doubleClicked(const QModelIndex&)) , this , SLOT(multiDoubleClicked(const QModelIndex&)));
	connect(this->ui.judgeTable , SIGNAL(doubleClicked(const QModelIndex&)) , this , SLOT(judgeDoubleClicked(const QModelIndex&)));
	connect(this->ui.tabWidget , SIGNAL(currentChanged(int)) , this , SLOT(onTabChanged(int)));
	connect(this->ui.selectBtn , SIGNAL(clicked(bool)) , this , SLOT(searchQuestion()));
	connect(this->ui.resetBtn , SIGNAL(clicked(bool)) , this , SLOT(reset()));
}

/**
  * @author:应承峻
  * @brief:刷新单选题、多选题和判断题的数据
  * @date:2018/12/19
  * @version:2.0
  */
void QuestionBank::dataRefresh(QString keyWord, int lowerValue, int upperValue, QString author) {
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("提示") , QStringLiteral("连接失败") , QMessageBox::Yes);
	} else {
		this->choice = sql.searchChoice(0 , keyWord , lowerValue , upperValue , author); //拉取符合条件单选题
		this->multichoice = sql.searchChoice(1 , keyWord , lowerValue , upperValue , author);  //拉取符合条件多选题
		this->judge = sql.searchJudge(keyWord , lowerValue , upperValue , author);          //拉取符合条件判断题
	}
}

/**
  * @author:应承峻
  * @brief:根据点击的TabBar显示相应的题型,0为单选题,1为多选题,2为判断题
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
  * @author:黄思泳
  * @brief:实现多选题表格双击修改的功能
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::multiDoubleClicked(const QModelIndex& index) {
	if (index.isValid() && index.column() != 7 && index.column() != 8) {
		emit sendMultiChoiceData(this->multichoice.at(index.row())); //发送数据
	}
}

/**
  * @author:黄思泳
  * @brief:实现多选题表格双击修改的功能
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::judgeDoubleClicked(const QModelIndex& index) {
	if (index.isValid()) {
		emit sendJudgeData(this->judge.at(index.row())); //发送数据
	}
}

/**
  * @author:应承峻
  * @brief:初始化单选题和多选题表头
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::setChoiceTableHeader(QStandardItemModel* model) {
	model->setHorizontalHeaderItem(0 , new QStandardItem(QStringLiteral("题目描述")));
	model->setHorizontalHeaderItem(1 , new QStandardItem(QStringLiteral("A选项描述")));
	model->setHorizontalHeaderItem(2 , new QStandardItem(QStringLiteral("B选项描述")));
	model->setHorizontalHeaderItem(3 , new QStandardItem(QStringLiteral("C选项描述")));
	model->setHorizontalHeaderItem(4 , new QStandardItem(QStringLiteral("D选项描述")));
	model->setHorizontalHeaderItem(5 , new QStandardItem(QStringLiteral("答案")));
	model->setHorizontalHeaderItem(6 , new QStandardItem(QStringLiteral("分值")));
	model->setHorizontalHeaderItem(7 , new QStandardItem(QStringLiteral("作者")));
	model->setHorizontalHeaderItem(8 , new QStandardItem(QStringLiteral("操作")));
}

/**
  * @author:应承峻
  * @brief:初始化判断题表头
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::setJudgeTableHeader(QStandardItemModel* model) {
	model->setHorizontalHeaderItem(0 , new QStandardItem(QStringLiteral("题目描述")));
	model->setHorizontalHeaderItem(1 , new QStandardItem(QStringLiteral("答案")));
	model->setHorizontalHeaderItem(2 , new QStandardItem(QStringLiteral("分值")));
	model->setHorizontalHeaderItem(3 , new QStandardItem(QStringLiteral("作者")));
	model->setHorizontalHeaderItem(4 , new QStandardItem(QStringLiteral("操作")));
}

/**
  * @author:应承峻
  * @brief:渲染单选题和多选题的内容
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::setChoiceModelItemView(QStandardItemModel* model, QList<Choice>& choice) {
	for (int i = 0; i < choice.size(); i++) {
		QString value = QString::number(choice.at(i).getValue()); //将分值转换成字符串
		model->setItem(i , 0 , new QStandardItem(choice.at(i).getDescription()));
		model->setItem(i , 1 , new QStandardItem(choice.at(i).getChoiceA()));
		model->setItem(i , 2 , new QStandardItem(choice.at(i).getChoiceB()));
		model->setItem(i , 3 , new QStandardItem(choice.at(i).getChoiceC()));
		model->setItem(i , 4 , new QStandardItem(choice.at(i).getChoiceD()));
		model->setItem(i , 5 , new QStandardItem(choice.at(i).getAnswer()));
		model->setItem(i , 6 , new QStandardItem(value));
		model->setItem(i , 7 , new QStandardItem(choice.at(i).getAuthor()));
		model->setItem(i , 8 , new QStandardItem(QStringLiteral("删除")));
		model->item(i , 5)->setTextAlignment(Qt::AlignCenter); //设置居中
		model->item(i , 6)->setTextAlignment(Qt::AlignCenter);
		model->item(i , 7)->setTextAlignment(Qt::AlignCenter);
		model->item(i , 8)->setTextAlignment(Qt::AlignCenter);
	}
}

/**
  * @author:应承峻
  * @brief:渲染判断题的内容
  * @date:2018/12/18
  * @version:1.0
  */
void QuestionBank::setJudgeModelItemView(QStandardItemModel* model, QList<Judge>& judge) {
	for (int i = 0; i < judge.size(); i++) {
		QString value = QString::number(judge.at(i).getValue()); //将分值转换成字符串
		QString answer;  //将判断题的答案以文字显示
		if (judge.at(i).getAnswer() == "T") answer = QStringLiteral("正确");
		else answer = QStringLiteral("错误");
		model->setItem(i , 0 , new QStandardItem(judge.at(i).getDescription()));
		model->setItem(i , 1 , new QStandardItem(answer));
		model->setItem(i , 2 , new QStandardItem(value));
		model->setItem(i , 3 , new QStandardItem(judge.at(i).getAuthor()));
		model->setItem(i , 4 , new QStandardItem(QStringLiteral("删除")));
		model->item(i , 1)->setTextAlignment(Qt::AlignCenter); //设置居中
		model->item(i , 2)->setTextAlignment(Qt::AlignCenter);
		model->item(i , 3)->setTextAlignment(Qt::AlignCenter);
		model->item(i , 4)->setTextAlignment(Qt::AlignCenter);
	}
}

/**
  * @author:应承峻
  * @brief:将单选题在题库上显示出来
  * @date:2018/12/18
  * @version:3.0
  */
void QuestionBank::showChoice() {
	this->choicemodel->clear();
	QuestionBank::setChoiceTableHeader(this->choicemodel); //初始化表头
	this->ui.choiceTable->setModel(choicemodel);
	this->ui.choiceTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //设置等列宽且不可拖动
	QuestionBank::setChoiceModelItemView(this->choicemodel , choice); //渲染单选题
}


/**
  * @author:应承峻
  * @brief:将多选题在题库上显示出来
  * @date:2018/12/18
  * @version:3.0
  */
void QuestionBank::showMultichoice() {
	this->multimodel->clear();
	QuestionBank::setChoiceTableHeader(this->multimodel); //初始化表头
	this->ui.multiTable->setModel(multimodel);
	this->ui.multiTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //设置等列宽且不可拖动
	QuestionBank::setChoiceModelItemView(this->multimodel , multichoice); //渲染多选题
}

/**
  * @author:应承峻
  * @brief:将判断题在题库上显示出来
  * @date:2018/12/16
  * @version:2.0
  */
void QuestionBank::showJudge() {
	this->judgemodel->clear();
	QuestionBank::setJudgeTableHeader(this->judgemodel); //初始化表头
	this->ui.judgeTable->setModel(judgemodel);
	this->ui.judgeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //设置等列宽且不可拖动
	QuestionBank::setJudgeModelItemView(this->judgemodel , judge); //渲染判断题
}

/**
  * @author:应承峻
  * @brief:实现单选题表格双击修改的功能
  * @date:2018/12/16
  * @version:1.0
  */
void QuestionBank::choiceDoubleClicked(const QModelIndex& index) {
	if (index.isValid() && index.column() != 7 && index.column() != 8) {  //点击合法
		emit sendChoiceData(this->choice.at(index.row())); //发送数据
	}
}

/**
  * @author:应承峻
  * @brief:实现单选题表格删除格处单击删除的功能
  * @date:2018/12/19
  * @version:1.0
  */
void QuestionBank::choiceClicked(const QModelIndex& index) {
	SqlModel sql;
	if (index.isValid() && index.column() == 8) {  //点击到删除按钮
		int ret = QMessageBox::warning(this , QStringLiteral("提示") , QStringLiteral("确定删除这道题吗？删除后将无法恢复！") , QMessageBox::Yes | QMessageBox::Cancel);
		if (ret == QMessageBox::Yes) {
			int id = choice.at(index.row()).getQuestionId();
			if (sql.isOpen() && sql.deleteChoice(id)) {
				QMessageBox::information(this , QStringLiteral("提示") , QStringLiteral("删除成功！") , QMessageBox::Ok);
				QuestionBank::searchQuestion(); //刷新页面
			} else {
				QMessageBox::information(this , QStringLiteral("提示") , QStringLiteral("删除失败！") , QMessageBox::Ok);
			}
		}
	}
}

/**
  * @author:应承峻
  * @brief:按条件查找
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
  * @author:应承峻
  * @brief:重置筛选表单
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
  * @author:应承峻
  * @brief:修改完成后在页面刷新
  * @date:2018/12/17
  * @version:1.0
  */
void QuestionBank::receiveOK(int index) {
	QuestionBank::reset(); //重置筛选数据
	QuestionBank::dataRefresh();  //刷新页面数据
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