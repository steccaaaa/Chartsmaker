#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QCloseEvent>

class aboutwindow : public QWidget
{
    Q_OBJECT
public:
    explicit aboutwindow(QWidget *parent = nullptr);
    ~aboutwindow();

protected:
    void closeEvent(QCloseEvent *event);
signals:
    void closing();
};

#endif