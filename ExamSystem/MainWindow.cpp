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

/**
  * @author:Ӧ�о�
  * @brief:���ӿ�
  * @date:2018/12/17
  * @version:2.0
  * @note:�޸����ڴ�й¶��bug
  */
void MainWindow::goQuestionBankTriggered() {
	questionbank = new QuestionBank;
	connect(questionbank , SIGNAL(sendChoiceData(Choice)) , choice , SLOT(receiveData(Choice)));  //�����޸�����ҳ�洫������
	connect(choice , SIGNAL(sendChoicePage(AddChoice*)) , this , SLOT(receiveAddChoicePage(AddChoice*)));
	questionbank->exec(); //�����鿴���ģ̬�򣬴�ʱ�û����ܶ���������в���
	if (questionbank != NULL) {
		delete questionbank;
	}
}

/**
  * @author:Ӧ�о�
  * @brief:����AddChoiceҳ�淢�͵��½��޸�ҳ��ĵ�ַ�������źŲ۰�
  * @date:2018/12/17
  * @version:1.0
  * @note:������޸����ˢ���¼���
  */
void MainWindow::receiveAddChoicePage(AddChoice* a) {
	connect(a , SIGNAL(updateOK(int)) , questionbank , SLOT(receiveOK(int)));
}

/*
 * @note:�޸���questionbankΪ��ʱɾ�����ֵ�bug
 */
MainWindow::~MainWindow() {
	delete choice;
	delete multichoice;
	delete judge;
}