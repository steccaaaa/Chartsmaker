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

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    Controller *controller;
    Model *model;

    //* menu
    QMenu *file;
    QMenu *view;
    QMenu *help;

    //* table
    QTableView *tableView;

public:
    MainWindow(Model *_model, QWidget *parent = nullptr);
    void setController(Controller *_controller);
    void refreshTableView(/*Model *_model*/);

public slots:
    /**
    * @brief Opens and read a JSon file to create a chart
    * 
    */
    void openFile();

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
    /**
    * @brief
    *
    */
    QWidget *getChart();
    /**
    * @brief
    *
    */
    void drawChart();
};

#endif // MAINWINDOW_H
