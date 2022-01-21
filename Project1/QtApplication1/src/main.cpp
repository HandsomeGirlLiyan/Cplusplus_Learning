#include "tabbar_demo.h"
#include <QtWidgets/QApplication>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TabBarWindow w;
    w.show();
    return a.exec();
}
