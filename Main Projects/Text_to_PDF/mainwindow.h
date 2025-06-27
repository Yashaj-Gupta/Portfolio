#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QFontDialog>
#include <QPrintPreviewDialog>
#include <QApplication>
#include <QColorDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void save();
    void saveAs();
    void print();
    void printPreviewDialog();
    void printPreview(QPrinter *printer);
    void exportPDF();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void fontBold();
    void fontItalic();
    void fontUnderline();
    void left();
    void right();
    void center();
    void justify();
    void changeFont();
    void changeColor();
    void helpInfo();
private:
    Ui::MainWindow *ui;
    QString currentFile;
};
#endif
