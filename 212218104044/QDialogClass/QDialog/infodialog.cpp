#include "infodialog.h"
#include "ui_infodialog.h"
#include <QAbstractButton>
#include<QDialogButtonBox>
#include<QPushButton>
#include<QString>
#include<QTextStream>
InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
    this->setFixedSize(400,300);
    this->setWindowTitle("Fill This:");
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button==ui->buttonBox->button(QDialogButtonBox::Ok))
    {
       position=ui->position->text();
       if(position=="")
           position="unnknown";
       if(ui->mac->isChecked())
           os="Mac";
       else if(ui->linux->isChecked())
           os="Linux";
       else if(ui->window->isChecked())
           os="Windows";
       else if(ui->ubuntu->isChecked())
           os="Ubuntu";

       else
           os="unknown";
    }
    else if(button==ui->buttonBox->button(QDialogButtonBox::Cancel))
    {
        qDebug()<<"Cancelled";
    }
}
QString InfoDialog::getPosition() const
{
    return position;
}
QString InfoDialog::getOs() const
{
    return os;
}
