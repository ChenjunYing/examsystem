#include "AddJudge.h"

AddJudge::AddJudge(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //������С��󻯰�ť�͹رհ�ť
}

AddJudge::~AddJudge() {

}
