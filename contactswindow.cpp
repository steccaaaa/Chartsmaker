#include "contactswindow.h"
#include <QLabel>
#include <QVBoxLayout>

contactswindow::contactswindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Developers", this);
    QLabel *label2 = new QLabel("Dentone Giulia", this);
    QLabel *label3 = new QLabel("Email: giulia.dentone@studenti.unipd.it", this);
    QLabel *label4 = new QLabel("Student in Computer Science at the University of Padua", this);

    QLabel *label5 = new QLabel("Stecca Andrea", this);
    QLabel *label6 = new QLabel("Email: andrea.stecca.1@studenti.unipd.it", this);
    QLabel *label7 = new QLabel("Student in Computer Science at the University of Padua", this);

    layout->addWidget(label);
    layout->addWidget(label2);
    layout->addWidget(label3);
    layout->addWidget(label4);
    layout->addWidget(label5);
    layout->addWidget(label6);
    layout->addWidget(label7);
}

contactswindow::~contactswindow() {}

void contactswindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
