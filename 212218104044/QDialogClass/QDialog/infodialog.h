#ifndef INFODIALOG_H
#define INFODIALOG_H
#include<QAbstractButton>
#include <QDialog>
#include<QString>
namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();
    QString getPosition() const;
    QString getOs() const;

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::InfoDialog *ui;
    QString position,os;

};

#endif // INFODIALOG_H
