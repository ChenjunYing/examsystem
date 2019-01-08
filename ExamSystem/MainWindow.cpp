#include "MainWindow.h"

/* MainWindow��Ӧ���߱����¹���
 * (1)��ʾ����Ա����Ϣ
 * (2)��ʾ��ǰ�������е��Ծ�,ͬʱ���Խ����޸ġ�ɾ���Ȳ���
 * (3)���н�����⡢�������(��ѡ����ѡ���ж�)�������Ծ��鿴�������ݵĽӿ�
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //������С��󻯰�ť�͹رհ�ť
	this->choice = new AddChoice;
	this->multichoice = new AddMultiChoice;
	this->judge = new AddJudge;
	this->scoreReport = new ScoreReport;
	this->exammodel = new QStandardItemModel;
	MainWindow::dataRefresh();
	MainWindow::showExamTable();
	connect(this->ui.choice, SIGNAL(triggered()), this, SLOT(choiceTriggered()));
	connect(this->ui.judge, SIGNAL(triggered()), this, SLOT(judgeTriggered()));
	connect(this->ui.multichoice, SIGNAL(triggered()), this, SLOT(multichoiceTriggered()));
	connect(this->ui.goQuestionBank, SIGNAL(triggered()), this, SLOT(goQuestionBankTriggered()));
	connect(this->ui.createExam, SIGNAL(triggered()), this, SLOT(createExamTriggered()));
	connect(this->ui.createExam , SIGNAL(triggered()) , this , SLOT(createExamTriggered()));
	connect(this->ui.user , SIGNAL(triggered()) , this , SLOT(userTriggered()));
	connect(this, SIGNAL(sendExamCode(int)), this->scoreReport, SLOT(receiveCode(int)));
	connect(this->ui.examTable, SIGNAL(clicked(const QModelIndex&)), this, SLOT(examClicked(const QModelIndex&)));
	connect(this->ui.examTable, SIGNAL(clicked(const QModelIndex&)), this, SLOT(deleteClicked(const QModelIndex&)));
}

/**
  * @author:Ӧ�о�
  * @brief:ˢ�¿�����Ϣ
  * @date:2018/12/23
  * @version:1.0
  */
void MainWindow::dataRefresh() {
	AdminModel admin;
	if (!admin.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("��ʾ"), QStringLiteral("����ʧ��"), QMessageBox::Yes);
	}
	else {
		this->exam = admin.searchExam();
	}
}
/**
  * @author:������
  * @brief:�鿴�μ�һ�����ԵĿ����ɼ��Ĵ����ź�
  * @date:2019/1/1
  * @version:1.0
  */
void MainWindow::examClicked(const QModelIndex& index) {
	if (index.isValid() && index.column() == 3) {
		emit sendExamCode(this->exam.at(index.row()).getExamCode());
		this->scoreReport->exec();
	}
}

/**
  * @author:������
  * @brief:ɾ��һ�����Լ������������Ϣ�Ľӿ�
  * @date:2019/1/1
  * @version:1.0
  */
void MainWindow::deleteClicked(const QModelIndex & index) {
	AdminModel admin;
	if (index.isValid() && index.column() == 5) {
		int ret = QMessageBox::warning(this, QStringLiteral("��ʾ"), QStringLiteral("ȷ��ɾ���ⳡ�����𣿽�ɾ�������Ϣ��ɾ�����޷��ָ���"), QMessageBox::Yes | QMessageBox::Cancel);
		if (ret == QMessageBox::Yes) {
			int code = exam.at(index.row()).getExamCode();
			if (admin.isOpen() && admin.deleteExam(code)) {
				QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("ɾ���ɹ���"), QMessageBox::Ok);
				MainWindow::dataRefresh();//ˢ��ҳ��
				MainWindow::showExamTable();
			}
			else {
				QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("ɾ��ʧ�ܣ�"), QMessageBox::Ok);
			}
		}
	}
}

void MainWindow::refreshAfterCreat() {
	MainWindow::dataRefresh();
	MainWindow::showExamTable();
}


/**
  * @author:Ӧ�о�
  * @brief:�ڹ���Ա��������ʾ������Ϣ
  * @date:2018/12/23
  * @version:1.0
  */
void MainWindow::showExamTable() {
	this->exammodel->clear();
	MainWindow::setTableHeader(this->exammodel); //��ʼ����ͷ
	this->ui.examTable->setModel(this->exammodel);
	this->ui.examTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.examTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //���õ��п��Ҳ����϶�
	MainWindow::setExamTableItemView(this->exammodel);
}


/**
  * @author:Ӧ�о�
  * @brief:���ÿ�����Ϣ���ı�ͷ
  * @date:2018/12/23
  * @version:1.0
  */
void MainWindow::setTableHeader(QStandardItemModel* model) {
	model->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("��������")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("����ʱ��")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("������Ϣ")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("��ѯ�ɼ�")));
	model->setHorizontalHeaderItem(4, new QStandardItem(QStringLiteral("�༭����")));
	model->setHorizontalHeaderItem(5, new QStandardItem(QStringLiteral("ɾ������")));
}


/**
  * @author:Ӧ�о�
  * @brief:��Ⱦ������Ϣ
  * @date:2018/12/23
  * @version:1.0
  */
