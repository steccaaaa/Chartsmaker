//#include <QApplication>
#include "model.h"
#include "mainwindow.h"
#include "controller.h"
//#include <vector>
//#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    std::cout << "asd\n";
    QApplication app(argc, argv);

    MainWindow mw;
    Controller c;
    Model m;

    c.setModel(&m);
    c.setMainWindow(&mw);
    mw.setController(&c);

    mw.resize(500, 500);

    mw.show();

    return app.exec();
}
