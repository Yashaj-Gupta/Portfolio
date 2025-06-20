#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QSerialPort>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void sendColor();

private:
    Ui::Widget *ui;
    QSerialPort *serial;
    QSpinBox *redSpin;
    QSpinBox *greenSpin;
    QSpinBox *blueSpin;
    QPushButton *sendButton;
};
#endif // WIDGET_H
