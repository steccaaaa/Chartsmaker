#include "contactswindow.h"

contactswindow::contactswindow(QWidget *parent) : QWidget(parent)
{
    QFont f( "Helvetica", 20, QFont::Bold);
    QFont g( "Helvetica", 12);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Developers:", this);
    label->setFont(f);
    QLabel *label2 = new QLabel("○ Dentone Giulia", this);
    label2->setFont(g);
    QLabel *label3 = new QLabel("<a href=\"mailto:giulia.dentone@studenti.unipd.it\">giulia.dentone@studenti.unipd.it</a>", this);
    label3->setFont(g);
    QLabel *label4 = new QLabel("Computer Science Student at the University of Padua", this);
    label4->setFont(g);

    QLabel *label5 = new QLabel("○ Stecca Andrea", this);
    label5->setFont(g);
    QLabel *label6 = new QLabel("<a href=\"mailto:andrea.stecca.1@studenti.unipd.it\">andrea.stecca.1@studenti.unipd.it</a>", this);
    label6->setFont(g);
    QLabel *label7 = new QLabel("Computer Science Student at the University of Padua", this);
    label7->setFont(g);

    label3->setTextFormat(Qt::RichText);
    label3->setTextInteractionFlags(Qt::TextBrowserInteraction);
    label3->setOpenExternalLinks(true);

    label6->setTextFormat(Qt::RichText);
    label6->setTextInteractionFlags(Qt::TextBrowserInteraction);
    label6->setOpenExternalLinks(true);


    layout->addWidget(label);
    layout->addSpacing(15);
    layout->addWidget(label2);
    layout->addWidget(label3);
    layout->addWidget(label4);
    layout->addSpacing(15);
    layout->addWidget(label5);
    layout->addWidget(label6);
    layout->addWidget(label7);

    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);
}

void contactswindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
