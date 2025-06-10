#ifndef WIDGET_H
#define WIDGET_H
#include <QHBoxLayout>
#include <QWidget>
#include <QLCDNumber>
#include <QTime>
#include <QString>
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
public slots:
    void showTime();
private:
    QLCDNumber *lcd;
    Ui::Widget *ui;
};
#endif // WIDGET_H
