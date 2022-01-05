#ifndef MODEL_H
#define MODEL_H

#include "DataMatrix.h"
#include <QAbstractTableModel>
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

class Model : public QAbstractTableModel
{
    Q_OBJECT
public:
    Model(QObject *parent = 0);                                                // overwrite necessario per definizione
    int rowCount(const QModelIndex &parent = QModelIndex()) const;             // overwrite necessario per definizione
    int columnCount(const QModelIndex &parent = QModelIndex()) const;          // overwrite necessario per definizione
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const; // overwrite necessario per definizione
    DataMatrix getTable();
    void readJson(std::string path);

private:
    DataMatrix table;
};

#endif // MODEL_H
