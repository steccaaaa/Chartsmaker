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
    Controller* controller;

public:
    MainWindow(QWidget *parent = nullptr);
    void setController(Controller* _controller);
};

#endif // MAINWINDOW_H
