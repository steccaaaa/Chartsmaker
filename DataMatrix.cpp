#include "DataMatrix.h"

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
    print(*vec);
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

    rowLabel = new auto(_rowLabel);
    columnLabel = new auto(_columnLabel);
    print(rowLabel);
    print(columnLabel);
}

DataMatrix::DataMatrix(const DataMatrix &_table) : data(new std::vector<std::vector<double>>(*_table.getData())), rowLabel(new std::vector<string>(*_table.getRowLabel())), columnLabel(new std::vector<string>(*_table.getColumnLabel()))
{
}

void DataMatrix::addRow(vector<double> &v, unsigned int position, string label)
{
    if (data->size() < position)
    {
        std::cerr << "invalid position to add a row\n";
        return;
    }
    data->insert(data->begin() + position, v);
    print(data); //! debug
    rowLabel->insert(rowLabel->begin() + position, label);
}

void DataMatrix::deleteRow(unsigned int position)
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

void DataMatrix::addColumn(vector<double> &v, unsigned int position, string label)
{
    if (data[0].size() < position)
    {
        std::cerr << "invalid position to add a column\n";
        return;
    }
    for (vector<vector<double>>::iterator it = data->begin(); it != data->end(); ++it)
        it->insert(it->begin() + position, v[it - data->begin()]);

    columnLabel->insert(columnLabel->begin() + position, label);
}

void DataMatrix::deleteColumn(unsigned int position)
{
    if (data[0].size() < position)
    {
        std::cerr << "invalid position to delete a column\n";
        return;
    }
    for (vector<vector<double>>::iterator it = data->begin(); it != data->end(); ++it)
        it->erase(it->begin() + position);

    columnLabel->erase(columnLabel->begin() + position);
}

//* GETTERS

std::vector<double> *DataMatrix::getColumnData(unsigned int n)
{
    std::vector<double> *datavector = new std::vector<double>;
    for (unsigned int i = 0; i < data->size(); ++i)
    {
        datavector->push_back(data->at(i).at(n));
    }
    return datavector;
}

std::vector<double> *DataMatrix::getRowData(unsigned int n) { return &data->at(n); }

std::vector<string> *DataMatrix::getRowLabel() const { return rowLabel; }

std::vector<string> *DataMatrix::getColumnLabel() const { return columnLabel; }

std::vector<std::vector<double>> *DataMatrix::getData() const { return data; }

unsigned int DataMatrix::getRowCount() const { return data->size(); }

unsigned int DataMatrix::getColumnCount() const { return data->at(0).size(); };


//* OPERATORS

DataMatrix::~DataMatrix()
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
}

DataMatrix &DataMatrix::operator=(const DataMatrix &table)
{
    data = new auto(*table.getData());
    rowLabel = new auto(*table.getRowLabel());
    columnLabel = new auto(*table.getColumnLabel());

    return *this;
}


//* PARSE

void DataMatrix::read(std::string path)
{
    QFile file(QString::fromStdString(path));
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

    for (long unsigned int i = 0; i < data->size(); ++i)
    {
        data[i].clear();
        data[i].shrink_to_fit();
    }
    data->clear();
    rowLabel->clear();
    columnLabel->clear();

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

    data->shrink_to_fit();
    rowLabel->shrink_to_fit();
    columnLabel->shrink_to_fit();
    print(rowLabel);
    print(columnLabel);
    print(data);
}


void DataMatrix::write(std::string path) const
{
    QFile file(QString::fromStdString(path));
    if (!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "File open error";
    }
    else
    {
        qDebug() << "File open!";
    }

    file.resize(0);

    QJsonObject recordObject;

    QJsonArray _rowLabel;
    for (unsigned int i = 0; i < rowLabel->size(); i++)
        _rowLabel.push_back(QString::fromStdString(rowLabel->at(i)));

    QJsonArray _columnLabel;
    for (unsigned int i = 0; i < columnLabel->size(); i++)
        _columnLabel.push_back(QString::fromStdString(columnLabel->at(i)));

    QJsonArray _data;
    QJsonArray dataRow;
    for (unsigned int i = 0; i < data->size(); i++)
    {
        for (unsigned int j = 0; j < data->at(i).size(); j++)
            dataRow.push_back(data->at(i).at(j));
        _data.push_back(dataRow);
        while (dataRow.count())
            dataRow.pop_back();
    }

    recordObject.insert("data", _data);
    recordObject.insert("rowLabel", _rowLabel);
    recordObject.insert("columnLabel", _columnLabel);
    QJsonDocument doc(recordObject);
    file.write(doc.toJson());
    file.close();
    qDebug() << "Write to file";
}
