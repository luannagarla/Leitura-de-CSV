# Projeto-01-POO

Implementar uma classe que possibilite ler um arquivo CSV e retornar ao código o endereço
da array bidimensional que contém os dados lidos do arquivo. Atenção, o tamanho do array
bidimensional retornado deve ser do tamanho exato do conteúdo que ele armazena, não
possuindo linhas ou colunas maior que a quantidade necessária.
Assuma que os dados a serem lidos podem ser de dois tipos, float ou int. Tenha um
método específico para a conversão do tipo string para o respectivo tipo que está lendo.
Informações de configurações ou necessárias para executar a leitura dos dados devem ser
inseridas na instanciação do objeto que fará a leitura. Como exemplo, podemos citar tais dados:
• Caractere que delimita cada célula da linha
• Nome do arquivo
• Máximo de linhas
• Máximo de colunas
A implementação deve ser capaz de ler diferentes quantidades de linhas e colunas sem a
necessidade de especificar a quantidade exata, apenas o limite máximo (se necessário) para
cada.
A classe implementada deve estar em um arquivo chamado read_csv.h, o qual deve ser
importado no outro arquivo <Nome>_<Sobrenome>.cpp através da instrução:
#include “read_csv.h”. Neste arquivo é implementado a função principal (main) a qual
deverá conter as instruções necessárias para utilizar a classe desenvolvida. Dentro da main, faça
a leitura dos dois arquivos
