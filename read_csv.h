#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

class CSVReader
{
private:
    string filename;
    char delimiter;
    bool ignoreFirstLine;
    int currentRows;
    int currentCols;
    bool isFirstColumnInt;

public:
    CSVReader(const string &file, char delim = ',', bool ignoreFLine = true)
        : filename(file), delimiter(delim), ignoreFirstLine(ignoreFLine), currentRows(0), currentCols(0), isFirstColumnInt(true)
    {
    }

    int getCurrentRows() const
    {
        return currentRows;
    }

    int getCurrentCols() const
    {
        return currentCols;
    }

    bool getIsFirstColumnInt() const
    {
        return isFirstColumnInt;
    }

    void *readData(ifstream &file)
    {
        string data[1000][1000]; 
        string line;
        int row = 0;

        if (ignoreFirstLine)
        {
            getline(file, line); 
        }

        while (getline(file, line) && row < 1000)
        {
            stringstream ss(line);
            string cell;
            int col = 0;

            while (getline(ss, cell, delimiter) && col < 1000)
            {
                data[row][col] = (cell.empty()) ? "0" : cell; 
                col++;
            }

            if (col > currentCols)
            {
                currentCols = col;
            }
            row++;
        }

        currentRows = row;

        for (int i = 1; i < currentRows; i++)
        {
            if (!isInteger(data[i][0]))
            {
                isFirstColumnInt = false;
                break;
            }
        }

        file.close();                                 
        return createNewList(isFirstColumnInt, data); 
    }

    void *createNewList(bool firstColumnInt, string data[1000][1000])
    {
        if (firstColumnInt)
        {
            int **newData = new int *[currentRows]; 
            for (int i = 0; i < currentRows; ++i)
            {
                newData[i] = new int[currentCols]; 
            }

            for (int i = 0; i < currentRows; ++i)
            {
                for (int j = 0; j < currentCols; ++j)
                {
                    newData[i][j] = stringToInt(data[i][j]); 
                }
            }

            return (void *)newData; 
        }
        else
        {
            float **newData = new float *[currentRows]; 
            for (int i = 0; i < currentRows; ++i)
            {
                newData[i] = new float[currentCols]; 
            }

            for (int i = 0; i < currentRows; ++i)
            {
                for (int j = 0; j < currentCols; ++j)
                {
                    newData[i][j] = stringToFloat(data[i][j]); 
                }
            }

            return (void *)newData; 
        }
    }

    int stringToInt(const string &str)
    {
        return atoi(str.c_str());
    }

    float stringToFloat(const string &str)
    {
        return atof(str.c_str());
    }

    bool isInteger(const string &str)
    {
        return !str.empty() && (str.find_first_not_of("0123456789-") == string::npos);
    }
};
