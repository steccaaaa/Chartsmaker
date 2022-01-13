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
    void writeJson(std::string path);
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    void insertRow(unsigned int i, std::string label);
    void insertColumn(unsigned int i, std::string label);
    void removeRow(unsigned int i);
    void removeColumn(unsigned int i);

    //! sta roba mi spaventa intanto lo faccio senza
    /*virtual bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    virtual bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex());
    virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    virtual bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex());
    virtual bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild);
    virtual bool moveColumns(const QModelIndex &sourceParent, int sourceColumn, int count, const QModelIndex &destinationParent, int destinationChild);*/

private:
    DataMatrix table;
};

#endif // MODEL_H
