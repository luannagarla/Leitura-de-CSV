#include "read_csv.h"
#include <iostream>

using namespace std;

void processFile(string fileName, char delimiter, bool ignoreFirstLine);
void printData(void* newLista, bool isFirstColumnInt, int currentRows, int currentCols);

int main()
{
    string file1 = "features-dataset1.csv";
    string file2 = "label-dataset1.csv";
    string file3 = "features-dataset2.csv";
    string file4 = "label-dataset2.csv";

    char delimiter = ',';
    bool ignoreFirstLine = true;

    // Processa cada arquivo
    processFile(file1, delimiter, ignoreFirstLine);
    processFile(file2, delimiter, ignoreFirstLine);
    processFile(file3, delimiter, ignoreFirstLine);
    processFile(file4, delimiter, ignoreFirstLine);

    return 0;
}

void processFile(string fileName, char delimiter, bool ignoreFirstLine)
{
    // O construtor CSVReader agora vai abrir e processar o arquivo automaticamente
    // CSVReader reader(fileName, delimiter, ignoreFirstLine);
    cout << "-------------------------------------------------" << endl;
    cout << "Arquivo: " << fileName << endl;

    // O CSVReader já processa o arquivo na criação do objeto
    // void *newLista = reader.createNewList();  // Não é mais necessário passar o 'ifstream' explicitamente

    // printData(newLista, reader.isFirstColumnInt(), reader.currentRows, reader.currentCols);

    // Libere a memória se necessário
    // delete[] static_cast<int**>(newLista);
    // delete[] static_cast<float**>(newLista);
}

void printData(void* newLista, bool isFirstColumnInt, int currentRows, int currentCols)
{
    // Se a primeira coluna for do tipo inteiro, trata como uma matriz de inteiros
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
        // Caso contrário, trata como uma matriz de floats
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