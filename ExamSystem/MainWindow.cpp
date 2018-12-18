#include "MainWindow.h"


/* MainWindow��Ӧ���߱����¹���
 * (1)��ʾ����Ա����Ϣ
 * (2)��ʾ��ǰ�������е��Ծ�,ͬʱ���Խ����޸ġ�ɾ���Ȳ���
 * (3)���н�����⡢�������(��ѡ����ѡ���ж�)�������Ծ��鿴�������ݵĽӿ�
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

/*��ӵ�ѡ��ӿ�*/
void MainWindow::choiceTriggered() {
	choice->exec();  //������ӵ�ѡ��ģ̬�򣬴�ʱ�û����ܶ���������в���
}

/*��Ӷ�ѡ��ӿ�*/
void MainWindow::multichoiceTriggered() {
	multichoice->exec();  //������Ӷ�ѡ��ģ̬�򣬴�ʱ�û����ܶ���������в���
}

/*����ж���ӿ�*/
void MainWindow::judgeTriggered() {
	judge->exec();  //��������ж���ģ̬�򣬴�ʱ�û����ܶ���������в���
}

/*���ӿ�*/
void MainWindow::goQuestionBankTriggered() {
	questionbank = new QuestionBank;
	connect(questionbank , SIGNAL(sendChoiceData(Choice)) , choice , SLOT(receiveData(Choice)));  //�����޸�����ҳ�洫������
	questionbank->exec(); //�����鿴���ģ̬�򣬴�ʱ�û����ܶ���������в���
}

MainWindow::~MainWindow() {
	delete choice;
	delete multichoice;
	delete judge;
	delete questionbank;
}