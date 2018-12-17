#include "StudentWindow.h"
#include "SqlModel.h"

StudentWindow::StudentWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	this->examModel= new QStandardItemModel; //�������Ա��

	StudentWindow::dataGet();
	StudentWindow::showExam();
}

StudentWindow::~StudentWindow()
{
	delete examModel;
}


void StudentWindow::showExam()
{
	this->examModel->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("���Ա��")));
	this->examModel->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("��������")));
	this->examModel->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("����ʱ��")));
	this->examModel->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("����״̬")));
	this->examModel->setHorizontalHeaderItem(4, new QStandardItem(QStringLiteral("���Ե÷�")));
	this->ui.examTable->setModel(examModel);
	StudentWindow::dataGet();
	for (int i = 0; i < student.size(); i++) {
		QString code = QString::number(student.at(i).getCode());
		QString duration = QString::number(student.at(i).getDuration());
		this->examModel->setItem(i, 0, new QStandardItem(code));
		this->examModel->setItem(i, 1, new QStandardItem(student.at(i).getName()));
		this->examModel->setItem(i, 2, new QStandardItem(duration));
		if (student.at(i).getIsSubmit() == 1) {
			QString score = QString::number(student.at(i).getScore());
			this->examModel->setItem(i, 3, new QStandardItem(QStringLiteral("�����")));
			this->examModel->setItem(i, 4, new QStandardItem(score));
		}else {
			this->examModel->setItem(i, 3, new QStandardItem(QStringLiteral("�ɲμ�")));
			this->examModel->setItem(i, 4, new QStandardItem(QStringLiteral("����")));
		}
	}
	
}


void StudentWindow::dataGet()
{
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("��ʾ"), QStringLiteral("����ʧ��"), QMessageBox::Yes);
		this->close();
	}
	else {
		this->student = sql.searchStudentExam();
	}
}
