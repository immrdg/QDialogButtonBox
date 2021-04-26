#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    widget w;
    w.setFixedSize(952,322);
    w.show();
    return a.exec();
}
