#include "AddExam.h"

AddExam::AddExam(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	AddExam::refreshQuestionBank();
	AddExam::refreshComboBox();
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


AddExam::~AddExam() {
	

}
