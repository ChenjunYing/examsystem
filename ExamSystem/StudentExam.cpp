#include "StudentExam.h"


StudentExam::StudentExam(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	StudentExam::dataGet(3);  //从数据库中拉取题目
	StudentExam::onTabChanged(0); //默认显示单选题

	connect(this->ui.tabWindow, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));
	connect(this->ui.choicePrevious, SIGNAL(clicked(bool)), this, SLOT(choicePrevious()));
	connect(this->ui.choiceNext, SIGNAL(clicked(bool)), this, SLOT(choiceNext()));
	connect(this->ui.multichoicePrevious, SIGNAL(clicked(bool)), this, SLOT(multichoicePrevious()));
	connect(this->ui.multichoiceNext, SIGNAL(clicked(bool)), this, SLOT(multichoiceNext()));
	connect(this->ui.judgePrevious, SIGNAL(clicked(bool)), this, SLOT(judgePrevious()));
	connect(this->ui.judgeNext, SIGNAL(clicked(bool)), this, SLOT(judgeNext()));
	connect(this->ui.choiceNum, SIGNAL(returnPressed()), this, SLOT(choiceJump()));
	connect(this->ui.multichoiceNum, SIGNAL(returnPressed()), this, SLOT(multichoiceJump()));
	connect(this->ui.judgeNum, SIGNAL(returnPressed()), this, SLOT(judgeJump()));
	connect(this->ui.submit, SIGNAL(clicked(bool)), this, SLOT(submit()));
}

/**
  * @author:应承峻
  * @brief:根据点击的TabBar显示相应的题型,0为单选题,1为多选题,2为判断题
  * @date:2018/12/16
  * @version:1.0
  * 引用QuestionBank
  */
void StudentExam::onTabChanged(int index) {
	switch (index) {
	case 0: {
		multichoiceStorage();
		judgeStorage();
		showChoice(); 
		break; 
	}
	case 1: {
		choiceStorage();
		judgeStorage();
		showMultichoice(); 
		break; 
	}
	case 2: {
		choiceStorage();
		multichoiceStorage();
		showJudge(); 
		break; 
	}
	default: break;
	}
}

