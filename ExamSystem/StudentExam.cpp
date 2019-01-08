#include "StudentExam.h"
#include <QCloseEvent>


StudentExam::StudentExam(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	QDateTime startT = QDateTime::currentDateTime();
	this->startT = startT;
	this->time_clock = new QTimer(this);
	this->time_clock->start(1000);
	connect(time_clock, SIGNAL(timeout()), this, SLOT(Countdown()));
	connect(this->ui.tabWindow , SIGNAL(currentChanged(int)) , this , SLOT(onTabChanged(int)));
	connect(this->ui.choicePrevious , SIGNAL(clicked(bool)) , this , SLOT(choicePrevious()));
	connect(this->ui.choiceNext , SIGNAL(clicked(bool)) , this , SLOT(choiceNext()));
	connect(this->ui.multichoicePrevious , SIGNAL(clicked(bool)) , this , SLOT(multichoicePrevious()));
	connect(this->ui.multichoiceNext , SIGNAL(clicked(bool)) , this , SLOT(multichoiceNext()));
	connect(this->ui.judgePrevious , SIGNAL(clicked(bool)) , this , SLOT(judgePrevious()));
	connect(this->ui.judgeNext , SIGNAL(clicked(bool)) , this , SLOT(judgeNext()));
	connect(this->ui.choiceJump , SIGNAL(clicked(bool)) , this , SLOT(choiceJump()));
	connect(this->ui.multichoiceJump , SIGNAL(clicked(bool)) , this , SLOT(multichoiceJump()));
	connect(this->ui.judgeJump , SIGNAL(clicked(bool)) , this , SLOT(judgeJump()));
	connect(this->ui.submit , SIGNAL(clicked(bool)) , this , SLOT(submit()));
}

/**
  * @author:应承峻
  * @brief:根据接收到的用户名和试题编号渲染试题
  * @date:2018/12/28
  * @version:1.0
  */
void StudentExam::display(QString username , int examCode) {
	this->username = username;
	this->examCode = examCode;
	StudentExam::dataGet(examCode);  //从数据库中拉取题目
	if (this->choice.size() == 0) {
		this->ui.tabWindow->setTabEnabled(0, false);
	}
	if (this->multichoice.size() == 0) {
		this->ui.tabWindow->setTabEnabled(1, false);
	}
	if (this->judge.size() == 0) {
		this->ui.tabWindow->setTabEnabled(2, false);
	}
	if (this->choice.size()>0) {
		StudentExam::onTabChanged(0); //默认显示单选题
	}
	else if (this->multichoice.size() > 0) {
		StudentExam::onTabChanged(1);
	}
	else if (this->judge.size() > 0) {
		StudentExam::onTabChanged(2);
	}
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
  * @date:2019/1/2
  * @version:2.0
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
		Exam exam = sql.getInformation(examCode);
		this->duration = exam.getDuration();
		this->examName = exam.getExamName();
		this->information = exam.getInformation();
		for (int i = 0; i < this->choiceAns.size(); i++) {
			this->choiceAns[i].writeAnswer(QString());
		}
		for (int i = 0; i < this->multichoiceAns.size(); i++) {
			this->multichoiceAns[i].writeAnswer(QString());
		}
		for (int i = 0; i < this->judgeAns.size(); i++) {
			this->judgeAns[i].writeAnswer(QString());
		}
		this->ui.examName->setText(this->examName);
		this->ui.examDuration->setText(QString::number(this->duration) + QStringLiteral("分钟"));
		this->ui.examInformation->setPlainText(this->information);
	}
}

/**
  * @author:陈欢
  * @brief:显示单选题页面
  * @date:2019/1/2
  * @version:2.0
  */
