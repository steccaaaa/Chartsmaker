#include "controller.h"

Controller::Controller(QObject *parent) : QObject{parent} {}

void Controller::setModel(Model *_model) { model = _model; }
void Controller::setMainWindow(MainWindow *_mainwindow) { mainwindow = _mainwindow; }

void Controller::open() const
{
    QString path = QFileDialog::getOpenFileName(mainwindow,
                                                tr("Open json graph file"), "",
                                                tr("Json file (*.json);;All Files (*)"));
    model->readJson(path.toStdString());
    mainwindow->setTableView();
    if(mainwindow->getChart()){ mainwindow->drawChart(mainwindow->getChart()); }
}

Model *Controller::getModel() const { return model; }

void Controller::newChart() const
{
    QString rowLabel = QInputDialog::getText(mainwindow, "Insert", "Row label:", QLineEdit::Normal);
    QString columnLabel = QInputDialog::getText(mainwindow, "Insert", "Column label:", QLineEdit::Normal);
    model->newModel(rowLabel.toStdString(), columnLabel.toStdString());
    mainwindow->setTableView();
    if(mainwindow->getChart()){ mainwindow->drawChart(mainwindow->getChart()); }
};

void Controller::saveAsPdf() const
{
    auto chart = mainwindow->getChartView();
    QPrinter printer(QPrinter::HighResolution);
    QString path = QFileDialog::getSaveFileName(mainwindow,
                                                tr("Pdf file"), "",
                                                tr("Pdf file (*.pdf)"));
    printer.setOutputFileName(path);
    printer.setPageMargins(QMarginsF(0, 0, 0, 0));

    QPainter painter;
    painter.begin(&printer);
    double xscale = printer.pageLayout().fullRectPixels(printer.resolution()).width() / double(chart->width());
    double yscale = printer.pageLayout().fullRectPixels(printer.resolution()).height() / double(chart->height());
    double scale = qMin(xscale, yscale);
    painter.scale(scale, scale);

    chart->render(&painter);
}

void Controller::saveAsImage() const
{
    QWidget *widget = mainwindow->getChartView();
    QPixmap pic = widget->grab(QRect(QPoint(10, 10), QSize(widget->width(), widget->height())));
    widget->render(&pic);
    QString path = QFileDialog::getSaveFileName(mainwindow,
                                                tr("Png image"), "",
                                                tr("Png image (*.png)"));
    pic.save(path);
}

void Controller::save() const
{
    QString path = QFileDialog::getSaveFileName(mainwindow,
                                                tr("Json graph file"), "",
                                                tr("Json file (*.json);;All Files (*)"));
    model->writeJson(path.toStdString());
};

void Controller::addColumnB()
{
    QString label = QInputDialog::getText(mainwindow, "Insert", "Column label:", QLineEdit::Normal);
    if (!label.isEmpty())
    {
        model->insertColumn(mainwindow->getSelectedColumn(), label.toStdString());
        mainwindow->setTableView();
        if(mainwindow->getChart()){ mainwindow->drawChart(mainwindow->getChart()); }
    }
};

void Controller::addColumnA()
{
    QString label = QInputDialog::getText(mainwindow, "Insert", "Column label:", QLineEdit::Normal);
    if (!label.isEmpty())
    {
        model->insertColumn(mainwindow->getSelectedColumn() + 1, label.toStdString());
        mainwindow->setTableView();
        if(mainwindow->getChart()){ mainwindow->drawChart(mainwindow->getChart()); }
    }
};

void Controller::addRowB()
{
    QString label = QInputDialog::getText(mainwindow, "Insert", "Row label:", QLineEdit::Normal);
    if (!label.isEmpty())
    {
        model->insertRow(mainwindow->getSelectedRow(), label.toStdString());
        mainwindow->setTableView();
        if(mainwindow->getChart()){ mainwindow->drawChart(mainwindow->getChart()); }
    }
}

void Controller::addRowA()
{
    QString label = QInputDialog::getText(mainwindow, "Insert", "Row label:", QLineEdit::Normal);
    if (!label.isEmpty())
    {
        model->insertRow(mainwindow->getSelectedRow() + 1, label.toStdString());
        mainwindow->setTableView();
        if(mainwindow->getChart()){ mainwindow->drawChart(mainwindow->getChart()); }
    }
}

void Controller::removeColumn()
{
    model->removeColumn(mainwindow->getSelectedColumn());
    mainwindow->setTableView();
    if(mainwindow->getChart()){ mainwindow->drawChart(mainwindow->getChart()); }
}

void Controller::removeRow()
{
    model->removeRow(mainwindow->getSelectedRow());
    mainwindow->setTableView();
    if(mainwindow->getChart()){ mainwindow->drawChart(mainwindow->getChart()); }
}

void Controller::init()
{
    mainwindow->setTableView();
    mainwindow->show();

    new InitWindow(this);
}
