#include "mainwindow.h"
#include "DataMatrix.h"
#include "model.h"
//#include "Charts.h"

#include <iostream> //! debug

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    //!--------------------------------------------------MENU
    QMenuBar *menuBar = new QMenuBar(this);

    //! file
    QMenu *file = new QMenu("File", menuBar); //cosa ci mettiamo? di solito dentro ci sono i save ma abbiamo dei tasti apposta quindi boh eviterei
    menuBar->addMenu(file);
    file->addAction(new QAction("New graph", file));
    file->addAction(new QAction("Open", file));

    /*
    void loadFromFile();
    QPushButton *loadButton;

    void AddressBook::loadFromFile()
    {
        QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Address Book"), "",
            tr("Address Book (*.abk);;All Files (*)"));
        if (fileName.isEmpty())
            return;
        else
        {
            QFile file(fileName);

            if (!file.open(QIODevice::ReadOnly))
            {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        contacts.clear();   // clear existing contacts
        in >> contacts;
        if (contacts.isEmpty())
        {
            QMessageBox::information(this, tr("No contacts in file"),
                tr("The file you are attempting to open contains no contacts."));
        }
        else
        {
             QMap<QString, QString>::iterator i = contacts.begin();
             nameLine->setText(i.key());
             addressText->setText(i.value());
        }
    }
    updateInterface(NavigationMode);
    }
    */

    file->addSeparator();
    file->addAction(new QAction("Save", file));

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

    file->addAction(new QAction("Save as...", file));

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

    file->addAction(new QAction("Export", file)); //caghiamo fuori secondo me, abbiamo già salva e salva come pdf
    file->addSeparator();
    file->addAction(new QAction("Exit", file));

    /*   EXIT THE WINDOW
    QPushButton *quitButton = new QPushButton("Quit");
    connect(quitButton, &QPushButton::clicked, &app, &QCoreApplication::quit, Qt::QueuedConnection);
    */

    //! edit
    QMenu *edit = new QMenu("Edit", menuBar); //da decidere cosa metterci dopo che abbiamo fatto apparire i grafici
    menuBar->addMenu(edit);

    //! view
    QMenu *view = new QMenu("View", menuBar);
    menuBar->addMenu(view);
    view->addAction(new QAction("Zoom in", view));
    view->addAction(new QAction("Zoom out", view));
    view->addSeparator();
    view->addAction(new QAction("Logarithmic scale", view)); // vorrei una checkbox

    //! help
    QMenu *help = new QMenu("Help", menuBar); //EVITEREI, Cosa CI METTIAMO? METTIAMO TIPO UN MANUALE DI UTILIZZO SU ABOUT PIUTTOSTO?
    menuBar->addMenu(help);
    help->addAction(new QAction("About", help));
    /*
     MANUAL OF USE:
    */
    help->addAction(new QAction("Contacts", help));
    /*
     Developers:

     Andrea Stecca
     Email: ..........
     Student in Computer Science at University of Padua

     Giulia Dentone
     Email: .........
     Student in  Computer Science at University of Padua

    */

    //!--------------------------------------------------TABLE

    Model *model = new Model;
    QTableView *tableView = new QTableView(this);
    auto x = model->table.getData();
    tableView->setModel(model);
    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();
    tableView->setGeometry(0, 0, 300, 300); //per ora sono obbligato a mettere un misura fissa
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

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