void StudentExam::showChoice() {
	if (!this->choice.isEmpty()) {
		QString str = "(" + QString::number(this->choice.at(this->choiceCurrent).getValue()) + QStringLiteral("分)");
		this->ui.choiceQuestion->setPlainText(str);
		this->ui.choiceQuestion->insertPlainText(this->choice.at(this->choiceCurrent).getDescription());
		this->ui.choiceA->setPlainText(this->choice.at(this->choiceCurrent).getChoiceA());
		this->ui.choiceB->setPlainText(this->choice.at(this->choiceCurrent).getChoiceB());
		this->ui.choiceC->setPlainText(this->choice.at(this->choiceCurrent).getChoiceC());
		this->ui.choiceD->setPlainText(this->choice.at(this->choiceCurrent).getChoiceD());
		
		this->ui.choiceCurrent->setText(QString::number(this->choiceCurrent + 1));
		this->ui.choiceCurrent->setAlignment(Qt::AlignCenter);
		this->ui.choiceTotal->setText(QString::number(this->choice.size()));
		this->ui.choiceTotal->setAlignment(Qt::AlignCenter);
		this->ui.choiceNum->clear();
		
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
	else {
		this->ui.choiceQuestion->clear();
		this->ui.choiceA->clear();
		this->ui.choiceB->clear();
		this->ui.choiceC->clear();
		this->ui.choiceD->clear();
	}
}

/**
  * @author:陈欢
  * @brief:显示多选题页面
  * @date:2019/1/2
  * @version:2.0
  */
void StudentExam::showMultichoice() {
	if (!this->multichoice.isEmpty()) {
		QString str = "(" + QString::number(this->multichoice.at(this->multichoiceCurrent).getValue()) + QStringLiteral("分)");
		this->ui.multichoiceQuestion->setPlainText(str);
		this->ui.multichoiceQuestion->insertPlainText(this->multichoice.at(this->multichoiceCurrent).getDescription());
		this->ui.multichoiceA->setPlainText(this->multichoice.at(this->multichoiceCurrent).getChoiceA());
		this->ui.multichoiceB->setPlainText(this->multichoice.at(this->multichoiceCurrent).getChoiceB());
		this->ui.multichoiceC->setPlainText(this->multichoice.at(this->multichoiceCurrent).getChoiceC());
		this->ui.multichoiceD->setPlainText(this->multichoice.at(this->multichoiceCurrent).getChoiceD());

		this->ui.multichoiceCurrent->setText(QString::number(this->multichoiceCurrent + 1));
		this->ui.multichoiceCurrent->setAlignment(Qt::AlignCenter);
		this->ui.multichoiceTotal->setText(QString::number(this->multichoice.size()));
		this->ui.multichoiceTotal->setAlignment(Qt::AlignCenter);
		this->ui.multichoiceNum->clear();

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
	else {
		this->ui.multichoiceQuestion->clear();
		this->ui.multichoiceA->clear();
		this->ui.multichoiceB->clear();
		this->ui.multichoiceC->clear();
		this->ui.multichoiceD->clear();
	}
}

/**
  * @author:陈欢
  * @brief:显示判断题页面
  * @date:2019/1/2
  * @version:2.0
  */
void StudentExam::showJudge() {
	if (!this->judge.isEmpty()) {
		QString str = "(" + QString::number(this->judge.at(this->judgeCurrent).getValue()) + QStringLiteral("分)");
		this->ui.judgeQuestion->setPlainText(str);
		this->ui.judgeQuestion->insertPlainText(this->judge.at(this->judgeCurrent).getDescription());

		this->ui.judgeCurrent->setText(QString::number(this->judgeCurrent + 1));
		this->ui.judgeCurrent->setAlignment(Qt::AlignCenter);
		this->ui.judgeTotal->setText(QString::number(this->judge.size()));
		this->ui.judgeTotal->setAlignment(Qt::AlignCenter);
		this->ui.judgeNum->clear();

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
	else {
		this->ui.judgeQuestion->clear();
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
	if (this->choiceCurrent < this->choice.size() - 1) {
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
	is_submit = 1;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("提示"), QStringLiteral("连接失败"), QMessageBox::Yes);
	}
	else {
		int num = this->choice.size();
		flag = sql.submit(this->username,this->choiceAns, this->multichoiceAns, this->judgeAns, this->examCode, this->objectScore, this->multiScore, this->judgeScore);
		if (flag) {
			QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("提交成功！"), QMessageBox::Yes);
			emit examFinish();
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("提交失败！"), QMessageBox::Yes);
			//emit examFinish();
		}
	}
}

/**
  * @author:陈欢
  * @brief:将暂存的答案与标准答案比较，得出分数
  * @date:2019/1/2
  * @version:2.0
  */
void StudentExam::getScore() {
	int i;
	int objectSum = 0;
	int judgeSum = 0;
	int multiSum = 0;
	for (i = 0; i < this->choice.size(); i++) {
		if (this->choice.at(i).getAnswer() == this->choiceAns.at(i).getAnswer()) {
			objectSum += choice.at(i).getValue();
		}
	}
	for (i = 0; i < this->multichoice.size(); i++) {
		if (this->multichoice.at(i).getAnswer() == this->multichoiceAns.at(i).getAnswer()) {
			multiSum += multichoice.at(i).getValue();
		}
	}
	for (i = 0; i < this->judge.size(); i++) {
		if (this->judge.at(i).getAnswer() == this->judgeAns.at(i).getAnswer()) {
			judgeSum += judge.at(i).getValue();
		}
	}
	this->objectScore = objectSum;
	this->judgeScore = judgeSum;
	this->multiScore = multiSum;
}

/**
  * @author:陈欢
  * @brief:实现倒计时功能
  * @date:2019/1/2
  * @version:1.0
  */
void StudentExam::Countdown() {
	static int i = this->duration * 60;
	i--;
	int hour = i / 3600;
	int min = (i - hour * 3600) / 60;
	int sec = i - hour * 3600 - min * 60;
	this->ui.remainingTime->setText(QString::number(hour) + ":" + QString::number(min) + ":" + QString::number(sec));
	this->ui.remainingTime->setAlignment(Qt::AlignCenter);
	if (hour == 0 && min == 0 && sec == 0) {
		is_submit = 1;
		submit();
	}
}


void StudentExam::closeEvent(QCloseEvent *event) {
	if (is_submit == 0) {
		int ret = QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("确定要离开考试吗？"), QMessageBox::Yes | QMessageBox::Cancel);
		if (ret == QMessageBox::Cancel) {
			event->ignore();
		}
		if (ret == QMessageBox::Yes) {
			is_submit = 1;
			submit();
		}
	}
}

StudentExam::~StudentExam() {
	delete time_clock;
}
