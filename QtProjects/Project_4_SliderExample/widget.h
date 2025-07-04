#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSlider>
#include <QLabel>

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
    void changeSlider();

private:
    Ui::Widget *ui;
    QSlider *Slide;
    QLabel *label;
};
#endif // WIDGET_H
