#include "mainwindow.h"
#include "DataMatrix.h"
#include "model.h"
#include "controller.h" //! non spostare
#include "aboutwindow.h"
#include "contactswindow.h"

#include <iostream> //! debug

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    //!--------------------------------------------------MENU
    QMenuBar *menuBar = new QMenuBar(this);

    //! file
    file = new QMenu("File", menuBar);
    menuBar->addMenu(file);
    file->addAction(new QAction("New chart", file)); //0

    file->addAction(new QAction("Open", file)); //1

    file->addSeparator();                       //2
    file->addAction(new QAction("Save", file)); //3

    file->addAction(new QAction("Save as PNG", file)); //4

    file->addAction(new QAction("Save as PDF", file)); //5

    file->addSeparator();                       //6
    file->addAction(new QAction("Exit", file)); //7

    //! edit da fareeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
    /*QMenu *edit = new QMenu("Edit", menuBar); 
    menuBar->addMenu(edit);*/

    //! view
    view = new QMenu("View", menuBar);
    menuBar->addMenu(view);
    view->addAction(new QAction("Zoom in", view));  //da fareeeeeeeeeeeeeeeeeeeeeeeeeeeee
    view->addAction(new QAction("Zoom out", view)); //da fareeeeeeeeeeeeeeeeeeeeeeeee
    view->addSeparator();
    view->addAction(new QAction("Logarithmic scale", view)); // vorrei una checkbox da fareeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee

    //! help
    help = new QMenu("Help", menuBar);
    menuBar->addMenu(help);
    help->addAction(new QAction("About", help));

    help->addAction(new QAction("Contacts", help));

    //!--------------------------------------------------TABLE

    mainLayout->addWidget(tableView);

    setLayout(mainLayout);
}

void MainWindow::refreshTableView(/*Model *_model*/)
{
    //*tableview
    tableView = new QTableView(this);
    tableView->setModel(controller->getModel());
    //tableView->setModel(_model);
    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();
    tableView->setGeometry(0, 30, 300, 300); //per ora sono obbligato a mettere un misura fissa
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::setController(Controller *_controller)
{
    controller = _controller;
    std::string path = "-----------------------------aaaaaaaaaaaaaaaaaa";
    connect(file->actions()[0], SIGNAL(triggered()), controller, SLOT(open())); //new
    connect(file->actions()[1], SIGNAL(triggered()), this, SLOT(openFile()));   //open
    //2 e' un separator
    connect(file->actions()[3], SIGNAL(triggered()), controller, SLOT(open("---------------------------open4----------------------------"))); //save
    connect(file->actions()[4], SIGNAL(triggered()), controller, SLOT(saveAsImage()));                                                        //save as png
    connect(file->actions()[5], SIGNAL(triggered()), controller, SLOT(saveAsPdf()));                                                          //save as pdf
    //6 e' un separator
    connect(file->actions()[7], SIGNAL(triggered()), this, SLOT(close())); //exit

    connect(help->actions()[0], SIGNAL(triggered()), this, SLOT(about()));    //about
    connect(help->actions()[1], SIGNAL(triggered()), this, SLOT(contacts())); //contacts

    //zoom in e out
    /*void MyQGraphicsView::wheelEvent(QWheelEvent *event)
    {
        if(event->delta() > 0)
        {
            emit mouseWheelZoom(true);
        }
        else
        {
            emit mouseWheelZoom(false);
        }
    }*/
    //zoom out
    //logarithmic scale
}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open json graph file"), "",
                                                tr("Json file (*.json);;All Files (*)"));
    controller->open(path.toStdString());
}

void MainWindow::save() //DA FAREEEEEEEEEEEEEEEEEEEEEEEEEEEEE
{
    std::cout << "asd";
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

QWidget *MainWindow::getGraph() { return tableView; } //! deve ritornare graph