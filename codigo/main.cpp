#include <iostream>
#include <string>
#include <filesystem>

#include "mochila.h"
#include "strassen.h"
#include "menu.h"

using namespace std;
using namespace chrono;
using std::filesystem::exists;

int main(){
    int op, op2, resp;
    
    welcome();
    desenvolvedores();
    
    do{
        print_opcoes();
        cin >> op;
        cin.ignore();
        system("cls");

        switch (op){

            case 1: 
                do{
                    print_matriz();
                    cin >> op2;
                    cin.ignore();
                    if (op2 == 1) {
                        do {
                            vector<vector<int>> a;
                            vector<vector<int>> b;
                            vector<vector<int>> c;
                            int tam;
                            string file_name;

                            cout << "Escreva o nome do arquivo teste (.txt): ";
                            cin >> file_name;

                            while(!exists(file_name)){
                                cout << "Arquivo nao encontrado." << endl;
                                cout << "Escreva o nome do arquivo teste (.txt): ";
                                cin >> file_name;
                            }

                            cout << "Arquivo encontrado com sucesso." << endl; 
                            system("cls");
                            
                            read_file_matrix(file_name, a, b, tam);

                            cout << "Matriz A" << endl;
                            print_matriz(a);

                            cout << "Matriz B" << endl;
                            print_matriz(b);

                            auto start = chrono::steady_clock::now();

                            c = matrix_mult(a, b);
                            cout << "Matriz resultante" << endl << endl;
                            print_matriz(c);

                            auto end = chrono::steady_clock::now();
                            auto elapsed_time = chrono::duration_cast<chrono::duration<double>>(end - start);
                            cout << "Tempo da multiplicacao normal: "  << elapsed_time.count() << " ms" << endl;

                            cout << "Deseja realizar outro teste?(1 - Sim | 0 - Nao) ";
                            cin >> resp; 
                            system("cls");
                            
                        }while(resp != 0);
                        system("cls");
                    }
                    else 
                        if (op2 == 2){
                            do{
                                vector<vector<int>> a;
                                vector<vector<int>> b;
                                vector<vector<int>> c;
                                int tam; 
                                string file_name;

                                cout << "Escreva o nome do arquivo teste (.txt): ";
                                cin >> file_name;

                                while(!exists(file_name)){
                                    cout << "Arquivo nao encontrado." << endl;
                                    cout << "Escreva o nome do arquivo teste (.txt): ";
                                    cin >> file_name;
                                }

                                cout << "Arquivo encontrado com sucesso." << endl; 
                                system("cls");

                                read_file_matrix(file_name, a, b, tam);

                                cout << "Matriz A" << endl;
                                print_matriz(a);

                                cout << "Matriz B" << endl;
                                print_matriz(b);
                                

                                auto start = chrono::steady_clock::now();
                                c = strassen(a,b);
                                cout << "Matriz resultante" << endl << endl;
                                print_matriz(c);

                                auto end = chrono::steady_clock::now();
                                auto elapsed_time = chrono::duration_cast<chrono::duration<double>>(end - start);
                                cout << "Tempo strassen: "  << elapsed_time.count() << " ms" << endl;

                                cout << "Deseja realizar outro teste?(1 - Sim | 0 - Nao) ";
                                cin >> resp;
                                system("cls");

                            }while(resp != 0);
                        system("cls");
                        }
                }while(op2 != 0);
                system("cls");
            break;
            
            case 2: 
                do{
                    print_mochila();
                    cin >> op2;
                    cin.ignore();
                    if (op2 == 1){
                        do{
                            int capacidade;
                            string file_name;
                            vector<int> pesos, valores, vetor_booleano;

                            cout << "Escreva o nome do arquivo teste (.txt): ";
                            cin >> file_name;

                            while(!exists(file_name)){
                                cout << "Arquivo nao encontrado." << endl;
                                cout << "Escreva o nome do arquivo teste (.txt): ";
                                cin >> file_name;
                            }

                            cout << "Arquivo encontrado com sucesso." << endl; 
                            system("cls");

                            read_file_mochila(file_name, valores, pesos, capacidade);
                            
                            cout << "Capacidade: " << endl << capacidade << endl << endl;
                            printVector("Pesos", pesos);
                            printVector("Valores", valores);

                            auto started = high_resolution_clock::now();
                            mochilaBoleana(pesos, valores, capacidade, vetor_booleano);
                            auto done = high_resolution_clock::now();

                            cout << endl;
                            printVectorBool("Vetor Booleano ", vetor_booleano);

                            std::cout << "Tempo da mochila em segundos1: " << duration_cast<seconds>(done-started).count() << endl;


                            cout << "Deseja realizar outro teste?(1 - Sim | 0 - Nao) ";
                            cin >> resp;
                            system("cls");
                        }while(resp != 0);
                    }
                }while(op2 != 0); 
                system("cls");
            break;
                
        default:
            break;
        }             
    }while(op != 0);

    return 0;
}