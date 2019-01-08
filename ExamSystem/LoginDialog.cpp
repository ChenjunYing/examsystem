#include "LoginDialog.h"

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	connect(this->ui.submitBtn , SIGNAL(clicked(bool)) , this , SLOT(login())); //绑定登录按钮
	connect(this, SIGNAL(sendUserName(QString)), &this->student, SLOT(receiveUserName(QString)));
	connect(this->student.ui.btnLogout, SIGNAL(clicked(bool)), this, SLOT(studentLogout()));
	connect(this->admin.ui.logout , SIGNAL(triggered()) , this , SLOT(adminLogout()));
	connect(this->ui.registBtn , SIGNAL(clicked(bool)) , this , SLOT(regist()));
}

/**
  * @author:应承峻
  * @brief:用户点击登录按钮后实现的功能
  * @date:2018/12/12
  * @version:1.0
  */
void LoginDialog::login() {
	int i;
	SqlModel sql;
	QString username = this->ui.username->text();   //获取用户输入的用户名
	QString password = this->ui.password->text();   //获取用户输入的密码
	QList<QAbstractButton*> radioBtn = this->ui.buttonGroup->buttons();  //获取单选按钮组中所有按钮
	for (i = 0; i < radioBtn.length(); i++)  //找到被选中的按钮
		if (radioBtn.at(i)->isChecked()) break;
	if (sql.isOpen()) {
		QSqlQuery query = sql.check(username , password , radioBtn.at(i)->text()); //数据库中查询
		if (query.size() <= 0) {
			QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("用户名或密码错误") , QMessageBox::Yes);
			this->ui.username->clear();  //清空输入的用户名
			this->ui.password->clear();  //清空输入的密码
			for (i = 0; i < radioBtn.length(); i++) {
				radioBtn.at(i)->setChecked(false);  //重置单选按钮组的选中状态
			}
			return;
		} else {
			query.next(); //转到第1条数据
			QMessageBox::information(NULL , QStringLiteral("提示") , QStringLiteral("登录成功") , QMessageBox::Yes);
			this->close(); //关闭该窗口
			if (radioBtn.at(i)->text().compare(QStringLiteral("普通用户")) == 0) {
				emit sendUserName(username);
				student.show(); //启动用户主界面
			} else {
				admin.show(); //启动管理员主界面
			}
		}
	} else {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("连接失败") , QMessageBox::Yes);
	}
}

/**
  * @author:应承峻
  * @brief:进入注册页面
  * @date:2019/1/8
  * @version:1.0
  */
void LoginDialog::regist() {
	addstudent.exec();
}

LoginDialog::~LoginDialog() {

}

/**
  * @author:夏林轩
  * @brief:学生点击主界面注销按钮后实现的功能
  * @date:2018/12/20
  * @version:1.0
  */
void LoginDialog::studentLogout() {
	QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("注销成功"), QMessageBox::Yes);
	this->student.close();
	this->ui.username->clear();  //清空输入的用户名
	this->ui.password->clear();  //清空输入的密码
	this->show();
}

/**
  * @author:应承峻
  * @brief:管理员点击主界面注销按钮后实现的功能
  * @date:2019/1/3
  * @version:1.0
  */
void LoginDialog::adminLogout() {
	QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("注销成功"), QMessageBox::Yes);
	this->admin.close();
	this->ui.username->clear();  //清空输入的用户名
	this->ui.password->clear();  //清空输入的密码
	this->show();
}