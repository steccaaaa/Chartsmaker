#include "mainwindow.h"
#include "DataMatrix.h"
#include "Charts.h"
#include <QApplication>
#include <QChartView>
#include <QLineSeries>
#include <QChart>
#include <QtCharts>
#include <QApplication>
#include <QWidget>
#include <QMenuBar>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QMenuBar *menuBar = new QMenuBar(this);

    QMenu *file = new QMenu("File", menuBar);
    QMenu *edit = new QMenu("Edit", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(edit);

    //-----------------------------
    std::vector<std::vector<double>> mat{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    std::vector<std::string> mats{"a", "b", "c"};
    DataMatrix x(mat, mats, mats);
    //PieChart pchart(x);
    //QChartView *chartView = new QChartView();

    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
}
