#include "AddChoice.h"
#include "SqlModel.h"
#include "QuestionBank.h"

AddChoice::AddChoice(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	connect(this->ui.submitBtn , SIGNAL(clicked(bool)) , this , SLOT(checkData())); //绑定提交按钮点击事件
	connect(this->ui.resetBtn , SIGNAL(clicked(bool)) , this , SLOT(resetData())); //绑定重置按钮点击事件
	//connect(); //接受修改数据

}

/**
  * @author:应承峻
  * @brief:判断添加单选题输入的合法性,若合法则执行插入操作,否则弹出非法操作对话框
  * @date:2018/12/14
  * @version:1.0
  */
void AddChoice::checkData() {
	QString description = this->ui.description->toPlainText(); //获取题目描述
	QString choiceA = this->ui.choiceA->toPlainText(); //获取A选项描述
	QString choiceB = this->ui.choiceB->toPlainText(); //获取B选项描述
	QString choiceC = this->ui.choiceC->toPlainText(); //获取C选项描述
	QString choiceD = this->ui.choiceD->toPlainText(); //获取D选项描述
	int score = this->ui.score->value(); //获取题目分值
	int answer = this->ui.answer->currentIndex(); //获取答案
	if (!description.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("题目描述不能为空！") , QMessageBox::Yes);
	} else if (!choiceA.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("A选项不能为空！") , QMessageBox::Yes);
	} else if (!choiceB.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("B选项不能为空！") , QMessageBox::Yes);
	} else if (!choiceC.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("C选项不能为空！") , QMessageBox::Yes);
	} else if (!choiceD.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("D选项不能为空！") , QMessageBox::Yes);
	} else if (!answer) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("请设定正确答案！") , QMessageBox::Yes);
	} else {
		SqlModel sql;
		bool information; //插入成功返回true,否则返回false
		information = sql.insertChoice(description , choiceA , choiceB , choiceC , choiceD , AddChoice::convertAnswer(answer), score);
		if (information) {
			QMessageBox::information(NULL , QStringLiteral("提示") , QStringLiteral("添加成功！") , QMessageBox::Yes);
			this->close();
		} else {
			QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("添加失败！") , QMessageBox::Yes);
		}
	}
}

/**
  * @author:应承峻
  * @brief:重置按钮的功能实现
  * @date:2018/12/14
  * @version:1.0
  */
void AddChoice::resetData() {
	this->ui.description->clear();
	this->ui.choiceA->clear();
	this->ui.choiceB->clear();
	this->ui.choiceC->clear();
	this->ui.choiceD->clear();
	this->ui.score->setValue(0);
	this->ui.answer->setCurrentIndex(0);
}

/**
  * @author:应承峻
  * @brief:将设定答案中获取的数字下标转换成字符串
  * @param [in] 输入参数1: 数字下标index
  * @param [out] 输出参数: 返回相应选项的字符串
  * @date:2018/12/14
  * @version:1.0
  */
QString AddChoice::convertAnswer(int index) {
	QString ans;
	switch (index) {
		case 1: ans.append('A'); break;
		case 2: ans.append('B'); break;
		case 3: ans.append('C'); break;
		case 4: ans.append('D'); break;
		default: break;
	}
	return ans;
}

AddChoice::~AddChoice() {

}
