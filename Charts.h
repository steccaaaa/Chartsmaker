#ifndef CHARTS_H
#define CHARTS_H

#include "DataMatrix.h"
#include <QApplication>
//#include <QtWidget/QMainWindow>
#include <QMainWindow>
#include <QtCharts/QChart>
//#include <QtCharts/Chartview>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
//#include <QCharts/QBarSet>
#include <QtCharts/QBarSet>
//#include <QCharts/QBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QSplineSeries>
#include <QPointF>
#include <QPainter>
#include <QPalette>

using namespace QtCharts;

class Chart
{
private:
    DataMatrix table;
public:
    /**
     * @brief Construct a new Chart object
     *
     * @param table reference of a 2d vector
     */
    Chart(DataMatrix table);

    /**
     *
     * @brief Getter function of the data needed for the different types of charts
     *
     * @return returns chart table
     */
    DataMatrix getData();
    /**
     * @brief
     *
     * @param chart
     * @return returns a new chart with the characteristics chosen by the user
     */
    DataMatrix getTable();

    /**
     * @brief
     *
     * @param chart
     * @return returns a new chart with the characteristics chosen by the user
     */
    virtual QChart *draw() = 0;

};

class RoundChart : public Chart
{
protected:
    QPieSeries* toSeries();
public:
    /**
     * @brief Construct a new RoundChart object
     *
     * @param table reference of a 2d vector
     */
    RoundChart(DataMatrix table);
};

class PieChart : public RoundChart
{
public:
    /**
     * @brief Construct a new PieChart object
     *
     * @param table reference of a 2d vector
     */
    PieChart(DataMatrix table);
    /**
     * @brief Draws pie charts 
     *
     * @param chart
     * @return QChart
     */
    QChart *draw();
};

class DonutChart : public RoundChart
{
public:
    /**
     * @brief Construct a new DonutChart object
     *
     * @param table reference of a 2d vector
     */
    DonutChart(DataMatrix table);
    /**
     * @brief Draws donut charts
     *
     * @param chart
     * @return QChart
     */
    QChart *draw();
};

class BarChart : public Chart
{
protected:
    QBarSeries* toSeries();
public:
    /**
     * @brief Construct a new BarChart object
     *
     * @param table reference of a 2d vector
     */
    BarChart(DataMatrix table);
    /**
     * @brief Draws bar charts
     *
     * @param chart
     * @return QChart
     */
    QChart *draw();
};

class ContinuousChart : public Chart
{
protected:
    template <class T> T* toSeries(unsigned int i);
public:
    /**
     * @brief Construct a new RoundChart object
     *
     * @param table reference of a 2d vector
     */
    ContinuousChart(DataMatrix table);
};

class LineChart : public ContinuousChart
{
public:
    /**
     * @brief Construct a new LineChart object
     *
     * @param table reference of a 2d vector
     */
    LineChart(DataMatrix table);
    /**
     * @brief Draws line charts
     *
     * @param chart
     * @return QChart
     */
    QChart *draw();
};

class SplineChart : public ContinuousChart
{
public:
    /**
     * @brief Construct a new SplineChart object
     *
     * @param table reference of a 2d vector
     */
    SplineChart(DataMatrix table);
    /**
     * @brief Draws spline charts (similar to line harts but with rounded edges
     *
     * @param chart
     * @return QChart
     */
    QChart *draw();
};

#endif
