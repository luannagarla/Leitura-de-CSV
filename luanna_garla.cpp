#include "read_csv.h"
#include <iostream>

using namespace std;

void processFile(string fileName);

//Queria ter implementado o print data aqui ;c

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