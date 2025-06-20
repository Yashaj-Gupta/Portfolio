#include "widget.h"
#include "./ui_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QVBoxLayout * Lay = new QVBoxLayout(this);

    FontBox = new QFontComboBox();
    Lay->addWidget(FontBox);
    Edit = new QTextEdit();
    Lay->addWidget(Edit);

    connect(FontBox,SIGNAL(currentFontChanged(QFont)),this,SLOT(changeFont()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeFont()
{
    QFont font = QFont(FontBox->itemText(FontBox->currentIndex()));
    Edit->setFont(font);
}
