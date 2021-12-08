#include "DataMatrix.h"
#include <vector>
#include <iostream> //! da togliere

void print(std::vector<std::vector<double>> &vec) //! debug
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

using std::vector;

DataMatrix::DataMatrix(vector<vector<double>> &_data, vector<std::string> &_rowLabel, vector<std::string> &_columnLabel) //Costructor for DataMatrix
{
    //vector<vector<double>> *data = new vector<vector<double>>; //our DataMatrix is a vector of vectors
    /*for (unsigned int i = 0; i < _data->size(); i++)           //to insert values in the vector
        data[i] = _data[i];*/
    //data = _data;
    auto data(_data);
    print(data);
    auto rowLabel = _rowLabel;
    auto columnLabel = _columnLabel;
}

DataMatrix::DataMatrix(DataMatrix &_table) : data(_table.getData()), rowLabel(_table.getRowLabel()), columnLabel(_table.getColumnLabel()) {}

void DataMatrix::addRow(vector<double> &v, unsigned int position) //adds a row in the chosen poition
{
    //print(data); //! debug
    //data->insert(data->begin() + position, v);
    //print(data); //! debug
}

void DataMatrix::deleteRow(unsigned int position) //deletes the row in the chosen position
{
    if (position < data->size())
        data->erase(data->begin() + position);
}

void DataMatrix::addColumn(vector<double> &v, unsigned int position) //adds a column in the chosen position
{
    for (int i = 0; i < data->size(); ++i)
    {
        //data->insert(data[i].begin() + position, v[i]);
        //data[i].insert(position, v[i]);
    }
}

//! copiata di brutto non credo funzioni
void DataMatrix::deleteColumn(unsigned int position) //deletes the column in the chosen position
{
    /*for (vector<double> row : *data)
        if (position < row.size())
            row.erase(row.begin() + position);
    */
    for (int i = 0; i <= data->size(); ++i)
    {
        data->erase(data[i].begin() + position);
    }
}

//* GETTERS
std::vector<std::vector<double>> *DataMatrix::getData() //to get the data
{
    return data;
}

std::vector<std::string> *DataMatrix::getRowLabel()
{
    return rowLabel;
}

std::vector<std::string> *DataMatrix::getColumnLabel()
{
    return columnLabel;
}

DataMatrix::~DataMatrix() //deep destrucion of the vector
{
    /*for (int i = 0; i < data->size(); ++i)
    {
        data[i].clear();
        data[i].shrink_to_fit();
    } 
    data->clear();
    data->shrink_to_fit();*/
    /*
    data->clear();
    data->shrink_to_fit();*/

    /*for (std::vector<DataMatrix *>::iterator i = data->begin(), end = data->end(); i != end; ++i)
    {
        delete (*i);
    }*/
    std::cout << "delete";
}