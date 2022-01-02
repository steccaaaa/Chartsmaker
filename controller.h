#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "model.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    MainWindow* mainwindow;
    Model* model;

public:
    explicit Controller(QObject *parent = nullptr);

    void setModel(Model* _model);
    void setMainWindow(MainWindow* _mainwindow);

signals:

};

#endif // CONTROLLER_H
