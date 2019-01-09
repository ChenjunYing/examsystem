#include "StudentWindow.h"
#include "SqlModel.h"

StudentWindow::StudentWindow(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	this->examModel = new QStandardItemModel; //�������Ա��
	connect(this->ui.examTable, SIGNAL(clicked(const QModelIndex&)), this, SLOT(examTableClicked(const QModelIndex&)));
	connect(this->ui.refreshBtn, SIGNAL(clicked(bool)), this, SLOT(dataRefresh()));
	connect(this->ui.updateBtn , SIGNAL(clicked(bool)) , this , SLOT(updateBtnClicked()));
}

StudentWindow::~StudentWindow() {
	delete examModel;
}

/**
  * @author:Ӧ�о�
  * @brief:ˢ��ҳ�����ݲ���ʾ
  * @date:2019/1/2
  * @version:1.0
  */
void StudentWindow::dataRefresh() {
	StudentWindow::showExam();
	StudentWindow::showStudent(userName);
}

/**
  * @author:Ӧ�о�
  * @brief:ʵ�ֵ������״̬���뿼�ԵĹ���
  * @date:2018/12/28
  * @version:1.0
  */
void StudentWindow::examTableClicked(const QModelIndex& index) {
	if (index.isValid() && index.column() == 2 && exam.at(index.row()).getIsSubmit() == 0) {
		//qDebug() << userName << "," << exam.at(index.row()).getName();
		int ret = QMessageBox::warning(this, QStringLiteral("��ʾ"), QStringLiteral("ȷ����ʼ������"), QMessageBox::Yes | QMessageBox::Cancel);
		if (ret == QMessageBox::Yes) {
			this->close();
			newExam = new StudentExam;
			connect(this->newExam, SIGNAL(examFinish()), this, SLOT(receiveExamFinish()));
			newExam->display(userName, exam.at(index.row()).getCode());
			newExam->show();
		}
	}
}

/**
  * @author:������
  * @brief:��������Ϣ��ѧ������������ʾ������2.0����С�ֵ���ʾ,3.0���������е����ݹ���ʱ���п��������Ӧ
  * @date:2018/12/20
  * @version:3.0
  */
void StudentWindow::showExam() {
	int columnWidthStrategy = 0;
	this->examModel->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("��������")));
	this->examModel->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("����ʱ��")));
	this->examModel->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("����״̬")));
	this->examModel->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("�����ܷ�")));
	this->examModel->setHorizontalHeaderItem(4, new QStandardItem(QStringLiteral("��ѡ�÷�")));
	this->examModel->setHorizontalHeaderItem(5, new QStandardItem(QStringLiteral("��ѡ�÷�")));
	this->examModel->setHorizontalHeaderItem(6, new QStandardItem(QStringLiteral("�жϵ÷�")));
	this->ui.examTable->setModel(examModel);
	this->ui.examTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	StudentWindow::dataGet();
	for (int j = 0; j < exam.size(); j++)
	{
		if (exam.at(j).getName().length() >= 16)
		{
			columnWidthStrategy = 1;
			break;
		}
	}
	for (int i = 0; i < exam.size(); i++) {
		QString duration = QString::number(exam.at(i).getDuration());
		this->examModel->setItem(i, 0, new QStandardItem(exam.at(i).getName()));
		if (columnWidthStrategy) {
			this->ui.examTable->resizeColumnToContents(0);
		}
		else {
			this->ui.examTable->setColumnWidth(0, 200);
		}
		this->examModel->setItem(i, 1, new QStandardItem(duration.append(QStringLiteral("����"))));
		if (exam.at(i).getIsSubmit() == 1) {
			QString score = QString::number(exam.at(i).getScore());
			QString choiceScore = QString::number(exam.at(i).getChoiceScore());
			QString multiScore = QString::number(exam.at(i).getMultiScore());
			QString judgeScore = QString::number(exam.at(i).getJudgeScore());
			this->examModel->setItem(i, 2, new QStandardItem(QStringLiteral("�����")));
			this->examModel->setItem(i, 3, new QStandardItem(score));
			this->examModel->setItem(i, 4, new QStandardItem(choiceScore));
			this->examModel->setItem(i, 5, new QStandardItem(multiScore));
			this->examModel->setItem(i, 6, new QStandardItem(judgeScore));
		}
		else {
			this->examModel->setItem(i, 2, new QStandardItem(QStringLiteral("�ɲμ�")));
			this->examModel->setItem(i, 3, new QStandardItem(QStringLiteral("����")));
			this->examModel->setItem(i, 4, new QStandardItem(QStringLiteral("����")));
			this->examModel->setItem(i, 5, new QStandardItem(QStringLiteral("����")));
			this->examModel->setItem(i, 6, new QStandardItem(QStringLiteral("����")));
		}
		for (int j = 0; j <= 6; j++)
		{
			this->examModel->item(i, j)->setTextAlignment(Qt::AlignCenter);
		}
	}
}

