#include "Charts.h"
#include "DataMatrix.h"
#include <QChart>

Chart::Chart(DataMatrix _table) //constructor for Charts objects
{
    table = _table;
}

Chart::auto getTable()
{
    return table;
}

QChart RoundChart::draw()
{
    //QApplication a(argc, argv);
    QChart *RoundChart = new QChart();
    chart->setTitle("This is your PieChart");
    
    QPieSeries *series = new QPieSeries();

    auto names = getTable().getRowLabel();
    auto values = getTable().getColumnData(0); //getter dei dati della prima colonna (poi nella view andrà fatto in modo che o consideri solo la prima colonna dando un warning o che faccia la pie solo se ho una sola colonna)
    for (unsigned int i = 0; i < names.size(); i++)
    {
        series->append(names[i], values[i]); 
    }

    QPieSlice *slice = series->slices().at(1);
    slice->setLabelVisible(true);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->setVisible(true);
    slice->setPen(QPen(Qt::black, 2));
    slice->setLabelPosition(QPieSlice::LabelOutside);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTheme(QChart::ChartThemeBlueIcy);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return RoundChart;
}

/*Chart::auto getSeries()     //perchè series in roundchart è privato
{
    return *series;
}*/

QChart PieChart::draw()
{
    Roundchart::draw();
    series->setHoleSize(0, 0);
}

QChart DonutChart::draw()
{
    Roundchart::draw();
    series->setHoleSize(0, 35);
}

QChart BarChart::draw()
{
    //QApplication a(argc, argv);

    QChart *BarChart = new QChart();
    chart->setTitle("This is your BarChart");

    QBarSet *set0 = new QBarSet("Pippo");      //da fare i getters
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
    chat->setAxisX(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAllignment(Qt::AllignTop);

    QChartView *chartView = QChartView(chart);
    chartView->setRenderHint(QPainter::AntiAliasing);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRbg(0x000000));
    pale.setColor(Qpalette::WindowText, QRbg(0x404040));
    qApp->setPalette(pale);

    return BarChart;
}

QChart LineChart::draw()
{
    //QApplication a(argc, argv);

    QChart *LineChart = new QChart();
    chart->setTitle("This is your line chart");

    QLineSeries *series = new QLineSeries();
   
    auto names = datamatrix.getRowLabel(); 
    for (unsigned int i = 0; i < names.size(); i++)
    {
        series->append(names[i], datamatrix.getColumnData[i]);         //lo fa solo per una delle due colonne devo capire come attaccare l'altra (per spline è uguale)  
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOption(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return LineChart;
}

QChart SplineChart::draw()
{
    //QApplication a(argc, argv);

    QChart *SpineChart = new QChart();
    chart->setTitle("This is your spline chart");

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

    QChart *chart = new QChart();
    chart->legend()->setVisible(true);
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first->setRange(0, 5);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return SplineChart;
}


