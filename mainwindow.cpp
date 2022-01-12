#include "mainwindow.h"
#include "DataMatrix.h"
#include "model.h"
#include "controller.h" //! non spostare
#include "aboutwindow.h"
#include "contactswindow.h"
#include "Charts.h"

#include <iostream> //! debug

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *mainLayout = new QHBoxLayout(this); // devono essere attributi di classe altrimenti poi scompaiono, vanno solo inizializzate nel costruttore. un po' per tutto

    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    resize(1000, 500);
    setWindowIcon(QIcon(":/images/icon.png"));

    setBar();
}

void MainWindow::setBar()
{
    //!--------------------------------------------------MENU
    menuBar = new QMenuBar();

    //! file
    file = new QMenu("File");
    menuBar->addMenu(file);
//placeholder per non scalare
    file->addAction(new QAction("New", file));    // f0

    file->addAction(new QAction("Open", file)); // f1

    file->addSeparator();                       // f2
    file->addAction(new QAction("Save", file)); // f3

    file->addAction(new QAction("Save as PNG", file)); // f4

    file->addAction(new QAction("Save as PDF", file)); // f5

    file->addSeparator();                       // f6
    file->addAction(new QAction("Exit", file)); // f7

    //! edit da fareeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
    /*QMenu *edit = new QMenu("Edit", menuBar);
    menuBar->addMenu(edit);*/

    //! view
    view = new QMenu("View", menuBar);
    menuBar->addMenu(view);

    /*QActionGroup *alignmentGroup = new QActionGroup(this);
    alignmentGroup->addAction(new QAction("Pie Chart", alignmentGroup));    // nc0
    alignmentGroup->addAction(new QAction("Donut Chart", alignmentGroup));  // nc1
    alignmentGroup->addAction(new QAction("Bar Chart", alignmentGroup));    // nc2
    alignmentGroup->addAction(new QAction("StackedBar Chart", alignmentGroup)); // nc3
    alignmentGroup->addAction(new QAction("Line Chart", alignmentGroup));   // nc4
    alignmentGroup->addAction(new QAction("Spline Chart", alignmentGroup)); // nc5
    alignmentGroup->setExclusive(true);
    */
/*
    view->addAction(new QAction("Pie Chart", view));    // nc0
    view->addAction(new QAction("Donut Chart", view));  // nc1
    view->addAction(new QAction("Bar Chart", view));    // nc2
    view->addAction(new QAction("StackedBar Chart", view)); // nc3
    view->addAction(new QAction("Line Chart", view));   // nc4
    view->addAction(new QAction("Spline Chart", view)); // nc5
    view->addAction(new QAction("Scatter Chart", view)); //nc6
*/

    QAction *item1 = new QAction("Pie Chart");
    item1->setCheckable(true);
    QAction *item2 = new QAction("Donut Chart");
    item2->setCheckable(true);
    QAction *item3 = new QAction("Bar Chart");
    item3->setCheckable(true);
    QAction *item4 = new QAction("Stackedbar Chart");
    item4->setCheckable(true);
    QAction *item5 = new QAction("Horizontalbar Chart");
    item5->setCheckable(true);
    QAction *item6 = new QAction("Line Chart");
    item6->setCheckable(true);
    QAction *item7 = new QAction("Spline Chart");
    item7->setCheckable(true);
    QAction *item8 = new QAction("Scatter Chart");
    item8->setCheckable(true);

    view->addAction(item1);
    view->addAction(item2);
    view->addAction(item3);
    view->addAction(item4);
    view->addAction(item5);
    view->addAction(item6);
    view->addAction(item7);

    QActionGroup *myGroup = new QActionGroup(this);
    myGroup->setExclusive(true);
    myGroup->addAction(item1);
    myGroup->addAction(item2);
    myGroup->addAction(item3);
    myGroup->addAction(item4);
    myGroup->addAction(item5);
    myGroup->addAction(item6);
    myGroup->addAction(item7);

    view->addAction(new QAction("Logarithmic scale", view)); // vorrei una checkbox da fareeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee

    //! help
    help = new QMenu("Help", menuBar);
    menuBar->addMenu(help);
    help->addAction(new QAction("About", help));

    help->addAction(new QAction("Contacts", help));
    this->layout()->setMenuBar(menuBar);
}

