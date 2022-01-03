#include "contactswindow.h"
#include <iostream>

contactswindow::contactswindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *l = new QLabel("About", this);
    layout->addWidget(l);

    QLabel *label = new QLabel(this);
    label->setText(" Developers:

     Stecca Andrea
     Email: andrea.stecca@studenti.unipd.it
     Student in Computer Science at the University of Padua

     Dentone Giulia
     Email: giuliadentone@studenti.unipd.it
     Student in  Computer Science at the University of Padua");

    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
}

contactswindow::~contactswindow() {}

void contactswindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}