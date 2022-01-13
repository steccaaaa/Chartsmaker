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

    resize(1500, 750);
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
    // placeholder per non scalare
    file->addAction(new QAction("New", file)); // f0

    file->addAction(new QAction("Open", file)); // f1

    file->addSeparator();                       // f2
    file->addAction(new QAction("Save", file)); // f3

    file->addAction(new QAction("Save as PNG", file)); // f4

    file->addAction(new QAction("Save as PDF", file)); // f5

    file->addSeparator();                       // f6
    file->addAction(new QAction("Exit", file)); // f7

    //! edit
    edit = new QMenu("Edit", menuBar);
    menuBar->addMenu(edit);

    edit->addAction(new QAction("Add column before", edit));
    edit->addAction(new QAction("Add column after", edit));
    edit->addAction(new QAction("Add row before", edit));
    edit->addAction(new QAction("Add row after", edit));

    //! view
    view = new QMenu("View", menuBar);
    menuBar->addMenu(view);

    QAction *item1 = new QAction("Pie Chart");
    item1->setCheckable(true);
    QAction *item2 = new QAction("Donut Chart");
    item2->setCheckable(true);
    QAction *item3 = new QAction("Bar Chart");
    item3->setCheckable(true);
    QAction *item4 = new QAction("Stacked Bar Chart");
    item4->setCheckable(true);
    QAction *item5 = new QAction("Horizontal Bar Chart");
    item5->setCheckable(true);
    QAction *item6 = new QAction("Horizontal Stacked Bar Chart");
    item6->setCheckable(true);
    QAction *item7 = new QAction("Percentbar Chart");
    item7->setCheckable(true);
    QAction *item8 = new QAction("Horizontal Percent Bar Chart");
    item8->setCheckable(true);
    QAction *item9 = new QAction("Line Chart");
    item9->setCheckable(true);
    QAction *item10 = new QAction("Spline Chart");
    item10->setCheckable(true);
    QAction *item11 = new QAction("Scatter Chart");
    item11->setCheckable(true);

    view->addAction(item1);
    view->addAction(item2);
    view->addAction(item3);
    view->addAction(item4);
    view->addAction(item5);
    view->addAction(item6);
    view->addAction(item7);
    view->addAction(item8);
    view->addAction(item9);
    view->addAction(item10);
    view->addAction(item11);

    QActionGroup *myGroup = new QActionGroup(this);
    myGroup->setExclusive(true);
    myGroup->addAction(item1);
    myGroup->addAction(item2);
    myGroup->addAction(item3);
    myGroup->addAction(item4);
    myGroup->addAction(item5);
    myGroup->addAction(item6);
    myGroup->addAction(item7);
    myGroup->addAction(item8);
    myGroup->addAction(item9);
    myGroup->addAction(item10);
    myGroup->addAction(item11);

    //view->addAction(new QAction("Logarithmic scale", view)); // vorrei una checkbox da

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

    // connessioni a slot
    // file
    connect(file->actions().at(1), SIGNAL(triggered()), controller, SLOT(open()));        // open
                                                                                          // 2 e' un separator
    connect(file->actions().at(3), SIGNAL(triggered()), controller, SLOT(save()));        // save
    connect(file->actions().at(4), SIGNAL(triggered()), controller, SLOT(saveAsImage())); // save as png
    connect(file->actions().at(5), SIGNAL(triggered()), controller, SLOT(saveAsPdf()));   // save as pdf
                                                                                          // 6 e' un separator
    connect(file->actions().at(7), SIGNAL(triggered()), this, SLOT(close()));             // exit

    // edit
    connect(edit->actions().at(0), SIGNAL(triggered()), controller, SLOT(addColumnB()));
    connect(edit->actions().at(1), SIGNAL(triggered()), controller, SLOT(addColumnA()));
    connect(edit->actions().at(2), SIGNAL(triggered()), controller, SLOT(addRowB()));
    connect(edit->actions().at(3), SIGNAL(triggered()), controller, SLOT(addRowA()));

    // help
    connect(help->actions().at(0), SIGNAL(triggered()), this, SLOT(about()));    // about
    connect(help->actions().at(1), SIGNAL(triggered()), this, SLOT(contacts())); // contacts

    // view
    connect(view->actions().at(0), &QAction::triggered, [&]()
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
                chart = new HorizontalStackedBarChart(tabella);
                drawChart(chart);
            });

    connect(view->actions().at(6), &QAction::triggered, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                chart = new PercentBarChart(tabella);
                drawChart(chart);
            });

    connect(view->actions().at(7), &QAction::triggered, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                chart = new HorizontalPercentBarChart(tabella);
                drawChart(chart);
            });

    connect(view->actions().at(8), &QAction::triggered, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                chart = new LineChart(tabella);
                drawChart(chart);
            });

    connect(view->actions().at(9), &QAction::triggered, [&]()
            {
                auto tabella = controller->getModel()->getTable();
                chart = new SplineChart(tabella);
                drawChart(chart);
            });

    connect(view->actions().at(10), &QAction::triggered, [&]()
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

unsigned int MainWindow::getSelectedColumn() { return tableView->selectionModel()->currentIndex().column(); }

unsigned int MainWindow::getSelectedRow() { return tableView->selectionModel()->currentIndex().row(); }

void MainWindow::about()
{
    std::cout << tableView->selectionModel()->currentIndex().row();
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

QWidget *MainWindow::getChartView() { return chartView; }

Chart *MainWindow::getChart() { return chart; }
