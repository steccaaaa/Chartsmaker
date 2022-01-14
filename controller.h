#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QApplication>
#include <QtCore>
#include <QPrinter>
#include <QPainter>
#include <QPixmap>
#include <QWidget>
#include "mainwindow.h"
#include "model.h"
#include "initwindow.h"

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

    Model *getModel();

    void init();

public slots:
    void open(/*std::string path*/);

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
     * @brief 
     * 
     */
    void saveAsPdf();

    /**
     * @brief 
     * 
     */
    void saveAsImage();

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
    * @brief Zooms out the content of the window
    * 
    */
    void zoomOut();

    /**
    * @brief Adds column before
    */
    void addColumnB();

    /**
     * @brief Adds column after
     */
    void addColumnA();

    void addRowB();
    void addRowA();
    void removeColumn();
    void removeRow();
};

#endif // CONTROLLER_H
