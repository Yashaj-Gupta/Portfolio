#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(300 ,110);

    Table = new QTableWidget(this);
    Table->setStyleSheet("backgrount-color:green");

    Table->setRowCount(3);
    Table->setColumnCount(3);

    QTableWidgetItem *name = new QTableWidgetItem("Name");
    QTableWidgetItem *email = new QTableWidgetItem("Email");
    Table->setItem(0,0,name);
    Table->setItem(0,1,email);
}

Widget::~Widget()
{
    delete ui;
}
