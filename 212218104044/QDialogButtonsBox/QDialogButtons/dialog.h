#ifndef DIALOG_H
#define DIALOG_H
#include<QAbstractButton>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button1);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
