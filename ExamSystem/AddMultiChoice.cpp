#include "AddMultiChoice.h"

AddMultiChoice::AddMultiChoice(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置最小最大化按钮和关闭按钮
}



AddMultiChoice::~AddMultiChoice() {

}
