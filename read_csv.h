#ifndef READ_CSV_H
#define READ_CSV_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

class CSVReader
{
private:
    string filename; // Nome do arquivo CSV
    char delimiter;  // Delimitador usado para separar os valores
    string data[100][100]; // Array para armazenar os dados do arquivo
    int currentRows; // Número de linhas lidas
    int currentCols; // Número de colunas lidas

public:
    // Construtor para inicializar o leitor
    CSVReader(string file, char delim = ',')
    {
        filename = file;
        delimiter = delim;
        currentRows = 0;
        currentCols = 0;
    }

    // Método para ler os dados do arquivo CSV
    bool readData()
    {
        ifstream file(filename.c_str()); // Abre o arquivo
        if (!file.is_open()) // Verifica se o arquivo foi aberto corretamente
        {
            cout << "Erro ao abrir o arquivo: " << filename << endl;
            return false;
        }

        string line;
        int row = 0;

        // Lê o arquivo linha por linha
        while (getline(file, line) && row < 100)
        {
            stringstream ss(line); // Transforma a linha em um stream
            string cell;
            int col = 0;

            // Lê cada célula da linha
            while (getline(ss, cell, delimiter) && col < 100)
            {
                data[row][col] = cell; // Armazena no array
                col++;
            }

            if (col > currentCols) currentCols = col; // Atualiza o número de colunas
            row++;
        }

        currentRows = row; // Atualiza o número de linhas lidas
        file.close(); // Fecha o arquivo
        return true;
    }

    // Método para imprimir os dados na tela
    void printData()
    {
        for (int i = 0; i < currentRows; i++)
        {
            for (int j = 0; j < currentCols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Método para retornar os dados como um array
    string (*getData())[100]
    {
        return data;
    }

    // Método para converter string para inteiro
    int stringToInt(string str)
    {
        return atoi(str.c_str()); // Usa a função atoi para conversão
    }

    // Método para converter string para float
    float stringToFloat(string str)
    {
        return atof(str.c_str()); // Usa a função atof para conversão
    }
};

#endif // READ_CSV_H
