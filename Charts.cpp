#include "Charts.h"
#include "DataMatrix.h"
#include "DataMatrix.cpp"
#include <QChart>

Chart::Chart(DataMatrix _table) //constructor for Charts objects
{
    table = _table;
}

/*DataMatrix Chart::getData()     //from json parse
{
    for (int i = 0; i <= ; ++i)
    {
    }
}*/

QChart PieChart::draw(QChart chart)
{
    QApplication a(argc, argv);

    QPieSeries *series = new QPieSeries();
    series->append("Pippo", 2); //da mettere i valori di datamatrix
    series->append("Pluto", 5);
    series->append("Paperino", 4);
    series->append("Minnie", 4);

    QPieSlice *slice = series->slices().at(1);
    slice->setLabelVisible(true);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("This is your PieChart");
    chart->legend()->setVisible(true);
    slice->setPen(QPen(Qt::black, 2));
    slice->setLabelPosition(QPieSlice::LabelOutside);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTheme(QChart::ChartThemeBlueIcy);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
}

QChart DonutChart::draw(QChart chart)
{
    QApplication a(argc, argv);

    series->setHoleSize(0, 35);
    slice->setExploded(true);
    Piechart::draw();
}

QChart BarChart::draw(QChart chart)
{
    QApplication a(argc, argv);

    QBarSet *set0 = new QBarSet("Pippo");
    QBarSet *set1 = new QBarSet("Pluto");
    QBarSet *set2 = new QBarSet("Paperino");
    QBarSet *set3 = new QBarSet("Minnie");

    *set0 << 4 << 10 << 0 << 3 << 23 << 12;
    *set1 << 5 << 20 << 7 << 8 << 20 << 2;
    *set2 << 5 << 0 << 9 << 23 << 23 << 0;
    *set3 << 8 << 20 << 6 << 5 << 4 << 15;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("This is your BarChart");
    chart->setAnimationOptions(QChart::SeriesAnimation);

    QStringList categories;
    categories << "Gennaio"
               << "Febbraio"
               << "Marzo"
               << "Aprile"
               << "Maggio"
               << "Giugno";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chat->setAxisX(axeis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAllignment(Qt::AllignTop);

    QChartView *chartView = QChartView(chart);
    chartView->setRenderHint(QPainter::AntiAliasing);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRbg(0x000000));
    pale.setColor(Qpalette::WindowText, QRbg(0x404040));
    qApp->setPalette(pale);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
}

QChart LineChart::draw(QChart chart)
{
    QApplication a(argc, argv);

    QLineSeries *series = new QLineSeries();
    series->append(0, 6);
    series->append(8, 6);
    series->append(9, 6);
    series->append(0, 2);
    *series << QPointF(7, 4) << QPointF(4, 3) << QPointF(8, 3) << QPointF(9, 2) << QPointF(1, 0);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTitle("This is your line chart");
    chart->setAnimationOption(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show()
}

QChart SplineChart::draw(QChart chart)
{
    QApplication a(argc, argv);

    QSplineSeries *series = new QSplineSeries();
    series->setName("Spline");
    series->append(0, 6);
    series->append(8, 6);
    series->append(9, 6);
    series->append(0, 2);
    *series << QPointF(7, 4) << QPointF(4, 3) << QPointF(8, 3) << QPointF(9, 2) << QPointF(1, 0);

    QChart *chart = new QChart();
    chart->legend()->setVisible(true);
    chart->addSeries(series);
    chart->setTitle("This is your spline chart");
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first->setRange(0, 5);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
}

QChart SplineChart::draw(QChart chart)
{
    QApplication a(argc, argv);

    QSplineSeries *series = new QSplineSeries();
    series->setName("Spline");
    series->append(0, 6);
    series->append(8, 6);
    series->append(9, 6);
    series->append(0, 2);
    *series << QPointF(7, 4) << QPointF(4, 3) << QPointF(8, 3) << QPointF(9, 2) << QPointF(1, 0);

    QChart *chart = new QChart();
    chart->legend()->setVisible(true);
    chart->addSeries(series);
    chart->setTitle("This is your spline chart");
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first->setRange(0, 5);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
}
