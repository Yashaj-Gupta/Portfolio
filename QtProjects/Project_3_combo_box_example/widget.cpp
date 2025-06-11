#include "widget.h"
#include "./ui_widget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(500,100);
    QHBoxLayout * Lay1 = new QHBoxLayout ();
    QLabel *label1 =  new QLabel;
    label1->setText("Select type of account");
    label1->setFont(QFont("Times",16));

    combo = new QComboBox();
    combo->setFont(QFont("Times",16));
    combo->addItem("Current Account");
    combo->addItem("Saving Account");
    combo->addItem("Deposite Account");

    Lay1->addWidget(label1);
    Lay1->addWidget(combo);

    labelresult = new QLabel;
    labelresult->setText("Hello");
    labelresult->setFont(QFont("Times",16));

    connect(combo,SIGNAL(currentTextChanged(QString)),this,SLOT(comboChanged()));

    QVBoxLayout * Lay2 = new QVBoxLayout (this);
    Lay2->addWidget(labelresult);
    Lay2->addLayout(Lay1);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::comboChanged()
{
    QString item = combo->currentText();
    labelresult->setText("Your account type is : " + item );
}
