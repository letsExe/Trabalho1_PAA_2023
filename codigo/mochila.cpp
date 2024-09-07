#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <algorithm>
#include "mochila.h"

using namespace std;

// Descrição: Função para imprimir um vetor de inteiros.
// Pré-condição: Nenhuma.
// Pós-condição: O vetor é impresso na saída padrão.
void printVectorBool(string name, vector<int> v){
    cout << name << ":" << endl;
    for (int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl << endl;
}

// Descrição: Função para imprimir um vetor de inteiros.
// Pré-condição: Nenhuma.
// Pós-condição: O vetor é impresso na saída padrão.
void printVector(string name, vector<int> v){
    cout << name << ":" << endl;
    for (int i = 1; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl << endl;
}

// Descrição: Função para imprimir uma matriz de inteiros.
// Pré-condição: Nenhuma.
// Pós-condição: A matriz é impressa na saída padrão.
void printMatriz(vector<vector<int>> v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.at(i).size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl << endl;
    }
}

// Descrição: Função para resolver o problema da mochila booleana usando programação dinâmica.
// Pré-condição: Os vetores de pesos e valores devem ter o mesmo tamanho.
// Pós-condição: O vetor booleano indica quais itens foram selecionados para maximizar o valor na mochila.
void mochilaBoleana(vector<int> pesos, vector<int> valores, int capacidade, vector<int> &vetor_booleano){
    vector<vector<int>> mochila(pesos.size(), vector<int>(capacidade + 1));

    for (int i = 1; i < pesos.size(); i++){
        for (int j = 1; j <= capacidade; j++){
            mochila[i][j] = mochila[i - 1][j];
            if (pesos[i] <= j && (valores[i] + mochila[i - 1][j - pesos[i]] > mochila[i][j])){
                mochila[i][j] = valores[i] + mochila[i - 1][j - pesos[i]];
            }
        }
    }

    for (int i = 0; i < pesos.size(); i++){
        for (int j = 0; j <= capacidade; j++){
            //cout << "[" << mochila[i][j] << "]";
        }
        //cout << endl;
    }

    for (int i = pesos.size() - 1; i > 0; i--){
        if (mochila[i][capacidade] == mochila[i - 1][capacidade]){
            vetor_booleano.insert(vetor_booleano.begin(), 0);
        }
        else{
            vetor_booleano.insert(vetor_booleano.begin(), 1);
            capacidade = capacidade - pesos[i];
        }
    }
}

// Descrição: Função para remover espaços em branco de uma string.
// Pré-condição: Nenhuma.
// Pós-condição: A string é modificada removendo todos os espaços em branco.
void remove_spaces(string &str){
    str.erase(remove_if(str.begin(), str.end(), ::isblank), str.end());
}

// Descrição: Função para ler um arquivo contendo informações sobre a mochila.
// Pré-condição: O arquivo deve estar formatado corretamente.
// Pós-condição: Os vetores de valores e pesos e a capacidade são preenchidos com os valores do arquivo.
void read_file_mochila(string filename, vector<int> &valores, vector<int> &pesos, int &capacidade){
    ifstream file(filename);
    string line;
    string subs;
    int begin;
    int end;
    int token;

    pesos.push_back(0);
    valores.push_back(0);
    while (getline(file, line)){
        if (line.find("C") != -1){
            begin = line.find("=") + 1;
            end = line.length();
            subs = line.substr(begin, end - begin);
            remove_spaces(subs);
            capacidade = stoi(subs);
        }
        else if (line.find("V") != -1){
            begin = line.find("=") + 1;
            end = line.find(";", begin);

            while (end != -1){
                subs = line.substr(begin, end - begin);
                remove_spaces(subs);
                token = stoi(subs);
                valores.push_back(token);
                begin = end + 1;
                end = line.find(";", begin);
            }
        }
        else if (line.find("P") != -1){
            begin = line.find("=") + 1;
            end = line.find(";", begin);

            while (end != -1){
                subs = line.substr(begin, end - begin);
                remove_spaces(subs);
                token = stoi(subs);
                pesos.push_back(token);
                begin = end + 1;
                end = line.find(";", begin);
            }
        }
    }
}
