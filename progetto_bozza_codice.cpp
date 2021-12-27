class Chart{   //classe principale della gerarchia
public:
    Chart(DataMatrix data){...} //costruttore di chart
    protected getData(); 
    virtual QChart draw(QChart chart) = 0; //funzione astratta virtuale per disegnare i diversi chart
};

class RoundChart: Chart(){      //le chart rotonde
    virtual QChart draw(QChart chart){    //per disegnare una chart rotonda
        auto data = getData()->getColumn(0); //so che la piechart prende solo la prima colonna della tabella quindi gli dico l'indice della tabella da prendere
        auto names = getData()->getNames() //gli dico le label da mettere sulla tabella
        QPieSeries *series = new QPieSeries();
        for(...){
            series->append(names[i], data[i]); //per associare label a dato
        }

        QPieSlice *slice = series->slices().at(1); //da qui per grafica
        slice->setExploded();
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setBrush(Qt::green);
        
        chart->addSeries(series);
        chart->setTitle("Simple piechart example");
        chart->legend()->hide();  //fino a qui
        return chart;
    };
}
class PiChart : RoundChart{  //classe derivata da roundchart
public:
    virtual QChart draw(QChart chart){
        auto data = getData();
        chart = this->RoundChart::draw(chart); //usa la draw della classe madre
        chart->withoutHole();  //non ha il buco in mezzo come la donut quindi un metodo per non mettercelo
        return chart;
    };
};

class DonutChart : RoundChart{ //classe derivata da roundchart
public:
    virtual QChart draw(QChart chart){
        auto data = getData();
        chart->withHole();  //ha il buco quindi metodo per metterlo
    };
};

class LineChart : Chart{   //classe derivata da chart
public:
    virtual QChart draw(QChart chart){
        auto data = getData(); //ti prendi le due colonne della tabella per x e y piano cartesiano
        QLineSeries *series = new QLineSeries();
        series->append(0, 6); //per grafica vedi documentazione copiata e incollata random
        series->append(2, 4);
        series->append(3, 8);
        series->append(7, 4);
        series->append(10, 5);
        *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
        chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes(); //fin qui
    };
};


class View : QFrame{  //la view 
    Controller* controller; //ha un puntatore a controller perchè ci comunica
    Model* model; //e un puntatore al modello perchè ci comuna per prendersi i risultati e mostrarli
    Chart* chart;
    QTChartView* chartView;
    setChart(int index){  //sceglie quale chart fare
        if(index == 0){  //se è la prima colonna fai una pie
            chart = new PiChart(model->getDataMatrix())
        } else if(index == 1){  //se sono due colonne fai la line
            chart = new LineChart(model->getDataMatrix())
        } //eccetera
    }
    onDrawButtonClickListener(){ //quando clicchi il bottone per scegliere il grafico...
        auto qtchart = chart->draw(new QChart());
        chartView = new QChartView(qtchart);
    }
}
