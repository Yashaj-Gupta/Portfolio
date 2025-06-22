#include "widget.h"
#include "./ui_widget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout *Lay = new QHBoxLayout(this);
    QLabel *label = new QLabel();
    label->setText("Choose Language");
    label->setFont(QFont("Times",16));
    Line = new QLineEdit();
    Line->setFont(QFont("Times",16));
    QPushButton *btn = new QPushButton();
    btn->setText("Choose Language");
    Lay->addWidget(label);
    Lay->addWidget(Line);
    Lay->addWidget(btn);

    //connect(btn,SIGNAL(clicked()),this,SLOT(getMyText()));
    connect(btn,SIGNAL(clicked()),this,SLOT(getMyItem()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::getMyText()
{
    QString text = QInputDialog::getText(this,"Get Username","Enter Your Name :");
    if(!text.isEmpty())
    {
        Line->setText(text);
    }
}

void Widget::getMyItem()
{
    QList<QString> language = {"c++","java","python","c#"};
    QString text = QInputDialog::getItem(this,"InputLanguage","Langauge :",language);
    if(!text.isEmpty())
    {
        Line->setText(text);
    }
}
