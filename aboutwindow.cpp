#include "aboutwindow.h"
#include <QLabel>
#include <QVBoxLayout>

aboutwindow::aboutwindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *l = new QLabel("About:", this);
    layout->addWidget(l);

    QLabel *label = new QLabel("User manual:", this);
    layout->addWidget(label);
    QLabel *label2 = new QLabel("ChartMaker allows you to have fun creating the charts you like the most.", this);
    layout->addWidget(label2);
    QLabel *label3 = new QLabel("All you need to do is opening a Json file with your elaborated data by clicking on FILE->OPEN and searching in your computer.", this);
    layout->addWidget(label3);
    QLabel *label4 = new QLabel("If you want to create new charts you need to click on FILE->NEW CHART and choose the one you want to display", this);
    layout->addWidget(label4);
    QLabel *label5 = new QLabel("The available charts at the moment are Pie Charts, Donut Charts, Bar Charts, Line Charts and Spline Charts.", this);
    layout->addWidget(label5);
    QLabel *label6 = new QLabel("However, we suggest you to stay tuned for any upgrades!", this);
    layout->addWidget(label6);
    QLabel *label7 = new QLabel("If you have any doubts please contact us in one of the emails you can find on ->HELP->CONTACTS, we will be pleased to answer.", this);
    layout->addWidget(label7);

    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    //setSizePolicy(0);
}

aboutwindow::~aboutwindow() {}

void aboutwindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
