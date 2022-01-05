#include "mainwindow.h"
#include "DataMatrix.h"
#include "model.h"
#include "controller.h" //! non spostare
#include "aboutwindow.h"
#include "contactswindow.h"
#include "Charts.h"

#include <iostream> //! debug

MainWindow::MainWindow(Model *_model, QWidget *parent)
    : QWidget(parent)
{
    model = _model;

    QHBoxLayout *mainLayout = new QHBoxLayout(this); // devono essere attributi di classe altrimenti poi scompaiono, vanno solo inizializzate nel costruttore. un po' per tutto

    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    //!--------------------------------------------------MENU
    QMenuBar *menuBar = new QMenuBar();

    //! file
    file = new QMenu("File");
    menuBar->addMenu(file);

    newChart = file->addMenu("New chart"); // f0

    newChart->addAction(new QAction("Pie Chart", newChart));    // nc0
    newChart->addAction(new QAction("Donut Chart", newChart));  // nc1
    newChart->addAction(new QAction("Bar Chart", newChart));    // nc2
    newChart->addAction(new QAction("Line Chart", newChart));   // nc3
    newChart->addAction(new QAction("Spline Chart", newChart)); // nc4

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

    view->addSeparator();

    view->addAction(new QAction("Logarithmic scale", view)); // vorrei una checkbox da fareeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee

    //! help
    help = new QMenu("Help", menuBar);
    menuBar->addMenu(help);
    help->addAction(new QAction("About", help));

    help->addAction(new QAction("Contacts", help));

    //!--------------------------------------------------TABLE

    // setLayout(mainLayout);
    this->layout()->setMenuBar(menuBar);
    drawChart();
}

void MainWindow::drawChart()
{
    qDebug() << model;
    auto table = model->getTable();
    DonutChart *pie = new DonutChart(table);
    QChartView *cv = new QChartView(pie->draw());
    cv->setRenderHint(QPainter::Antialiasing); // messo antialiasing
    layout()->addWidget(cv);
}

void MainWindow::refreshTableView(/*Model *_model*/)
{
    //*tableview
    tableView = new QTableView();
    tableView->setModel(controller->getModel()); // la view non deve sapere nulla del controller, il modello lo passo alla view nel  costruttore!!!!!!
                                                 // NOOOOOOOOOOOOO è il contrario

    // tableView->setModel(_model);
    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();
    tableView->setGeometry(0, 30, 300, 300); // per ora sono obbligato a mettere un misura fissa
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout()->addWidget(tableView);
}

void MainWindow::setController(Controller *_controller)
{
    controller = _controller;
    // connect(file->actions()[0], SIGNAL(triggered()), controller, SLOT(open())); //new
    connect(newChart->actions()[0], SIGNAL(triggered()), this, SLOT(openFile())); // fake va fatto seriamente
    connect(file->actions()[1], SIGNAL(triggered()), controller, SLOT(open()));   // open
    // 2 e' un separator
    connect(file->actions()[3], SIGNAL(triggered()), controller, SLOT(open("---------------------------open4----------------------------"))); // save
    connect(file->actions()[4], SIGNAL(triggered()), controller, SLOT(saveAsImage()));                                                        // save as png
    connect(file->actions()[5], SIGNAL(triggered()), controller, SLOT(saveAsPdf()));                                                          // save as pdf
    // 6 e' un separator
    connect(file->actions()[7], SIGNAL(triggered()), this, SLOT(close())); // exit

    connect(help->actions()[0], SIGNAL(triggered()), this, SLOT(about())); // about

    connect(help->actions()[1], SIGNAL(triggered()), this, SLOT(contacts())); // contacts

    connect(help->actions()[1], SIGNAL(triggered()), this, SLOT(contacts())); // contacts */

    // logarithmic scale
}

/*void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open json graph file"), "",
                                                tr("Json file (*.json);;All Files (*)"));
    controller->open(path.toStdString());
}

void MainWindow::save() //DA FAREEEEEEEEEEEEEEEEEEEEEEEEEEEEE
{
    std::cout << "asd";

}*/

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

QWidget *MainWindow::getChart() { return tableView; } //! deve ritornare graph
