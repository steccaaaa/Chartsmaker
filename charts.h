#ifndef CHARTS_H
#define CHARTS_H

#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QSplineSeries>
#include <QStackedBarSeries>
#include <QHorizontalBarSeries>
#include <QHorizontalStackedBarSeries>
#include <QPercentBarSeries>
#include <QHorizontalPercentBarSeries>
#include <QScatterSeries>
#include <QPointF>
#include <QPainter>
#include <QPalette>

#include "datamatrix.h"

using namespace QtCharts;

class Chart
{
private:
    DataMatrix table;
public:
    /**
     * @brief Constructor of Chart objects
     *
     * @param Table reference of a 2D vector
     */
    Chart(DataMatrix table);

    /**
     *
     * @brief Getter function of the data needed for the different types of charts
     *
     * @return Returns the data in the table
     */
    DataMatrix getData() const;

    /**
     * @brief   Getter function for the data table
     *
     * @return Returns the entire table
     */
    DataMatrix getTable() const;

    /**
     * @brief Virtual function to draw the different charts
     *
     * @return Returns a new chart with the characteristics chosen by the user
     */
    virtual QChart* draw() const = 0;

    /**
     * @brief Virtual function that clones the already existing chart
     *
     * @param Table reference of a 2D vector
     * @return The cloned chart
     */
    virtual Chart* clone(const DataMatrix &table) const = 0;

};

class RoundChart : public Chart
{
protected:
    /**
     * @brief Function that creates the specified series for the chart and inserts the data from the data table
     *
     * @return The series for the chart
     */
    QPieSeries* toSeries() const;

public:
    /**
     * @brief Constructor of Round Chart objects (parent class to rounded shaped objects)
     *
     * @param Table reference of a 2D vector
     */
    RoundChart(DataMatrix table);
};

class PieChart : public RoundChart
{
public:
    /**
     * @brief Constructor of Pie Chart objects
     *
     * @param Table reference of a 2D vector
     */
    PieChart(DataMatrix table);

    /**
     * @brief Draws pie charts 
     *
     * @return A Pie Chart
     */
    QChart* draw() const;

    /**
     * @brief From the virtual function in class Charts
     */
    Chart* clone(const DataMatrix &table) const;
};

class DonutChart : public RoundChart
{
public:
    /**
     * @brief Construct of Donut Chart objects
     *
     * @param table reference of a 2d vector
     */
    DonutChart(DataMatrix table);

    /**
     * @brief Draws Donut Charts
     *
     * @return A Donut Chart
     */
    QChart* draw() const;

    /**
     * @brief From the virtual function in class Charts
     */
    Chart* clone(const DataMatrix &table) const;
};

class BarredChart : public Chart
{
protected:
    /**
     * @brief Template function that creates the specified series for the chart and inserts the data from the data table
     *
     * @return The series for the chart
     */
    template <class T, class T2> T* toSeries() const;

public:
    /**
     * @brief Constructor of Barred Chart objects (parent class for the charts that need bars)
     *
     * @param Table reference of a 2D vector
     */
    BarredChart(DataMatrix table);
};

class BarChart : public BarredChart
{
public:
    /**
     * @brief Constructor of Bar Chart objects
     *
     * @param Table reference of a 2D vector
     */
    BarChart(DataMatrix table);

    /**
     * @brief Draws Bar Charts
     *
     * @return A Bar Chart
     */
    QChart* draw() const;

    /**
     * @brief From the virtual function in class Charts
     */
    Chart* clone(const DataMatrix &table) const;
};

class StackedBarChart : public BarredChart
{
public:
    /**
     * @brief Constructor of Stacked Bar Chart objects
     *
     * @param Table reference of a 2D vector
     */
    StackedBarChart(DataMatrix table);

    /**
     * @brief Draws Stacked Bar Charts
     *
     * @return A Stacked Bar Chart
     */
    QChart* draw() const;

    /**
     * @brief From the virtual function in class Charts
     */
    Chart* clone(const DataMatrix &table) const;
};

