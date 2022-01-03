#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QChartView>
#include <QLineSeries>
#include <QChart>
#include <QtCharts>
#include <QApplication>
#include <QWidget>
#include <QMenuBar>
#include <QVBoxLayout>
#include "model.h"

class Controller; //dichiarazione incompleta di classe per evitare dipendenze circolari

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Controller *controller;

    //* menu
    QMenu *file;
    QMenu *view;
    QMenu *help;

    //* table
    QTableView *tableView;

public:
    MainWindow(QWidget *parent = nullptr);
    void setController(Controller *_controller);
    void setTableView(Model *_model);

public slots:
    /**
    * @brief Opens and read a JSon file to create a chart
    * 
    */
    void openFile();

    /**
    * @brief Saves the window in .pdf format
    * 
    */
    void saveAsPdf();

    /**
    * @brief Saves the window 
    * 
    */
    void save();

    /**
    * @brief Opens a new window with the contacts of the developers
    * 
    */
    //void saveAsImage();

    /**
    * @brief Opens a new window
    * 
    */
    void about();

    /**
    * @brief Opens a new window with the contacts of the developers
    * 
    */
    void contacts();
};

#endif // MAINWINDOW_H
