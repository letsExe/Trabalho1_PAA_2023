#include <iostream>
#include "menu.h"

using namespace std;

// Descrição: Função para exibir uma mensagem de boas-vindas.
// Pré-condição: Nenhuma.
// Pós-condição: A mensagem de boas-vindas é exibida na saída padrão.
void welcome(){
	cout <<" __   __  __    _  ______   _______  ___________  _______  _______  ___      _______ " << endl;
	cout <<"|  | |  ||  |  | ||      | |       ||    ___    ||       ||   _   ||   |    |       |" << endl;
	cout <<"|  | |  ||   |_| ||  _    ||    ___||   |   |   ||_     _||  |_|  ||   |    |    ___|" << endl;
	cout <<"|  |_|  ||       || | |   ||   |___ |   |___|   |  |   |  |       ||   |    |   |___ " << endl;
	cout <<"|       ||  _    || |_|   ||    ___||     __   _|  |   |  |       ||   |___ |    ___|" << endl;
	cout <<"|       || | |   ||       ||   |___ |    |  |  |_  |   |  |   _   ||       ||   |___ " << endl;
	cout <<"|_______||_|  |__||______| |_______||____|  |____| |___|  |__| |__||_______||_______|" << endl;
	cout << endl;
}

// Descrição: Função para exibir os nomes dos desenvolvedores do trabalho.
// Pré-condição: Nenhuma.
// Pós-condição: Os nomes dos desenvolvedores são exibidos na saída padrão.
void desenvolvedores(){
	cout <<"O trabalho desenvolvido por:" << endl;
	cout <<" ->  Leticia Zanellatto de Oliveira" << endl;
	cout <<" ->  Renan de Lara Hipolito" << endl << endl;
}

// Descrição: Função para exibir o menu de opções do programa.
// Pré-condição: Nenhuma.
// Pós-condição: O menu de opções é exibido na saída padrão.
void print_opcoes(){
    cout <<"==========Menu de Opcoes========" << endl;
	cout <<"1 - Multiplicacao de Matrizes   " << endl;
	cout <<"2 - Problema da Mochila         " << endl;
	cout <<"0 - Sair                        " << endl;
	cout <<"Digite uma Opcao: ";
}

// Descrição: Função para exibir o submenu de multiplicação de matrizes.
// Pré-condição: Nenhuma.
// Pós-condição: O submenu é exibido na saída padrão.
void print_matriz(){
    cout <<"==========Multiplicacao de Matrizes========" << endl;
	cout <<"1 - Multiplicacao normal de Matrizes       " << endl;
	cout <<"2 - Algoritmo de Stressen                  " << endl;
	cout <<"0 - Sair                                   " << endl;
	cout <<"Digite uma Opcao: ";
}

// Descrição: Função para exibir o submenu do problema da mochila.
// Pré-condição: Nenhuma.
// Pós-condição: O submenu é exibido na saída padrão.
void print_mochila(){
    cout <<"==========Problema da Mochila=========" << endl;
	cout <<"1 - Algoritmo da Mochila              " << endl;
	cout <<"0 - Sair                              " << endl;
	cout <<"Digite uma Opcao: ";
}