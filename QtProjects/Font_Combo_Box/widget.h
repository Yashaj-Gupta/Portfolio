#ifndef WIDGET_H
#define WIDGET_H
#include <QTextEdit>
#include <QWidget>
#include <QFontComboBox>
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
    void changeFont();

private:
    Ui::Widget *ui;
    QFontComboBox *FontBox;
    QTextEdit *Edit;
};
#endif // WIDGET_H
