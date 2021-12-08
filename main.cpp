#include <QApplication>
#include "DataMatrix.h"
#include <vector>
#include <iostream>

/*void print(std::vector<std::vector<double>> *vec) //! debug
{
    for (int i = 0; i < vec->size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}*/

int main(int argc, char *argv[])
{
    std::vector<std::vector<double>> mat{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<std::string> mats{"a", "b", "c"};
    //DataMatrix x = DataMatrix(mat, mats, mats);
    DataMatrix x(mat, mats, mats);
    std::vector<double> mario{1, 3, 7};
    x.addRow(mario, 2);
}
