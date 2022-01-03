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

class Controller; //dichiarazione incompleta di classe per evitare dipendenze circolari

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Controller *controller;

    //* menu
    QMenu *file;

public:
    MainWindow(QWidget *parent = nullptr);
    void setController(Controller *_controller);
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
};

#endif // MAINWINDOW_H
