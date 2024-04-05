#include <QApplication>

#include "model.h"
#include "mainwindow.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Controller c;
    Model m;
    MainWindow mw;

    c.setModel(&m);
    c.setMainWindow(&mw);
    mw.setController(&c);

    c.init();

    return app.exec();
}
