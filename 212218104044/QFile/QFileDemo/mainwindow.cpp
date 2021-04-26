#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_read_clicked()
{
    QFile file(R"(C:\Users\Surya\Documents\QFileDemo\myfile.txt)");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"File Error","File Cant be Opened");
    }
    else
     {
    QString filename = (file.fileName()).section("/",-1,-1);
    setWindowTitle(file.fileName());
    ui->filename->setText(filename);
    ui->action->setText("File Successfully Read");
    QTextStream in(&file);
    QString text=in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.flush();
    file.close();
    }
}

void MainWindow::on_write_clicked()
{
    QFile file(R"(C:\Users\Surya\Documents\QFileDemo\myfile.txt)");
    QString filename = (file.fileName()).section("/",-1,-1);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"File Error","File Cant be Opened "+filename);
    }
    else
    {
    setWindowTitle(file.fileName());
    ui->filename->setText(filename);
    ui->action->setText("Text Written Into File");
    QTextStream out(&file);
    QString text=ui->plainTextEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
    }
}
