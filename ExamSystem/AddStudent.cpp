#include "AddStudent.h"

AddStudent::AddStudent(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	connect(this->ui.submitBtn , SIGNAL(clicked(bool)) , this , SLOT(regist()));
	connect(this->ui.checkBtn , SIGNAL(clicked(bool)) , this , SLOT(check()));
	connect(this->ui.resetBtn , SIGNAL(clicked(bool)) , this , SLOT(reset()));
}


/**
  * @author:Ӧ�о�
  * @brief:�޸���Ϣ
  * @date:2019/1/8
  * @version:1.0
  */
void AddStudent::update() {
	int checked = AddStudent::checkdata(1);
	if (checked) {
		Student student(username , password , phonenumber , name , major , id , sex);
		bool res = sql.updateStudent(student);
		if (res == true) {
			QMessageBox::information(NULL , QStringLiteral("��ʾ") , QStringLiteral("�޸ĳɹ���") , QMessageBox::Yes);
			this->close();
			this->reset();
			emit userUpdateOk();
		} else {
			QMessageBox::information(NULL , QStringLiteral("��ʾ") , QStringLiteral("�޸�ʧ�ܣ�") , QMessageBox::Yes);
		}
	}
}

/**
  * @author:Ӧ�о�
  * @brief:�û�ע��
  * @date:2019/1/8
  * @version:1.0
  */
void AddStudent::regist() {
	int checked = AddStudent::checkdata();
	if (checked) {
		Student student(username , password , phonenumber , name , major , id , sex);
		bool res = sql.insertStudent(student);
		if (res == true) {
			QMessageBox::information(NULL , QStringLiteral("��ʾ") , QStringLiteral("ע��ɹ���") , QMessageBox::Yes);
			this->close();
			this->reset();
		} else {
			QMessageBox::information(NULL , QStringLiteral("��ʾ") , QStringLiteral("ע��ʧ�ܣ�") , QMessageBox::Yes);
		}
	}
}

/**
  * @author:Ӧ�о�
  * @brief:����¼�
  * @date:2019/1/8
  * @version:1.0
  */
void AddStudent::check() {
	int checked = checkdata();
	if (checked) {
		QMessageBox::information(NULL , QStringLiteral("��ʾ") , QStringLiteral("���ͨ����") , QMessageBox::Yes);
	}
}

/**
  * @author:Ӧ�о�
  * @brief:�������Ϸ���
  * @date:2019/1/8
  * @version:1.0
  */
int AddStudent::checkdata() {
	if (this->ui.male->isChecked()) sex = 1;
	else if (this->ui.female->isChecked()) sex = 0;
	else sex = -1;
	username = this->ui.username->text();
	password = this->ui.password->text();
	name = this->ui.name->text();
	id = this->ui.studentId->text();
	major = this->ui.major->text();
	phonenumber = this->ui.phonenumber->text();
	if (!sql.isOpen()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("�û�������Ϊ�գ�") , QMessageBox::Yes);
	} else if (!username.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("�û�������Ϊ�գ�") , QMessageBox::Yes);
	} else if (sql.isUsernameExist(username)) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("�û����Ѵ��ڣ�") , QMessageBox::Yes);
	} else if (!password.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("���벻��Ϊ�գ�") , QMessageBox::Yes);
	} else if (!name.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("��ʵ��������Ϊ�գ�") , QMessageBox::Yes);
	} else if (!id.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("ѧ�Ų���Ϊ�գ�") , QMessageBox::Yes);
	} else if (!major.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("����רҵ����Ϊ�գ�") , QMessageBox::Yes);
	} else if (!phonenumber.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("�绰���벻��Ϊ�գ�") , QMessageBox::Yes);
	} else if (sex < 0) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("�Ա���Ϊ�գ�") , QMessageBox::Yes);
	} else {
		return 1;
	}
	return 0; 
}

/**
  * @author:Ӧ�о�
  * @brief:�������Ϸ��� +1����
  * @date:2019/1/8
  * @version:1.0
  */
int AddStudent::checkdata(int) {
	if (this->ui.male->isChecked()) sex = 1;
	else if (this->ui.female->isChecked()) sex = 0;
	else sex = -1;
	username = this->ui.username->text();
	password = this->ui.password->text();
	name = this->ui.name->text();
	id = this->ui.studentId->text();
	major = this->ui.major->text();
	phonenumber = this->ui.phonenumber->text();
	if (!sql.isOpen()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("�û�������Ϊ�գ�") , QMessageBox::Yes);
	} else if (!username.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("�û�������Ϊ�գ�") , QMessageBox::Yes);
	} else if (!password.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("���벻��Ϊ�գ�") , QMessageBox::Yes);
	} else if (!name.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("��ʵ��������Ϊ�գ�") , QMessageBox::Yes);
	} else if (!id.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("ѧ�Ų���Ϊ�գ�") , QMessageBox::Yes);
	} else if (!major.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("����רҵ����Ϊ�գ�") , QMessageBox::Yes);
	} else if (!phonenumber.length()) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("�绰���벻��Ϊ�գ�") , QMessageBox::Yes);
	} else if (sex < 0) {
		QMessageBox::warning(NULL , QStringLiteral("��ʾ") , QStringLiteral("�Ա���Ϊ�գ�") , QMessageBox::Yes);
	} else {
		return 1;
	}
	return 0; 
}

/**
  * @author:Ӧ�о�
  * @brief:���ù���
  * @date:2019/1/8
  * @version:1.0
  */
void AddStudent::reset() {
	this->ui.username->clear();
	this->ui.password->clear();
	this->ui.name->clear(); 
	this->ui.studentId->clear();
	this->ui.major->clear();
	this->ui.phonenumber->clear();
	this->ui.male->setChecked(false);
	this->ui.female->setChecked(false);
}

AddStudent::~AddStudent() {

}
