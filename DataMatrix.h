#ifndef DATAMATRIX_H
#define DATAMATRIX_H
#include <vector>
#include <string>
#include <QJsonObject>
#include <QObject>
#include <QString>

class DataMatrix
{
private:
    std::vector<std::vector<double>> *data; // reference of a 2D vector
    std::vector<std::string> *rowLabel;     // vector of labels for the rows
    std::vector<std::string> *columnLabel;  // vector of labels for the columns

public:
    DataMatrix() : data(nullptr), rowLabel(nullptr), columnLabel(nullptr) {}

    /**
     * @brief Construct a new Data Matrix object
     *
     * @param data reference of a 2d vector
     * @param rowLabel reference of a string vector
     * @param columnLabel reference of a string vector
     */
    DataMatrix(std::vector<std::vector<double>> &data, std::vector<std::string> &rowLabel, std::vector<std::string> &columnLabel);

    /**
     * @brief Copy constructor of a new Data Matrix object
     *
     * @param table
     */
    DataMatrix(DataMatrix &table);
    /**
     * @brief Destructor of Data Matrix object
     *
     */
    ~DataMatrix();

    DataMatrix& operator= (const DataMatrix& table);

    /**
     * @brief adds a row in n poition
     *
     * @param a reference to the vector to add
     * @param n index in which to insert the row
     * @param label label of the new row
     */
    void addRow(std::vector<double> &a, unsigned int n = 0, std::string label = "");

    /**
     * @brief adds a column in n position
     *
     * @param a reference to the vector to add
     * @param n index in which to insert the column
     * @param label label of the new column
     */
    void addColumn(std::vector<double> &a, unsigned int n = 0, std::string label = "");

    /**
     * @brief deletes the row in n index
     *
     * @param n index of the row to remove
     */
    void deleteRow(unsigned int n);

    /**
     * @brief deletes the column in n index
     *
     * @param n index of the column to remove
     */
    void deleteColumn(unsigned int n);

    /**
     * @brief Get the data in from the different columns
     *
     * @return std::vector<std::vector<double>>
     */
    std::vector<double> *getColumnData(unsigned int n);

    /**
     * @brief Get the Row Label object
     *
     * @return std::vector<string>*
     */
    std::vector<std::string> *getRowLabel() const;

    /**
     * @brief Get the Column Label object
     *
     * @return std::vector<std::string>*
     */
    std::vector<std::string> *getColumnLabel() const;

    /**
     * @brief Get the data in the matrix
     *
     * @return std::vector<std::string>*
     */
    std::vector<std::vector<double>> *getData() const;

    unsigned int getRowCount() const;

    unsigned int getColumnCount() const;

    /**
     * @brief reads from file
     * 
     * @param json 
     */
    void read(/*const QJsonObject &json*/);

    /**
     * @brief write to file
     * 
     * @param json 
     */
    void write(/*QJsonObject &json*/) const;
};

#endif
