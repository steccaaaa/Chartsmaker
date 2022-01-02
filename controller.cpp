#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{

}

void Controller::setModel(Model* _model) { model = _model; }
void Controller::setMainWindow(MainWindow* _mainwindow) { mainwindow = _mainwindow; }
