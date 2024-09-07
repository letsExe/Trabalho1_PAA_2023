#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
#include <ctime>
#include <ratio>
#include <string>

#include "strassen.h"

using namespace std;

#define MAXn 80
#define MAXvalue 10

// Descrição: Função para gerar uma matriz quadrada.aa
// Pré-condição: Nenhuma.
// Pós-condição: Retorna a matriz gerada.
vector<vector<int>> gerar_matriz(int n){
    vector<vector<int>> v(n, vector<int>(n, 0)); // Inicializa uma matriz n x n com zeros
    return v;
}

// Descrição: Função para exibir os elementos de uma matriz.
// Pré-condição: Nenhuma.
// Pós-condição: Os elementos da matriz são exibidos na saída padrão.
void print_matriz(vector<vector<int>> mat){
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            cout << mat[i][j] << "\t"; // Exibe os elementos da matriz separados por tabulação
        }
        cout << endl; // Pula para a próxima linha após exibir uma linha completa da matriz
    }
    cout << endl; // Adiciona uma linha em branco após
}

// Descrição: Função para ler uma matriz de um arquivo.
// Pré-condição: O arquivo deve estar formatado corretamente.
// Pós-condição: As matrizes A e B são preenchidas com os valores do arquivo, e o tamanho é atualizado.
void read_file_matrix(string filename , vector<vector<int>> &A, vector<vector<int>> &B, int &size){
    std::string file, name_file;
    int end, start, num_matriz;
    int line, col, token, i, j;

    ifstream file_name(filename);

    start = num_matriz = i = j = 0;
    while (getline(file_name, file)){
        if (file.find("x") == -1){
            start = end = 0;
            if(num_matriz == 1){
                while (end != -1){
                    end = file.find(";", start);
                    token = stoi(file.substr(start, end - start));
                    A[i][j] = token;
                    j++;
                    start = end + 1;
                }
            }else {
                while (end != -1){
                    end = file.find(";", start);
                    token = stoi(file.substr(start, end - start));
                    B[i][j] = token;
                    j++;
                    start = end + 1;
                }
            }
            i++;
            j = 0;

        } else {
            i = j = 0;
            num_matriz++;

            if (num_matriz == 1){
                start = file.find("=") + 1;
                end = file.find("x");

                line = stoi(file.substr(start, end - start));

                start = end +1;
                end = file.length();

                col = stoi(file.substr(start, end - start));
                size = line;
                A = gerar_matriz(line);

            } else {
                start = file.find("=") + 1;

                end = file.find("x");
                line = stoi(file.substr(start, end - start));

                start = end +1;
                end = file.length();

                col = stoi(file.substr(start, end - start));
                B = gerar_matriz(line);
            }
        }  
    }
    file_name.close();
}

// Descrição: Função para adicionar zeros às linhas e colunas de uma matriz para torná-la de tamanho 2^n.
// Pré-condição: Nenhuma.
// Pós-condição: A matriz é modificada com zero-padding até a próxima potência de 2.
void add_zero(vector<vector<int>> &mat){
    int n = pow(2, ceil(log2(mat.size())));
    int i;

    for(i = 0; i < mat.size(); i++){
        for(int j = mat[i].size(); j < n; j++)
            mat[i].push_back(0);
    }
    
    for(i = mat.size(); i < n; i++){
        mat.push_back(vector <int> (n, 0));
    }
}

// Descrição: Função para realizar a adição de duas matrizes.
// Pré-condição: Ambas as matrizes têm as mesmas dimensões.
// Pós-condição: Retorna a matriz resultante da adição
vector<vector<int>> matrix_add(vector<vector<int>> matA, vector<vector<int>> matB){
    for(int i = 0; i <matA.size(); i++){
        for(int j = 0; j < matA[0].size(); j++){
            matA[i][j] = matA[i][j] + matB[i][j];
        }
    }
    return matA;
}

// Descrição: Função para realizar a subtração de duas matrizes.
// Pré-condição: Ambas as matrizes têm as mesmas dimensões.
// Pós-condição: Retorna a matriz resultante da subtração.
vector<vector<int>> matrix_sub(vector<vector<int>> matA, vector<vector<int>> matB){
    for(int i = 0; i < matA.size(); i++){
        for(int j = 0; j < matA[i].size(); j++)
            matA[i][j] = matA[i][j ]- matB[i][j];
    }
    return matA;
}

