#include "MainWindow.h"
#include "LoginDialog.h"
#include <QFile>
#include <QApplication>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	LoginDialog logindialog;
	logindialog.show();
	//MainWindow admin;
	//admin.show();
	//StudentWindow student;
	//student.show();
	return a.exec();
}