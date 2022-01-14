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
    QScreen *screen = QWidget::screen();
    const QRect sr = screen->availableGeometry();
    const QRect wr({}, frameSize().boundedTo(sr.size()));
    move(sr.center() - wr.center());

    connect(buttonN, SIGNAL(clicked()), this, SLOT(close()));
    connect(buttonN, SIGNAL(clicked()), controller, SLOT(newChart()));
    connect(buttonO, SIGNAL(clicked()), this, SLOT(close()));
    connect(buttonO, SIGNAL(clicked()), controller, SLOT(open()));

    show();
}

//void InitWindow::setController(Controller *_controller) { controller = _controller; }

void InitWindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
