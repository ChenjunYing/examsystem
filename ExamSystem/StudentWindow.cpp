#include "StudentWindow.h"
#include "SqlModel.h"

StudentWindow::StudentWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	this->examModel= new QStandardItemModel; //创建考试表格
}

StudentWindow::~StudentWindow()
{
	delete examModel;
}

/**
  * @author:夏林轩
  * @brief:将考试信息在学生主界面上显示出来，2.0增加小分的显示
  * @date:2018/12/16
  * @version:2.0
  */
void StudentWindow::showExam()
{
	this->examModel->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("考试编号")));
	this->examModel->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("考试名称")));
	this->examModel->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("考试时长")));
	this->examModel->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("考试状态")));
	this->examModel->setHorizontalHeaderItem(4, new QStandardItem(QStringLiteral("考试总分")));
	this->examModel->setHorizontalHeaderItem(5, new QStandardItem(QStringLiteral("选择得分")));
	this->examModel->setHorizontalHeaderItem(6, new QStandardItem(QStringLiteral("判断得分")));
	this->ui.examTable->setModel(examModel);
	StudentWindow::dataGet();
	for (int i = 0; i < exam.size(); i++) {
		QString code = QString::number(exam.at(i).getCode());
		QString duration = QString::number(exam.at(i).getDuration());
		this->examModel->setItem(i, 0, new QStandardItem(code));
		this->examModel->setItem(i, 1, new QStandardItem(exam.at(i).getName()));
		this->examModel->setItem(i, 2, new QStandardItem(duration));
		if (exam.at(i).getIsSubmit() == 1) {
			QString score = QString::number(exam.at(i).getScore());
			QString objectScore = QString::number(exam.at(i).getObjectScore());
			QString judgeScore = QString::number(exam.at(i).getJudgeScore());
			this->examModel->setItem(i, 3, new QStandardItem(QStringLiteral("已完成")));
			this->examModel->setItem(i, 4, new QStandardItem(score));
			this->examModel->setItem(i, 5, new QStandardItem(objectScore));
			this->examModel->setItem(i, 6, new QStandardItem(judgeScore));
		}else {
			this->examModel->setItem(i, 3, new QStandardItem(QStringLiteral("可参加")));
			this->examModel->setItem(i, 4, new QStandardItem(QStringLiteral("暂无")));
			this->examModel->setItem(i, 5, new QStandardItem(QStringLiteral("暂无")));
			this->examModel->setItem(i, 6, new QStandardItem(QStringLiteral("暂无")));
		}
	}
}

/**
  * @author:夏林轩
  * @brief:刷新考试的数据
  * @date:2018/12/17
  * @version:1.0
  */
void StudentWindow::dataGet()
{
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("提示"), QStringLiteral("连接失败"), QMessageBox::Yes);
		this->close();
	}
	else {
		this->exam = sql.searchExam(this->userName);
	}
}
/**
  * @author:夏林轩
  * @brief:将学生信息在学生主界面上显示出来
  * @date:2018/12/18
  * @version:1.0
  */
void StudentWindow::showStudent(QString username)
{
	SqlModel sql;
	Student student = sql.searchStudentInfo(username);
	this->ui.Name->setText(student.getName());
	this->ui.Major->setText(student.getMajor());
	this->ui.Id->setText(student.getId());
}

void StudentWindow::receiveUserName(QString name)
{
	userName = name;
	StudentWindow::showExam();
	StudentWindow::showStudent(userName);
}
