#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->actionSave_As,SIGNAL(triggered()),this,SLOT(saveAs()));
    connect(ui->actionPrint,SIGNAL(triggered()),this,SLOT(print()));
    connect(ui->actionPrint_Preview,SIGNAL(triggered()),this,SLOT(printPreviewDialog()));
    connect(ui->actionExport_as_PDF,SIGNAL(triggered()),this,SLOT(exportPDF()));
    connect(ui->actionExit,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(ui->actionUndo,SIGNAL(triggered()),this,SLOT(undo()));
    connect(ui->actionRedo,SIGNAL(triggered()),this,SLOT(redo()));
    connect(ui->actionCut,SIGNAL(triggered()),this,SLOT(cut()));
    connect(ui->actionCopy,SIGNAL(triggered()),this,SLOT(copy()));
    connect(ui->actionPaste,SIGNAL(triggered()),this,SLOT(paste()));
    connect(ui->actionBold,SIGNAL(triggered()),this,SLOT(fontBold()));
    connect(ui->actionItalic,SIGNAL(triggered()),this,SLOT(fontItalic()));
    connect(ui->actionUnderline,SIGNAL(triggered()),this,SLOT(fontUnderline()));
    connect(ui->actionLeft,SIGNAL(triggered()),this,SLOT(left()));
    connect(ui->actionRight,SIGNAL(triggered()),this,SLOT(right()));
    connect(ui->actionCenter,SIGNAL(triggered()),this,SLOT(center()));
    connect(ui->actionJustify,SIGNAL(triggered()),this,SLOT(justify()));
    connect(ui->actionFont,SIGNAL(triggered()),this,SLOT(changeFont()));
    connect(ui->actionColour,SIGNAL(triggered()),this,SLOT(changeColor()));
    connect(ui->actionInfo,SIGNAL(triggered()),this,SLOT(helpInfo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (fileName.isEmpty())
    {
        return;
    }
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QFile::FileError err = file.error();
        QString msg = file.errorString();

        QMessageBox::critical
        (this, "File Open Error","Error Code: "+ QString::number(err) + "\n" +"Details: " + msg);
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::save()
{
    QString FileName;
    if(currentFile.isEmpty())
    {
        FileName = QFileDialog::getSaveFileName(this,"Save");
        currentFile = FileName;
    }
    else
    {
        FileName = currentFile;
    }
    QFile file(FileName);

    if(!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QFile::FileError err = file.error();
        QString msg = file.errorString();

        QMessageBox::critical
            (this, "File Save Error","Error Code: "+ QString::number(err)+ "\n" +"Details: " + msg);
        return;
    }
    setWindowTitle(FileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.close();
}

void MainWindow::saveAs()
{
    QString FileName = QFileDialog::getSaveFileName(this,"Save As");
    QFile file(FileName);


    if(!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QFile::FileError err = file.error();
        QString msg = file.errorString();

        QMessageBox::critical
            (this, "File Save Error","Error Code: "+ QString::number(err)+ "\n" +"Details: " + msg);
        return;
    }
    currentFile = FileName;
    setWindowTitle(FileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.close();
}

void MainWindow::print()
{
    QPrinter printDev;
    QPrintDialog dialog(&printDev,this);
    if(dialog.exec() == QDialog::Rejected)
    {return;};
    ui->textEdit->print(&printDev);
}

void MainWindow::printPreviewDialog()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer,this);
    preview.setWindowFlags(Qt::Window);
    connect(&preview, &QPrintPreviewDialog::paintRequested,this, &MainWindow::printPreview);
    preview.exec();
}

void MainWindow::printPreview(QPrinter *printer)
{
    ui->textEdit->print(printer);
}

void MainWindow::exportPDF()
{
    QString FileName = QFileDialog::getSaveFileName(this,"Export");
    if(FileName != ' ')
    {
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(FileName);
        printer.setPageMargins(QMargins(30,30,30,30));
        ui->textEdit->document()->print(&printer);
    }
}

void MainWindow::undo()
{
    ui->textEdit->undo();
}

void MainWindow::redo()
{
    ui->textEdit->redo();
}

void MainWindow::cut()
{
    ui->textEdit->cut();
}

void MainWindow::copy()
{
    ui->textEdit->copy();
}

void MainWindow::paste()
{
    ui->textEdit->paste();
}

void MainWindow::fontBold()
{
    QFont font;
    font.setBold(true);
    ui->textEdit->setFont(font);

}

void MainWindow::fontItalic()
{
    QFont font;
    font.setItalic(true);
    ui->textEdit->setFont(font);
}

void MainWindow::fontUnderline()
{
    QFont font;
    font.setUnderline(true);
    ui->textEdit->setFont(font);
}

void MainWindow::left()
{
    ui->textEdit->setAlignment(Qt::AlignmentFlag::AlignLeft);
}

void MainWindow::right()
{

    ui->textEdit->setAlignment(Qt::AlignmentFlag::AlignRight);
}

void MainWindow::center()
{

    ui->textEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
}

void MainWindow::justify()
{

    ui->textEdit->setAlignment(Qt::AlignmentFlag::AlignJustify);
}

void MainWindow::changeFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
}

void MainWindow::changeColor()
{

    QColor color = QColorDialog::getColor();
    ui->textEdit->setTextColor(color);

}

void MainWindow::helpInfo()
{
    QMessageBox::information(this,"Help","Contact Yashaj on GitHub");
    return;
}






