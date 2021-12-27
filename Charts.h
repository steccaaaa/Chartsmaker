#ifndef CHARTS_H
#define CHARTS_H

#include "DataMatrix.h"
#include "DataMatrix.cpp"
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

using namespace QtCharts; //include da sistemare

class Chart
{
private:
    DataMatrix table;

public:
    /**
     * @brief Construct a new Chart  object
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
    virtual QChart draw(QChart chart) = 0;
};

class Roundchart : public Chart
{
private:
    QPieSeries *series;

public:
    /**
     * @brief Draws round shaped charts 
     *
     * @param chart
     * @return QChart
     */
    virtual QChart draw(QChart chart);

};

class PieChart : public Roundchart  //eredita da roundchart
{
private:
    QPieSeries *series;

public:
    /**
     * @brief Draws pie charts 
     *
     * @param chart
     * @return QChart
     */
    virtual QChart draw(QChart chart);
};

class DonutChart : public Roundchart // eredita da roundchart ma col buco
{
public:
    /**
     * @brief Draws donut charts
     *
     * @param chart
     * @return QChart
     */
    virtual QChart draw(QChart chart);
};

class BarChart : public Chart
{
public:
    /**
     * @brief Draws bar charts
     *
     * @param chart
     * @return QChart
     */
    virtual QChart draw(QChart chart);
};

class LineChart : public Chart
{
public:
    /**
     * @brief Draws line charts
     *
     * @param chart
     * @return QChart
     */
    virtual QChart draw(QChart chart);
};

class SplineChart : public Chart
{
public:
    /**
     * @brief Draws spline charts (similar to line harts but with rounded edges
     *
     * @param chart
     * @return QChart
     */
    virtual QChart draw(QChart chart);
};

#endif
