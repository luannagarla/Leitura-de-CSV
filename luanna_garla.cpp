#include "read_csv.h"
#include <iostream>

using namespace std;

void processFile(string fileName);
void printData(string (*data)[100], int rows, int cols);

int main()
{
    string file1 = "features-dataset1.csv";
    string file2 = "label-dataset1.csv";
    
    processFile(file1);
    processFile(file2);

    return 0;
}

void processFile(string fileName)
{
    CSVReader reader(fileName, ',');
    cout << "-------------------------------------------------" << endl;
    cout << "Lendo o arquivo: " << fileName << endl;

    ifstream file(fileName.c_str());

    if (file.is_open())
    {
        string (*data)[100] = reader.readData(file);

        cout << "Conteúdo do arquivo:" << endl;
        printData(data, reader.getCurrentRows(), reader.getCurrentCols());
    }
    else
    {
        cout << "Erro ao abrir o arquivo: " << fileName << endl;
    }

    cout << endl;
}

void printData(string (*data)[100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}