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
void Controller::saveAsPfd(){};
void Controller::exit(){};
void Controller::save(){};
