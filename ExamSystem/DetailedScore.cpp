#include "DetailedScore.h"
#include "ScoreModel.h"

DetailedScore::DetailedScore(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //设置最小化按钮和关闭按钮
	this->detailModel = new QStandardItemModel; //创建小题分表格
}

DetailedScore::~DetailedScore()
{
}

/**
  * @author:夏林轩
  * @brief:显示被查询学生的小题分信息
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
  * @author:夏林轩
  * @brief:设置学生小题分表格的表头
  * @date:2019/1/1
  * @version:1.0
  */
void DetailedScore::setDetailsTableHeader() {
	detailModel->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("考生答案")));
	detailModel->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("正确答案")));
	detailModel->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("得分")));
}

/**
  * @author:夏林轩
  * @brief:渲染学生小题分表格
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
		detailModel->item(i, 0)->setTextAlignment(Qt::AlignCenter); //设置居中
		detailModel->item(i, 1)->setTextAlignment(Qt::AlignCenter);
		detailModel->item(i, 2)->setTextAlignment(Qt::AlignCenter);
	}
}

/**
  * @author:夏林轩
  * @brief:获取学生小题分的信息
  * @date:2019/1/1
  * @version:1.0
  */
void DetailedScore::dataGet() {
	ScoreModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("提示"), QStringLiteral("连接失败"), QMessageBox::Yes);
		this->close();
	}
	else {
		this->details = sql.searchDetails(this->code, this->userName);
	}
}

/**
  * @author:夏林轩
  * @brief:接收学生成绩窗口传递的用户名参数
  * @date:2019/1/1
  * @version:1.0
  */
void DetailedScore::receiveName(QString name) {
	userName = name;
	DetailedScore::showDetails();
}
