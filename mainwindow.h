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
#include <QMessageBox>

#include "model.h"
#include "charts.h"
#include "datamatrix.h"
#include "aboutwindow.h"
#include "contactswindow.h"
#include "charts.h"

class Controller; //dichiarazione incompleta di classe per evitare dipendenze circolari

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    Controller *controller;
    Model *model;

    //Menu
    QMenuBar *menuBar;
    QMenu *file;
    QMenu *newChart;
    QMenu *view;
    QMenu *edit;
    QMenu *help;

    //* Table
    QTableView *tableView = nullptr;

    //* chart
    QChartView *chartView = nullptr;
    Chart *chart = nullptr;

public:
    MainWindow(QWidget *parent = nullptr);
    void setController(Controller *_controller);
    void setTableView(/*Model *_model*/);
    void setBar();
    unsigned int getSelectedRow() const;
    unsigned int getSelectedColumn() const;

    /**
    * @brief Getter for chartView
    *
    */
    QWidget *getChartView() const;

    /**
    * @brief Getter for chart
    *
    */
    Chart *getChart() const;

public slots:

    /**
    * @brief Opens a new window with the user manual
    * 
    */
    void about() const;

    /**
    * @brief Opens a new window with the contacts of the developers
    * 
    */
    void contacts() const;

    /**
    * @brief Draws the different charts
    *
    */
    void drawChart(Chart *chart);
};

#endif // MAINWINDOW_H
