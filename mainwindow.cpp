#include "mainwindow.h"
#include "DataMatrix.h"
#include "model.h"
#include "controller.h" //! non spostare
#include "aboutwindow.h"
#include "contactswindow.h"
#include <QApplication>
#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>

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

    file->addAction(new QAction("Save as...", file)); //4

    file->addAction(new QAction("Export", file)); //5

    file->addSeparator();                       //6
    file->addAction(new QAction("Exit", file)); //7

    //! edit
    /*QMenu *edit = new QMenu("Edit", menuBar); //da decidere cosa metterci dopo che abbiamo fatto apparire i grafici
    menuBar->addMenu(edit);*/

    //! view
    view = new QMenu("View", menuBar);
    menuBar->addMenu(view);
    view->addAction(new QAction("Zoom in", view));  //da fare
    view->addAction(new QAction("Zoom out", view)); //da fare
    view->addSeparator();
    view->addAction(new QAction("Logarithmic scale", view)); // vorrei una checkbox da fare

    //! help
    help = new QMenu("Help", menuBar);
    menuBar->addMenu(help);
    help->addAction(new QAction("About", help));

    help->addAction(new QAction("Contacts", help));

    //!--------------------------------------------------TABLE

    mainLayout->addWidget(tableView);

    setLayout(mainLayout);
}

void MainWindow::setTableView(Model *_model)
{
    //*tableview
    tableView = new QTableView(this);
    //tableView->setModel(controller->getModel());
    tableView->setModel(_model);
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
    connect(file->actions()[4], SIGNAL(triggered()), controller, SLOT(open("---------------------------open4----------------------------"))); //save as
    connect(file->actions()[5], SIGNAL(triggered()), this, SLOT(saveAsPdf()));                                                                //export
    //6 e' un separator
    connect(file->actions()[7], SIGNAL(triggered()), this, SLOT(close())); //exit

    connect(help->actions()[0], SIGNAL(triggered()), this, SLOT(about()));    //about
    connect(help->actions()[1], SIGNAL(triggered()), this, SLOT(contacts())); //contacts

    //zoom in
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

void MainWindow::saveAsPdf()
{
    QPixmap pixmap;
    WId asdasd = this->winId();
    pixmap = QPixmap::grabWindow(asdasd);

    QPrinter printer;
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFormat(QPrinter::PdfFormat);

    printer.setOutputFileName(QApplication::applicationDirPath() + QDir::separator() + "file");

    QPainter painter(&printer);
    QRect rect = painter.viewport();
    QSize size = pixmap.size();

    size.scale(rect.size(), Qt::KeepAspectRatio);
    painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
    painter.setWindow(pixmap.rect());

    painter.drawPixmap(0, 0, 100, 100, pixmap);
}

void MainWindow::save()
{
    std::cout << "asd";
}

/*void MainWindow::saveAsImage()
{
    QWidget *widget = ui->mywidget;

    QPixmap pic = QPixmap::grabWidget(widget);
    widget->render(&pic);
    pic.save("Your chart.png");
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
