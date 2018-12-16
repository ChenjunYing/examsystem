#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QDebug>
#include <QAction>
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "AddChoice.h"
#include "AddMultiChoice.h"
#include "AddJudge.h"
#include "QuestionBank.h"

class MainWindow : public QMainWindow {

	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private slots:
	void choiceTriggered();
	void judgeTriggered();
	void multichoiceTriggered();
	void goQuestionBankTriggered();

private:
	Ui::MainWindowClass ui;
	AddChoice* choice;
	AddMultiChoice* multichoice;
	AddJudge* judge;
	QuestionBank* questionbank;
};

#endif