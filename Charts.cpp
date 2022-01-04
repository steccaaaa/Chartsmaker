#include "Charts.h"
#include "DataMatrix.h"
#include <QChart>

Chart::Chart(DataMatrix _table) //constructor for Charts objects
{
    table = _table;
}
RoundChart::RoundChart(DataMatrix _table) : Chart(_table) {}

PieChart::PieChart(DataMatrix _table) : RoundChart(_table) {}

DonutChart::DonutChart(DataMatrix _table) : RoundChart(_table) {}

BarChart::BarChart(DataMatrix _table) : Chart(_table) {}

LineChart::LineChart(DataMatrix _table) : Chart(_table) {}

SplineChart::SplineChart(DataMatrix _table) : Chart(_table) {}

DataMatrix Chart::getTable()
{
    return table;
}

QChart *RoundChart::draw()
{
    QChart *RoundChart = new QChart();
    RoundChart->setTitle("This is your PieChart");

    QPieSeries *series = new QPieSeries();
    auto table = getTable();
    auto names = table.getRowLabel();
    auto values = table.getColumnData(0); //getter dei dati della prima colonna (poi nella view andrà fatto in modo che o consideri solo la prima colonna dando un warning o che faccia la pie solo se ho una sola colon
    for (unsigned int i = 0; i < names->size(); i++)
    {
        series->append(new QPieSlice(QString::fromStdString((*names)[i]), (*values)[i]));
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

QChart *PieChart::draw()
{
    auto chart = RoundChart::draw();
    //chart->series().setHoleSize(0);
    return chart;
}

QChart *DonutChart::draw()
{
    auto chart = RoundChart::draw();
    //auto getSeries();
    //series->setHoleSize(35);
    return chart;
}

QChart *BarChart::draw()
{
    QChart *BarChart = new QChart();
    BarChart->setTitle("This is your BarChart");

    //QBarSet *set = new QBarSet();
    auto table = getTable();
    auto names = table.getRowLabel();
   
     QBarSeries *series = new QBarSeries();
    /*for (unsigned int i = 0; i < names->size(); i++)
    {
        QBarSet *set = new QBarSet((*names)[i]);
        for (auto& tmp: (*table)[i])
        {
            *set << tmp;
        }
        series->append(set);
    }*/
    
    BarChart->addSeries(series);
    BarChart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    for (auto& tmp: *table.getColumnLabel())  
        {
            categories << tmp;
        }

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    BarChart->createDefaultAxes();
    BarChart->setAxisX(axis, series);
    BarChart->legend()->setVisible(true);
    BarChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(BarChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0x000000));
    pale.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(pale);

    return BarChart;
}

QChart *LineChart::draw()
{
    QChart *LineChart = new QChart();
    LineChart->setTitle("This is your line chart");

    QLineSeries *series = new QLineSeries();

    auto names = getTable().getRowLabel();
    /*for (unsigned int i = 0; i < names->size(); i++)
    {
        series->append(names[i], getTable().getColumnData[i]); //lo fa solo per una delle due colonne devo capire come attaccare l'altra (per spline è uguale)
    }*/
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
    QChart *SplineChart = new QChart();
    SplineChart->setTitle("This is your spline chart");

    QSplineSeries *series = new QSplineSeries();
    series->setName("Spline");
    auto names = getTable().getRowLabel();
    auto values = getTable().getColumnData(0);
    auto values2 = getTable().getColumnData(1);
    /*for (unsigned int i = 0; i < names->size(); i++)
    {
        series->append(new QSplineSeries(QString::fromStdString((*names)[i]), (*values)[i]));
    }*/
    *series << QPointF(7, 4) << QPointF(4, 3) << QPointF(8, 3) << QPointF(9, 2) << QPointF(1, 0);

    SplineChart->legend()->setVisible(true);
    SplineChart->addSeries(series);
    SplineChart->createDefaultAxes();
    SplineChart->axes(Qt::Vertical).first()->setRange(0, 5);

    QChartView *chartView = new QChartView(SplineChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return SplineChart;
}
