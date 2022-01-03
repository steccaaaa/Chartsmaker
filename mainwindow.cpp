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
    file->addAction(new QAction("New graph", file)); //0
    file->addAction(new QAction("Open", file));      //1

    file->addSeparator();                       //2
    file->addAction(new QAction("Save", file)); //3

    /* NON SONO SICURA SE SEMPLICEMENTE SALVA SULLA FINESTRA
    void saveToFile();
    QPushButton *saveButton;

    void AddressBook::saveToFile()
    {
        QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Address Book"), "",
            tr("Address Book (*.abk);;All Files (*)"));
        if (fileName.isEmpty())
            return;
        else {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << contacts;
        }
    }
    */

    file->addAction(new QAction("Save as...", file)); //4

    /*   SAVE AS PDF
    #include <QApplication>
    #include <QtCore>
    #include <QPrinter>
    #include <QPdfWriter>
    #include <QPainter>

    void pdf(QString filename)
    {
        QPdfWriter writer(filename);
        writer.setPageSize(QPagedPaintDevice::A4);
        writer.setPageMargins(QMargins(30, 30, 30, 30));

        QPainter painter(&writer);
        painter.setPen(Qt::black);
        painter.setFont(QFont("Times", 10));

        QRect r = painter.viewport();

        painter.drawText(r, Qt::AlignLeft, sender);
        painter.end();
    }
    */

    file->addAction(new QAction("Export", file)); //5
    file->addSeparator();                         //6
    file->addAction(new QAction("Exit", file));   //7

    //! edit
    /*QMenu *edit = new QMenu("Edit", menuBar); //da decidere cosa metterci dopo che abbiamo fatto apparire i grafici
    menuBar->addMenu(edit);*/

    //! view
    view = new QMenu("View", menuBar);
    menuBar->addMenu(view);
    view->addAction(new QAction("Zoom in", view));
    view->addAction(new QAction("Zoom out", view));
    view->addSeparator();
    view->addAction(new QAction("Logarithmic scale", view)); // vorrei una checkbox

    //! help
    help = new QMenu("Help", menuBar);
    menuBar->addMenu(help);
    help->addAction(new QAction("About", help));

    help->addAction(new QAction("Contacts", help));

    //!--------------------------------------------------TABLE

    Model *model = new Model;
    QTableView *tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();
    tableView->setGeometry(0, 30, 300, 300); //per ora sono obbligato a mettere un misura fissa
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    mainLayout->addWidget(tableView);

    setLayout(mainLayout);
}

void MainWindow::setController(Controller *_controller)
{
    controller = _controller;
    std::string path = "-----------------------------aaaaaaaaaaaaaaaaaa";
    connect(file->actions()[0], SIGNAL(triggered()), controller, SLOT(open()));
    connect(file->actions()[1], SIGNAL(triggered()), this, SLOT(openFile()));
    //2 è un separator
    connect(file->actions()[3], SIGNAL(triggered()), controller, SLOT(open("---------------------------open4----------------------------")));
    connect(file->actions()[4], SIGNAL(triggered()), controller, SLOT(open("---------------------------open4----------------------------")));
    connect(file->actions()[5], SIGNAL(triggered()), controller, SLOT(open("---------------------------open2----------------------------")));
    //6 è un separator
    connect(file->actions()[7], SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open json graph file"), "",
                                                tr("Json file (*.json);;All Files (*)"));
    controller->open(/*path.toStdString()*/);
}

void MainWindow::about()
{
    QPushButton *pb = new QPushButton("About", this);
    connect(pb, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    setCentralWidget(pb);
    aboutwindow *m_aboutwindow = new aboutwindow();
    connect(m_aboutwindow, SIGNAL(closing()), this, SLOT(show()));
}

void MainWindow::contacts()
{
    QPushButton *pb = new QPushButton("Contacts", this);
    connect(pb, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    setCentralWidget(pb);
    contactswindow *m_contactswindow = new contactswindow();
    connect(m_contactswindow, SIGNAL(closing()), this, SLOT(show()));
    /*
     Developers:

     Stecca Andrea
     Email: andrea.stecca@studenti.unipd.it
     Student in Computer Science at the University of Padua

     Dentone Giulia
     Email: giuliadentone@studenti.unipd.it
     Student in  Computer Science at the University of Padua
    */
}
