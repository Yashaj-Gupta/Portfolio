#ifndef WIDGET_H
#define WIDGET_H
#include <QLabel>
#include <QWidget>
#include <QCalendarWidget>
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
    void selectDate();

private:
    Ui::Widget *ui;
    QCalendarWidget *calendar;
    QLabel *Label;
};
 #endif // WIDGET_H


