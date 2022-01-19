#ifndef CONTACTSWINDOW_H
#define CONTACTSWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QCloseEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QFont>

class contactswindow : public QWidget
{
    Q_OBJECT
public:
    explicit contactswindow(QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent *event);
signals:
    void closing();
};

#endif
