#include "Charts.h"
#include "DataMatrix.h"
#include <QChart>

Chart::Chart(DataMatrix _table) //constructor for Charts objects
{
    table = _table;
}

/*Chart::auto getTable()
{
    return table;
}*/

QChart *RoundChart::draw()
{
    //QApplication a(argc, argv);
    QChart *RoundChart = new QChart();
    RoundChart->setTitle("This is your PieChart");

    QPieSeries *series = new QPieSeries();

    auto names = getTable().getRowLabel();
    auto values = getTable().getColumnData(0); //getter dei dati della prima colonna (poi nella view andrà fatto in modo che o consideri solo la prima colonna dando un warning o che faccia la pie solo se ho una sola colonna)
    for (unsigned int i = 0; i < names.size(); i++)
    {
        series->append(names[i], values[i]);
    }

    QPieSlice *slice = series->slices().at(1);
    slice->setLabelVisible(true);
    RoundChart->addSeries(series);
    RoundChart->legend()->setVisible(true);
    slice->setPen(QPen(Qt::black, 2));
    slice->setLabelPosition(QPieSlice::LabelOutside);
    RoundChart->setAnimationOptions(QChart::SeriesAnimations);
    RoundChart->setTheme(QChart::ChartThemeBlueIcy);

    QChartView *chartView = new QChartView(RoundChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return RoundChart;
}

/*Chart::auto getSeries()     //perchè series in roundchart è privato
{
    return *series;
}*/

QChart PieChart::draw()
{
    RoundChart::draw();
    series->setHoleSize(0);
}

QChart DonutChart::draw()
{
    RoundChart::draw();
    //auto getSeries();
    series->setHoleSize(35);
}

QChart *BarChart::draw()
{
    //QApplication a(argc, argv);

    QChart *BarChart = new QChart();
    BarChart->setTitle("This is your BarChart");

    QBarSet *set0 = new QBarSet("Pippo"); //da fare i getters
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

    BarChart->addSeries(series);
    BarChart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Gennaio"
               << "Febbraio"
               << "Marzo"
               << "Aprile"
               << "Maggio"
               << "Giugno";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    BarChart->createDefaultAxes();
    BarChart->setAxisX(axis, series);
    BarChart->legend()->setVisible(true);
    BarChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = QChartView(BarChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0x000000));
    pale.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(pale);

    return BarChart;
}

QChart *LineChart::draw()
{
    //QApplication a(argc, argv);

    QChart *LineChart = new QChart();
    LineChart->setTitle("This is your line chart");

    QLineSeries *series = new QLineSeries();

    auto names = getTable.getRowLabel();
    for (unsigned int i = 0; i < names.size(); i++)
    {
        series->append(names[i], getTable.getColumnData[i]); //lo fa solo per una delle due colonne devo capire come attaccare l'altra (per spline è uguale)
    }
    LineChart->addSeries(series);
    LineChart->createDefaultAxes();
    LineChart->legend()->setVisible(true);
    LineChart->legend()->setAlignment(Qt::AlignBottom);
    LineChart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(LineChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return LineChart;
}

QChart *SplineChart::draw()
{
    //QApplication a(argc, argv);

    QChart *SplineChart = new QChart();
    SplineChart->setTitle("This is your spline chart");

    QSplineSeries *series = new QSplineSeries();
    series->setName("Spline");
    auto names = getTable().getRowLabel();
    auto values = getTable().getColumnData(0);
    auto values2 = getTable().getColumnData(1);
    for (unsigned int i = 0; i < names.size(); i++)
    {
        series->append(names[i], values[i]);
    }
    *series << QPointF(7, 4) << QPointF(4, 3) << QPointF(8, 3) << QPointF(9, 2) << QPointF(1, 0);

    SplineChart->legend()->setVisible(true);
    SplineChart->addSeries(series);
    SplineChart->createDefaultAxes();
    SplineChart->axes(Qt::Vertical).first->setRange(0, 5);

    QChartView *chartView = new QChartView(SplineChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return SplineChart;
}
