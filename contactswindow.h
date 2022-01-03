#ifndef CONTACTSWINDOW_H
#define CONTACTSWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QCloseEvent>

class contacstwindow : public QWidget
{
    Q_OBJECT
public:
    explicit contactswindow(QWidget *parent = nullptr);
    ~contactswindow();

protected:
    void closeEvent(QCloseEvent *event);
signals:
    void closing();
};

#endif