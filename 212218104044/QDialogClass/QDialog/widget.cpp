#include "widget.h"
#include "ui_widget.h"
#include"infodialog.h"
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
    InfoDialog *dialog=new InfoDialog(this);
    connect(dialog,&InfoDialog::accepted,[=](){
        QString position=dialog->getPosition();
        QString os=dialog->getOs();
        qDebug()<<"Dialog Accepted,Position is "<<position<<" and Favourite OS is "<<os;
        ui->label->setText("Your position is: "+position+" and your Favourite OS is "+os);
        return 0;
    });
    connect(dialog,&InfoDialog::rejected,[=](){qDebug()<<"Dialog Rejected";});
    dialog->show();
    dialog->raise();
    dialog->activateWindow();
}
