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
    std::cout << path.toStdString() << "\n";
    std::cout << "------------------------------------------------------\n";
}

Model *Controller::getModel() { return model; }

void Controller::zoomIn(){};
void Controller::zoomOut(){};
void Controller::newChart(){};

void Controller::saveAsPdf()
{
    QPixmap pixmap;
    WId asdasd = mainwindow->winId();
    pixmap = QPixmap::grabWindow(asdasd);

    QPrinter printer;
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFormat(QPrinter::PdfFormat);

    printer.setOutputFileName(QApplication::applicationDirPath() + QDir::separator() + "file");

    QPainter painter(&printer);
    QRect rect = painter.viewport();
    QSize size = pixmap.size();

    size.scale(rect.size(), Qt::KeepAspectRatio);
    painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
    painter.setWindow(pixmap.rect());

    painter.drawPixmap(0, 0, 100, 100, pixmap);
}

void Controller::saveAsImage()
{
    QWidget *widget = mainwindow->getChart();
    QPixmap pic = QPixmap::grabWidget(widget);
    widget->render(&pic);
    pic.save("Your chart.png");
}

void Controller::save(){};

void Controller::exit(){};
