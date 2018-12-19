#include "AddJudge.h"
#include "SqlModel.h"
#include "QuestionBank.h"

AddJudge::AddJudge(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //������С��󻯰�ť�͹رհ�ť
	connect(this->ui.submitBtn, SIGNAL(clicked(bool)), this, SLOT(checkData())); //���ύ��ť����¼�
	connect(this->ui.resetBtn, SIGNAL(clicked(bool)), this, SLOT(resetData())); //�����ð�ť����¼�
}

/**
  * @author:��˼Ӿ
  * @brief:�ж�����ж�������ĺϷ���,���Ϸ���ִ�в������,���򵯳��Ƿ������Ի���
  * @date:2018/12/19
  * @version:1.0
  */
void AddJudge::checkData() {
	QString description = this->ui.description->toPlainText(); //��ȡ��Ŀ����
	int score = this->ui.score->value(); //��ȡ��Ŀ��ֵ
	bool answer[2] = { this->ui.right->isChecked(),this->ui.wrong->isChecked()}; //��ȡ��
	if (!description.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("��Ŀ��������Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (answer[0] == 0 && answer[1] == 0 ) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("���趨��ȷ�𰸣�"), QMessageBox::Yes);
	}
	else {
		SqlModel sql;
		bool information; //����ɹ�����true,���򷵻�false
		information = sql.insertJudge(description, AddJudge::convertAnswer(answer), score);
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
  * @brief:�ж��޸��ж�������ĺϷ���,���Ϸ���ִ���޸Ĳ���,���򵯳��Ƿ������Ի���
  * @date:2018/12/19
  * @version:1.0
 */
void AddJudge::checkUpdateData()
{
	QString description = this->ui.description->toPlainText(); //��ȡ��Ŀ����
	int score = this->ui.score->value(); //��ȡ��Ŀ��ֵ
	bool answer[2] = { this->ui.right->isChecked(),this->ui.wrong->isChecked() }; //��ȡ��
	if (!description.length()) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("��Ŀ��������Ϊ�գ�"), QMessageBox::Yes);
	}
	else if (answer[0] == 0 && answer[1] == 0) {
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("���趨��ȷ�𰸣�"), QMessageBox::Yes);
	}
	else {
		SqlModel sql;
		bool information; //����ɹ�����true,���򷵻�false
		information = sql.updateJudge(description, AddJudge::convertAnswer(answer), score, tempQuestionId);
		if (information) {
			emit updateOK(2);  //��QuestionBankҳ�淢�͸�������ź�,ʹ�����ˢ�²���
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
   * @author:��˼Ӿ
   * @brief:���𰸵�bool����ת��Ϊ�ַ�
   * @param [in] �������1: ����Ϊ2��bool����
   * @param [out] �������: ����T����F���ַ�
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
  * @author:��˼Ӿ
  * @brief:���շ��͹�����ѡ�ж�ѡ�����Ӧ���ݲ���ʾ
  * @date:2018/12/18
  * @version:1.0
  */
void AddJudge::receiveData(Judge c) {
	AddJudge* a;
	a = new AddJudge;  //�½��޸�����ҳ��
	a->tempQuestionId = c.getQuestionId();  //�洢������
	disconnect(a->ui.submitBtn, SIGNAL(clicked(bool)), a, SLOT(checkData())); //������ύ��ť����¼�
	connect(a->ui.submitBtn, SIGNAL(clicked(bool)), a, SLOT(checkUpdateData())); //���°��޸İ�ť����¼�
	a->ui.label->setText(QStringLiteral("�޸Ķ�ѡ��"));   //�޸ı�������
	a->ui.submitBtn->setText(QStringLiteral("��   ��"));  //�޸İ�ť����
	a->ui.description->setText(c.getDescription());  //���������Ϣ
	a->ui.score->setValue(c.getValue());
	if(c.getAnswer()=='T')
		a->ui.right->setChecked(true);
	else if (c.getAnswer() == 'F')
		a->ui.wrong->setChecked(true);
	emit sendJudgePage(a);  //��MainWindowҳ�淢���޸�ҳ���ָ���Ա�������ź���۵İ�
	a->exec();  //���޸�ģ̬��
	if (a != NULL) {
		delete a;  //ɾ��ҳ��
	}
}

AddJudge::~AddJudge() {

}
