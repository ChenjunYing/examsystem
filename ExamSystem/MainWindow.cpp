#include "MainWindow.h"
#include "AddMultiChoice.h"
#include "AddJudge.h"

/* MainWindow��Ӧ���߱����¹���
 * (1)��ʾ����Ա����Ϣ
 * (2)��ʾ��ǰ�������е��Ծ�,ͬʱ���Խ����޸ġ�ɾ���Ȳ���
 * (3)���н�����⡢�������(��ѡ����ѡ���ж�)�������Ծ��鿴�������ݵĽӿ�
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
	dialogA = new AddChoice;
	dialogQ = new QuestionBank;
	//connect(dialogQ,SIGNAL(toAddChoi));  //�����޸�����ҳ�洫������
	connect(this->ui.choice , SIGNAL(triggered()) , this , SLOT(choiceTriggered()));
	connect(this->ui.judge , SIGNAL(triggered()) , this , SLOT(judgeTriggered()));
	connect(this->ui.multichoice , SIGNAL(triggered()) , this , SLOT(multichoiceTriggered()));
	connect(this->ui.goQuestionBank , SIGNAL(triggered()) , this , SLOT(goQuestionBankTriggered()));
}

/*��ӵ�ѡ��ӿ�*/
void MainWindow::choiceTriggered() {
	qDebug() << "Choice Triggered!" ;
	AddChoice choice;
	choice.exec();  //������ӵ�ѡ��ģ̬�򣬴�ʱ�û����ܶ���������в���
}

/*��Ӷ�ѡ��ӿ�*/
void MainWindow::multichoiceTriggered() {
	qDebug() << "Multichoice Triggered!";
	AddMultiChoice multichoice;
	multichoice.exec();  //������Ӷ�ѡ��ģ̬�򣬴�ʱ�û����ܶ���������в���
}

/*����ж���ӿ�*/
void MainWindow::judgeTriggered() {
	qDebug() << "Judge Triggered!" ;
	AddJudge judge;
	judge.exec();  //��������ж���ģ̬�򣬴�ʱ�û����ܶ���������в���
}

/*���ӿ�*/
void MainWindow::goQuestionBankTriggered() {
	QuestionBank questionbank;
	qDebug() << "QuestionBank Triggered!";
	questionbank.exec(); //�����鿴���ģ̬�򣬴�ʱ�û����ܶ���������в���
}

MainWindow::~MainWindow() {
	delete dialogA;
	delete dialogQ;
}