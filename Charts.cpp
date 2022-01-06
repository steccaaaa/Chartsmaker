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

QPieSeries *RoundChart::toSeries()
{
    QPieSeries *series = new QPieSeries();
    auto table = getTable();
    auto names = table.getRowLabel();
    auto values = table.getColumnData(0); //andrà fatto in modo che dia un warning che prende solo la prima colonna come dati!!!!!!!!!!!!!!1
    for (unsigned int i = 0; i < names->size(); i++)
    {
        series->append(new QPieSlice(QString::fromStdString((*names)[i]), (*values)[i]));
    }
    return series;
}

QChart *PieChart::draw()
{
    QChart *RoundChart = new QChart();
    RoundChart->setTitle("This is your PieChart");

    auto series = RoundChart::toSeries();
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

    series->setHoleSize(0);
    return RoundChart;
}

QChart *DonutChart::draw()
{
    QChart *RoundChart = new QChart();
    RoundChart->setTitle("This is your DonutChart");
    auto series = RoundChart::toSeries();
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

    series->setHoleSize(0.5);
    return RoundChart;
}

QBarSeries *BarChart::toSeries()
{
    QBarSeries *series = new QBarSeries();
    auto table = getTable();
    auto names = table.getRowLabel();
    for (unsigned int i = 0; i < names->size(); i++)
    {
        QBarSet *set = new QBarSet(QString::fromStdString((*names)[i]));
        for (auto& tmp: (*(table.getData()))[i])
        {
            *set << tmp;
        }
        series->append(set);
    }
    return series;
}

QChart *BarChart::draw()
{
    QChart *BarChart = new QChart();
    BarChart->setTitle("This is your BarChart");
    auto series = BarChart::toSeries();
    BarChart->addSeries(series);
    BarChart->setAnimationOptions(QChart::SeriesAnimations);
    auto table = getTable();
    QStringList categories;
    for (auto& tmp: *table.getColumnLabel())
    {
        categories << QString::fromStdString(tmp);
    }

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    BarChart->createDefaultAxes();
    BarChart->setAxisX(axis, series);
    BarChart->legend()->setVisible(true);
    BarChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(BarChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    BarChart->setTheme(QChart::ChartThemeBlueIcy);
    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    return BarChart;
}

QLineSeries *LineChart::toSeries()
{
    auto table = getTable();
    QLineSeries *series = new QLineSeries();
    for(unsigned int j = 0; j < table.getColumnCount(); j++)
    {
        series->append(j, table.getData()->at(0).at(j));
    }

    return series;
}

QChart *LineChart::draw()
{
    QChart *LineChart = new QChart();
    LineChart->setTitle("This is your Line chart");
    auto table = getTable();
    auto series = LineChart::toSeries();
    LineChart->addSeries(series);
    LineChart->createDefaultAxes();
    QCategoryAxis *axisX = new QCategoryAxis();
    QCategoryAxis *axisY = new QCategoryAxis();
    for(unsigned int i = 0; i < table.getColumnCount(); i++)
    {
        axisX->append(QString::fromStdString(table.getColumnLabel()->at(i)), i + 0.5);
    }
    LineChart->addAxis(axisX, Qt::AlignBottom);
    LineChart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    //series->attachAxis(axisY);
    LineChart->legend()->setVisible(true);
    LineChart->legend()->setAlignment(Qt::AlignBottom);
    LineChart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(LineChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    LineChart->setTheme(QChart::ChartThemeBlueIcy);

    return LineChart;
}

QSplineSeries *SplineChart::toSeries()
{
    auto table = getTable();
    QSplineSeries *series = new QSplineSeries();
    for(unsigned int j = 0; j < table.getColumnCount(); j++)
    {
        series->append(j, table.getData()->at(0).at(j));
    }
    return series;
}

QChart *SplineChart::draw()
{
    QChart *SplineChart = new QChart();
    SplineChart->setTitle("This is your Spline chart");
    auto table = getTable();
    auto series = SplineChart::toSeries();
    SplineChart->addSeries(series);
    SplineChart->createDefaultAxes();
    QCategoryAxis *axisX = new QCategoryAxis();
    QCategoryAxis *axisY = new QCategoryAxis();
    for(unsigned int i = 0; i < table.getColumnCount(); i++)
    {
        axisX->append(QString::fromStdString(table.getColumnLabel()->at(i)), i + 0.5);
    }
    SplineChart->addAxis(axisX, Qt::AlignBottom);
    SplineChart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    SplineChart->axes(Qt::Vertical).first()->setRange(0, 5);
    QChartView *chartView = new QChartView(SplineChart);
    SplineChart->legend()->setVisible(true);
    SplineChart->legend()->setAlignment(Qt::AlignBottom);
    chartView->setRenderHint(QPainter::Antialiasing);
    SplineChart->setTheme(QChart::ChartThemeBlueIcy);

    return SplineChart;
}
