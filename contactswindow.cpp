#include "contactswindow.h"
#include <QLabel>
#include <QVBoxLayout>

contactswindow::contactswindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *l = new QLabel("About", this);
    layout->addWidget(l);

    QLabel *label = new QLabel(this);
    label->setText("Developers");
    QLabel *label2 = new QLabel(this);
    label2->setText("Stecca Andrea");
    QLabel *label3 = new QLabel(this);
    label3->setText("Email: andrea.stecca@studenti.unipd.it");
    QLabel *label4 = new QLabel(this);
    label4->setText("Student in Computer Science at the University of Padua");
    QLabel *label5 = new QLabel(this);
    label5->setText("Dentone Giulia");
    QLabel *label6 = new QLabel(this);
    label6->setText("Email: giuliadentone@studenti.unipd.it");
    QLabel *label7 = new QLabel(this);
    label7->setText("Student in  Computer Science at the University of Padua");
}

contactswindow::~contactswindow() {}

void contactswindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
