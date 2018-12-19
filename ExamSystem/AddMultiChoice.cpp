#include "AddMultiChoice.h"
#include "SqlModel.h"
#include "QuestionBank.h"

AddMultiChoice::AddMultiChoice(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	connect(this->ui.submitBtn, SIGNAL(clicked(bool)), this, SLOT(checkData())); //绑定提交按钮点击事件
	connect(this->ui.resetBtn, SIGNAL(clicked(bool)), this, SLOT(resetData())); //绑定重置按钮点击事件
}

/**
  * @author:黄思泳
  * @brief:判断添加多选题输入的合法性,若合法则执行插入操作,否则弹出非法操作对话框
  * @date:2018/12/18
  * @version:1.0
  */
void AddMultiChoice::checkData() {
	QString description = this->ui.description->toPlainText(); //获取题目描述
	QString choiceA = this->ui.choiceA->toPlainText(); //获取A选项描述
	QString choiceB = this->ui.choiceB->toPlainText(); //获取B选项描述
	QString choiceC = this->ui.choiceC->toPlainText(); //获取C选项描述
	QString choiceD = this->ui.choiceD->toPlainText(); //获取D选项描述
	int score = this->ui.score->value(); //获取题目分值
	bool answer[4] = { this->ui.answerA->isChecked(),this->ui.answerB->isChecked(), this->ui.answerC->isChecked(), this->ui.answerD->isChecked() }; //获取答案
	if (!description.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("题目描述不能为空！"), QMessageBox::Yes);
	}
	else if (!choiceA.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("A选项不能为空！"), QMessageBox::Yes);
	}
	else if (!choiceB.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("B选项不能为空！"), QMessageBox::Yes);
	}
	else if (!choiceC.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("C选项不能为空！"), QMessageBox::Yes);
	}
	else if (!choiceD.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("D选项不能为空！"), QMessageBox::Yes);
	}
	else if (answer[0] == 0 && answer[1] == 0 && answer[2] == 0 && answer[3] == 0) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("请设定正确答案！"), QMessageBox::Yes);
	}
	else {
		SqlModel sql;
		bool information; //插入成功返回true,否则返回false
		information = sql.insertMultiChoice(description, choiceA, choiceB, choiceC, choiceD, AddMultiChoice::convertAnswer(answer), score);
		if (information) {
			QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("添加成功！"), QMessageBox::Yes);
			this->close();
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("添加失败！"), QMessageBox::Yes);
		}
	}
}

/**
  * @author:黄思泳
  * @brief:判断修改多选题输入的合法性,若合法则执行修改操作,否则弹出非法操作对话框
  * @date:2018/12/18
  * @version:1.0
  */
void AddMultiChoice::checkUpdateData() {
	QString description = this->ui.description->toPlainText(); //获取题目描述
	QString choiceA = this->ui.choiceA->toPlainText(); //获取A选项描述
	QString choiceB = this->ui.choiceB->toPlainText(); //获取B选项描述
	QString choiceC = this->ui.choiceC->toPlainText(); //获取C选项描述
	QString choiceD = this->ui.choiceD->toPlainText(); //获取D选项描述
	int score = this->ui.score->value(); //获取题目分值
	bool answer[4] = { this->ui.answerA->isChecked(),this->ui.answerB->isChecked(), this->ui.answerC->isChecked(), this->ui.answerD->isChecked() }; //获取答案
	if (!description.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("题目描述不能为空！"), QMessageBox::Yes);
	}
	else if (!choiceA.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("A选项不能为空！"), QMessageBox::Yes);
	}
	else if (!choiceB.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("B选项不能为空！"), QMessageBox::Yes);
	}
	else if (!choiceC.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("C选项不能为空！"), QMessageBox::Yes);
	}
	else if (!choiceD.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("D选项不能为空！"), QMessageBox::Yes);
	}
	else if (answer[0] == 0 && answer[1] == 0 && answer[2] == 0 && answer[3] == 0) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("请设定正确答案！"), QMessageBox::Yes);
	}
	else {
		SqlModel sql;
		bool information; //插入成功返回true,否则返回false
		information = sql.updateMultiChoice(description, choiceA, choiceB, choiceC, choiceD, AddMultiChoice::convertAnswer(answer), score, tempQuestionId);
		if (information) {
			emit updateOK(1);  //向QuestionBank页面发送更新完成信号,使其进行刷新操作
			QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("修改成功！"), QMessageBox::Yes);
			this->close();
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("修改失败！"), QMessageBox::Yes);
		}
	}
}

/**
  * @author:黄思泳
  * @brief:重置按钮的功能实现
  * @date:2018/12/18
  * @version:1.0
  */
void AddMultiChoice::resetData() {
	this->ui.description->clear();
	this->ui.choiceA->clear();
	this->ui.choiceB->clear();
	this->ui.choiceC->clear();
	this->ui.choiceD->clear();
	this->ui.score->setValue(0);
	this->ui.answerA->setChecked(false);
	this->ui.answerB->setChecked(false);
	this->ui.answerC->setChecked(false);
	this->ui.answerD->setChecked(false);
}

/**
   * @author:黄思泳
   * @brief:将每个选项是否选为答案的bool数组转换为字符串
   * @param [in] 输入参数1: 长度为4的bool数组
   * @param [out] 输出参数: 返回选为答案的字符串
   * @date:2018/12/18
   * @version:1.0
   */
QString AddMultiChoice::convertAnswer(bool *answer) {
	QString ans;
	if (answer[0] == 1)
		ans.append('A');
	if (answer[1] == 1)
		ans.append('B');
	if (answer[2] == 1)
		ans.append('C');
	if (answer[3] == 1)
		ans.append('D');
	return ans;
}

/**
  * @author:黄思泳
  * @brief:接收发送过来的选中多选题的相应数据并显示
  * @date:2018/12/18
  * @version:1.0
  */
void AddMultiChoice::receiveData(Choice c) {
	AddMultiChoice* a;
	a = new AddMultiChoice;  //新建修改试题页面
	QString answer;
	a->tempQuestionId = c.getQuestionId();  //存储试题编号
	disconnect(a->ui.submitBtn, SIGNAL(clicked(bool)), a, SLOT(checkData())); //解除绑定提交按钮点击事件
	connect(a->ui.submitBtn, SIGNAL(clicked(bool)), a, SLOT(checkUpdateData())); //重新绑定修改按钮点击事件
	a->ui.label->setText(QStringLiteral("修改多选题"));   //修改标题文字
	a->ui.submitBtn->setText(QStringLiteral("修   改"));  //修改按钮文字
	a->ui.description->setText(c.getDescription());  //填上相关信息
	a->ui.choiceA->setText(c.getChoiceA());
	a->ui.choiceB->setText(c.getChoiceB());
	a->ui.choiceC->setText(c.getChoiceC());
	a->ui.choiceD->setText(c.getChoiceD());
	a->ui.score->setValue(c.getValue());
	answer = c.getAnswer();
	for (int i = 0; answer[i] != '\0'; i++)
	{
		if (answer[i] == 'A') a->ui.answerA->setChecked(true);
		if (answer[i] == 'B') a->ui.answerB->setChecked(true);
		if (answer[i] == 'C') a->ui.answerC->setChecked(true);
		if (answer[i] == 'D') a->ui.answerD->setChecked(true);
	}
	emit sendMultiChoicePage(a);  //向MainWindow页面发送修改页面的指针以便其进行信号与槽的绑定
	a->exec();  //打开修改模态框
	if (a != NULL) {
		delete a;  //删除页面
	}
}


AddMultiChoice::~AddMultiChoice() {

}
