#ifndef MOCHILA_H
#define MOCHILA_H

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Descrição: Função para imprimir um vetor de inteiros.
// Entrada: O nome do vetor e o vetor a ser impresso.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: O vetor é impresso na saída padrão. 
void printVectorBool(string name, vector<int>v);

// Descrição: Função para imprimir um vetor de inteiros.
// Entrada: O nome do vetor e o vetor a ser impresso.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: O vetor é impresso na saída padrão. 
void printVector(string name, vector<int>v);

// Descrição: Função para imprimir uma matriz de inteiros.
// Entrada: A matriz a ser impressa.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: A matriz é impressa na saída padrão.
void printMatriz(vector<vector<int>> v);

// Descrição: Função para resolver o problema da mochila booleana usando programação dinâmica.
// Entrada: Vetores de pesos e valores, capacidade da mochila, e um vetor booleano resultante.
// Retorno: Nenhum.
// Pré-condição: Os vetores de pesos e valores devem ter o mesmo tamanho.
// Pós-condição: O vetor booleano indica quais itens foram selecionados para maximizar o valor na mochila.
void mochilaBoleana(vector<int> pesos, vector<int> valores, int capacidade, vector<int> &vetor_booleano);

// Descrição: Função para remover espaços em branco de uma string.
// Entrada: A string a ser modificada.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: A string é modificada removendo todos os espaços em branco.
void remove_spaces(string &str);

// Descrição: Função para ler um arquivo contendo informações sobre a mochila.
// Entrada: O nome do arquivo, vetores de valores e pesos, e a capacidade da mochila.
// Retorno: Nenhum.
// Pré-condição: O arquivo deve estar formatado corretamente.
// Pós-condição: Os vetores de valores e pesos e a capacidade são preenchidos com os valores do arquivo.
void read_file_mochila(string filename, vector<int> &valores, vector<int> &pesos, int &capacidade);

#endif