void MainWindow::setExamTableItemView(QStandardItemModel* model) {
	for (int i = 0; i < exam.size(); i++) {
		QString duration = QString::number(exam.at(i).getDuration());
		model->setItem(i, 0, new QStandardItem(exam.at(i).getExamName()));
		model->setItem(i, 1, new QStandardItem(QString::number(exam.at(i).getDuration()) + QStringLiteral("����")));
		model->setItem(i, 2, new QStandardItem(exam.at(i).getInformation()));
		model->setItem(i, 3, new QStandardItem(QStringLiteral("��ѯ")));
		model->setItem(i, 4, new QStandardItem(QStringLiteral("�鿴")));
		model->setItem(i, 5, new QStandardItem(QStringLiteral("ɾ��")));
		model->item(i, 0)->setTextAlignment(Qt::AlignCenter); //���þ���
		model->item(i, 1)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 2)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 3)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 4)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 5)->setTextAlignment(Qt::AlignCenter);
	}
}

/*��ӵ�ѡ��ӿ�*/
void MainWindow::choiceTriggered() {
	choice->resetData();
	choice->exec();  //������ӵ�ѡ��ģ̬�򣬴�ʱ�û����ܶ���������в���
}

/*��Ӷ�ѡ��ӿ�*/
void MainWindow::multichoiceTriggered() {
	multichoice->resetData();
	multichoice->exec();  //������Ӷ�ѡ��ģ̬�򣬴�ʱ�û����ܶ���������в���
}

/*����ж���ӿ�*/
void MainWindow::judgeTriggered() {
	judge->resetData();
	judge->exec();  //��������ж���ģ̬�򣬴�ʱ�û����ܶ���������в���
}

/*��������ӿ�*/
void MainWindow::userTriggered() {
	if (info != NULL) {
		delete info;
		info = NULL;
	}
	info = new StudentInfo;
	info->exec();
}

/*�������Խӿ�*/
void MainWindow::createExamTriggered() {
	if (newexam) {
		delete newexam;
		newexam = NULL;
	}
	newexam = new AddExam;
	qDebug() << connect(this->newexam, SIGNAL(creatFinished()), this, SLOT(refreshAfterCreat()));
	newexam->show();
}

/*���ӿ�*/
void MainWindow::goQuestionBankTriggered() {
	questionbank = new QuestionBank;
	connect(questionbank, SIGNAL(sendChoiceData(Choice)), choice, SLOT(receiveData(Choice)));  //�����޸ĵ�ѡ��ҳ�洫������
	connect(questionbank, SIGNAL(sendMultiChoiceData(Choice)), multichoice, SLOT(receiveData(Choice)));  //�����޸Ķ�ѡ��ҳ�洫������
	connect(questionbank, SIGNAL(sendJudgeData(Judge)), judge, SLOT(receiveData(Judge)));  //�����޸��ж���ҳ�洫������
	connect(choice, SIGNAL(sendChoicePage(AddChoice*)), this, SLOT(receiveAddChoicePage(AddChoice*)));
	connect(multichoice, SIGNAL(sendMultiChoicePage(AddMultiChoice*)), this, SLOT(receiveAddMultiChoicePage(AddMultiChoice*)));
	connect(judge, SIGNAL(sendJudgePage(AddJudge*)), this, SLOT(receiveAddJudgePage(AddJudge*)));
	questionbank->exec(); //�����鿴���ģ̬�򣬴�ʱ�û����ܶ���������в���
	if (questionbank) delete questionbank;
}

/**
  * @author:Ӧ�о�
  * @brief:����AddChoiceҳ�淢�͵��½��޸�ҳ��ĵ�ַ�������źŲ۰�
  * @date:2018/12/17
  * @version:1.0
  * @note:������޸����ˢ���¼���
  */
void MainWindow::receiveAddChoicePage(AddChoice* a) {
	connect(a, SIGNAL(updateOK(int)), questionbank, SLOT(receiveOK(int)));
}

/**
  * @author:��˼Ӿ
  * @brief:����AddMultiChoiceҳ�淢�͵��½��޸�ҳ��ĵ�ַ�������źŲ۰�
  * @date:2018/12/18
  * @version:1.0
  * @note:������޸����ˢ���¼���
  */
void MainWindow::receiveAddMultiChoicePage(AddMultiChoice* a) {
	connect(a, SIGNAL(updateOK(int)), questionbank, SLOT(receiveOK(int)));
}

/**
  * @author:��˼Ӿ
  * @brief:����AddJudgeҳ�淢�͵��½��޸�ҳ��ĵ�ַ�������źŲ۰�
  * @date:2018/12/19
  * @version:1.0
  * @note:������޸����ˢ���¼���
  */
void MainWindow::receiveAddJudgePage(AddJudge* a) {
	connect(a, SIGNAL(updateOK(int)), questionbank, SLOT(receiveOK(int)));
}

/*
 * @note:�޸���questionbankΪ��ʱɾ�����ֵ�bug
 */
MainWindow::~MainWindow() {
	delete choice;
	delete multichoice;
	delete judge;
	delete exammodel;
	delete scoreReport;
	delete info;
	delete newexam;
}