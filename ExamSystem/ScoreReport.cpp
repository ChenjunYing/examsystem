#include "ScoreReport.h"
#include "ScoreModel.h"

ScoreReport::ScoreReport(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->scoreModel = new QStandardItemModel;
}

ScoreReport::~ScoreReport()
{
	delete scoreModel;
}

void ScoreReport::showScore()
{
	this->scoreModel->clear();
	ScoreReport::setScoreTableHeader(this->scoreModel);
	this->ui.scoreTable->setModel(scoreModel);
	this->ui.scoreTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.scoreTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ScoreReport::scoreGet();
	ScoreReport::setScoreModelItemView(this->scoreModel, score);
}

void ScoreReport::scoreGet()
{
	ScoreModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("提示"), QStringLiteral("连接失败"), QMessageBox::Yes);
		this->close();
	}
	else {
		this->score = sql.searchScore(this->code);
	}
}

void ScoreReport::setScoreTableHeader(QStandardItemModel * model)
{
	model->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("考生用户名")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("单选得分")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("多选得分")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("判断得分")));
}

void ScoreReport::setScoreModelItemView(QStandardItemModel * model, QList<Score>& score)
{
	for (int i = 0; i < score.size(); i++)
	{
		model->setItem(i, 0, new QStandardItem(score.at(i).getStudentName()));
		if (score.at(i).getIsSubmit()) {
			QString choiceScore = QString::number(score.at(i).getChoiceScore());
			QString multiScore = QString::number(score.at(i).getMultiScore());
			QString judgeScore = QString::number(score.at(i).getJudgeScore());
			model->setItem(i, 1, new QStandardItem(choiceScore));
			model->setItem(i, 2, new QStandardItem(multiScore));
			model->setItem(i, 3, new QStandardItem(judgeScore));
		}
		else {
			model->setItem(i, 1, new QStandardItem(QStringLiteral("暂无")));
			model->setItem(i, 2, new QStandardItem(QStringLiteral("暂无")));
			model->setItem(i, 3, new QStandardItem(QStringLiteral("暂无")));
		}
		scoreModel->item(i, 0)->setTextAlignment(Qt::AlignCenter); //设置居中
		scoreModel->item(i, 1)->setTextAlignment(Qt::AlignCenter);
		scoreModel->item(i, 2)->setTextAlignment(Qt::AlignCenter);
		scoreModel->item(i, 3)->setTextAlignment(Qt::AlignCenter);
	}
}

void ScoreReport::receiveCode(int code)
{
	this->code = code;
	ScoreReport::showScore();
}