#include "read_csv.h"
#include <iostream>

using namespace std;

void processFile(string fileName);

int main()
{
    string file1 = "features-dataset1.csv";
    string file2 = "label-dataset1.csv";

    processFile(file1);
    processFile(file2);

    return 0;
}

// Função para processar um arquivo
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
        reader.printData();
    }
    else
    {
        cout << "Erro ao abrir o arquivo: " << fileName << endl;
    }

    cout << endl;
}