/**
  * @author:陈欢
  * @brief:根据试卷编号查询数据库得到题目
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::dataGet(int examCode) {
	StudentExamModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("提示"), QStringLiteral("连接失败"), QMessageBox::Yes);
	}
	else {
		this->choice = sql.searchChoice(0, examCode); //拉取符合条件单选题
		this->multichoice = sql.searchChoice(1, examCode);  //拉取符合条件多选题
		this->judge = sql.searchJudge(examCode);          //拉取符合条件判断题
		this->choiceAns = this->choice;
		this->multichoiceAns = this->multichoice;
		this->judgeAns = this->judge;
		for (int i = 0; i < this->choiceAns.size(); i++) {
			this->choiceAns[i].writeAnswer(QString());
		}
		for (int i = 0; i < this->multichoiceAns.size(); i++) {
			this->multichoiceAns[i].writeAnswer(QString());
		}
		for (int i = 0; i < this->judgeAns.size(); i++) {
			this->judgeAns[i].writeAnswer(QString());
		}
	}
}

/**
  * @author:陈欢
  * @brief:显示单选题页面
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::showChoice() {
	this->ui.choiceQuestion->setPlainText(this->choice.at(this->choiceCurrent).getDescription());
	this->ui.choiceQuestion->setAlignment(Qt::AlignCenter);
	this->ui.choiceA->setPlainText(this->choice.at(this->choiceCurrent).getChoiceA());
	this->ui.choiceB->setPlainText(this->choice.at(this->choiceCurrent).getChoiceB());
	this->ui.choiceC->setPlainText(this->choice.at(this->choiceCurrent).getChoiceC());
	this->ui.choiceD->setPlainText(this->choice.at(this->choiceCurrent).getChoiceD());
	
	if (this->choiceAns.at(this->choiceCurrent).getAnswer() != QString()) {
		switch (choiceAns.at(this->choiceCurrent).getAnswer().toStdString()[0]) {
		case 'A': {
			this->ui.selectA->setChecked(true);
			break;
		}
		case 'B': {
			this->ui.selectB->setChecked(true);
			break;
		}
		case 'C': {
			this->ui.selectC->setChecked(true);
			break;
		}
		case 'D': {
			this->ui.selectD->setChecked(true);
			break;
		}
		default: {
			break;
		}
		}
	}
	else {
		this->ui.selectA->setAutoExclusive(false);
		this->ui.selectB->setAutoExclusive(false);
		this->ui.selectC->setAutoExclusive(false);
		this->ui.selectD->setAutoExclusive(false);

		this->ui.selectA->setChecked(false);
		this->ui.selectB->setChecked(false);
		this->ui.selectC->setChecked(false);
		this->ui.selectD->setChecked(false);

		this->ui.selectA->setAutoExclusive(true);
		this->ui.selectB->setAutoExclusive(true);
		this->ui.selectC->setAutoExclusive(true);
		this->ui.selectD->setAutoExclusive(true);
	}
}

/**
  * @author:陈欢
  * @brief:显示多选题页面
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::showMultichoice() {
	this->ui.multichoiceQuestion->setPlainText(this->multichoice.at(this->multichoiceCurrent).getDescription());
	this->ui.multichoiceQuestion->setAlignment(Qt::AlignCenter);
	this->ui.multichoiceA->setPlainText(this->multichoice.at(this->multichoiceCurrent).getChoiceA());
	this->ui.multichoiceB->setPlainText(this->multichoice.at(this->multichoiceCurrent).getChoiceB());
	this->ui.multichoiceC->setPlainText(this->multichoice.at(this->multichoiceCurrent).getChoiceC());
	this->ui.multichoiceD->setPlainText(this->multichoice.at(this->multichoiceCurrent).getChoiceD());

	this->ui.multiselectA->setChecked(false);
	this->ui.multiselectB->setChecked(false);
	this->ui.multiselectC->setChecked(false);
	this->ui.multiselectD->setChecked(false);

	if (this->multichoiceAns.at(this->multichoiceCurrent).getAnswer() != QString()) {
		int i = 0;
		while (multichoiceAns.at(this->multichoiceCurrent).getAnswer().toStdString()[i]) {
			switch (multichoiceAns.at(this->multichoiceCurrent).getAnswer().toStdString()[i]) {
			case 'A': {
				this->ui.multiselectA->setChecked(true);
				break;
			}
			case 'B': {
				this->ui.multiselectB->setChecked(true);
				break;
			}
			case 'C': {
				this->ui.multiselectC->setChecked(true);
				break;
			}
			case 'D': {
				this->ui.multiselectD->setChecked(true);
				break;
			}
			default: {
				break;
			}
			}
			i++;
		}
	}
}

/**
  * @author:陈欢
  * @brief:显示判断题页面
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::showJudge() {
	this->ui.judgeQuestion->setPlainText(this->judge.at(this->judgeCurrent).getDescription());
	this->ui.judgeQuestion->setAlignment(Qt::AlignCenter);

	if (this->judgeAns.at(this->judgeCurrent).getAnswer() != QString()) {
		switch (judgeAns.at(this->judgeCurrent).getAnswer().toStdString()[0]) {
		case 'T': {
			this->ui.selectT->setChecked(true);
			break;
		}
		case 'F': {
			this->ui.selectF->setChecked(true);
			break;
		}
		default: {
			break;
		}
		}
	}
	else {
		this->ui.selectT->setAutoExclusive(false);
		this->ui.selectF->setAutoExclusive(false);

		this->ui.selectT->setChecked(false);
		this->ui.selectF->setChecked(false);

		this->ui.selectT->setAutoExclusive(true);
		this->ui.selectF->setAutoExclusive(true);
	}
}

/**
  * @author:陈欢
  * @brief:单选题页面显示上一题
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::choicePrevious() {
	if (this->choiceCurrent > 0) {
		choiceStorage();
		this->choiceCurrent--;
		showChoice();
	}
}

/**
  * @author:陈欢
  * @brief:单选题页面显示下一题
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::choiceNext() {
	if (this->choiceCurrent < this->choice.size()-1) {
		choiceStorage();
		this->choiceCurrent++;
		showChoice();
	}
}

/**
  * @author:陈欢
  * @brief:多选题页面显示上一题
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::multichoicePrevious() {
	if (this->multichoiceCurrent > 0) {
		multichoiceStorage();
		this->multichoiceCurrent--;
		showMultichoice();
	}

}

/**
  * @author:陈欢
  * @brief:多选题页面显示下一题
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::multichoiceNext() {
	if (this->multichoiceCurrent < this->multichoice.size() - 1) {
		multichoiceStorage();
		this->multichoiceCurrent++;
		showMultichoice();
	}
}

/**
  * @author:陈欢
  * @brief:判断题页面显示上一题
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::judgePrevious() {
	if (this->judgeCurrent > 0) {
		judgeStorage();
		this->judgeCurrent--;
		showJudge();
	}
}

/**
  * @author:陈欢
  * @brief:判断题页面显示下一题
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::judgeNext() {
	if (this->judgeCurrent < this->judge.size() - 1) {
		judgeStorage();
		this->judgeCurrent++;
		showJudge();
	}
}

/**
  * @author:陈欢
  * @brief:单选题页面跳转指定题数
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::choiceJump() {
	int num;
	num = this->ui.choiceNum->text().toInt();
	if (num > 0 && num <= this->choice.size()) {
		choiceStorage();
		this->choiceCurrent = num - 1;
		showChoice();
	}
}

/**
  * @author:陈欢
  * @brief:多选题页面跳转指定题数
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::multichoiceJump() {
	int num;
	num = this->ui.multichoiceNum->text().toInt();
	if (num > 0 && num <= this->multichoice.size()) {
		multichoiceStorage();
		this->multichoiceCurrent = num - 1;
		showMultichoice();
	}
}

/**
  * @author:陈欢
  * @brief:判断题页面跳转指定题数
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::judgeJump() {
	int num;
	num = this->ui.judgeNum->text().toInt();
	if (num > 0 && num <= this->judge.size()) {
		judgeStorage();
		this->judgeCurrent = num - 1;
		showJudge();
	}
}

/**
  * @author:陈欢
  * @brief:单选题暂存答案
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::choiceStorage() {
	int i;
	QString ans;
	QList<QAbstractButton*> radioBtn = this->ui.choiceGroup->buttons();
	if (this->ui.selectA->isChecked()) {
		ans = this->ui.selectA->text();
	}
	else if (this->ui.selectB->isChecked()) {
		ans = this->ui.selectB->text();
	}
	else if (this->ui.selectC->isChecked()) {
		ans = this->ui.selectC->text();
	}
	else if (this->ui.selectD->isChecked()) {
		ans = this->ui.selectD->text();
	}
	if (!ans.isEmpty()) {
		this->choiceAns[this->choiceCurrent].writeAnswer(ans);
	}
}

/**
  * @author:陈欢
  * @brief:多选题暂存答案
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::multichoiceStorage() {
	QString ans;
	if (this->ui.multiselectA->isChecked()) {
		ans.append(this->ui.multiselectA->text());
	}
	if (this->ui.multiselectB->isChecked()) {
		ans.append(this->ui.multiselectB->text());
	}
	if (this->ui.multiselectC->isChecked()) {
		ans.append(this->ui.multiselectC->text());
	}
	if (this->ui.multiselectD->isChecked()) {
		ans.append(this->ui.multiselectD->text());
	}

	if (!ans.isEmpty()) {
		this->multichoiceAns[this->multichoiceCurrent].writeAnswer(ans);
	}
}

/**
  * @author:陈欢
  * @brief:判断题暂存答案
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::judgeStorage() {

	if (this->ui.selectT->isChecked()) {
		this->judgeAns[this->judgeCurrent].writeAnswer("T");
	}
	else if (this->ui.selectF->isChecked()) {
		this->judgeAns[this->judgeCurrent].writeAnswer("F");
	}
}

/**
  * @author:陈欢
  * @brief:点击提交按钮后将暂存的答案插库
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::submit() {
	StudentExamModel sql;
	int flag;
	choiceStorage();
	multichoiceStorage();
	judgeStorage();
	getScore();
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("提示"), QStringLiteral("连接失败"), QMessageBox::Yes);
	}
	else {
		int num = this->choice.size();
		flag=sql.submit(this->choice, this->multichoice, this->judge, 3,this->objectScore,this->judgeScore);
		if (flag) {
			QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("提交成功！"), QMessageBox::Yes);
			this->close();
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("提交失败！"), QMessageBox::Yes);
		}
	}
}

/**
  * @author:陈欢
  * @brief:将暂存的答案与标准答案比较，得出分数
  * @date:2018/12/24
  * @version:1.0
  */
void StudentExam::getScore() {
	int i;
	int objectSum = 0;
	int judgeSum = 0;
	for (i = 0; i < this->choice.size(); i++) {
		if (this->choice.at(i).getAnswer() == this->choiceAns.at(i).getAnswer()) {
			objectSum += choice.at(i).getValue();
		}
	}
	for (i = 0; i < this->multichoice.size(); i++) {
		if (this->multichoice.at(i).getAnswer() == this->multichoiceAns.at(i).getAnswer()) {
			objectSum += multichoice.at(i).getValue();
		}
	}
	for (i = 0; i < this->judge.size(); i++) {
		if (this->judge.at(i).getAnswer() == this->judgeAns.at(i).getAnswer()) {
			judgeSum += judge.at(i).getValue();
		}
	}
	this->objectScore = objectSum;
	this->judgeScore = judgeSum;
}

StudentExam::~StudentExam() {

}
