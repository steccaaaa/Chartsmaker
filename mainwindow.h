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
    QMenuBar *menuBar;

    QMenu *file;
    QMenu *newChart;
    QMenu *view;
    QMenu *help;

    //* table
    QTableView *tableView;

    //* chart
    QChartView *chartView;

public:
    MainWindow(QWidget *parent = nullptr);
    void setController(Controller *_controller);
    void setTableView(/*Model *_model*/);
    void setBar();

public slots:

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
    * @brief Getter for charts
    *
    */
    QWidget *getChart();
    /**
    * @brief to draw the different charts
    *
    */
    void drawChart();
};

#endif // MAINWINDOW_H
