#include "widget.h"
#include "./ui_widget.h"
#include <QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QVBoxLayout *lay =  new QVBoxLayout(this);
    calendar = new QCalendarWidget();
    calendar->setGridVisible(true);
    lay->addWidget(calendar);
    connect(calendar,SIGNAL(selectionChanged()),this,SLOT(selectDate()));

    Label = new QLabel("Hello");
    Label->setFont(QFont("Times",20));
    Label->setStyleSheet("color:red");
    lay->addWidget(Label);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::selectDate()
{
    QString dateSelected = calendar->selectedDate().toString();
    Label->setText(dateSelected);
}
