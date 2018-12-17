#include "StudentWindow.h"
#include "SqlModel.h"

StudentWindow::StudentWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	this->examModel= new QStandardItemModel; //创建考试表格

	StudentWindow::dataGet();
	StudentWindow::showExam();
}

StudentWindow::~StudentWindow()
{
	delete examModel;
}


void StudentWindow::showExam()
{
	this->examModel->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("考试编号")));
	this->examModel->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("考试名称")));
	this->examModel->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("考试时长")));
	this->examModel->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("考试状态")));
	this->examModel->setHorizontalHeaderItem(4, new QStandardItem(QStringLiteral("考试得分")));
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
			this->examModel->setItem(i, 3, new QStandardItem(QStringLiteral("已完成")));
			this->examModel->setItem(i, 4, new QStandardItem(score));
		}else {
			this->examModel->setItem(i, 3, new QStandardItem(QStringLiteral("可参加")));
			this->examModel->setItem(i, 4, new QStandardItem(QStringLiteral("暂无")));
		}
	}
	
}


void StudentWindow::dataGet()
{
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("提示"), QStringLiteral("连接失败"), QMessageBox::Yes);
		this->close();
	}
	else {
		this->student = sql.searchStudentExam();
	}
}
