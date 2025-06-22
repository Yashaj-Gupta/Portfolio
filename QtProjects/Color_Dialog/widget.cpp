#include "widget.h"
#include "./ui_widget.h"
#include <QVBoxLayout>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QVBoxLayout *Lay = new QVBoxLayout(this);

    Text = new QTextEdit();
    QPushButton *btn = new QPushButton();
    btn->setText("change colour");
    btn->setFont(QFont("Times",16));
    connect(btn,SIGNAL(clicked()),this,SLOT(changeColor()));
    Lay->addWidget(Text);
    Lay->addWidget(btn);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeColor()
{
    dia = new QColorDialog();
    QColor color = dia->getColor();
    Text->setTextColor(color);
}
