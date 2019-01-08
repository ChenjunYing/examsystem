#include "StudentInfo.h"


StudentInfo::StudentInfo(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint); //������С��󻯰�ť�͹رհ�ť
	this->table = new QStandardItemModel;
	StudentInfo::refreshData();
	StudentInfo::showStudentTable();
	connect(this->ui.stuTable , SIGNAL(clicked(const QModelIndex&)) , this , SLOT(tableClicked(const QModelIndex&)));
}

/**
  * @author:Ӧ�о�
  * @brief:�����ݿ���ȡѧ����Ϣ
  * @date:2019/1/8
  * @version:1.0
  */
void StudentInfo::refreshData() {
	SqlModel sql;
	if (!sql.isOpen()) {
		QMessageBox::critical(NULL , QStringLiteral("��ʾ") , QStringLiteral("����ʧ��") , QMessageBox::Yes);
		return;
	}
	this->student = sql.searchStudent();
}

/**
  * @author:������
  * @brief:ɾ��ѧ����Ϣ
  * @date:2019/1/8
  * @version:1.0
  */
void StudentInfo::tableClicked(const QModelIndex & index) {
	if (index.isValid() && index.column() == 8) {
		int ret = QMessageBox::warning(this , QStringLiteral("��ʾ") , QStringLiteral("ȷ��ɾ���ÿ�����Ϣ��") , QMessageBox::Yes | QMessageBox::Cancel);
		if (ret == QMessageBox::Yes) {
			SqlModel sql;
			QString username = student.at(index.row()).getUsername();
			if (sql.isOpen() && sql.deleteStudent(username)) {
				QMessageBox::information(this , QStringLiteral("��ʾ") , QStringLiteral("ɾ���ɹ���") , QMessageBox::Ok);
				StudentInfo::refreshData();//ˢ��ҳ��
				StudentInfo::showStudentTable();
			} else {
				QMessageBox::information(this , QStringLiteral("��ʾ") , QStringLiteral("ɾ��ʧ�ܣ�") , QMessageBox::Ok);
			}
		}
	}
}


/**
  * @author:Ӧ�о�
  * @brief:���ÿ�����Ϣ���ı�ͷ
  * @date:2019/1/8
  * @version:1.0
  */
void StudentInfo::setTableHeader(QStandardItemModel* model) {
	model->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("�û���")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("�û�����")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("��ʵ����")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("�Ա�")));
	model->setHorizontalHeaderItem(4, new QStandardItem(QStringLiteral("ѧ��")));
	model->setHorizontalHeaderItem(5, new QStandardItem(QStringLiteral("����רҵ")));
	model->setHorizontalHeaderItem(6 , new QStandardItem(QStringLiteral("�绰����")));
	model->setHorizontalHeaderItem(7 , new QStandardItem(QStringLiteral("�޸���Ϣ")));
	model->setHorizontalHeaderItem(8 , new QStandardItem(QStringLiteral("ɾ���û�")));
}

/**
  * @author:Ӧ�о�
  * @brief:��ѧ����Ϣ��Ⱦ�������
  * @date:2019/1/8
  * @version:1.0
  */
void StudentInfo::setStudentTableItemView(QStandardItemModel* model) {
	for (int i = 0; i < student.size(); i++) {
		QString sex;
		if (student.at(i).getSex() == 1) sex = QStringLiteral("��"); else sex = QStringLiteral("Ů");
		model->setItem(i, 0, new QStandardItem(student.at(i).getUsername()));
		model->setItem(i, 1, new QStandardItem(student.at(i).getPassword()));
		model->setItem(i, 2, new QStandardItem(student.at(i).getName()));
		model->setItem(i, 3 , new QStandardItem(sex));
		model->setItem(i, 4 , new QStandardItem(student.at(i).getId()));
		model->setItem(i, 5 , new QStandardItem(student.at(i).getMajor()));
		model->setItem(i, 6 , new QStandardItem(student.at(i).getPhonenumber()));
		model->setItem(i, 7, new QStandardItem(QStringLiteral("�鿴")));
		model->setItem(i, 8, new QStandardItem(QStringLiteral("ɾ��")));
		model->item(i, 0)->setTextAlignment(Qt::AlignCenter); //���þ���
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
  * @author:Ӧ�о�
  * @brief:��ʾѧ����Ϣ
  * @date:2019/1/8
  * @version:1.0
  */
void StudentInfo::showStudentTable() {
	this->table->clear();
	StudentInfo::setTableHeader(this->table); //��ʼ����ͷ
	this->ui.stuTable->setModel(this->table);
	this->ui.stuTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->ui.stuTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //���õ��п��Ҳ����϶�
	StudentInfo::setStudentTableItemView(this->table);
}

StudentInfo::~StudentInfo(){
	delete table;
}
