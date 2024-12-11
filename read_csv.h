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
    string data[100][100];
    int currentRows;
    int currentCols;

public:
    CSVReader(string file, char delim = ',') : filename(file), delimiter(delim), currentRows(0), currentCols(0) {}

    int getCurrentRows() const { return currentRows; }
    int getCurrentCols() const { return currentCols; }

    string (*readData(ifstream &file))[100]
    {
        string line;
        int row = 0;

        while (getline(file, line) && row < 100)
        {
            stringstream ss(line);
            string cell;
            int col = 0;

            while (getline(ss, cell, delimiter) && col < 100)
            {
                if (isInteger(cell))
                {
                    data[row][col] = intToString(stringToInt(cell));
                }
                else if (isFloat(cell))
                {
                    data[row][col] = floatToString(stringToFloat(cell));
                }
                else
                {
                    data[row][col] = cell;
                }
                col++;
            }

            if (col > currentCols)
                currentCols = col;
            row++;
        }

        currentRows = row;
        file.close();

        return data;
    }

    int stringToInt(string str) { return atoi(str.c_str()); }
    float stringToFloat(string str) { return atof(str.c_str()); }

    bool isInteger(const string &str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (!isdigit(str[i]) && str[i] != '-')
                return false;
        }
        return true;
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

    string intToString(int value)
    {
        stringstream ss;
        ss << value;
        return ss.str();
    }

    string floatToString(float value)
    {
        stringstream ss;
        ss << value;
        return ss.str();
    }
};