#include "mainwindow.h"
#include <iostream> //!da togliere

#include <QApplication>

int main(int argc, char *argv[])
{
    std::cout<<"ciao mondo!"; //!da togliere
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
