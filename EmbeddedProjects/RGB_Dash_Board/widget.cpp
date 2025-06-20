#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("COM7");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->open(QIODevice::WriteOnly);

    QLabel *rLabel = new QLabel("Red:");
    redSpin = new QSpinBox();
    redSpin->setRange(0, 255);

    QLabel *gLabel = new QLabel("Green:");
    greenSpin = new QSpinBox();
    greenSpin->setRange(0, 255);

    QLabel *bLabel = new QLabel("Blue:");
    blueSpin = new QSpinBox();
    blueSpin->setRange(0, 255);

    sendButton = new QPushButton("Send Color");
    connect(sendButton, &QPushButton::clicked, this, &Widget::sendColor);

    QHBoxLayout *rLayout = new QHBoxLayout;
    rLayout->addWidget(rLabel);
    rLayout->addWidget(redSpin);

    QHBoxLayout *gLayout = new QHBoxLayout;
    gLayout->addWidget(gLabel);
    gLayout->addWidget(greenSpin);

    QHBoxLayout *bLayout = new QHBoxLayout;
    bLayout->addWidget(bLabel);
    bLayout->addWidget(blueSpin);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(rLayout);
    mainLayout->addLayout(gLayout);
    mainLayout->addLayout(bLayout);
    mainLayout->addWidget(sendButton);

    setLayout(mainLayout);
    setWindowTitle("RGB LED Dashboard");
    resize(300, 150);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::sendColor() {
    int r = redSpin->value();
    int g = greenSpin->value();
    int b = blueSpin->value();

    QString colorData = QString("%1,%2,%3\n").arg(r).arg(g).arg(b);
    serial->write(colorData.toUtf8());
}
