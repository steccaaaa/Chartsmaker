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
    chart->SetTitle();
    //ROUNDCHART VIEWWWW
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
    series->setHoleSize(0,35);
    slice->setExploded(true);
    //voglio che erediti il resto dalla drawroundchart
    chart->setAnimationOptions(QChart::SeriesAnimation);
    chart->setTheme(QChart::ChartThemeBlueIcy);
}

QChart BarChart::draw(QChart chart)
{
    QBarSet *set0 = new QBarSet(//lable);
    //tante quante barre abbiamo
    *set0 << //dato << //dato << //dato //...;
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    //per tutti i ser che abbiamo
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("this is the chart");
    chart->setAnimationOptions(QChart::SeriesAnimation);
    QStirngList categories;
    categories << //prima lable << //seconda lable << //ecc...;
    QBarCategoryAxes *axes = QBarCategoryAxes();
    axes->append(categories);
    chart->createDefaultAxes();
    chat->setAxes(axes, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAllignment(Qt::AllignTop);
    
   //BARCHART VIEWWWWWW
}
        
QChart LineChart::draw(QChart chart)
{
    
}
        

