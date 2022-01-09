#include "aboutwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QFont>
#include <QLabel>

aboutwindow::aboutwindow(QWidget *parent) : QWidget(parent)
{
    QFont f("Helvetica", 20, QFont::SansSerif);
    QFont g("Helvetica", 12, QFont::SansSerif);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("User manual:", this);
    layout->addWidget(label);
    label->setFont(f);
    QLabel *label2 = new QLabel("ChartMaker allows you to have fun creating the charts you like the most.", this);
    layout->addWidget(label2);
    label2->setFont(g);
    QLabel *label3 = new QLabel("○ All you need to do is opening a Json file with your elaborated data by clicking on FILE->OPEN and searching in your computer.", this);
    layout->addWidget(label3);
    label3->setFont(g);
    QLabel *label4 = new QLabel("○ If you want to create new charts you need to click on FILE->NEW CHART and choose the one you want to display", this);
    layout->addWidget(label4);
    label4->setFont(g);
    QLabel *label5 = new QLabel("○ The available charts at the moment are Pie Charts, Donut Charts, Bar Charts, Line Charts and Spline Charts.", this);
    layout->addWidget(label5);
    label5->setFont(g);

    QPixmap image(":/images/Q15.png");
    image = image.scaled(300, 300, Qt::KeepAspectRatio);
    QLabel *imageLabel = new QLabel();
    imageLabel->setPixmap(image);
    layout->addWidget(imageLabel);

    QPixmap image2(":/images/Q15.png");
    image2 = image2.scaled(300, 300, Qt::KeepAspectRatio);
    QLabel *imageLabel2 = new QLabel();
    imageLabel->setPixmap(image2);
    layout->addWidget(imageLabel2);

    QPixmap image3(":/images/Q15.png");
    image3 = image3.scaled(300, 300, Qt::KeepAspectRatio);
    QLabel *imageLabel3 = new QLabel();
    imageLabel->setPixmap(image3);
    layout->addWidget(imageLabel3);

    QPixmap image4(":/images/Q15.png");
    image4 = image4.scaled(300, 300, Qt::KeepAspectRatio);
    QLabel *imageLabel4 = new QLabel();
    imageLabel->setPixmap(image4);
    layout->addWidget(imageLabel4);

    QPixmap image5(":/images/Q15.png");
    image5 = image5.scaled(300, 300, Qt::KeepAspectRatio);
    QLabel *imageLabel5 = new QLabel();
    imageLabel->setPixmap(image5);
    layout->addWidget(imageLabel5);

    QLabel *label6 = new QLabel("    However, we suggest you to stay tuned for any upgrades!", this);
    layout->addWidget(label6);
    label6->setFont(g);
    QLabel *label7 = new QLabel("○ By clicking on FILE->OPEN you can give the .json file that you want to analyze in input.", this);
    layout->addWidget(label7);
    label7->setFont(g);
    QLabel *label8 = new QLabel("    Pay attention: the data must be already elaborated. This means that the program will not for example sum data if they are from the same istance.", this);
    layout->addWidget(label8);
    label8->setFont(g);
    QLabel *label9 = new QLabel("    To clarify, here's an image:", this);
    layout->addWidget(label9);
    label9->setFont(g);

    QPixmap image6(":/images/Q15.png");
    image5 = image6.scaled(200, 200, Qt::KeepAspectRatio);
    QLabel *imageLabel6 = new QLabel();
    imageLabel->setPixmap(image6);
    layout->addWidget(imageLabel6);

    QLabel *label10 = new QLabel("○ If you want to save your data you can click FILE->SAVE and by choosing were to save on your computer and choosing a name the program will create a new .json file with your data.", this);
    layout->addWidget(label10);
    label10->setFont(g);
    QLabel *label11 = new QLabel("○ Moreover, if you need to save the chart you can click on FILE->SAVE AS PNG and by choosing were to save on your computer and choosing a name you will have a useful image of your chart.", this);
    layout->addWidget(label11);
    label11->setFont(g);
    QLabel *label12 = new QLabel("○ By clicking on FILE->SAVE AS PDF and doing the same process explained above you obtain a .pdf file.", this);
    layout->addWidget(label12);
    label12->setFont(g);
    QLabel *label13 = new QLabel("   If you have troubles saving you can try to write .png or .pdf manually at the end of the file name you chose.", this);
    layout->addWidget(label13);
    label13->setFont(g);
    QLabel *label14 = new QLabel("○ To close the application all you need to do is click on FILE->EXIT and the window will close.", this);
    layout->addWidget(label14);
    label14->setFont(g);
    QLabel *label15 = new QLabel("If you have any doubts please contact us in one of the emails you can find on HELP->CONTACTS, we will be pleased to answer.", this);
    layout->addWidget(label15);
    label15->setFont(g);

    QPalette pale = qApp->palette();
    pale.setColor(QPalette::Window, QRgb(0xFFFFFFF));
    qApp->setPalette(pale);
}

aboutwindow::~aboutwindow() {}

void aboutwindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
