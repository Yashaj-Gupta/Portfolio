#include "widget.h"
#include "./ui_widget.h"
#include <QVBoxLayout>
#include  <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout *VBox =  new QVBoxLayout(this);
    lcd = new QLCDNumber();
    lcd->setStyleSheet("background-color:yellow");

    QPushButton *btn = new QPushButton();
    btn->setText("Random Generator");
    btn->setFont(QFont("Times",15));
    btn->setStyleSheet("background-color:green");

    connect(btn,SIGNAL(clicked()),this,SLOT(randGenerator()));

    VBox->addWidget(lcd);
    VBox->addWidget(btn);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::randGenerator()
{
    int randnumber = rand();
    lcd->display(randnumber);
}