void MainWindow::drawChart(Chart *chart)
{
    auto qchart = chart->draw();
    if (!chartView)
    {
        chartView = new QChartView(qchart);
    }
    else
    {
        chartView->setChart(qchart);
    }
    chartView->setRenderHint(QPainter::Antialiasing);
    layout()->addWidget(chartView);
}

void MainWindow::setTableView(/*Model *_model*/)
{
    //*tableview
    layout()->removeWidget(tableView);
    tableView = new QTableView();
    tableView->setModel(controller->getModel());
    // tableView->setModel(_model);
    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();
    tableView->setGeometry(0, 30, 300, 300); // per ora sono obbligato a mettere un misura fissa
    tableView->setStyleSheet("QHeaderView::section { background-color:lightblue }");
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout()->addWidget(tableView);
}

void MainWindow::setController(Controller *_controller)
{
    controller = _controller;

    //connessioni a slot
    connect(file->actions().at(1), SIGNAL(triggered()), controller, SLOT(open())); // open
    // 2 e' un separator
    connect(file->actions().at(3), SIGNAL(triggered()), controller, SLOT(save()));        // save
    connect(file->actions().at(4), SIGNAL(triggered()), controller, SLOT(saveAsImage())); // save as png
    connect(file->actions().at(5), SIGNAL(triggered()), controller, SLOT(saveAsPdf()));   // save as pdf
    // 6 e' un separator
    connect(file->actions().at(7), SIGNAL(triggered()), this, SLOT(close())); // exit

    connect(help->actions().at(0), SIGNAL(triggered()), this, SLOT(about())); // about

    connect(help->actions().at(1), SIGNAL(triggered()), this, SLOT(contacts())); // contacts

    connect(view->actions().at(0), &QAction::triggered, [&]()  //new chart
            {
                auto tabella = controller->getModel()->getTable();
                chart = new PieChart(tabella);
                drawChart(chart);
            });

    connect(view->actions().at(1), &QAction::triggered, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                chart = new DonutChart(tabella);
                drawChart(chart);
            });

    connect(view->actions().at(2), &QAction::triggered, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                chart = new BarChart(tabella);
                drawChart(chart);
            });


    connect(view->actions().at(3), &QAction::triggered, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                chart = new StackedBarChart(tabella);
                drawChart(chart);
            });

    connect(view->actions().at(4), &QAction::triggered, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                chart = new HorizontalBarChart(tabella);
                drawChart(chart);
            });

    connect(view->actions().at(5), &QAction::triggered, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                chart = new LineChart(tabella);
                drawChart(chart);
            });

    connect(view->actions().at(6), &QAction::triggered, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                chart = new SplineChart(tabella);
                drawChart(chart);
            });

    connect(view->actions().at(7), &QAction::triggered, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                chart = new ScatterChart(tabella);
                drawChart(chart);
            });


    connect(controller->getModel(), &QAbstractItemModel::dataChanged, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                drawChart(chart->clone(tabella));
            });

    //! la table view e il chart va messa ora dopo che il controller è stato settato se no il model non lo ha
    //* tableview
    setTableView();
}

void MainWindow::about()
{
    aboutwindow *m_aboutwindow = new aboutwindow();
    m_aboutwindow->setWindowTitle("About");
    m_aboutwindow->show();
}

void MainWindow::contacts()
{
    contactswindow *m_contactswindow = new contactswindow();
    m_contactswindow->setWindowTitle("Contacts");
    m_contactswindow->show();
}

QWidget *MainWindow::getChart() { return chartView; } //! deve ritornare graph
