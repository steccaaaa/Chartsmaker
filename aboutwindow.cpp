#include "aboutwindow.h"

aboutwindow::aboutwindow(QWidget *parent) : QWidget(parent)
{
    QFont f("Helvetica", 20, QFont::Bold);
    QFont g("Helvetica", 12);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("User manual:", this);
    layout->addWidget(label);
    label->setFont(f);
    QLabel *label2 = new QLabel("ChartMaker allows you to have fun creating the charts you like the most.", this);
    layout->addWidget(label2);
    label2->setFont(g);
    QLabel *label3 = new QLabel("○ When you open the application you will se a window in which you can choose either to create a new table of data directly on the application or to open a Json file with the data.", this);
    layout->addWidget(label3);
    label3->setFont(g);
    QLabel *label4 = new QLabel("○ If you want to create new charts you need to click VIEW and choose the one you want to display", this);
    layout->addWidget(label4);
    label4->setFont(g);
    QLabel *label5 = new QLabel("○ The available charts at the moment are Pie Charts, Donut Charts, Bar Charts, Stacked Bar Charts, Horizontal Bar Charts, Horizontal Stacked Bar Charts, Percent Bar Charts, Horizontal Percent Bar Charts, Line Charts, Spline Charts and Scatter Charts.", this);
    layout->addWidget(label5);
    label5->setFont(g);

    QHBoxLayout *layout2 = new QHBoxLayout();
    layout->addLayout(layout2);

    QLabel *label6 = new QLabel("    However, we suggest you to stay tuned for any upgrades!", this);
    layout->addWidget(label6);
    label6->setFont(g);
    QLabel *label7 = new QLabel("○ By clicking on FILE->OPEN you can give the .json file that you want to analyze in input.", this);
    layout->addWidget(label7);
    label7->setFont(g);
    QLabel *label8 = new QLabel("    Pay attention: the data must be already elaborated. This means that the program will not for example sum data if they are from the same instance.", this);
    layout->addWidget(label8);
    label8->setFont(g);
    QLabel *label22 = new QLabel("    We also want to warn you that Pie Charts and Donut Charts will consider only the first column of the data table.", this);
    layout->addWidget(label22);
    label22->setFont(g);
    QLabel *label9 = new QLabel("    To clarify, here's an image:", this);
    layout->addWidget(label9);
    label9->setFont(g);

    QPixmap image8(":/images/explphoto.png");
    image8 = image8.scaled(350, 350, Qt::KeepAspectRatio);
    QLabel *imageLabel8 = new QLabel();
    imageLabel8->setPixmap(image8);
    layout->addWidget(imageLabel8);

    QLabel *label20 = new QLabel("○ It is possible to modify the data directly on the table by double clicking on the desired cell and changing the data. By pressing enter on your keyboard the chart will automatically refresh itself.", this);
    layout->addWidget(label20);
    label20->setFont(g);
    QLabel *label21 = new QLabel("○ To add or delete row and columns on the table you have to select the cell and then go to EDIT. The chart will automatically.", this);
    layout->addWidget(label21);
    label21->setFont(g);
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

void aboutwindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    event->accept();
}
