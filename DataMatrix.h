#ifndef DATAMATRIX_H
#define DATAMATRIX_H

class DataMatrix
{
private:
    double *data;              //pointer to an two dimensions array
    unsigned int rowNumber;    //number of rows
    unsigned int columnNumber; //number of columns

public:
    DataMatrix(double *data, unsigned int rowNumber, unsigned int columnNumber = 1);
    ~DataMatrix();

    /**
     * @brief adds a row in n poition
     * 
     * @param a pointer to the array to add
     * @param n number of the column to replace
     */
    void addRow(double *a, unsigned int n = 0);

    /**
     * @brief adds a column in n position
     * 
     * @param a pointer to the array to add
     * @param n number of the row to replace
     */
    void addColumn(double *a, unsigned int n = 0);

    /**
     * @brief deletes the row in k index
     * 
     * @param k index of row to remove
     */
    void deleteRow(unsigned int k);

    /**
     * @brief deletes the column in h index
     * 
     * @param h index of column to remove
     */
    void deleteColumn(unsigned int h);
};

#endif