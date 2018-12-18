#include "StudentWindow.h"
#include "SqlModel.h"

StudentWindow::StudentWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	this->examModel= new QStandardItemModel; //�������Ա��
}

StudentWindow::~StudentWindow()
{
	delete examModel;
}

/**
  * @author:������
  * @brief:��������Ϣ��ѧ������������ʾ������2.0����С�ֵ���ʾ
  * @date:2018/12/16
  * @version:2.0
  */
void StudentWindow::showExam()
{
	this->examModel->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("���Ա��")));
	this->examModel->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("��������")));
	this->examModel->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("����ʱ��")));
	this->examModel->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("����״̬")));
	this->examModel->setHorizontalHeaderItem(4, new QStandardItem(QStringLiteral("�����ܷ�")));
	this->examModel->setHorizontalHeaderItem(5, new QStandardItem(QStringLiteral("ѡ��÷�")));
	this->examModel->setHorizontalHeaderItem(6, new QStandardItem(QStringLiteral("�жϵ÷�")));
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
			this->examModel->setItem(i, 3, new QStandardItem(QStringLiteral("�����")));
			this->examModel->setItem(i, 4, new QStandardItem(score));
			this->examModel->setItem(i, 5, new QStandardItem(objectScore));
			this->examModel->setItem(i, 6, new QStandardItem(judgeScore));
		}else {
			this->examModel->setItem(i, 3, new QStandardItem(QStringLiteral("�ɲμ�")));
			this->examModel->setItem(i, 4, new QStandardItem(QStringLiteral("����")));
			this->examModel->setItem(i, 5, new QStandardItem(QStringLiteral("����")));
			this->examModel->setItem(i, 6, new QStandardItem(QStringLiteral("����")));
		}
	}
}

/**
  * @author:������
  * @brief:ˢ�¿��Ե�����
  * @date:2018/12/17
  * @version:1.0
  */
void StudentWindow::dataGet()
{
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("��ʾ"), QStringLiteral("����ʧ��"), QMessageBox::Yes);
		this->close();
	}
	else {
		this->exam = sql.searchExam(this->userName);
	}
}
/**
  * @author:������
  * @brief:��ѧ����Ϣ��ѧ������������ʾ����
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
