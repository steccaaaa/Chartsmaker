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
#include <QAbstractItemModel>
#include <QScreen>

#include "model.h"
#include "Charts.h"

class Controller;

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    Controller *controller; //pointer to the controller
    Model *model; //pointer to the model

    //Menu
    QMenuBar *menuBar;
    QMenu *file;
    QMenu *newChart;
    QMenu *view;
    QMenu *edit;
    QMenu *help;

    //* Table
    QTableView *tableView;

    //* chart
    QChartView *chartView = nullptr;
    Chart *chart = nullptr;

public:
    MainWindow(QWidget *parent = nullptr);
    void setController(Controller *_controller);
    void setTableView(/*Model *_model*/);
    void setBar();
    unsigned int getSelectedRow();
    unsigned int getSelectedColumn();

    /**
    * @brief Getter for chartView
    *
    */
    QWidget *getChartView();

    /**
    * @brief Getter for chart
    *
    */
    Chart *getChart();

public slots:

    /**
    * @brief Opens a new window with the user manual
    * 
    */
    void about();

    /**
    * @brief Opens a new window with the contacts of the developers
    * 
    */
    void contacts();
    /**
    * @brief Draws the different charts
    *
    */
    void drawChart(Chart *chart);
};

#endif // MAINWINDOW_H
