#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->multiple->setReadOnly(true);
    ui->dir->setReadOnly(true);
    ui->file->setReadOnly(true);
    ui->right->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Select One or More Files"),
                                                          "C://",
                                               "Text Files (*.txt) ;; Images (*.jpg *.png *jpeg) ;; Html Files (*html)");
    ui->multiple->setPlainText("Files Choosen are:\n"+files.join("\n"));
}


void MainWindow::on_pushButton_2_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                        "C://",
                                                        QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    ui->dir->setText("Directory Selected ->"+dir);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Save As"),
                               "C://", "Text Files (*.txt) ;; Image Files (*.jpg *.png *jpeg);; Html Files (*html)");
    ui->file->setText("File Selected  >>"+fileName);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "C://", "Text Files (*.txt);;html (*.html)");
    QFile file(fileName);
    file.open(QFile::WriteOnly|QFile::Text);
    QString leftdata=ui->left->toPlainText();
    QTextStream data(&fileName);
    data<<leftdata;
    file.flush();
    file.close();
    ui->right->setPlainText("Data Is Saved In Location\n"+file.fileName()+"\n==========================\nContents Of File Are:\n"+leftdata);
}
