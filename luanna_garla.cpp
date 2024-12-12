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
        void *data = reader.readData(file);
    }
    else
    {
        cout << "Erro ao abrir o arquivo: " << fileName << endl;
    }

    cout << endl;
}

/*void printData(void* data[100][100], int rows, int cols)
{
    cout << "Dados lidos do arquivo CSV:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // if (data[i][j] != nullptr)
            // {
            //     if (typeid(*(int *)data[i][j]) == typeid(int))
            //         cout << *(int *)data[i][j] << "\t";
            //     else if (typeid(*(float *)data[i][j]) == typeid(float))
            //         cout << *(float *)data[i][j] << "\t";
            //     else if (typeid(*(string *)data[i][j]) == typeid(string))
            //         cout << *(string *)data[i][j] << "\t";
            // }
        }
        cout << endl;
    }
}*/