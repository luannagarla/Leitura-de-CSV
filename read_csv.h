// Arquivo: read_csv.h
#ifndef READ_CSV_H
#define READ_CSV_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

class CSVReader
{
private:
    string filename; // Nome do arquivo CSV
    char delimiter;  // Delimitador usado para separar os valores
    int maxRows;     // Número máximo de linhas permitidas
    int maxCols;     // Número máximo de colunas permitidas

    // Array fixo para armazenar os dados do arquivo
    string data[100][100];
    int currentRows; // Número de linhas lidas
    int currentCols; // Número de colunas lidas

public:
    // Construtor para inicializar o leitor com as configurações desejadas
    CSVReader(string file, char delim = ',', int maxRows = 100, int maxCols = 100)
    {
        filename = file;
        delimiter = delim;
        this->maxRows = maxRows;
        this->maxCols = maxCols;
        currentRows = 0;
        currentCols = 0;
    }

    // Método para ler os dados do arquivo CSV
    bool readData()
    {
        // Tenta abrir o arquivo com conversão explícita para const char*
        ifstream file(filename.c_str());
        if (!file.is_open())
        {
            cout << "Erro ao abrir o arquivo: " << filename << endl;
            return false;
        }

        string line;
        int row = 0;

        // Lê o arquivo linha por linha
        while (getline(file, line) && row < maxRows)
        {
            stringstream ss(line); // Converte a linha para um stream
            string cell;
            int col = 0;

            // Lê cada célula da linha separada pelo delimitador
            while (getline(ss, cell, delimiter) && col < maxCols)
            {
                data[row][col] = cell; // Armazena o valor no array
                col++;
            }

            if (col > currentCols)
            {
                currentCols = col; // Atualiza o número de colunas lidas
            }
            row++;
        }

        currentRows = row; // Atualiza o número de linhas lidas
        file.close();      // Fecha o arquivo
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

    // Método para retornar o endereço do array bidimensional
    string (*getData())[100]
    {
        return data;
    }

    // Método para converter string para int
    int stringToInt(const string &str)
    {
        try
        {
            size_t pos;
            int value = stoi(str, &pos);
            if (pos < str.size())
            {
                throw invalid_argument("Caracteres não numéricos encontrados");
            }
            return value;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Erro: Não foi possível converter '" << str << "' para int." << endl;
            return 0; // Valor padrão em caso de erro
        }
    }

    // Método para converter string para float
    float stringToFloat(const string &str)
    {
        try
        {
            return std::stof(str);
        }
        catch (const invalid_argument &e)
        {
            cout << "Erro: Não foi possível converter '" << str << "' para float." << endl;
            return 0.0f; // Valor padrão em caso de erro
        }
    }
};

#endif // READ_CSV_H