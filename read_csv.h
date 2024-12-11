// Arquivo: read_csv.h
#ifndef READ_CSV_H
#define READ_CSV_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class CSVReader {
private:
    std::string filename; // Nome do arquivo CSV
    char delimiter;       // Delimitador usado para separar os valores
    int maxRows;          // Número máximo de linhas permitidas
    int maxCols;          // Número máximo de colunas permitidas

    // Array fixo para armazenar os dados do arquivo
    std::string data[100][100];
    int currentRows;      // Número de linhas lidas
    int currentCols;      // Número de colunas lidas

public:
    // Construtor para inicializar o leitor com as configurações desejadas
    CSVReader(std::string file, char delim = ',', int maxRows = 100, int maxCols = 100) {
        filename = file;
        delimiter = delim;
        this->maxRows = maxRows;
        this->maxCols = maxCols;
        currentRows = 0;
        currentCols = 0;
    }

    // Método para ler os dados do arquivo CSV
    bool readData() {
        // Tenta abrir o arquivo com conversão explícita para const char*
        std::ifstream file(filename.c_str());
        if (!file.is_open()) {
            std::cout << "Erro ao abrir o arquivo: " << filename << std::endl;
            return false;
        }

        std::string line;
        int row = 0;

        // Lê o arquivo linha por linha
        while (getline(file, line) && row < maxRows) {
            std::stringstream ss(line); // Converte a linha para um stream
            std::string cell;
            int col = 0;

            // Lê cada célula da linha separada pelo delimitador
            while (getline(ss, cell, delimiter) && col < maxCols) {
                data[row][col] = cell; // Armazena o valor no array
                col++;
            }

            if (col > currentCols) {
                currentCols = col; // Atualiza o número de colunas lidas
            }
            row++;
        }

        currentRows = row; // Atualiza o número de linhas lidas
        file.close(); // Fecha o arquivo
        return true;
    }

    // Método para imprimir os dados na tela
    void printData() {
        for (int i = 0; i < currentRows; i++) {
            for (int j = 0; j < currentCols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif // READ_CSV_H