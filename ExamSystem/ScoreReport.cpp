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
}

void ScoreReport::showScore()
{
}

void ScoreReport::receiveCode(int code)
{
	this->code = code;
}