#include "widget.h"
#include "./ui_widget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFontDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QVBoxLayout *Lay = new QVBoxLayout(this);
    QPushButton *btn = new QPushButton();
    btn->setText("Change Font");
    Text = new QTextEdit();
    Lay->addWidget(Text);
    Lay->addWidget(btn);

    connect(btn,SIGNAL(clicked()),this,SLOT(changeFont()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeFont()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok,this);
    if(ok)
    {
        Text->setFont(f);
    }
}
