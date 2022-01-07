#include "controller.h"
#include <iostream>

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    /*
    Model m;
    MainWindow mw(&m);

    setModel(&m);
    setMainWindow(&mw);
    mw.setController(&(*this));

    mw.refreshTableView();

    mw.resize(1000, 500);

    mw.show();
    */
    //new Model.......
    //new View.....
    /*costruttore controller:
1) chiede a utente il file da aprire
2) chiama la classe per convertire il JSON in DataMatrix
3) ora che ho la datamatrix, creo Model(Datamatrix)
4) ora che ho il model, creo la View(Model)*/
}

void Controller::setModel(Model *_model) { model = _model; }
void Controller::setMainWindow(MainWindow *_mainwindow) { mainwindow = _mainwindow; }

void Controller::open(/*std::string path*/)
{
    QString path = QFileDialog::getOpenFileName(mainwindow,
                                                tr("Open json graph file"), "",
                                                tr("Json file (*.json);;All Files (*)"));
    std::cout << "opening " << path.toStdString() << "...\n";
    model->readJson(path.toStdString());
}

Model *Controller::getModel() { return model; }

void Controller::zoomIn(){};
void Controller::zoomOut(){};
void Controller::newChart(){};

void Controller::saveAsPdf()
{
    auto chart = mainwindow->getChart();
    QPrinter printer(QPrinter::HighResolution);
    QString path = QFileDialog::getSaveFileName(mainwindow,
                                                tr("Pdf file"), "",
                                                tr("Pdf file (*.pdf)"));
    printer.setOutputFileName(path);
    printer.setPageMargins(0, 0, 0, 0, QPrinter::DevicePixel);

    QPainter painter;
    painter.begin(&printer);
    double xscale = printer.pageRect().width() / double(chart->width());
    double yscale = printer.pageRect().height() / double(chart->height());
    double scale = qMin(xscale, yscale);
    painter.scale(scale, scale);

    chart->render(&painter);
}

void Controller::saveAsImage()
{
    QWidget *widget = mainwindow->getChart();
    QPixmap pic = QPixmap::grabWidget(widget);
    widget->render(&pic);
    QString path = QFileDialog::getSaveFileName(mainwindow,
                                                tr("Png image"), "",
                                                tr("Png image (*.png)"));
    pic.save(path);
}

void Controller::save()
{
    QString path = QFileDialog::getSaveFileName(mainwindow,
                                                tr("Json graph file"), "",
                                                tr("Json file (*.json);;All Files (*)"));
    std::cout << "saving " << path.toStdString() << "...\n";
    model->writeJson(path.toStdString());
};

void Controller::exit(){};