// Descrição: Função para realizar a multiplicação de duas matrizes usando o algoritmo convencional.
// Pré-condição: O número de colunas de 'a' deve ser igual ao número de linhas de 'b'.
// Pós-condição: Retorna a matriz resultante da multiplicação.
vector<vector<int>> matrix_mult(vector<vector<int>> matA, vector<vector<int>> matB){
    int original_size = matA.size();
    int sum = 0;
    vector<vector<int>> matC(original_size, vector<int>(original_size,0));

        for(int i = 0; i < original_size; i++){
            for(int j = 0; j < original_size; j++){
                for(int k = 0; k < original_size; k++){
                    sum += matA[i][k] * matB[k][j];
                }
                matC[i][j] = sum;
                sum = 0;
            }
        }
        return matC;
}

// Descrição: Função para realizar a multiplicação de duas matrizes usando o algoritmo de Strassen.
// Pré-condição: Ambas as matrizes devem ser quadradas e do mesmo tamanho.
// Pós-condição: Retorna a matriz resultante da multiplicação.
vector<vector<int>> strassen(vector<vector<int>> matA, vector<vector<int>> matB){
    add_zero(matA);
    add_zero(matB);

    int original_size = matA.size();
    int n = matA.size();
    int i, j, k;

    vector<vector<int>> c(original_size,vector<int>(original_size,0));
    vector<vector<int>> d(original_size,vector<int>(original_size,0));

    if(n <= 64){ 
        return c = matrix_mult(matA, matB);
    }

    vector<vector<int>> a1(n/2);
    vector<vector<int>> a2(n/2);
    vector<vector<int>> a3(n/2);
    vector<vector<int>> a4(n/2);

    vector<vector<int>> b1(n/2);
    vector<vector<int>> b2(n/2);
    vector<vector<int>> b3(n/2);
    vector<vector<int>> b4(n/2);

    for(i = 0, k = 0; i < n/2; i++, k++){
        for(j=0; j < n/2; j++){
            a1[k].push_back(matA[i][j]);
            b1[k].push_back(matB[i][j]);
        }
        for(; j < n; j++){
            a2[k].push_back(matA[i][j]);
            b2[k].push_back(matB[i][j]);
        }
    }
    for(k = 0; i < n; i++, k++){
        for(j = 0; j < n/2; j++){
            a3[k].push_back(matA[i][j]);
            b3[k].push_back(matB[i][j]);
        }
        for(; j < n; j++){
            a4[k].push_back(matA[i][j]);
            b4[k].push_back(matB[i][j]);
        }
    }

    vector<vector<int>> p1 = strassen(a1, matrix_sub(b2, b4));
    vector<vector<int>> p2 = strassen(matrix_add(a1, a2), b4);
    vector<vector<int>> p3 = strassen(matrix_add(a3,a4),b1);
    vector<vector<int>> p4 = strassen(a4, matrix_sub(b3, b1));
    vector<vector<int>> p5 = strassen(matrix_add(a1, a4), matrix_add(b1, b4));
    vector<vector<int>> p6 = strassen(matrix_sub(a2, a4), matrix_add(b3, b4));
    vector<vector<int>> p7 = strassen(matrix_sub(a1,a3), matrix_add(b1, b2));

    vector<vector<int>> x1 = matrix_add(matrix_add(p5, p4), matrix_sub(p6, p2));
    vector<vector<int>> x2 = matrix_add(p1, p2);
    vector<vector<int>> x3 = matrix_add(p3, p4);
    vector<vector<int>> x4 = matrix_add(matrix_sub(p1, p3), matrix_sub(p5, p7));

    for(i = 0; i < n/2; i++){
        for(j = 0; j < n/2; j++)
            c[i][j] = x1[i][j];

        for(j = n/2; j < original_size; j++)
            c[i][j] = x2[i][j - n/2];
    }
    for(i = n/2; i < original_size; i++){
        for(j = 0; j < n/2; j++)
            c[i][j] = x3[i - (n/2)][j];

        for(j = n/2; j < original_size; j++)
            c[i][j] = x4[i - (n/2)][j - (n/2)];
    }

    return c;
}