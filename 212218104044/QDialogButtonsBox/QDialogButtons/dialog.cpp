#include "dialog.h"
#include "ui_dialog.h"
#include <QAbstractButton>
#include<QDialogButtonBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setFixedSize(952,322);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_clicked(QAbstractButton *button1)
{
    if((QPushButton *)button1==ui->buttonBox->button(QDialogButtonBox::Ok))
    {
        qDebug()<<"Okay Is Clicked";
    }
    if((QPushButton *)button1==ui->buttonBox->button(QDialogButtonBox::Yes))
    {
        qDebug()<<"Yes Is Clicked";
    }
    if((QPushButton *)button1==ui->buttonBox->button(QDialogButtonBox::YesToAll))
    {
        qDebug()<<"YESToAll is clicked";
    }
    if((QPushButton *)button1==ui->buttonBox->button(QDialogButtonBox::Cancel))
    {
        qDebug()<<"Cancel is clicked";
    }
    if((QPushButton *)button1==ui->buttonBox->button(QDialogButtonBox::Open))
    {
        qDebug()<<"Open is clicked";
    }
    if((QPushButton *)button1==ui->buttonBox->button(QDialogButtonBox::No))
    {
        qDebug()<<"No is clicked";
    }
    if((QPushButton *)button1==ui->buttonBox->button(QDialogButtonBox::NoToAll))
    {
        qDebug()<<"NoToAll is clicked";
    }
    if((QPushButton *)button1==ui->buttonBox->button(QDialogButtonBox::Save))
    {
        qDebug()<<"Save is clicked";
    }
    if((QPushButton *)button1==ui->buttonBox->button(QDialogButtonBox::SaveAll))
    {
        qDebug()<<"SaveAll is clicked";
    }

}
