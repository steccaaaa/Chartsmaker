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
    series = new QPieseries();
    series = append( //lable; data from matrix con getters);
    series = append( //lable; data from matrix con getters);
    series = append( //lable; data from matrix con getters);
    QPieSlice *slice = new QPieSlice();
    slice->setLabel("label")
    slice->setValue(//...)
    series->append(std::move(slice));
    for(int i = 0; i < series->count(); ++i){
        series->slices.at(i)->setLabelVisible(true);
        if(i == 0)
        {
            seres->slices().at(i)->setColor(Qt::black);
            series->slices().at(i)->setLabelPosition(QPieSLice::LabelInsideNormal);
            QFont m_font = series->slices().at(i)->labelfont();
            m_font.setPointSize(12);
            m_font.setBold(true);
            m_font.setItalic(true);
            series->slices().at(i)->setLabelFont(m_font);
        }
        else if(i == 1)
        {
           seres->slices().at(i)->setColor(Qt::black);
           series->slices().at(i)->setLabelPosition(QPieSlice::LabelInsideOrizontal);
            QFont m_font = series->slices().at(i)->labelfont();
            m_font.setPointSize(12);
            m_font.setBold(true);
            m_font.setItalic(true);
            series->slices().at(i)->setLabelFont(m_font);
        }
        else if(i == 2){
            seres->slices().at(i)->setColor(Qt::black);
            series->slices().at(i)->setLabelPosition(QPieSlice::LabelInsideTangential);
            QFont m_font = series->slices().at(i)->labelfont();
            m_font.setPointSize(12);
            m_font.setBold(true);
            m_font.setItalic(true);
            series->slices().at(i)->setLabelFont(m_font);
        }
        else(i == 3)
        {
            seres->slices().at(i)->setColor(Qt::black);
            series->slices().at(i)->setLabelPosition(QPieSlice::LabelOutside);
            QFont m_font = series->slices().at(i)->labelfont();
            m_font.setPointSize(12);
            m_font.setBold(true);
            m_font.setItalic(true);
            series->slices().at(i)->setLabelFont(m_font);      
        }
    }       
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
        

