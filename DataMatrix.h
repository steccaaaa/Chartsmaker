#ifndef DATAMATRIX_H
#define DATAMATRIX_H
#include <vector>
#include <string>

class DataMatrix
{
private:
    std::vector<std::vector<double>> *data; //pointer to a 2D vector
    ////unsigned int rowNumber;                 //number of rows
    ////unsigned int columnNumber;              //number of columns
    std::vector<std::string> *rowLabel;    //vector of labels for the rows
    std::vector<std::string> *columnLabel; //vector of labels for the columns

public:
    /**
     * @brief Constructor for Data Matrix object
     * 
     * @param data pointer to an 2D vector
     * @param rowNumber number of rows
     * @param columnNumber number of columns
     */
    DataMatrix(std::vector<std::vector<double>> *data, std::vector<std::string> *rowLabel = nullptr, std::vector<std::string> *columnLabel = nullptr);

    /**
     * @brief Destructor of Data Matrix object
     * 
     */
    ~DataMatrix();

    /**
     * @brief adds a row in n poition
     * 
     * @param a pointer to the vector to add
     * @param n index in which to insert the row
     */
    void addRow(std::vector<double> *a, unsigned int n = 0);

    /**
     * @brief adds a column in n position
     * 
     * @param a pointer to the vector to add
     * @param n index in which to insert the column
     */
    void addColumn(std::vector<double> *a, unsigned int n = 0);

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
     * @brief Get the Data object
     * 
     * @return std::vector<std::vector<double>> 
     */
    std::vector<std::vector<double>> getData();
};

#endif