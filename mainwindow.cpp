#include "mainwindow.h"
#include "DataMatrix.h"
#include "model.h"
//#include "Charts.h"
#include <QApplication>
#include <QChartView>
#include <QLineSeries>
#include <QChart>
#include <QtCharts>
#include <QApplication>
#include <QWidget>
#include <QMenuBar>
#include <QVBoxLayout>

#include <iostream> //! debug

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    //!--------------------------------------------------MENU
    QMenuBar *menuBar = new QMenuBar(this);

    //! file
    QMenu *file = new QMenu("File", menuBar);
    menuBar->addMenu(file);
    file->addAction(new QAction("New graph", file));
    file->addAction(new QAction("Open", file));
    file->addSeparator();
    file->addAction(new QAction("Save", file));
    file->addAction(new QAction("Save as...", file));
    file->addAction(new QAction("Export", file));
    file->addSeparator();
    file->addAction(new QAction("Exit", file));

    //! edit
    QMenu *edit = new QMenu("Edit", menuBar);
    menuBar->addMenu(edit);

    //! view
    QMenu *view = new QMenu("View", menuBar);
    menuBar->addMenu(view);
    view->addAction(new QAction("Zoom in", view));
    view->addAction(new QAction("Zoom out", view));
    view->addSeparator();
    view->addAction(new QAction("Logarithmic scale", view)); // vorrei una checkbox

    //! help
    QMenu *help = new QMenu("Help", menuBar);
    menuBar->addMenu(help);
    help->addAction(new QAction("About", help));
    help->addAction(new QAction("Contacts", help));

    //!--------------------------------------------------TABLE

    Model *model = new Model;
    QTableView *tableView = new QTableView(this);
    auto x = model->table.getData();
    tableView->setModel(model);
    //tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    mainLayout->addWidget(tableView);


    //!---------------------------------------------------TEST

    /*QPushButton *button = new QPushButton("pisnelo", this);
    button->setText("sbugba");
    button->setGeometry(100, 20, 80, 20);
    QPushButton *button2 = new QPushButton("pisnelo2", this);
    button2->setGeometry(50, 20, 80, 20);

    mainLayout->addWidget(button);
    mainLayout->addWidget(button2);*/
    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
}