/**
  * @author:������
  * @brief:ˢ�¿��Ե�����
  * @date:2018/12/17
  * @version:1.0
  */
void StudentWindow::dataGet() {
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
  * @param [in] �������: ��ǰ��¼���û���
  * @date:2018/12/18
  * @version:1.0
  */
void StudentWindow::showStudent(QString username) {
	SqlModel sql;
	Student student = sql.searchStudentInfo(username);
	this->ui.Name->setText(student.getName());
	this->ui.Major->setText(student.getMajor());
	this->ui.Id->setText(student.getId());
}

/**
  * @author:������
  * @brief:�����û��ڵ�¼����������û������ں�������Ϣɸѡ
  * @param [in] �������: ��ǰ��¼���û���
  * @date:2018/12/17
  * @version:1.0
  */
void StudentWindow::receiveUserName(QString name) {
	userName = name;
	StudentWindow::showExam();
	StudentWindow::showStudent(userName);
}

/**
  * @author:Ӧ�о�
  * @brief:�޸��û���Ϣ
  * @date:2019/1/9
  * @version:1.0
  */
void StudentWindow::updateBtnClicked() {
	SqlModel sql;
	Student student = sql.searchStudentInfo(this->userName);
	if (studentAdd == NULL) {
		studentAdd = new AddStudent();
		studentAdd->setWindowTitle(QStringLiteral("�޸���Ϣ"));
		studentAdd->ui.username->setReadOnly(true);
		disconnect(studentAdd->ui.submitBtn , SIGNAL(clicked(bool)) , studentAdd , SLOT(regist()));
		connect(studentAdd->ui.submitBtn , SIGNAL(clicked(bool)) , studentAdd , SLOT(update()));
		connect(studentAdd , SIGNAL(userUpdateOk()) , this , SLOT(dataRefresh()));
		studentAdd->ui.username->setText(student.getUsername());
		studentAdd->ui.password->setText(student.getPassword());
		studentAdd->ui.name->setText(student.getName());
		studentAdd->ui.studentId->setText(student.getId());
		studentAdd->ui.major->setText(student.getMajor());
		studentAdd->ui.phonenumber->setText(student.getPhonenumber());
		studentAdd->ui.male->setChecked(student.getSex());
		studentAdd->ui.female->setChecked(!student.getSex());
		studentAdd->ui.checkBtn->hide();
		studentAdd->exec();
	}
	if (studentAdd) {
		delete studentAdd;
		studentAdd = NULL;
	}
	return;
}

/**
  * @author:Ӧ�о�
  * @brief:���յ���������źź�ɾ������ҳ�沢��ҳ��ˢ��
  * @date:2019/1/3
  * @version:1.0
  */
void StudentWindow::receiveExamFinish() {
	delete newExam;
	StudentWindow::dataRefresh();
	this->show();
}
