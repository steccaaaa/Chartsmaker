#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "model.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    MainWindow *mainwindow;
    Model *model;

public:
    explicit Controller(QObject *parent = nullptr);

    /**
     * @brief Set the Model object
     * 
     * @param _model 
     */
    void setModel(Model *_model);

    /**
     * @brief Set the Main Window object
     * 
     * @param _mainwindow 
     */
    void setMainWindow(MainWindow *_mainwindow);

    /**
     * 
    * @brief Opens and read a JSon file to create a chart
    * 
    * @param path string of the path
    */
    void open(std::string path);

    Model *getModel();

public slots:

    /**
    * @brief Creates and shows a new chart on the window
    * 
    */
    void newChart();

    /**
    * @brief Saves 
    * 
    */
    void save();

    /**
    * @brief Saves your chart in .pdf format
    * 
    */
    void saveAsPfd();

    /**
    * @brief closes the window
    * 
    */
    void exit();

    /**
    * @brief Zooms in the content of the window
    * 
    */
    void zoomIn();

    /**
    * @brief >Zooms out the content of the window
    * 
    */
    void zoomOut();
};

#endif // CONTROLLER_H
