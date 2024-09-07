#ifndef STRASSEN_H
#define STRASSEN_H

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
#include <ctime>
#include <ratio>
#include <string>

using namespace std;
#define MAXn 80
#define MAXvalue 10

// Descrição: Função para gerar uma matriz quadrada.
// Entrada: O tamanho da matriz (n).
// Retorno: A matriz gerada (n x n) preenchida com zeros.
// Pré-condição: Nenhuma.
// Pós-condição: Retorna a matriz gerada.
vector<vector<int>> gerar_matriz(int n);

// Descrição: Função para exibir os elementos de uma matriz.
// Entrada: A matriz a ser exibida.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: Os elementos da matriz são exibidos na saída padrão.
void print_matriz(vector<vector<int>> matA);

// Descrição: Função para ler uma matriz de um arquivo.
// Entrada: O nome do arquivo, referências para as matrizes A e B, e o tamanho da matriz.
// Retorno: Nenhum.
// Pré-condição: O arquivo deve estar formatado corretamente.
// Pós-condição: As matrizes A e B são preenchidas com os valores do arquivo, e o tamanho é atualizado.
void read_file_matrix(string filename , vector<vector<int>> &A, vector<vector<int>> &B, int &size);

// Descrição: Função para adicionar zeros às linhas e colunas de uma matriz para torná-la de tamanho 2^n.
// Entrada: A matriz a ser modificada.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: A matriz é modificada com zero-padding até a próxima potência de 2.
void add_zero(vector<vector<int>> &matA);

// Descrição: Função para realizar a adição de duas matrizes.
// Entrada: Duas matrizes a e b.
// Retorno: A matriz resultante da adição.
// Pré-condição: Ambas as matrizes têm as mesmas dimensões.
// Pós-condição: Retorna a matriz resultante da adição
vector<vector<int>> matrix_add(vector<vector<int>> matA, vector<vector<int>> matB);

// Descrição: Função para realizar a subtração de duas matrizes.
// Entrada: Duas matrizes a e b.
// Retorno: A matriz resultante da subtração.
// Pré-condição: Ambas as matrizes têm as mesmas dimensões.
// Pós-condição: Retorna a matriz resultante da subtração.
vector<vector<int>> matrix_sub(vector<vector<int>> matA, vector<vector<int>> matB);

// Descrição: Função para realizar a multiplicação de duas matrizes usando o algoritmo convencional.
// Entrada: Duas matrizes a e b.
// Retorno: A matriz resultante da multiplicação.
// Pré-condição: O número de colunas de 'a' deve ser igual ao número de linhas de 'b'.
// Pós-condição: Retorna a matriz resultante da multiplicação.
vector<vector<int>> matrix_mult(vector<vector<int>> matA,vector<vector<int>> matB);

// Descrição: Função para realizar a multiplicação de duas matrizes usando o algoritmo de Strassen.
// Entrada: Duas matrizes a e b.
// Retorno: A matriz resultante da multiplicação usando o algoritmo de Strassen.
// Pré-condição: Ambas as matrizes devem ser quadradas e do mesmo tamanho.
// Pós-condição: Retorna a matriz resultante da multiplicação.
vector<vector<int>> strassen(vector<vector<int>> matA,vector<vector<int>> matB);

#endif