#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "datamatrix.h"

class Model : public QAbstractTableModel
{
    Q_OBJECT
public:
    Model(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    DataMatrix getTable() const;

    void readJson(std::string path);
    void writeJson(std::string path);

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    void insertRow(unsigned int i, std::string label);
    void insertColumn(unsigned int i, std::string label);
    void removeRow(unsigned int i);
    void removeColumn(unsigned int i);
    void newModel(std::string rowLabel, std::string columnLabel);

private:
    DataMatrix table;
};

#endif // MODEL_H
