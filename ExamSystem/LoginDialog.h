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
#include "SqlModel.h"
#include "MainWindow.h"
#include "StudentWindow.h"
#include "ui_LoginDialog.h"

class LoginDialog : public QDialog {
	
	Q_OBJECT

public:
	LoginDialog(QWidget *parent = Q_NULLPTR);
	~LoginDialog();

signals:
	void sendUserName(QString name);

private slots:
	void login();
	void studentLogout();
	void adminLogout();

private:
	Ui::LoginDialog ui;
	MainWindow admin;
	StudentWindow student;

};

#endif