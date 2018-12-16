#include "LoginDialog.h"
#include "SqlModel.h"

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	connect(this->ui.submitBtn , SIGNAL(clicked(bool)) , this , SLOT(login())); //�󶨵�¼��ť
}

/**
  * @author:Ӧ�о�
  * @brief:�û������¼��ť��ʵ�ֵĹ���
  * @date:2018/12/12
  * @version:1.0
  */
void LoginDialog::login(){
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
			//int usernamecol = query.record().indexOf("username"); //��ȡusername�ֶε��к�
			//int personnamecol = query.record().indexOf("person_name");
			QMessageBox::information(NULL , QStringLiteral("��ʾ") , QStringLiteral("��¼�ɹ�") , QMessageBox::Yes);
			this->close(); //�رոô���
			if (radioBtn.at(i)->text().compare(QStringLiteral("��ͨ�û�")) == 0) {
				//�����û�������
			} else {
				admin.show(); //��������Ա������
			}
		}
	} else {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("����ʧ��") , QMessageBox::Yes);
	}
}

LoginDialog::~LoginDialog() {

}