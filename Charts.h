#ifndef CHARTS_H
#define CHARTS_H

#include "DataMatrix.h"
#include "DataMatrix.cpp"
#include <QtCharts/QChart>
#include <QtCharts/Chartview>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

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
    Datamatrix getData();

    /**
     * @brief 
     * 
     * @param chart 
     * @return returns a new chart with the characteristics chosen by the user 
     */
    virtual QChart draw(QChart chart) = 0;
}

class Roundchart : public Chart //for rounded shaped charts
{
private:
    QPieSeries *series;
public:
    /**
     * @brief Draws rounded shaped charts 
     * 
     * @param data ????????????
     * @return QChart
     */
    virtual QChart draw(QChart chart);
}

class PieChart : public RoundChar //similar to a DonutChart but without the hole
{
public:
    /**
     * @brief Draws rounded shaped charts 
     * 
     * @param data ????????????
     * @return QChart 
     */
    virtual QChart draw(QChart chart);
}

class DonutChart : public RoundChart //similar to a PieChart but with a hole
{
public:
    /**
     * @brief Draws rounded shaped charts 
     * 
     * @param data ????????????
     * @return QChart 
     */
    virtual QChart draw(QChart chart);
}

class LineChart : public Chart
{
public:
    /**
     * @brief Draws rounded shaped charts 
     * 
     * @param data ????????????
     * @return QChart 
     */
    virtual QChart draw(QChart chart);
}

class BarChart : public Chart
{
public:
    /**
     * @brief Draws rounded shaped charts 
     * 
     * @param data ????????????
     * @return QChart 
     */
    virtual QChart draw(QChart chart);
}

//DA AGGIUNGERE un TIPo DI GRAFICOOOOOOOOOOOOO

#endif
