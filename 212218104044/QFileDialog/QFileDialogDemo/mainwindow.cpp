#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include<QDir>
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


void MainWindow::on_pushButton_clicked()
{
    QString filedir= QFileDialog::getOpenFileName(this,"Open Files","C://");
    if(filedir=="")
        QMessageBox::warning(this,"Error","No Files Selected");
    else
    QMessageBox::information(this,"selected file with path",filedir);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filedir= QFileDialog::getOpenFileName(this,"Open Files using QDir::homePath",QDir::homePath());
    if(filedir=="")
        QMessageBox::warning(this,"Error","No Files Selected");
    else
    QMessageBox::information(this,"selected file with path",filedir);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString filter="Text Files (*.txt *.html)";
    QString filedir= QFileDialog::getOpenFileName(this,"Open Only Text Filess",QDir::homePath()+"/Downloads",filter);
    if(filedir=="")
        QMessageBox::warning(this,"Error","No Files Selected");
    else
    {
        QFile file(filedir);
        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this,"File Error","File Cant be Opened");
        }
        else
         {
        QString filename = (file.fileName()).section("/",-1,-1);
        ui->filename->setText(filename);
        QTextStream in(&file);
        QString text=in.readAll();
        ui->plainTextEdit->setPlainText(text);
        file.flush();
        file.close();
        }

    }
}
