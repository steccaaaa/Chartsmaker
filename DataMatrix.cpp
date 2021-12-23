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
    QFile file("inputfile.json");
    //QFile file("/home/stecca/Chartmaker/inputfile.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //std::cout << file.readAll().toStdString();
    QString val = file.readAll();
    QJsonParseError *err = new QJsonParseError();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(val.toUtf8(), err);
    qWarning() << err->errorString() << err->offset;
    file.close();

    std::cout << "empty: " << jsonDocument.isEmpty() << "\n"
              << "object: " << jsonDocument.isObject() << "\n"
              << "null: " << jsonDocument.isNull();
    QJsonObject object = jsonDocument.object();

    QJsonArray row = object.value("rowLabel").toArray();
    std::cout << "\n\nsize: " << row.size() << "\n\n";

    for (int i = 0; i < row.size(); ++i)
        std::cout << row[i].toInt() << "a";
    /*for (auto it = row.begin(); it != row.end(); ++it)
        std::cout << it;*/
    /*foreach (const QJsonValue & v, row)
        qDebug() << v.toObject().value("ID").toInt();*/
}

void DataMatrix::write() const
{
    std::cout << " ";
}