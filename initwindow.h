#ifndef INITWINDOW_H
#define INITWINDOW_H

#include <QObject>
#include <QWidget>
#include <QCloseEvent>
#include <QVBoxLayout>
#include <QPushButton>

class Controller;

class InitWindow : public QWidget
{
    Q_OBJECT
public:
    explicit InitWindow(Controller *controller, QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent *event);
signals:
    void closing();

};

#endif // INITWINDOW_H
