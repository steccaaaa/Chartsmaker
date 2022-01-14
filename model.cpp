#include "model.h"
#include <QVariant>
#include <iostream>
using std::vector;

void print2(vector<vector<double>> const &vec) //! debug
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

void print2(vector<vector<double>> const *vec) //! debug
{
    print2(*vec);
}

Model::Model(QObject *parent) : QAbstractTableModel(parent)
{
    std::vector<std::vector<double>> mat{{1}};
    std::vector<std::string> matr{"a"};
    std::vector<std::string> matc{"x"};
    DataMatrix x(mat, matr, matc);
    table = x;
}

int Model::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return table.getRowCount();
}

int Model::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return table.getColumnCount();
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        qreal temp = table.getData()->at(index.row()).at(index.column());

        return temp;
    }
    return QVariant();
}

DataMatrix Model::getTable()
{
    return table;
}

void Model::readJson(std::string path)
{
    table.read(path);
}

void Model::writeJson(std::string path)
{
    table.write(path);
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (Qt::Orientation::Vertical == orientation)
        {
            if (table.getRowCount() > section)
                return QString::fromStdString(table.getRowLabel()->at(section));
        }
        else
        {
            if (table.getColumnCount() > section)
                return QString::fromStdString(table.getColumnLabel()->at(section));
        }
    }
    return QVariant();
}

Qt::ItemFlags Model::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
    {
        table.getData()->at(index.row()).at(index.column()) = value.toDouble();
        emit dataChanged(index, index);
    }
    return true;
}

void Model::insertRow(unsigned int i, std::string label)
{
    vector<double> v(table.getColumnCount(), 0);
    table.addRow(v, i, label);
}

void Model::insertColumn(unsigned int i, std::string label)
{
    vector<double> v(table.getRowCount(), 0);
    table.addColumn(v, i, label);
}

void Model::removeRow(unsigned int i) { table.deleteRow(i); }

void Model::removeColumn(unsigned int i) { table.deleteColumn(i); }

void Model::newModel(std::string rowLabel, std::string columnLabel)
{
    if(table.getData())
    {
        for (long unsigned int i = 0; i < table.getData()->size(); ++i)
        {
            table.getData()[i].clear();
            table.getData()[i].shrink_to_fit();
        }
        table.getData()->clear();
        table.getData()->shrink_to_fit();
        table.getRowLabel()->clear();
        table.getRowLabel()->shrink_to_fit();
        table.getColumnLabel()->clear();
        table.getColumnLabel()->shrink_to_fit();
    }
    std::vector<std::vector<double>> mat{{0}};
    std::vector<std::string> matr{rowLabel};
    std::vector<std::string> matc{columnLabel};
    DataMatrix x(mat, matr, matc);
    table = x;
}


