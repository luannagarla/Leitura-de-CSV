// Arquivo: Nome_Sobrenome.cpp
#include "read_csv.h"
#include <iostream>

using namespace std;

int main()
{
    CSVReader reader("features-dataset1.csv");
    if (reader.readData())
    {
        string(*data)[100] = reader.getData();
        // Agora você pode acessar os dados diretamente usando o array data
    }

    cout << "Conteúdo do arquivo CSV:" << endl;
    reader.printData();

    return 0;
}