#ifndef WIDGET_H
#define WIDGET_H
#include <QLabel>
#include <QWidget>
#include <QComboBox>
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
    void comboChanged();



private:
    Ui::Widget *ui;
    QComboBox *combo;
    QLabel  *labelresult;
};
#endif // WIDGET_H
