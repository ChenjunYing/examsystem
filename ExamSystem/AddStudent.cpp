#include "AddStudent.h"

AddStudent::AddStudent(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	connect(this->ui.submitBtn , SIGNAL(clicked(bool)) , this , SLOT(regist()));
	connect(this->ui.checkBtn , SIGNAL(clicked(bool)) , this , SLOT(check()));
	connect(this->ui.resetBtn , SIGNAL(clicked(bool)) , this , SLOT(reset()));
}


/**
  * @author:应承峻
  * @brief:修改信息
  * @date:2019/1/8
  * @version:1.0
  */
void AddStudent::update() {
	int checked = AddStudent::checkdata(1);
	if (checked) {
		Student student(username , password , phonenumber , name , major , id , sex);
		bool res = sql.updateStudent(student);
		if (res == true) {
			QMessageBox::information(NULL , QStringLiteral("提示") , QStringLiteral("修改成功！") , QMessageBox::Yes);
			this->close();
			this->reset();
			emit userUpdateOk();
		} else {
			QMessageBox::information(NULL , QStringLiteral("提示") , QStringLiteral("修改失败！") , QMessageBox::Yes);
		}
	}
}

/**
  * @author:应承峻
  * @brief:用户注册
  * @date:2019/1/8
  * @version:1.0
  */
void AddStudent::regist() {
	int checked = AddStudent::checkdata();
	if (checked) {
		Student student(username , password , phonenumber , name , major , id , sex);
		bool res = sql.insertStudent(student);
		if (res == true) {
			QMessageBox::information(NULL , QStringLiteral("提示") , QStringLiteral("注册成功！") , QMessageBox::Yes);
			this->close();
			this->reset();
		} else {
			QMessageBox::information(NULL , QStringLiteral("提示") , QStringLiteral("注册失败！") , QMessageBox::Yes);
		}
	}
}

/**
  * @author:应承峻
  * @brief:检测事件
  * @date:2019/1/8
  * @version:1.0
  */
void AddStudent::check() {
	int checked = checkdata();
	if (checked) {
		QMessageBox::information(NULL , QStringLiteral("提示") , QStringLiteral("检测通过！") , QMessageBox::Yes);
	}
}

/**
  * @author:应承峻
  * @brief:检测输入合法性
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
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("用户名不能为空！") , QMessageBox::Yes);
	} else if (!username.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("用户名不能为空！") , QMessageBox::Yes);
	} else if (sql.isUsernameExist(username)) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("用户名已存在！") , QMessageBox::Yes);
	} else if (!password.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("密码不能为空！") , QMessageBox::Yes);
	} else if (!name.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("真实姓名不能为空！") , QMessageBox::Yes);
	} else if (!id.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("学号不能为空！") , QMessageBox::Yes);
	} else if (!major.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("主修专业不能为空！") , QMessageBox::Yes);
	} else if (!phonenumber.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("电话号码不能为空！") , QMessageBox::Yes);
	} else if (sex < 0) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("性别不能为空！") , QMessageBox::Yes);
	} else {
		return 1;
	}
	return 0; 
}

/**
  * @author:应承峻
  * @brief:检测输入合法性 +1重载
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
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("用户名不能为空！") , QMessageBox::Yes);
	} else if (!username.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("用户名不能为空！") , QMessageBox::Yes);
	} else if (!password.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("密码不能为空！") , QMessageBox::Yes);
	} else if (!name.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("真实姓名不能为空！") , QMessageBox::Yes);
	} else if (!id.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("学号不能为空！") , QMessageBox::Yes);
	} else if (!major.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("主修专业不能为空！") , QMessageBox::Yes);
	} else if (!phonenumber.length()) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("电话号码不能为空！") , QMessageBox::Yes);
	} else if (sex < 0) {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("性别不能为空！") , QMessageBox::Yes);
	} else {
		return 1;
	}
	return 0; 
}

/**
  * @author:应承峻
  * @brief:重置功能
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
