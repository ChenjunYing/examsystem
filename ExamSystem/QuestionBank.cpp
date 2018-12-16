#include "QuestionBank.h"
#include "SqlModel.h"
#include "Question.h"
#include "AddChoice.h"

QuestionBank::QuestionBank(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	this->choicemodel = new QStandardItemModel; //创建单选题表格
	this->multimodel = new QStandardItemModel;  //创建多选题表格
	this->judgemodel = new QStandardItemModel;  //创建判断题表格
	
	QuestionBank::dataRefresh();  //从数据库中拉取数据
	QuestionBank::onTabChanged(0); //默认显示单选题
	connect(this->ui.choiceTable , SIGNAL(doubleClicked(const QModelIndex&)) , this , SLOT(choiceDoubleClicked()));
	connect(this->ui.tabWidget , SIGNAL(currentChanged(int)) , this , SLOT(onTabChanged(int)));
}


/**
  * @author:应承峻
  * @brief:实现单选题表格双击修改的功能
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
		a.ui.label->setText(QStringLiteral("修改单选题"));   //修改标题文字
		a.ui.submitBtn->setText(QStringLiteral("提   交"));  //修改按钮文字

		a.exec();  //打开修改模态框
	}
}

/**
  * @author:应承峻
  * @brief:将单选题在题库上显示出来
  * @date:2018/12/16
  * @version:2.0
  */
void QuestionBank::showChoice() {
	this->choicemodel->clear();
	this->choicemodel->setHorizontalHeaderItem(0 , new QStandardItem(QStringLiteral("题目描述")));
	this->choicemodel->setHorizontalHeaderItem(1 , new QStandardItem(QStringLiteral("A选项描述")));
	this->choicemodel->setHorizontalHeaderItem(2 , new QStandardItem(QStringLiteral("B选项描述")));
	this->choicemodel->setHorizontalHeaderItem(3 , new QStandardItem(QStringLiteral("C选项描述")));
	this->choicemodel->setHorizontalHeaderItem(4 , new QStandardItem(QStringLiteral("D选项描述")));
	this->choicemodel->setHorizontalHeaderItem(5 , new QStandardItem(QStringLiteral("答案")));
	this->choicemodel->setHorizontalHeaderItem(6 , new QStandardItem(QStringLiteral("分值")));
	this->choicemodel->setHorizontalHeaderItem(7 , new QStandardItem(QStringLiteral("作者")));
	this->ui.choiceTable->setModel(choicemodel);
	QuestionBank::dataRefresh();
	for (int i = 0; i < choice.size(); i++) {
		QString value = QString::number(choice.at(i).getValue()); //将分值转换成字符串
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
  * @author:应承峻
  * @brief:将多选题在题库上显示出来
  * @date:2018/12/16
  * @version:2.0
  */
void QuestionBank::showMultichoice() {
	this->multimodel->clear();
	this->multimodel->setHorizontalHeaderItem(0 , new QStandardItem(QStringLiteral("题目描述")));
	this->multimodel->setHorizontalHeaderItem(1 , new QStandardItem(QStringLiteral("A选项描述")));
	this->multimodel->setHorizontalHeaderItem(2 , new QStandardItem(QStringLiteral("B选项描述")));
	this->multimodel->setHorizontalHeaderItem(3 , new QStandardItem(QStringLiteral("C选项描述")));
	this->multimodel->setHorizontalHeaderItem(4 , new QStandardItem(QStringLiteral("D选项描述")));
	this->multimodel->setHorizontalHeaderItem(5 , new QStandardItem(QStringLiteral("答案")));
	this->multimodel->setHorizontalHeaderItem(6 , new QStandardItem(QStringLiteral("分值")));
	this->multimodel->setHorizontalHeaderItem(7 , new QStandardItem(QStringLiteral("作者")));
	this->ui.multiTable->setModel(multimodel);
	QuestionBank::dataRefresh();
	for (int i = 0; i < multichoice.size(); i++) {
		QString value = QString::number(multichoice.at(i).getValue()); //将分值转换成字符串
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
  * @author:应承峻
  * @brief:将判断题在题库上显示出来
  * @date:2018/12/16
  * @version:2.0
  */
void QuestionBank::showJudge() {
	this->judgemodel->clear();
	this->judgemodel->setHorizontalHeaderItem(0 , new QStandardItem(QStringLiteral("题目描述")));
	this->judgemodel->setHorizontalHeaderItem(1 , new QStandardItem(QStringLiteral("答案")));
	this->judgemodel->setHorizontalHeaderItem(2 , new QStandardItem(QStringLiteral("分值")));
	this->judgemodel->setHorizontalHeaderItem(3 , new QStandardItem(QStringLiteral("作者")));
	this->ui.judgeTable->setModel(judgemodel);
	QuestionBank::dataRefresh();
	for (int i = 0; i < judge.size(); i++) {
		QString value = QString::number(judge.at(i).getValue()); //将分值转换成字符串
		QString answer;  //将判断题的答案以文字显示
		if (judge.at(i).getAnswer() == "T") answer = QStringLiteral("正确");
		else answer = QStringLiteral("错误");
		this->judgemodel->setItem(i , 0 , new QStandardItem(judge.at(i).getDescription()));
		this->judgemodel->setItem(i , 1 , new QStandardItem(answer));
		this->judgemodel->setItem(i , 2 , new QStandardItem(value));
		this->judgemodel->setItem(i , 3 , new QStandardItem(judge.at(i).getAuthor()));
	}
}

/**
  * @author:应承峻
  * @brief:刷新单选题、多选题和判断题的数据
  * @date:2018/12/16
  * @version:1.0
  */
void QuestionBank::dataRefresh() {
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("提示") , QStringLiteral("连接失败") , QMessageBox::Yes);
		this->close();
	} else {
		this->choice = sql.searchChoice(0);       //拉取所有单选题
		this->multichoice = sql.searchChoice(1);  //拉取所有多选题
		this->judge = sql.searchJudge();          //拉取所有判断题
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