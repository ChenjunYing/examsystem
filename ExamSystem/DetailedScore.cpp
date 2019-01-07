#include "DetailedScore.h"
#include "ScoreModel.h"

DetailedScore::DetailedScore(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //������С����ť�͹رհ�ť
	this->detailModel = new QStandardItemModel; //����С��ֱ��
}

DetailedScore::~DetailedScore()
{
}

/**
  * @author:������
  * @brief:��ʾ����ѯѧ����С�����Ϣ
  * @date:2019/1/1
  * @version:1.0
  */
void DetailedScore::showDetails() {
	this->detailModel->clear();
	DetailedScore::setDetailsTableHeader();
	this->ui.detailsTable->setModel(detailModel);
	this->ui.detailsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.detailsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	DetailedScore::dataGet();
	DetailedScore::setDetailModelItemView();
}

/**
  * @author:������
  * @brief:����ѧ��С��ֱ��ı�ͷ
  * @date:2019/1/1
  * @version:1.0
  */
void DetailedScore::setDetailsTableHeader() {
	detailModel->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("������")));
	detailModel->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("��ȷ��")));
	detailModel->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("�÷�")));
}

/**
  * @author:������
  * @brief:��Ⱦѧ��С��ֱ��
  * @date:2019/1/1
  * @version:1.0
  */
void DetailedScore::setDetailModelItemView() {
	for (int i = 0; i < details.size(); i++)
	{
		detailModel->setItem(i, 0, new QStandardItem(details.at(i).getStudentAnswer()));
		detailModel->setItem(i, 1, new QStandardItem(details.at(i).getAnswer()));
		QString score = QString::number(details.at(i).getScore());
		detailModel->setItem(i, 2, new QStandardItem(score));
		detailModel->item(i, 0)->setTextAlignment(Qt::AlignCenter); //���þ���
		detailModel->item(i, 1)->setTextAlignment(Qt::AlignCenter);
		detailModel->item(i, 2)->setTextAlignment(Qt::AlignCenter);
	}
}

/**
  * @author:������
  * @brief:��ȡѧ��С��ֵ���Ϣ
  * @date:2019/1/1
  * @version:1.0
  */
void DetailedScore::dataGet() {
	ScoreModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("��ʾ"), QStringLiteral("����ʧ��"), QMessageBox::Yes);
		this->close();
	}
	else {
		this->details = sql.searchDetails(this->code, this->userName);
	}
}

/**
  * @author:������
  * @brief:����ѧ���ɼ����ڴ��ݵ��û�������
  * @date:2019/1/1
  * @version:1.0
  */
void DetailedScore::receiveName(QString name) {
	userName = name;
	DetailedScore::showDetails();
}
