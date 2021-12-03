#ifndef DATAMATRIX_H
#define DATAMATRIX_H

class DataMatrix
{
private:
    double *data;

public:
    DataMatrix(/* args */);
    ~DataMatrix();
};

DataMatrix::DataMatrix(/* args */)
{
}

DataMatrix::~DataMatrix()
{
}

void addRow(&);
void addColumn(&);
void deleteRow(unsigned int);
void deleteColumn(unsigned int);

#endif