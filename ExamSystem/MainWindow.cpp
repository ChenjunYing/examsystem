#include "MainWindow.h"


/* MainWindow中应当具备以下功能
 * (1)显示管理员的信息
 * (2)显示当前正在运行的试卷,同时可以进行修改、删除等操作
 * (3)具有进入题库、添加试题(单选、多选、判断)、创建试卷、查看考生数据的接口
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
	choice = new AddChoice;
	multichoice = new AddMultiChoice;
	judge = new AddJudge;

	connect(this->ui.choice , SIGNAL(triggered()) , this , SLOT(choiceTriggered()));
	connect(this->ui.judge , SIGNAL(triggered()) , this , SLOT(judgeTriggered()));
	connect(this->ui.multichoice , SIGNAL(triggered()) , this , SLOT(multichoiceTriggered()));
	connect(this->ui.goQuestionBank , SIGNAL(triggered()) , this , SLOT(goQuestionBankTriggered()));
}

/*添加单选题接口*/
void MainWindow::choiceTriggered() {
	choice->exec();  //弹出添加单选题模态框，此时用户不能对主界面进行操作
}

/*添加多选题接口*/
void MainWindow::multichoiceTriggered() {
	multichoice->exec();  //弹出添加多选题模态框，此时用户不能对主界面进行操作
}

/*添加判断题接口*/
void MainWindow::judgeTriggered() {
	judge->exec();  //弹出添加判断题模态框，此时用户不能对主界面进行操作
}

/**
  * @author:应承峻
  * @brief:题库接口
  * @date:2018/12/17
  * @version:2.0
  * @note:修复了内存泄露的bug
  */
void MainWindow::goQuestionBankTriggered() {
	questionbank = new QuestionBank;
	connect(questionbank , SIGNAL(sendChoiceData(Choice)) , choice , SLOT(receiveData(Choice)));  //题库和修改试题页面传递数据
	connect(choice , SIGNAL(sendChoicePage(AddChoice*)) , this , SLOT(receiveAddChoicePage(AddChoice*)));
	questionbank->exec(); //弹出查看题库模态框，此时用户不能对主界面进行操作
	if (questionbank != NULL) {
		delete questionbank;
	}
}

/**
  * @author:应承峻
  * @brief:接收AddChoice页面发送的新建修改页面的地址并进行信号槽绑定
  * @date:2018/12/17
  * @version:1.0
  * @note:与题库修改完成刷新事件绑定
  */
void MainWindow::receiveAddChoicePage(AddChoice* a) {
	connect(a , SIGNAL(updateOK(int)) , questionbank , SLOT(receiveOK(int)));
}

/*
 * @note:修复了questionbank为空时删除出现的bug
 */
MainWindow::~MainWindow() {
	delete choice;
	delete multichoice;
	delete judge;
}