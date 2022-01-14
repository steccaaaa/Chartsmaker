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
    * @param Path string of the path
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
    * @brief Saves the data inside the table in a new .json file
    * 
    */
    void save();

    /**
     * @brief Saves a screenshot of the chart in a .pdf file
     * 
     */
    void saveAsPdf();

    /**
     * @brief Saves a screenshot of the file in .png format
     * 
     */
    void saveAsImage();

    /**
    * @brief Closes the window
    * 
    */
    void exit();

    /**
    * @brief Adds a column before the column of the selected cell
    */
    void addColumnB();

    /**
     * @brief Adds a column after the column of the selected cell
     */
    void addColumnA();

    /**
     * @brief Similar to the two previous functions
     */
    void addRowB();
    void addRowA();
    void removeColumn();
    void removeRow();
};

#endif // CONTROLLER_H
