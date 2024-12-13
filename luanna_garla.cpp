#include "read_csv.h"
#include <iostream>
#include <vector>

using namespace std;

void processFile(string fileName);
void printData(void* newLista, bool isFirstColumnInt, int currentRows, int currentCols);

int main()
{
    string file1 = "features-dataset1.csv";
    string file2 = "label-dataset1.csv";
    string file3 = "features-dataset2.csv";
    string file4 = "label-dataset2.csv";

    processFile(file1);
    processFile(file2);
    processFile(file3);
    processFile(file4);

    return 0;
}

void processFile(string fileName)
{
    CSVReader reader(fileName, ',');
    cout << "-------------------------------------------------" << endl;
    cout << "Arquivo: " << fileName << endl;

    ifstream file(fileName.c_str());

    if (file.is_open())
    {
        void *newLista = reader.createNewList(file);

        printData(newLista, reader.isFirstColumnInt(), reader.currentRows, reader.currentCols);
    }
    else
    {
        cout << "Erro ao abrir o arquivo: " << fileName << endl;
    }

    cout << endl;
}

void printData(void* newLista, bool isFirstColumnInt, int currentRows, int currentCols)
{
    if (isFirstColumnInt)
    {
        int (*dataInt)[100] = static_cast<int (*)[100]>(newLista);

        for (int i = 0; i < currentRows; i++)
        {
            for (int j = 0; j < currentCols; j++)
            {
                cout << dataInt[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        float (*dataFloat)[100] = static_cast<float (*)[100]>(newLista);

        for (int i = 0; i < currentRows; i++)
        {
            for (int j = 0; j < currentCols; j++)
            {
                cout << dataFloat[i][j] << " ";
            }
            cout << endl;
        }
    }
}