class HorizontalBarChart : public BarredChart
{
public:
    /**
     * @brief Constructor of Stacked Bar Chart objects
     *
     * @param Table reference of a 2D vector
     */
    HorizontalBarChart(DataMatrix table);

    /**
     * @brief Draws Stacked Bar Charts
     *
     * @return A Stacked Bar Chart
     */
    QChart* draw() const;

    /**
     * @brief From the virtual function in class Charts
     */
    Chart* clone(const DataMatrix &table) const;
};

class HorizontalStackedBarChart : public BarredChart
{
public:
    /**
     * @brief Constructor of Horizontal Stacked Bar Chart objects
     *
     * @param Table reference of a 2D vector
     */
    HorizontalStackedBarChart(DataMatrix table);

    /**
     * @brief Draws Horizontal Stacked Bar Charts
     *
     * @return An Horizontal Stacked Bar Chart
     */
    QChart* draw() const;

    /**
     * @brief From the virtual function in class Charts
     */
    Chart* clone(const DataMatrix &table) const;
};

class PercentBarChart : public BarredChart
{
public:
    /**
     * @brief Constructor of Percent Bar Chart objects
     *
     * @param Table reference of a 2D vector
     */
    PercentBarChart(DataMatrix table);

    /**
     * @brief Draws Percent Bar Charts
     *
     * @return A Percent Bar Chart
     */
    QChart* draw() const;

    /**
     * @brief From the virtual function in class Charts
     */
    Chart* clone(const DataMatrix &table) const;
};

class HorizontalPercentBarChart : public BarredChart
{
public:
    /**
     * @brief Constructor of Horizontal Percent Bar Chart objects
     *
     * @param Table reference of a 2D vector
     */
    HorizontalPercentBarChart(DataMatrix table);

    /**
     * @brief Draws Horizontal Percent Bar Charts
     *
     * @return A Horizontal Percent Bar Chart
     */
    QChart* draw() const;

    /**
     * @brief From the virtual function in class Charts
     */
    Chart* clone(const DataMatrix &table) const;
};

class ContinuousChart : public Chart
{
protected:
    /**
     * @brief Template function that creates the specified series for the chart and inserts the data from the data table
     *
     * @param Index
     * @return The series for the chart
     */
    template <class T> T* toSeries(unsigned int i) const;

public:
    /**
     * @brief Constructor of Continuous Chart object
     *
     * @param Table reference of a 2D vector
     */
    ContinuousChart(DataMatrix table);
};

class LineChart : public ContinuousChart
{
public:
    /**
     * @brief Constructor of Line Chart objects
     *
     * @param Table reference of a 2D vector
     */
    LineChart(DataMatrix table);

    /**
     * @brief Draws Line Charts
     *
     * @return A Line Chart
     */
    QChart* draw() const;

    /**
     * @brief From the virtual function in class Charts
     */
    Chart* clone(const DataMatrix &table) const;
};

class SplineChart : public ContinuousChart
{
public:
    /**
     * @brief Constructor of Line Chart objects
     *
     * @param Table reference of a 2D vector
     */
    SplineChart(DataMatrix table);

    /**
     * @brief Draws Line Charts
     *
     * @return A Line Chart
     */
    QChart* draw() const;

    /**
     * @brief From the virtual function in class Charts
     */
    Chart* clone(const DataMatrix &table) const;
};

class ScatterChart : public Chart
{
protected:
    /**
     * @brief Function that creates the specified series for the chart and inserts the data from the data table
     *
     * @return The series for the chart
     */
    QScatterSeries* toSeries(unsigned int i) const;

public:
    /**
     * @brief Constructor of Scatter Chart objects
     *
     * @param Table reference of a 2D vector
     */
    ScatterChart(DataMatrix table);

    /**
     * @brief Draws Scatter Charts
     *
     * @return A Scatter Chart
     */
    QChart* draw() const;

    /**
     * @brief From the virtual function in class Charts
     */
    Chart* clone(const DataMatrix &table) const;
};

#endif
