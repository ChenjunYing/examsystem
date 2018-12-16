#include "MainWindow.h"
#include "AddMultiChoice.h"
#include "AddJudge.h"

/* MainWindow中应当具备以下功能
 * (1)显示管理员的信息
 * (2)显示当前正在运行的试卷,同时可以进行修改、删除等操作
 * (3)具有进入题库、添加试题(单选、多选、判断)、创建试卷、查看考生数据的接口
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
	dialogA = new AddChoice;
	dialogQ = new QuestionBank;
	//connect(dialogQ,SIGNAL(toAddChoi));  //题库和修改试题页面传递数据
	connect(this->ui.choice , SIGNAL(triggered()) , this , SLOT(choiceTriggered()));
	connect(this->ui.judge , SIGNAL(triggered()) , this , SLOT(judgeTriggered()));
	connect(this->ui.multichoice , SIGNAL(triggered()) , this , SLOT(multichoiceTriggered()));
	connect(this->ui.goQuestionBank , SIGNAL(triggered()) , this , SLOT(goQuestionBankTriggered()));
}

/*添加单选题接口*/
void MainWindow::choiceTriggered() {
	qDebug() << "Choice Triggered!" ;
	AddChoice choice;
	choice.exec();  //弹出添加单选题模态框，此时用户不能对主界面进行操作
}

/*添加多选题接口*/
void MainWindow::multichoiceTriggered() {
	qDebug() << "Multichoice Triggered!";
	AddMultiChoice multichoice;
	multichoice.exec();  //弹出添加多选题模态框，此时用户不能对主界面进行操作
}

/*添加判断题接口*/
void MainWindow::judgeTriggered() {
	qDebug() << "Judge Triggered!" ;
	AddJudge judge;
	judge.exec();  //弹出添加判断题模态框，此时用户不能对主界面进行操作
}

/*题库接口*/
void MainWindow::goQuestionBankTriggered() {
	QuestionBank questionbank;
	qDebug() << "QuestionBank Triggered!";
	questionbank.exec(); //弹出查看题库模态框，此时用户不能对主界面进行操作
}

MainWindow::~MainWindow() {
	delete dialogA;
	delete dialogQ;
}