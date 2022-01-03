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

    Controller c;
    Model m;
    MainWindow mw(&m);

    c.setModel(&m);
    c.setMainWindow(&mw);
    mw.setController(&c);

    mw.refreshTableView();

    mw.resize(1000, 500);

    mw.show();

    return app.exec();
}
