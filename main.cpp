// Arquivo: Nome_Sobrenome.cpp
#include "read_csv.h"
#include <iostream>

using namespace std;

int main() {    
    CSVReader csvReader("features-dataset1.csv", ',', 100, 100);
    CSVReader csvReader("features-dataset2.csv", ',', 100, 100);
    CSVReader csvReader("label-dataset1.csv", ',', 100, 100);
    CSVReader csvReader("label-dataset2.csv", ',', 100, 100);

    if (!csvReader.readData()) {
        cout << "Falha ao ler os dados do arquivo." << endl;
        return 1;
    }

    cout << "Conteúdo do arquivo CSV:" << endl;
    csvReader.printData();

    return 0;
}