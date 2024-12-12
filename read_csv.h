#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <typeinfo> // Para usar typeid

using namespace std;

class CSVReader
{
private:
    string filename;
    char delimiter;
    void *data[100][100];
    int currentRows;
    int currentCols;

    // Método para exibir os dados
    void printData()
    {
        cout << "Dados lidos do arquivo CSV:" << endl;
        for (int i = 0; i < currentRows; i++)
        {
            for (int j = 0; j < currentCols; j++)
            {
                if (data[i][j] != NULL) // Verifica se há dados na célula
                {
                    if (typeid(*(int *)data[i][j]) == typeid(int))
                        cout << *(int *)data[i][j] << "\t"; // Exibe número inteiro
                    else if (typeid(*(float *)data[i][j]) == typeid(float))
                        cout << *(float *)data[i][j] << "\t"; // Exibe número float
                    else if (typeid(*(string *)data[i][j]) == typeid(string))
                        cout << *(string *)data[i][j] << "\t"; // Exibe string
                }
            }
            cout << endl; // Nova linha após cada linha
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
                if (isInteger(cell))
                    data[row][col] = new int(stringToInt(cell));
                else if (isFloat(cell))
                    data[row][col] = new float(stringToFloat(cell));
                else
                    data[row][col] = new string(cell);

                col++;
            }

            if (col > currentCols)
                currentCols = col;
            row++;
        }

        currentRows = row;
        file.close();

        // Chamar a exibição dos dados aqui
        printData();

        return data;
    }

    int stringToInt(string str) { return atoi(str.c_str()); }
    float stringToFloat(string str) { return atof(str.c_str()); }

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