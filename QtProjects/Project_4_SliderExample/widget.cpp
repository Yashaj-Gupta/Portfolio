#include "widget.h"
#include "./ui_widget.h"
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout * Lay1 = new QHBoxLayout(this);

    Slide = new QSlider;

    Slide->setOrientation(Qt::Horizontal);
    Slide->setTickPosition(QSlider::TicksBelow);
    Slide->setTickInterval(5);
    Slide->setMinimum(1);
    Slide->setMaximum(100);

    connect(Slide,SIGNAL(valueChanged(int)),this,SLOT(changeSlider()));

    label = new QLabel("Hello");
    label->setFont(QFont("Times",16));

    Lay1->addWidget(label);
    Lay1->addWidget(Slide);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeSlider()
{
    int value = Slide->value();
    label->setText(QString::number(value));
}
