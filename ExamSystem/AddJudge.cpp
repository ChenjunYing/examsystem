#include "AddJudge.h"
#include "SqlModel.h"
#include "QuestionBank.h"

AddJudge::AddJudge(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置最小最大化按钮和关闭按钮
	connect(this->ui.submitBtn, SIGNAL(clicked(bool)), this, SLOT(checkData())); //绑定提交按钮点击事件
	connect(this->ui.resetBtn, SIGNAL(clicked(bool)), this, SLOT(resetData())); //绑定重置按钮点击事件
}

/**
  * @author:黄思泳
  * @brief:判断添加判断题输入的合法性,若合法则执行插入操作,否则弹出非法操作对话框
  * @date:2018/12/19
  * @version:1.0
  */
void AddJudge::checkData() {
	QString description = this->ui.description->toPlainText(); //获取题目描述
	int score = this->ui.score->value(); //获取题目分值
	bool answer[2] = { this->ui.right->isChecked(),this->ui.wrong->isChecked()}; //获取答案
	if (!description.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("题目描述不能为空！"), QMessageBox::Yes);
	}
	else if (answer[0] == 0 && answer[1] == 0 ) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("请设定正确答案！"), QMessageBox::Yes);
	}
	else {
		SqlModel sql;
		bool information; //插入成功返回true,否则返回false
		information = sql.insertJudge(description, AddJudge::convertAnswer(answer), score);
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
  * @brief:判断修改判断题输入的合法性,若合法则执行修改操作,否则弹出非法操作对话框
  * @date:2018/12/19
  * @version:1.0
 */
void AddJudge::checkUpdateData()
{
	QString description = this->ui.description->toPlainText(); //获取题目描述
	int score = this->ui.score->value(); //获取题目分值
	bool answer[2] = { this->ui.right->isChecked(),this->ui.wrong->isChecked() }; //获取答案
	if (!description.length()) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("题目描述不能为空！"), QMessageBox::Yes);
	}
	else if (answer[0] == 0 && answer[1] == 0) {
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("请设定正确答案！"), QMessageBox::Yes);
	}
	else {
		SqlModel sql;
		bool information; //插入成功返回true,否则返回false
		information = sql.updateJudge(description, AddJudge::convertAnswer(answer), score, tempQuestionId);
		if (information) {
			emit updateOK(2);  //向QuestionBank页面发送更新完成信号,使其进行刷新操作
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
  * @date:2018/12/19
  * @version:1.0
  */
void AddJudge::resetData() {
	this->ui.description->clear();
	this->ui.score->setValue(0);
	this->ui.right->setChecked(false);
	this->ui.wrong->setChecked(false);
}

/**
   * @author:黄思泳
   * @brief:将答案的bool数组转换为字符
   * @param [in] 输入参数1: 长度为2的bool数组
   * @param [out] 输出参数: 返回T或者F的字符
   * @date:2018/12/19
   * @version:1.0
   */
QString AddJudge::convertAnswer(bool *answer) {
	QString ans;
	if (answer[0] == 1)
		ans.append('T');
	else if (answer[1] == 1)
		ans.append('F');
	return ans;
}

/**
  * @author:黄思泳
  * @brief:接收发送过来的选中多选题的相应数据并显示
  * @date:2018/12/18
  * @version:1.0
  */
void AddJudge::receiveData(Judge c) {
	AddJudge* a;
	a = new AddJudge;  //新建修改试题页面
	a->tempQuestionId = c.getQuestionId();  //存储试题编号
	disconnect(a->ui.submitBtn, SIGNAL(clicked(bool)), a, SLOT(checkData())); //解除绑定提交按钮点击事件
	connect(a->ui.submitBtn, SIGNAL(clicked(bool)), a, SLOT(checkUpdateData())); //重新绑定修改按钮点击事件
	a->ui.label->setText(QStringLiteral("修改多选题"));   //修改标题文字
	a->ui.submitBtn->setText(QStringLiteral("修   改"));  //修改按钮文字
	a->ui.description->setText(c.getDescription());  //填上相关信息
	a->ui.score->setValue(c.getValue());
	if(c.getAnswer()=='T')
		a->ui.right->setChecked(true);
	else if (c.getAnswer() == 'F')
		a->ui.wrong->setChecked(true);
	emit sendJudgePage(a);  //向MainWindow页面发送修改页面的指针以便其进行信号与槽的绑定
	a->exec();  //打开修改模态框
	if (a != NULL) {
		delete a;  //删除页面
	}
}

AddJudge::~AddJudge() {

}
