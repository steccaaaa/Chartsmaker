#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QCloseEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QFont>
#include <QLabel>
#include <QHBoxLayout>
#include <QScrollArea>

class aboutwindow : public QWidget
{
    Q_OBJECT
public:
    explicit aboutwindow(QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent *event);
signals:
    void closing();
};

#endif
