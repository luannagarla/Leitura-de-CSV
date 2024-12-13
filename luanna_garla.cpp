#include "read_csv.h"
#include <iostream>

using namespace std;

void processFile(string fileName);
void printData(void* newLista, bool isFirstColumnInt, int currentRows, int currentCols);

int main()
{
    string file1 = "features-dataset1.csv";
    string file2 = "label-dataset1.csv";
    string file3 = "features-dataset2.csv";
    string file4 = "label-dataset2.csv";

    char delimiter = ',';
    bool ignoreFirstLine = true;

    processFile(file1, delimiter, ignoreFirstLine);
    processFile(file2, delimiter, ignoreFirstLine);
    processFile(file3, delimiter, ignoreFirstLine);
    processFile(file4, delimiter, ignoreFirstLine);

    return 0;
}

void processFile(string fileName char delimiter, bool ignoreFirstLine)
{
    CSVReader reader(fileName, delimiter, ignoreFirstLine);
    cout << "-------------------------------------------------" << endl;
    cout << "Arquivo: " << fileName << endl;

    ifstream file(fileName.c_str());

    if (file.is_open())
    {
        void *newLista = reader.createNewList(file);

        printData(newLista, reader.isFirstColumnInt(), reader.currentRows, reader.currentCols);

        // delete[] static_cast<int**>(newLista);         
        // delete[] static_cast<float**>(newLista);  
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
        int **dataInt = static_cast<int**>(newLista);  // Cast para ponteiro para ponteiro de int

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
        float **dataFloat = static_cast<float**>(newLista);  // Cast para ponteiro para ponteiro de float

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
