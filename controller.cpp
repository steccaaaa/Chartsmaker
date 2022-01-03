#include "controller.h"
#include <iostream>

Controller::Controller(QObject *parent)
    : QObject{parent}
{
}

void Controller::setModel(Model *_model) { model = _model; }
void Controller::setMainWindow(MainWindow *_mainwindow) { mainwindow = _mainwindow; }

void Controller::open(std::string path)
{
    std::cout << path << "\n";
    std::cout << "-------------------------------------------------------\n";
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
    QWidget *widget = mainwindow->getGraph();
    QPixmap pic = QPixmap::grabWidget(widget);
    widget->render(&pic);
    pic.save("Your chart.png");
}

void Controller::save(){};

void Controller::exit(){};
