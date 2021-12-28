#include "model.h"

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
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<std::string> mats{"a", "b", "c"};
    DataMatrix x(mat, mats, mats);
    table = x;
}

int Model::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent) // parent non è usato -- evita compilazioni inutili
    return table.getRowCount();
}

int Model::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent) // parent non è usato -- evita compilazioni inutili
    return table.getColumnCount();
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QList<QVector<qreal> *> *temp = new QList<QVector<qreal> *>;
        for (unsigned int i = 0; i < table.getRowCount(); i++)
        {
            QVector<qreal> *dataVector = new QVector<qreal>(table.getColumnCount());
            for (int j = 0; j < dataVector->size(); j++)
                dataVector->replace(j, (j + 1) * i);
            temp->append(dataVector); // appendi alla lista di vettori
        }
        return (*temp)[index.row()]->at(index.column());
    }
    return QVariant();
}
