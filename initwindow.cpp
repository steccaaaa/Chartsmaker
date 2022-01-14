#include "initwindow.h"
#include "controller.h" //! non toccare

InitWindow::InitWindow(Controller *controller, QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QPushButton *buttonN = new QPushButton("&New", this);
    QPushButton *buttonO = new QPushButton("&Open", this);
    layout->addWidget(buttonN);
    layout->addWidget(buttonO);

    resize(400, 500);
    setWindowTitle("Start");

    //centra la finestra
    QRect screenSize = QApplication::desktop()->screenGeometry();
    const QRect wr({}, frameSize().boundedTo(screenSize.size()));
    move(screenSize.center() - wr.center());

    connect(buttonN, SIGNAL(clicked()), this, SLOT(close()));
    connect(buttonN, SIGNAL(clicked()), controller, SLOT(newChart()));
    connect(buttonO, SIGNAL(clicked()), this, SLOT(close()));
    connect(buttonO, SIGNAL(clicked()), controller, SLOT(open()));

    setWindowModality(Qt::ApplicationModal);

    show();
}

//void InitWindow::setController(Controller *_controller) { controller = _controller; }

void InitWindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
