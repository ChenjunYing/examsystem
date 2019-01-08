#include "LoginDialog.h"

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	connect(this->ui.submitBtn , SIGNAL(clicked(bool)) , this , SLOT(login())); //�󶨵�¼��ť
	connect(this, SIGNAL(sendUserName(QString)), &this->student, SLOT(receiveUserName(QString)));
	connect(this->student.ui.btnLogout, SIGNAL(clicked(bool)), this, SLOT(studentLogout()));
	connect(this->admin.ui.logout , SIGNAL(triggered()) , this , SLOT(adminLogout()));
	connect(this->ui.registBtn , SIGNAL(clicked(bool)) , this , SLOT(regist()));
}

/**
  * @author:Ӧ�о�
  * @brief:�û������¼��ť��ʵ�ֵĹ���
  * @date:2018/12/12
  * @version:1.0
  */
void LoginDialog::login() {
	int i;
	SqlModel sql;
	QString username = this->ui.username->text();   //��ȡ�û�������û���
	QString password = this->ui.password->text();   //��ȡ�û����������
	QList<QAbstractButton*> radioBtn = this->ui.buttonGroup->buttons();  //��ȡ��ѡ��ť�������а�ť
	for (i = 0; i < radioBtn.length(); i++)  //�ҵ���ѡ�еİ�ť
		if (radioBtn.at(i)->isChecked()) break;
	if (sql.isOpen()) {
		QSqlQuery query = sql.check(username , password , radioBtn.at(i)->text()); //���ݿ��в�ѯ
		if (query.size() <= 0) {
			QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("�û������������") , QMessageBox::Yes);
			this->ui.username->clear();  //���������û���
			this->ui.password->clear();  //������������
			for (i = 0; i < radioBtn.length(); i++) {
				radioBtn.at(i)->setChecked(false);  //���õ�ѡ��ť���ѡ��״̬
			}
			return;
		} else {
			query.next(); //ת����1������
			QMessageBox::information(NULL , QStringLiteral("��ʾ") , QStringLiteral("��¼�ɹ�") , QMessageBox::Yes);
			this->close(); //�رոô���
			if (radioBtn.at(i)->text().compare(QStringLiteral("��ͨ�û�")) == 0) {
				emit sendUserName(username);
				student.show(); //�����û�������
			} else {
				admin.show(); //��������Ա������
			}
		}
	} else {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("����ʧ��") , QMessageBox::Yes);
	}
}

/**
  * @author:Ӧ�о�
  * @brief:����ע��ҳ��
  * @date:2019/1/8
  * @version:1.0
  */
void LoginDialog::regist() {
	addstudent.exec();
}

LoginDialog::~LoginDialog() {

}

/**
  * @author:������
  * @brief:ѧ�����������ע����ť��ʵ�ֵĹ���
  * @date:2018/12/20
  * @version:1.0
  */
void LoginDialog::studentLogout() {
	QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("ע���ɹ�"), QMessageBox::Yes);
	this->student.close();
	this->ui.username->clear();  //���������û���
	this->ui.password->clear();  //������������
	this->show();
}

/**
  * @author:Ӧ�о�
  * @brief:����Ա���������ע����ť��ʵ�ֵĹ���
  * @date:2019/1/3
  * @version:1.0
  */
void LoginDialog::adminLogout() {
	QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("ע���ɹ�"), QMessageBox::Yes);
	this->admin.close();
	this->ui.username->clear();  //���������û���
	this->ui.password->clear();  //������������
	this->show();
}