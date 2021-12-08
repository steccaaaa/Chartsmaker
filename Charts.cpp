#include "Charts.h"
#include "DataMatrix.h"
#include "DataMatrix.cpp"
#include <QChart>

Chart::Chart(DataMatrix _table) //constructor for Charts objects
{
    table = _table;
}

DataMatrix Chart::getData()
{
    for (int i = 0; i <= ; ++i)
    {
    }
}

QChart RoundChart::draw(QChart chart)
{
    //getdata per la prima colonna
    //get data per le labels
    //qpieseries e attacco dati a nomi
    //roba grafica
}

QChart PieChart::draw(QChart chart)
{
    //getdata
    //chart = this->roundchart::Draw
    //ritorno
    //grafica???
}

QChart DonutChart::draw(QChart chart)
{
    //getdata
    //chart = this->roundchart::Draw
    //ci metto il buco con funzione
    //grafica??
}

QChart LineChart::draw(QChart chart)
{
}
