/*#include "mainwindow.h"

#include <QApplication>*/
#include "DataMatrix.h"
#include <vector>
#include <iostream>

void print(std::vector<std::vector<double>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j];
        }
    }
}

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
    ////
    std::vector<std::vector<double>> mat{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<std::string> mats{"a", "b", "c"};
    DataMatrix x = DataMatrix(&mat);
    std::cout << x[0][0];
    //print(x.getData());
}
