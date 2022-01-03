#include "aboutwindow.h"
#include <QLabel>
#include <QVBoxLayout>

aboutwindow::aboutwindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *l = new QLabel("About", this);
    layout->addWidget(l);

    QLabel *label = new QLabel(this);
    label->setText("Manuale d'uso: ......................");
    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
}

aboutwindow::~aboutwindow() {}

void aboutwindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
