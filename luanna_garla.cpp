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
        
        // Acessando o endereço da matriz de dados
        string (*data1)[100] = reader1.getData();
        // Exemplo de como acessar um valor específico da matriz
        cout << "Primeiro valor lido do arquivo " << file1 << ": " << data1[0][0] << endl;
    } else {
        cerr << "Erro ao ler o arquivo " << file1 << endl;
    }

    cout << endl;

    // Lendo e imprimindo o segundo arquivo
    cout << "Lendo o arquivo: " << file2 << endl;
    if (reader2.readData()) {
        cout << "Conteúdo do arquivo " << file2 << ":" << endl;
        reader2.printData();
        
        // Acessando o endereço da matriz de dados
        string (*data2)[100] = reader2.getData();
        // Exemplo de como acessar um valor específico da matriz
        cout << "Primeiro valor lido do arquivo " << file2 << ": " << data2[0][0] << endl;
    } else {
        cerr << "Erro ao ler o arquivo " << file2 << endl;
    }

    return 0;
}