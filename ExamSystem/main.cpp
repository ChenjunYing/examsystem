#include "MainWindow.h"
#include "LoginDialog.h"
#include "StudentExam.h"
#include "AddExam.h"
#include "StudentInfo.h"
#include "AddStudent.h"
#include <QFile>
#include <QApplication>
#include <QtWidgets/QApplication>

void initStyle() {
	QFile file(":/qss/psblack.css");
	if (file.open(QFile::ReadOnly)) {
		QString qss = QLatin1String(file.readAll());
		QString paletteColor = qss.mid(20 , 7);
		qApp->setPalette(QPalette(QColor(paletteColor)));
		qApp->setStyleSheet(qss);
		file.close();
	}
}

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	initStyle();
	//LoginDialog logindialog;
	//logindialog.show();
	AddStudent add;
	add.show();
	return a.exec();
}