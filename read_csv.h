// Arquivo: read_csv.h
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
                // Tenta converter o valor da célula para int ou float
                if (isInteger(cell))
                {
                    data[row][col] = intToString(stringToInt(cell)); // Converte para int e armazena
                }
                else if (isFloat(cell))
                {
                    data[row][col] = floatToString(stringToFloat(cell)); // Converte para float e armazena
                }
                else
                {
                    data[row][col] = cell; // Armazena como string
                }
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

    // Método para verificar se uma string é um número inteiro
    bool isInteger(const string &str)
    {
        for (int i = 0; i < str.length(); i++) // Loop convencional (compatível com C++98)
        {
            if (!isdigit(str[i]) && str[i] != '-')
                return false;
        }
        return true;
    }

    // Método para verificar se uma string é um número float
    bool isFloat(const string &str)
    {
        bool dotFound = false;
        for (int i = 0; i < str.length(); i++) // Loop convencional (compatível com C++98)
        {
            if (!isdigit(str[i]) && str[i] != '-')
            {
                return false;
            }
        }
        return dotFound; // Retorna true se houver um ponto (.) e a string for válida
    }

    // Método para converter int para string
    string intToString(int value)
    {
        stringstream ss;
        ss << value; // Converte o inteiro para string
        return ss.str();
    }

    // Método para converter float para string
    string floatToString(float value)
    {
        stringstream ss;
        ss << value; // Converte o float para string
        return ss.str();
    }
};

#endif // READ_CSV_H
