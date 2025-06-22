#include "widget.h"
#include "./ui_widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout *Lay = new QHBoxLayout(this);
    QPushButton *warn = new QPushButton();
    warn->setText("warning!!");
    connect(warn,SIGNAL(clicked()),this,SLOT(warning()));

    QPushButton *info = new QPushButton();
    info->setText("Information");
    connect(info,SIGNAL(clicked()),this , SLOT(setInfo()));

    QPushButton *about = new QPushButton();
    about->setText("About");
    connect(about,SIGNAL(clicked()),this,SLOT(About()));

    Lay->addWidget(warn);
    Lay->addWidget(info);
    Lay->addWidget(about);

}

Widget::~Widget()
{
    delete ui;


}

void Widget::setInfo()
{

    QMessageBox::information(this,"Info","this is Info");
}

void Widget::warning()
{
    QMessageBox::warning(this,"Warning","this is warning");
}

void Widget::About()
{
    QMessageBox::about(this,"ABOUT","this is about");
}
