#include "DataMatrix.h"

void DataMatrix::deleteRow(unsigned int k)
{
    double *newData = new double[(rowNumber - 1) * columnNumber]; //new empty array with one less row allocated in the heap

    for (unsigned int i = 0; i < columnNumber; ++i) //to scan the matrix
    {
        for (unsigned int j = 0; j < rowNumber; ++j)
        {
            if (j != k) //if my row selector is not equal to the row the user wants to delete i have to copy data on the new array
            {
                newData[] = data[]; //fills the nwe array with old the data besides the ones in the index k row
            }
        }
    }
    delete[] data;  //delete the content of the old array
    data = newData; //now the data pointer points to the new array created in the function without a row
    rowNumber--;    //decrement rowNumber
}

// 1 2 3 4 5 6 7 8 9 10 11 12

// 00 01 02 03
// 10 11 12 13
// 20 21 22 23

void DataMatrix::deleteColumn(unsigned int h)
{
    double *newData = new double[rowNumber * (columnNumber - 1)]; //new empty array without a column in the heap

    for (unsigned int i = 0; i < rowNumber; ++i) //scan the array/matrix
    {
        for (unsigned int j = 0; j < columnNumber; ++j)
        {
            //fills new array with the old data without the deleted column
            if (j < h)
                newData[i * j] = data[i * j];
            else if (j > h)
                newData[i * (j - 1)] = data[i * j];
        }
    }
    delete[] data;  //deletes old array
    data = newData; //replaces the data address with the newer one
    columnNumber--; //decrement columnNumber
}

DataMatrix DataMatrix::addRow(double *a, unsigned int k)
{
}

DataMatrix DataMatrix::addColumn(double *a, unsigned int h)
{
}
