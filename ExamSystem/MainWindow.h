#pragma once

#include <QtWidgets/QMainWindow>
#include <QAction>
#include <QDebug>
#include "ui_MainWindow.h"
#include "QuestionBank.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private slots:
	void choiceTriggered();
	void judgeTriggered();
	void multichoiceTriggered();
	void goQuestionBankTriggered();

private:
	Ui::MainWindowClass ui;
};
