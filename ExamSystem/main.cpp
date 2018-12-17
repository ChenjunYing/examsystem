#include "MainWindow.h"
#include "LoginDialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginDialog logindialog;
	logindialog.show();
	//MainWindow admin;
	//admin.show();
	//StudentWindow student;
	//student.show();
	return a.exec();
}