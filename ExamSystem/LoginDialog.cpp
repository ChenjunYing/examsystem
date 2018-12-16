#include "LoginDialog.h"
#include "SqlModel.h"

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	connect(this->ui.submitBtn , SIGNAL(clicked(bool)) , this , SLOT(login())); //绑定登录按钮
}

/**
  * @author:应承峻
  * @brief:用户点击登录按钮后实现的功能
  * @date:2018/12/12
  * @version:1.0
  */
void LoginDialog::login(){
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
			//int usernamecol = query.record().indexOf("username"); //获取username字段的列号
			//int personnamecol = query.record().indexOf("person_name");
			QMessageBox::information(NULL , QStringLiteral("提示") , QStringLiteral("登录成功") , QMessageBox::Yes);
			this->close(); //关闭该窗口
			if (radioBtn.at(i)->text().compare(QStringLiteral("普通用户")) == 0) {
				//启动用户主界面
			} else {
				admin.show(); //启动管理员主界面
			}
		}
	} else {
		QMessageBox::warning(NULL , QStringLiteral("提示") , QStringLiteral("连接失败") , QMessageBox::Yes);
	}
}

LoginDialog::~LoginDialog() {

}