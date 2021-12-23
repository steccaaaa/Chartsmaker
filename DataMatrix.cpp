#include "DataMatrix.h"
#include <vector>
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
using std::string;
using std::vector;

void print(vector<vector<double>> const &vec) //! debug
{
    for (long unsigned int i = 0; i < vec.size(); i++)
    {
        for (long unsigned int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void print(vector<vector<double>> const *vec) //! debug
{
    print(*vec); // usa l'altro print e magicamente va tutto
}

void print(vector<string> const &label)
{
    for (long unsigned int i = 0; i < label.size(); i++)
    {
        if (label[i] == "")
            std::cout << "❌ "; //! forse è meglio non usare emoji
        else
            std::cout << label[i] << " ";
    }
    std::cout << std::endl;
}

void print(vector<string> const *label)
{
    print(*label);
}

DataMatrix::DataMatrix(vector<vector<double>> &_data, vector<string> &_rowLabel, vector<string> &_columnLabel) // Costructor for DataMatrix
{
    data = new auto(_data);
    print(data); //! debug
    rowLabel = new auto(_rowLabel);
    //std::cout << "printing rowLabel \n";
    //print(rowLabel);
    columnLabel = new auto(_columnLabel);
    //std::cout << "printing columnLabel \n";
    //print(columnLabel);
}

DataMatrix::DataMatrix(DataMatrix &_table) : data(_table.getData()), rowLabel(_table.getRowLabel()), columnLabel(_table.getColumnLabel()) {}

void DataMatrix::addRow(vector<double> &v, unsigned int position, string label) // adds a row in the chosen poition
{
    if (data->size() < position)
    {
        std::cerr << "invalid position to add a row\n";
        return;
    }
    //*data
    //print(data); //! debug
    //std::cout << "adding a row \n";
    data->insert(data->begin() + position, v);
    print(data); //! debug

    //*label
    //print(rowLabel);
    rowLabel->insert(rowLabel->begin() + position, label);
    //print(rowLabel);
}

void DataMatrix::deleteRow(unsigned int position) // deletes the row in the chosen position
{
    if (data[0].size() < position)
    {
        std::cerr << "invalid position to delete a row\n";
        return;
    }
    data->erase(data->begin() + position);
    rowLabel->erase(rowLabel->begin() + position);
    print(data); //!debug
}

void DataMatrix::addColumn(vector<double> &v, unsigned int position, string label) // adds a column in the chosen position
{
    if (data[0].size() < position)
    {
        std::cerr << "invalid position to add a column\n";
        return;
    }
    //* data
    // non mi piacciono neanche un po' gli iterators
    for (vector<vector<double>>::iterator it = data->begin(); it != data->end(); ++it)
        it->insert(it->begin() + position, v[it - data->begin()]);

    //* label
    columnLabel->insert(columnLabel->begin() + position, label);

    print(data); //! debug
}

void DataMatrix::deleteColumn(unsigned int position) // deletes the column in the chosen position
{
    if (data[0].size() < position)
    {
        std::cerr << "invalid position to delete a column\n";
        return;
    }

    //* data
    // non mi piacciono neanche un po' gli iterators parte 2
    for (vector<vector<double>>::iterator it = data->begin(); it != data->end(); ++it)
        it->erase(it->begin() + position);

    //* labels
    columnLabel->erase(columnLabel->begin() + position);

    print(data); //! debug
}

//* GETTERS

std::vector<std::vector<double>> *DataMatrix::getData() { return data; }

std::vector<string> *DataMatrix::getRowLabel() { return rowLabel; }

std::vector<string> *DataMatrix::getColumnLabel() { return columnLabel; }

//* OPERATORS

DataMatrix::~DataMatrix() // deep destrucion of the vector
{
    for (long unsigned int i = 0; i < data->size(); ++i)
    {
        data[i].clear();
        data[i].shrink_to_fit();
    }
    data->clear();
    data->shrink_to_fit();
    delete data;

    rowLabel->clear();
    rowLabel->shrink_to_fit();
    delete rowLabel;

    columnLabel->clear();
    columnLabel->shrink_to_fit();
    delete columnLabel;

    std::cout << "deleted DataMatrix \n"; //!debug
}

//* PARSE

void DataMatrix::read()
{
    //apre il file
    QFile file("inputfile.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = file.readAll();
    file.close();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(val.toUtf8());
    //! debug
    std::cout
        << "empty: " << jsonDocument.isEmpty() << "\n"
        << "object: " << jsonDocument.isObject() << "\n"
        << "null: " << jsonDocument.isNull() << "\n";
    QJsonObject object = jsonDocument.object();

    QJsonArray _row = object.value("rowLabel").toArray();
    QJsonArray _column = object.value("columnLabel").toArray();
    QJsonArray _data = object.value("data").toArray();

    //controlli per non distruggere tutto
    if (_data.size() == 0)
    {
        std::cerr << "data can't be empty";
        return;
    }
    if (_row.size() != _data.size())
    {
        std::cerr << "rowLabel size is different from data rows\n";
        return;
    }
    if (_column.size() != _data[0].toArray().size())
    {
        std::cerr << "columnLabel size is different from data rows\n";
        return;
    }

    //nel caso sia valido si cancella tutto quello che c'era prima
    for (long unsigned int i = 0; i < data->size(); ++i)
    {
        data[i].clear();
        data[i].shrink_to_fit();
    }
    data->clear();
    rowLabel->clear();
    columnLabel->clear();

    //si riempie datamatrix
    for (int i = 0; i < _row.size(); ++i)
        rowLabel->push_back(_row[i].toString().toStdString());
    for (int i = 0; i < _column.size(); ++i)
        columnLabel->push_back(_column[i].toString().toStdString());

    data->resize(_data.size());
    for (int i = 0; i < _data.size(); ++i)
    {
        for (int j = 0; j < _data[i].toArray().size(); ++j)
            data->at(i).push_back(_data[i].toArray()[j].toDouble());
    }
    //per non sprecare memoria
    data->shrink_to_fit();
    rowLabel->shrink_to_fit();
    columnLabel->shrink_to_fit();
    print(rowLabel);
    print(columnLabel);
    print(data);
}

void DataMatrix::write() const
{
    std::cout << " ";
}