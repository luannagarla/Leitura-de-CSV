#include "read_csv.h"
#include <iostream>

using namespace std;

int main() {
    // Nome dos arquivos CSV a serem lidos
    string file1 = "features-dataset1.csv";
    string file2 = "label-dataset1.csv";

    // Criando instâncias da classe CSVReader para os dois arquivos
    CSVReader reader1(file1, ',');
    CSVReader reader2(file2, ',');

    // Lendo e imprimindo o primeiro arquivo
    cout << "Lendo o arquivo: " << file1 << endl;
    if (reader1.readData()) {
        cout << "Conteúdo do arquivo " << file1 << ":" << endl;
        reader1.printData();
    } else {
        cerr << "Erro ao ler o arquivo " << file1 << endl;
    }

    cout << endl;

    // Lendo e imprimindo o segundo arquivo
    cout << "Lendo o arquivo: " << file2 << endl;
    if (reader2.readData()) {
        cout << "Conteúdo do arquivo " << file2 << ":" << endl;
        reader2.printData();
    } else {
        cerr << "Erro ao ler o arquivo " << file2 << endl;
    }

    return 0;
}