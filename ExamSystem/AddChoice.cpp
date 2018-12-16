#include "AddChoice.h"
#include "SqlModel.h"
#include "QuestionBank.h"

AddChoice::AddChoice(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	connect(this->ui.submitBtn , SIGNAL(clicked(bool)) , this , SLOT(checkData())); //���ύ��ť����¼�
	connect(this->ui.resetBtn , SIGNAL(clicked(bool)) , this , SLOT(resetData())); //�����ð�ť����¼�
}

/**
  * @author:Ӧ�о�
  * @brief:�ж���ӵ�ѡ������ĺϷ���,���Ϸ���ִ�в������,���򵯳��Ƿ������Ի���
  * @date:2018/12/14
  * @version:1.0
  */
void AddChoice::checkData() {
	QString description = this->ui.description->toPlainText(); //��ȡ��Ŀ����
	QString choiceA = this->ui.choiceA->toPlainText(); //��ȡAѡ������
	QString choiceB = this->ui.choiceB->toPlainText(); //��ȡBѡ������
	QString choiceC = this->ui.choiceC->toPlainText(); //��ȡCѡ������
	QString choiceD = this->ui.choiceD->toPlainText(); //��ȡDѡ������
	int score = this->ui.score->value(); //��ȡ��Ŀ��ֵ
	int answer = this->ui.answer->currentIndex(); //��ȡ��
	if (!description.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("��Ŀ��������Ϊ�գ�") , QMessageBox::Yes);
	} else if (!choiceA.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("Aѡ���Ϊ�գ�") , QMessageBox::Yes);
	} else if (!choiceB.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("Bѡ���Ϊ�գ�") , QMessageBox::Yes);
	} else if (!choiceC.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("Cѡ���Ϊ�գ�") , QMessageBox::Yes);
	} else if (!choiceD.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("Dѡ���Ϊ�գ�") , QMessageBox::Yes);
	} else if (!answer) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("���趨��ȷ�𰸣�") , QMessageBox::Yes);
	} else {
		SqlModel sql;
		bool information; //����ɹ�����true,���򷵻�false
		information = sql.insertChoice(description , choiceA , choiceB , choiceC , choiceD , AddChoice::convertAnswer(answer) , score);
		if (information) {
			QMessageBox::information(NULL , QStringLiteral("��ʾ") , QStringLiteral("��ӳɹ���") , QMessageBox::Yes);
			this->close();
		} else {
			QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("���ʧ�ܣ�") , QMessageBox::Yes);
		}
	}
}


/**
  * @author:Ӧ�о�
  * @brief:�ж��޸ĵ�ѡ������ĺϷ���,���Ϸ���ִ���޸Ĳ���,���򵯳��Ƿ������Ի���
  * @date:2018/12/16
  * @version:2.0
  */
void AddChoice::checkUpdateData() {
	QString description = this->ui.description->toPlainText(); //��ȡ��Ŀ����
	QString choiceA = this->ui.choiceA->toPlainText(); //��ȡAѡ������
	QString choiceB = this->ui.choiceB->toPlainText(); //��ȡBѡ������
	QString choiceC = this->ui.choiceC->toPlainText(); //��ȡCѡ������
	QString choiceD = this->ui.choiceD->toPlainText(); //��ȡDѡ������
	int score = this->ui.score->value(); //��ȡ��Ŀ��ֵ
	int answer = this->ui.answer->currentIndex(); //��ȡ��
	if (!description.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("��Ŀ��������Ϊ�գ�") , QMessageBox::Yes);
	} else if (!choiceA.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("Aѡ���Ϊ�գ�") , QMessageBox::Yes);
	} else if (!choiceB.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("Bѡ���Ϊ�գ�") , QMessageBox::Yes);
	} else if (!choiceC.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("Cѡ���Ϊ�գ�") , QMessageBox::Yes);
	} else if (!choiceD.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("Dѡ���Ϊ�գ�") , QMessageBox::Yes);
	} else if (!answer) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("���趨��ȷ�𰸣�") , QMessageBox::Yes);
	} else {
		SqlModel sql;
		bool information; //����ɹ�����true,���򷵻�false
		information = sql.updateChoice(description , choiceA , choiceB , choiceC , choiceD , AddChoice::convertAnswer(answer) , score , tempQuestionId);
		if (information) {
			QMessageBox::information(NULL , QStringLiteral("��ʾ") , QStringLiteral("�޸ĳɹ���") , QMessageBox::Yes);
			this->close();
		} else {
			QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("�޸�ʧ�ܣ�") , QMessageBox::Yes);
		}
	}
}


/**
  * @author:Ӧ�о�
  * @brief:���ð�ť�Ĺ���ʵ��
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
  * @author:Ӧ�о�
  * @brief:���趨���л�ȡ�������±�ת�����ַ���
  * @param [in] �������1: �����±�index
  * @param [out] �������: ������Ӧѡ����ַ���
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


/**
  * @author:Ӧ�о�
  * @brief:���շ��͹�����ѡ�е�ѡ�����Ӧ���ݲ���ʾ
  * @date:2018/12/16
  * @version:1.0
  */
void AddChoice::receiveData(Choice c) {
	this->tempQuestionId = c.getQuestionId();
	AddChoice* a = new AddChoice;  //�½�ҳ��
	disconnect(a->ui.submitBtn , SIGNAL(clicked(bool)) , a , SLOT(checkData())); //������ύ��ť����¼�
	connect(a->ui.submitBtn , SIGNAL(clicked(bool)) , a , SLOT(checkUpdateData())); //���°��޸İ�ť����¼�
	a->ui.label->setText(QStringLiteral("�޸ĵ�ѡ��"));   //�޸ı�������
	a->ui.submitBtn->setText(QStringLiteral("��   ��"));  //�޸İ�ť����
	a->ui.description->setText(c.getDescription());  //���������Ϣ
	a->ui.choiceA->setText(c.getChoiceA());
	a->ui.choiceB->setText(c.getChoiceB());
	a->ui.choiceC->setText(c.getChoiceC());
	a->ui.choiceD->setText(c.getChoiceD());
	a->ui.score->setValue(c.getValue());
	if (c.getAnswer() == "A") {
		a->ui.answer->setCurrentIndex(1);
	} else if (c.getAnswer() == "B") {
		a->ui.answer->setCurrentIndex(2);
	} else if (c.getAnswer() == "C") {
		a->ui.answer->setCurrentIndex(3);
	} else if (c.getAnswer() == "D") {
		a->ui.answer->setCurrentIndex(4);
	}
	a->exec();  //���޸�ģ̬��
	delete a;  //ɾ��ҳ��
}

AddChoice::~AddChoice() {

}
