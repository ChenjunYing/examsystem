#include "AddMultiChoice.h"
#include "SqlModel.h"
#include "QuestionBank.h"

AddMultiChoice::AddMultiChoice(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	connect(this->ui.submitBtn, SIGNAL(clicked(bool)), this, SLOT(checkData())); //���ύ��ť����¼�
	connect(this->ui.resetBtn, SIGNAL(clicked(bool)), this, SLOT(resetData())); //�����ð�ť����¼�
}

/**
  * @author:��˼Ӿ
  * @brief:�ж���Ӷ�ѡ������ĺϷ���,���Ϸ���ִ�в������,���򵯳��Ƿ������Ի���
  * @date:2018/12/18
  * @version:1.0
  */
void AddMultiChoice::checkData() {
	QString description = this->ui.description->toPlainText(); //��ȡ��Ŀ����
	QString choiceA = this->ui.choiceA->toPlainText(); //��ȡAѡ������
	QString choiceB = this->ui.choiceB->toPlainText(); //��ȡBѡ������
	QString choiceC = this->ui.choiceC->toPlainText(); //��ȡCѡ������
	QString choiceD = this->ui.choiceD->toPlainText(); //��ȡDѡ������
	int score = this->ui.score->value(); //��ȡ��Ŀ��ֵ
	bool answer[4] = { this->ui.answerA->isChecked(),this->ui.answerB->isChecked(), this->ui.answerC->isChecked(), this->ui.answerD->isChecked() }; //��ȡ��
	if (!description.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("��Ŀ��������Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (!choiceA.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("Aѡ���Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (!choiceB.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("Bѡ���Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (!choiceC.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("Cѡ���Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (!choiceD.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("Dѡ���Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (answer[0] == 0 && answer[1] == 0 && answer[2] == 0 && answer[3] == 0) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("���趨��ȷ�𰸣�"), QMessageBox::Yes);
	}
	else {
		SqlModel sql;
		bool information; //����ɹ�����true,���򷵻�false
		information = sql.insertMultiChoice(description, choiceA, choiceB, choiceC, choiceD, AddMultiChoice::convertAnswer(answer), score);
		if (information) {
			QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("��ӳɹ���"), QMessageBox::Yes);
			this->close();
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("���ʧ�ܣ�"), QMessageBox::Yes);
		}
	}
}

/**
  * @author:��˼Ӿ
  * @brief:�ж��޸Ķ�ѡ������ĺϷ���,���Ϸ���ִ���޸Ĳ���,���򵯳��Ƿ������Ի���
  * @date:2018/12/18
  * @version:1.0
  */
void AddMultiChoice::checkUpdateData() {
	QString description = this->ui.description->toPlainText(); //��ȡ��Ŀ����
	QString choiceA = this->ui.choiceA->toPlainText(); //��ȡAѡ������
	QString choiceB = this->ui.choiceB->toPlainText(); //��ȡBѡ������
	QString choiceC = this->ui.choiceC->toPlainText(); //��ȡCѡ������
	QString choiceD = this->ui.choiceD->toPlainText(); //��ȡDѡ������
	int score = this->ui.score->value(); //��ȡ��Ŀ��ֵ
	bool answer[4] = { this->ui.answerA->isChecked(),this->ui.answerB->isChecked(), this->ui.answerC->isChecked(), this->ui.answerD->isChecked() }; //��ȡ��
	if (!description.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("��Ŀ��������Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (!choiceA.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("Aѡ���Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (!choiceB.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("Bѡ���Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (!choiceC.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("Cѡ���Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (!choiceD.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("Dѡ���Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (answer[0] == 0 && answer[1] == 0 && answer[2] == 0 && answer[3] == 0) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("���趨��ȷ�𰸣�"), QMessageBox::Yes);
	}
	else {
		SqlModel sql;
		bool information; //����ɹ�����true,���򷵻�false
		information = sql.updateMultiChoice(description, choiceA, choiceB, choiceC, choiceD, AddMultiChoice::convertAnswer(answer), score, tempQuestionId);
		if (information) {
			emit updateOK(1);  //��QuestionBankҳ�淢�͸�������ź�,ʹ�����ˢ�²���
			QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("�޸ĳɹ���"), QMessageBox::Yes);
			this->close();
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("�޸�ʧ�ܣ�"), QMessageBox::Yes);
		}
	}
}

/**
  * @author:��˼Ӿ
  * @brief:���ð�ť�Ĺ���ʵ��
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
   * @author:��˼Ӿ
   * @brief:��ÿ��ѡ���Ƿ�ѡΪ�𰸵�bool����ת��Ϊ�ַ���
   * @param [in] �������1: ����Ϊ4��bool����
   * @param [out] �������: ����ѡΪ�𰸵��ַ���
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
  * @author:��˼Ӿ
  * @brief:���շ��͹�����ѡ�ж�ѡ�����Ӧ���ݲ���ʾ
  * @date:2018/12/18
  * @version:1.0
  */
void AddMultiChoice::receiveData(Choice c) {
	AddMultiChoice* a;
	a = new AddMultiChoice;  //�½��޸�����ҳ��
	QString answer;
	a->tempQuestionId = c.getQuestionId();  //�洢������
	disconnect(a->ui.submitBtn, SIGNAL(clicked(bool)), a, SLOT(checkData())); //������ύ��ť����¼�
	connect(a->ui.submitBtn, SIGNAL(clicked(bool)), a, SLOT(checkUpdateData())); //���°��޸İ�ť����¼�
	a->ui.label->setText(QStringLiteral("�޸Ķ�ѡ��"));   //�޸ı�������
	a->ui.submitBtn->setText(QStringLiteral("��   ��"));  //�޸İ�ť����
	a->ui.description->setText(c.getDescription());  //���������Ϣ
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
	emit sendMultiChoicePage(a);  //��MainWindowҳ�淢���޸�ҳ���ָ���Ա�������ź���۵İ�
	a->exec();  //���޸�ģ̬��
	if (a != NULL) {
		delete a;  //ɾ��ҳ��
	}
}


AddMultiChoice::~AddMultiChoice() {

}
