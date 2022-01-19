#ifndef DATAMATRIX_H
#define DATAMATRIX_H

#include <vector>
#include <string>
#include <QObject>
#include <QString>
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

class DataMatrix
{
private:
    std::vector<std::vector<double>> *data; // Reference of a 2D vector
    std::vector<std::string> *rowLabel;     // Vector of labels for the rows
    std::vector<std::string> *columnLabel;  // Vector of labels for the columns

public:
    DataMatrix() : data(new std::vector<std::vector<double>>), rowLabel(new std::vector<std::string>), columnLabel(new std::vector<std::string>) {}

    /**
     * @brief Constructor of Data Matrix objects
     *
     * @param Data reference of a 2D vector
     * @param RowLabel reference of a string vector
     * @param ColumnLabel reference of a string vector
     */
    DataMatrix(const std::vector<std::vector<double>> &data, const std::vector<std::string> &rowLabel, const std::vector<std::string> &columnLabel);

    /**
     * @brief Copy constructor of Data Matrix objects
     *
     * @param Table
     */
    DataMatrix(const DataMatrix &table);

    /**
     * @brief Destructor of Data Matrix objects
     *
     */
    ~DataMatrix();

    /**
     * @brief Ridefinition of operator =
     *
     * @param Table
     */
    DataMatrix &operator=(const DataMatrix &table);

    /**
     * @brief Adds a row in n poition
     *
     * @param a reference to the vector to add
     * @param n index in which to insert the row
     * @param label label of the new row
     */
    void addRow(const std::vector<double> &a, unsigned int n = 0, const std::string &label = "");

    /**
     * @brief Adds a column in n position
     *
     * @param a reference to the vector to add
     * @param n index in which to insert the column
     * @param label label of the new column
     */
    void addColumn(const std::vector<double> &a, unsigned int n = 0, const std::string &label = "");

    /**
     * @brief Deletes the row at n index
     *
     * @param n index of the row to remove
     */
    void deleteRow(unsigned int n);

    /**
     * @brief Deletes the column at n index
     *
     * @param n index of the column to remove
     */
    void deleteColumn(unsigned int n);

    /**
     * @brief Getter for the data at n position
     *
     * @return std::vector<std::vector<double>> vector of data
     */
    std::vector<double> *getColumnData(unsigned int n) const;

    /**
     * @brief Getter for the data at n position
     *
     * @return std::vector<std::vector<double>> vector of data
     */
    std::vector<double> *getRowData(unsigned int n) const;

    /**
     * @brief Getter for the Row Label object
     *
     * @return std::vector<string>*
     */
    std::vector<std::string> *getRowLabel() const;

    /**
     * @brief Getter fot the Column Label object
     *
     * @return std::vector<std::string>*
     */
    std::vector<std::string> *getColumnLabel() const;

    /**
     * @brief Getter for the data from the matrix
     *
     * @return std::vector<std::string>*
     */
    std::vector<std::vector<double>> *getData() const;

    /**
     * @brief Counter for the number of rows
     *
     * @param The number of rows
     */
    unsigned int getRowCount() const;

    /**
     * @brief Counter for the number of columns
     *
     * @param The number of columns
     */
    unsigned int getColumnCount() const;

    /**
     * @brief Reads from file
     * 
     * @param Path of the .json file
     */
    void read(std::string path = "inputfile.json");

    /**
     * @brief Writes to file
     * 
     * @param Path of the .json file
     */
    void write(std::string path = "1.json") const;
};

#endif
