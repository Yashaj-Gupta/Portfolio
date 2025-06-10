#include "widget.h"
#include "./ui_widget.h"
#include <QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout *lay1 = new QHBoxLayout(this);
    lcd = new QLCDNumber;
    lay1->addWidget(lcd);
    QTimer *timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showTime()
{
    QTime t =  QTime::currentTime();
    QString text = t.toString("hh:mm");
    if((t.second() %2) == 0)
    {
        text[2] = ' ';
    }
    lcd->display(text);
}
