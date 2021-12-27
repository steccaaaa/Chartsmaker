#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QLineSeries *series = new QLineSeries();

    series->append(0,2);
    series->append(QPointF(2,6));
    series->append(3,8);
    series->append(7,9);
    series->append(11,3);

    *series << QPointF(11,2) << QPointF(15,5) << QPointF(18,4) << QPointF(19,2);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    //When OpenGL is enabled, qlineseries supports GPU drawing. Other chart types of QT are not supported.
    series->setUseOpenGL(true);
    chart->createDefaultAxes();
    //Set chart title
    chart->setTitle(QStringLiteral("Qt line chart example"));

    QChartView *view = new QChartView(chart);
    //Turn on anti aliasing for better display
    view->setRenderHint(QPainter::Antialiasing);
    view->resize(400,300);
    //Show chart
    view->show();

    return a.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

