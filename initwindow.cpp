#include "initwindow.h"
#include "controller.h"

InitWindow::InitWindow(Controller *controller, QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QPushButton *buttonN = new QPushButton("&New", this);
    QPushButton *buttonO = new QPushButton("&Open", this);
    layout->addWidget(buttonN);
    layout->addWidget(buttonO);

    resize(350, 250);
    setWindowTitle("Start");

    QRect screenSize = QApplication::desktop()->screenGeometry();
    const QRect wr({}, frameSize().boundedTo(screenSize.size()));
    move(screenSize.center() - wr.center());

    connect(buttonN, SIGNAL(clicked()), this, SLOT(close()));
    connect(buttonN, SIGNAL(clicked()), controller, SLOT(newChart()));
    connect(buttonO, SIGNAL(clicked()), this, SLOT(close()));
    connect(buttonO, SIGNAL(clicked()), controller, SLOT(open()));

    setWindowModality(Qt::ApplicationModal);

    buttonN->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
    "stop: 0 lightblue, stop: 1 lightblue);"
    "border-style: solid;"
    "padding: 35px;"
    "border-color: lightblue;"
    "border-width: 2px;"
    "border-radius: 20px;}"));

    buttonO->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
    "stop: 0 lightblue, stop: 1 lightblue);"
    "border-style: solid;"
    "padding: 35px;"
    "border-color: lightblue;"
    "border-width: 2px;"
    "border-radius: 20px;}"));

    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);

    show();
}

void InitWindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
