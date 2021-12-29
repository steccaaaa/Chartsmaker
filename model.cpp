#include "model.h"
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
    print2(*vec); // usa l'altro print e magicamente va tutto
}

Model::Model(QObject *parent) : QAbstractTableModel(parent)
{
    /*for (unsigned int i = 0; i < table.getRowCount(); i++)
    {
        QVector<qreal> *dataVector = new QVector<qreal>(table.getColumnCount());
        for (int j = 0; j < dataVector->size(); j++)
            dataVector->replace(j, (j+1)*i);
        _data.append(dataVector); // appendi alla lista di vettori
    }*/
    std::vector<std::vector<double>> mat{
        {1, 2, 7},
        {4, 7, 6},
        {7, 8, 9}};
    std::vector<std::string> mats{"a", "b", "c"};
    DataMatrix x(mat, mats, mats);
    table = x;
}

int Model::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent) // parent non è usato -- evita compilazioni inutili
    std::cout<<"rowcount\n";
    return table.getRowCount();
}

int Model::columnCount(const QModelIndex &parent) const
{
    std::cout<<"colcount\n";
    Q_UNUSED(parent) // parent non è usato -- evita compilazioni inutili
    return table.getColumnCount();
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {/*
        std::cout<<"dio canaglia\n";
        print2(table.getData());
        QList<QVector<qreal> *> *temp = new QList<QVector<qreal> *>;
        for (unsigned int i = 0; i < table.getRowCount(); i++)
        {
            QVector<qreal> *dataVector = new QVector<qreal>(table.getColumnCount());
            for (int j = 0; j < dataVector->size(); j++)
                dataVector->replace(j, (j + 1) * i);
            temp->append(dataVector); // appendi alla lista di vettori
        }
        return (*temp)[index.row()]->at(index.column());*/
        std::cout<<"data\n";
        qreal temp = table.getData()->at(index.row()).at(index.column());
        std::cout<<temp<<"\n";
        return temp;
    }

    std::cout<<"qvariant\n";
    return QVariant();
}
