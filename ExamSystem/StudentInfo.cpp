#include "StudentInfo.h"


StudentInfo::StudentInfo(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //设置最小最大化按钮和关闭按钮
	this->table = new QStandardItemModel;
	StudentInfo::refreshData();
	StudentInfo::showStudentTable();
	connect(this->ui.stuTable , SIGNAL(clicked(const QModelIndex&)) , this , SLOT(tableClicked(const QModelIndex&)));
}

/**
  * @author:应承峻
  * @brief:从数据库拉取学生信息
  * @date:2019/1/8
  * @version:1.0
  */
void StudentInfo::refreshData() {
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("提示") , QStringLiteral("连接失败") , QMessageBox::Yes);
		return;
	}
	this->student = sql.searchStudent();
}

/**
  * @author:夏林轩
  * @brief:删除学生信息
  * @date:2019/1/8
  * @version:1.0
  */
void StudentInfo::tableClicked(const QModelIndex & index) {
	if (index.isValid() && index.column() == 8) {
		int ret = QMessageBox::warning(this , QStringLiteral("提示") , QStringLiteral("确定删除该考生信息吗！") , QMessageBox::Yes | QMessageBox::Cancel);
		if (ret == QMessageBox::Yes) {
			SqlModel sql;
			QString username = student.at(index.row()).getUsername();
			if (sql.isOpen() && sql.deleteStudent(username)) {
				QMessageBox::information(this , QStringLiteral("提示") , QStringLiteral("删除成功！") , QMessageBox::Ok);
				StudentInfo::refreshData();//刷新页面
				StudentInfo::showStudentTable();
			} else {
				QMessageBox::information(this , QStringLiteral("提示") , QStringLiteral("删除失败！") , QMessageBox::Ok);
			}
		}
	}
}


/**
  * @author:应承峻
  * @brief:设置考生信息表格的表头
  * @date:2019/1/8
  * @version:1.0
  */
void StudentInfo::setTableHeader(QStandardItemModel* model) {
	model->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("用户名")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("用户密码")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("真实姓名")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("性别")));
	model->setHorizontalHeaderItem(4, new QStandardItem(QStringLiteral("学号")));
	model->setHorizontalHeaderItem(5, new QStandardItem(QStringLiteral("主修专业")));
	model->setHorizontalHeaderItem(6 , new QStandardItem(QStringLiteral("电话号码")));
	model->setHorizontalHeaderItem(7 , new QStandardItem(QStringLiteral("修改信息")));
	model->setHorizontalHeaderItem(8 , new QStandardItem(QStringLiteral("删除用户")));
}

/**
  * @author:应承峻
  * @brief:将学生信息渲染到表格中
  * @date:2019/1/8
  * @version:1.0
  */
void StudentInfo::setStudentTableItemView(QStandardItemModel* model) {
	for (int i = 0; i < student.size(); i++) {
		QString sex;
		if (student.at(i).getSex() == 1) sex = QStringLiteral("男"); else sex = QStringLiteral("女");
		model->setItem(i, 0, new QStandardItem(student.at(i).getUsername()));
		model->setItem(i, 1, new QStandardItem(student.at(i).getPassword()));
		model->setItem(i, 2, new QStandardItem(student.at(i).getName()));
		model->setItem(i, 3 , new QStandardItem(sex));
		model->setItem(i, 4 , new QStandardItem(student.at(i).getId()));
		model->setItem(i, 5 , new QStandardItem(student.at(i).getMajor()));
		model->setItem(i, 6 , new QStandardItem(student.at(i).getPhonenumber()));
		model->setItem(i, 7, new QStandardItem(QStringLiteral("查看")));
		model->setItem(i, 8, new QStandardItem(QStringLiteral("删除")));
		model->item(i, 0)->setTextAlignment(Qt::AlignCenter); //设置居中
		model->item(i, 1)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 2)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 3)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 4)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 5)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 6)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 7)->setTextAlignment(Qt::AlignCenter);
		model->item(i, 8)->setTextAlignment(Qt::AlignCenter);
	}
}

/**
  * @author:应承峻
  * @brief:显示学生信息
  * @date:2019/1/8
  * @version:1.0
  */
void StudentInfo::showStudentTable() {
	this->table->clear();
	StudentInfo::setTableHeader(this->table); //初始化表头
	this->ui.stuTable->setModel(this->table);
	this->ui.stuTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.stuTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //设置等列宽且不可拖动
	StudentInfo::setStudentTableItemView(this->table);
}

StudentInfo::~StudentInfo(){
	delete table;
}
