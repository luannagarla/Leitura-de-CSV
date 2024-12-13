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
    string data[1000][1000];

public:
    CSVReader(const string &file, char delim = ',', bool ignoreFLine = true)
        : filename(file), delimiter(delim), ignoreFirstLine(ignoreFLine) {}

    int currentRows = 0;
    int currentCols = 0;

    void readData(ifstream &file)
    {
        string line;
        int row = 0;
        
        if (ignoreFirstLine)
        {
            getline(file, line); // Ignora a primeira linha de cabeçalho
        }

        while (getline(file, line) && row < 100)
        {
            stringstream ss(line);
            string cell;
            int col = 0;

            while (getline(ss, cell, delimiter) && col < 100)
            {
                if (cell.empty())
                {
                    data[row][col] = "0"; // Tratamento de nulos meio ruim
                }
                else
                {
                    data[row][col] = cell;
                }
                col++;
            }

            if (col > currentCols)
            {
                currentCols = col;
            }
            row++;
        }

        currentRows = row;
        file.close();
    }

    bool isFirstColumnInt()
    {
        bool isFirstColumnInt = true;
        for (int i = 1; i < currentRows; i++)
        {
            if (!isInteger(data[i][0]))
            {
                isFirstColumnInt = false;
            }
        }

        return isFirstColumnInt;
    }

    void *createNewList(ifstream &file)
    {
        readData(file);

        bool firstColumnInt = isFirstColumnInt();

        if (firstColumnInt)
        {
            int **newData = new int *[currentRows]; // aloca um vetor de ponteiros para linhas

            for (int i = 0; i < currentRows; ++i)
            {
                newData[i] = new int[currentCols]; // aloca cada linha dinamicamente
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

        float **newData = new float *[currentRows]; // aloca um vetor de ponteiros para linhas

        for (int i = 0; i < currentRows; ++i)
        {
            newData[i] = new float[currentCols]; // aloca cada linha dinamicamente
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

    int stringToInt(string str)
    {
        return atoi(str.c_str());
    }

    float stringToFloat(string str)
    {
        return atof(str.c_str());
    }

    bool isInteger(const string &str)
    {
        return !str.empty() && (str.find_first_not_of("0123456789-") == string::npos);
    }

    bool isFloat(const string &str)
    {
        bool dotFound = false;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '.')
            {
                if (dotFound)
                    return false;
                dotFound = true;
            }
            else if (!isdigit(str[i]) && str[i] != '-')
            {
                return false;
            }
        }
        return dotFound;
    }
};
