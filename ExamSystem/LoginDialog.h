#ifndef _LOGINDIALOG_H
#define _LOGINDIALOG_H

#include <QList>
#include <QString>
#include <QDialog>
#include <QSqlQuery>
#include <QWidget>
#include <QRadioButton>
#include <QAbstractButton>
#include <QtWidgets/QApplication>
#include <QMessageBox>
#include <QDebug>
#include "MainWindow.h"
#include "StudentWindow.h"
#include "ui_LoginDialog.h"

class LoginDialog : public QDialog
{
	Q_OBJECT

public:
	LoginDialog(QWidget *parent = Q_NULLPTR);
	~LoginDialog();

signals:
	void sendUserName(QString name);

private slots:
	/**
	  * @author:应承峻
	  * @brief:用户点击登录按钮后实现的功能
	  * @date:2018/12/12
	  * @version:1.0
	  */
	void login();

private:
	Ui::LoginDialog ui;
	MainWindow admin;
	StudentWindow student;
};


#endif