#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
}

widget::~widget()
{
    delete ui;
}



void widget::on_pushButton_clicked()
{
        Dialog *dialog=new Dialog(this);
        connect(dialog,&Dialog::accepted,[=](){qDebug()<<"Dialog Accepted";});
        connect(dialog,&Dialog::rejected,[=](){qDebug()<<"Dialog Rejected";});
        dialog->exec();
}
