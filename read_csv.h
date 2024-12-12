#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <typeinfo>

using namespace std;

class CSVReader
{
private:
    string filename;
    char delimiter;
    void *data[100][100]; // aceita vários tipos de dados, sintaxe complexa
    int currentRows;
    int currentCols;

    // Uso do TypeId
    void printData()
    {
        cout << "Dados:" << endl;
        for (int i = 0; i < currentRows; i++)
        {
            for (int j = 0; j < currentCols; j++)
            {
                void *actual = data[i][j];

                if (i == 0)
                    cout << *(string *)actual << "\t"; // cast obaa
                else if (actual != NULL)               // as virgulas que tinham no arquivo viraram null, causou confusão
                {
                    if (typeid(*(int *)actual) == typeid(int))
                    {
                        cout << *(int *)actual << "\t";
                    }
                    else if (typeid(*(float *)actual) == typeid(float))
                    {
                        cout << *(float *)actual << "\t";
                    }
                }
            }

            cout << endl;
        }
    }

public:
    CSVReader(string file, char delim = ',') : filename(file), delimiter(delim), currentRows(0), currentCols(0) {}

    int getCurrentRows() const { return currentRows; }
    int getCurrentCols() const { return currentCols; }

    void *readData(ifstream &file)
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
                if (cell.empty())
                    data[row][col] = new int(0); // tratativa de nulos meio ruim
                else if (isInteger(cell))
                    data[row][col] = new int(stringToInt(cell));
                else if (isFloat(cell))
                    data[row][col] = new float(stringToFloat(cell));
                else
                    data[row][col] = new string(cell); // cabeçalho

                col++;
            }

            if (col > currentCols)
                currentCols = col;
            row++;
        }

        currentRows = row;
        file.close();

        printData();
        return data;
    }

    int stringToInt(string str) { return atoi(str.c_str()); }
    float stringToFloat(string str) { return atof(str.c_str()); }

    bool isInteger(const string &str)
    {
        return !str.empty() && (str.find_first_not_of("0123456789-") == string::npos);
    }

    // Não consegui usar o typeId e não entendi se teria realmente como
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