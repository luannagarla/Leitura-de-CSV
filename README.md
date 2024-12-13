# Projeto 01 - POO

**Dificuldade:** Não consegui utilizar a classe typeId no código, estudei a implementação, mas não consegui encaiar. Queria ter utilizado no isInteger.
Outro problema foi que o sugerido em sala era uma amtriz [1000][1000], o que causou muitos erros de overflow no compilador.

**Como testar:** Apenas rodar o luanna_garla.cpp com o nome dos arquivos adequados nas variáveis "file"
No meu código está definido como 
    string file1 = "label-Aula 13 - Projeto 1 - dataset1.csv";
    string file2 = "label-Aula 13 - Projeto 1 - dataset2.csv";
    string file3 = "features-Aula 13 - Projeto 1 - dataset1.csv";
    string file4 = "features-Aula 13 - Projeto 1 - dataset2.csv";

 E os arquivos estavam dentro de uma pasta "output" no mesmo diretórios dos arquivos .cpp e .h

**Objetivo:** Implementação de uma classe que possibilite ler um arquivo CSV e retornar ao código o endereço
da array bidimensional que contém os dados lidos do arquivo com o tamanho do array
bidimensional do tamanho do conteúdo que ele armazena. Dos tipos float ou int.