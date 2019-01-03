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
	ScoreReport::setScoreTableHeader();
	this->ui.scoreTable->setModel(scoreModel);
	this->ui.scoreTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.scoreTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ScoreReport::scoreGet();
	ScoreReport::setScoreModelItemView();
}

void ScoreReport::scoreGet()
{
	ScoreModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL, QStringLiteral("��ʾ"), QStringLiteral("����ʧ��"), QMessageBox::Yes);
		this->close();
	}
	else {
		this->score = sql.searchScore(this->code);
	}
}

void ScoreReport::setScoreTableHeader()
{
	scoreModel->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("��������")));
	scoreModel->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("�ܷ�")));
	scoreModel->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("��ѡ�÷�")));
	scoreModel->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("��ѡ�÷�")));
	scoreModel->setHorizontalHeaderItem(4, new QStandardItem(QStringLiteral("�жϵ÷�")));
}

void ScoreReport::setScoreModelItemView()
{
	for (int i = 0; i < score.size(); i++)
	{
		scoreModel->setItem(i, 0, new QStandardItem(score.at(i).getStudentName()));
		if (score.at(i).getIsSubmit()) {
			QString score = QString::number(this->score.at(i).getScore());
			QString choiceScore = QString::number(this->score.at(i).getChoiceScore());
			QString multiScore = QString::number(this->score.at(i).getMultiScore());
			QString judgeScore = QString::number(this->score.at(i).getJudgeScore());
			scoreModel->setItem(i, 1, new QStandardItem(score));
			scoreModel->setItem(i, 2, new QStandardItem(choiceScore));
			scoreModel->setItem(i, 3, new QStandardItem(multiScore));
			scoreModel->setItem(i, 4, new QStandardItem(judgeScore));
		}
		else {
			scoreModel->setItem(i, 1, new QStandardItem(QStringLiteral("����")));
			scoreModel->setItem(i, 2, new QStandardItem(QStringLiteral("����")));
			scoreModel->setItem(i, 3, new QStandardItem(QStringLiteral("����")));
			scoreModel->setItem(i, 4, new QStandardItem(QStringLiteral("����")));
		}
		scoreModel->item(i, 0)->setTextAlignment(Qt::AlignCenter); //���þ���
		scoreModel->item(i, 1)->setTextAlignment(Qt::AlignCenter);
		scoreModel->item(i, 2)->setTextAlignment(Qt::AlignCenter);
		scoreModel->item(i, 3)->setTextAlignment(Qt::AlignCenter);
		scoreModel->item(i, 4)->setTextAlignment(Qt::AlignCenter);
	}
}

void ScoreReport::receiveCode(int code)
{
	this->code = code;
	ScoreReport::showScore();
}