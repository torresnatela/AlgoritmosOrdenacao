#include <iostream>
#include <cstdio>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

//funcao do menu
void MenuFunc(){
    std::cout << "------------------------Seja bem vindo aos algoritmos de ordenação------------------------\n";
    cout << "Digite a operação que voce deseja realizar" << endl;
    cout << "0 - Definir um novo Vetor de inteiros Aleatorio" << endl;
    cout << "1 - Imprime vetor de inteiros aleatorio" << endl;
    cout << "2 - Ordenação pelo metodo bolha" << endl;
    cout << "3 - Ordenação pelo metodo seleçao" << endl;
    cout << "4 - Ordenação pelo metodo Insercao" << endl;
}
/*-------------------------------------------------------------------------------------------------------------*/

//Funçoes de Seleçao
#define Troca(A, B) {int c = A; A = B; B = c;}
//Algoritmo Bolha
void Bolha (int *v, int n){
    for(int i = 0; i < n-1; i++){
        for (int j = 1; j < n-i; j++){
            if(v[j] < v[j-1]){
                Troca(v[j-1], v[j]);
            }
        }
    }
}
//Algoritmo de Seleçao
void Selecao(int *v, int n){
    int Min;

    for(int i = 0; i<n-1; i++){
        Min = i;
        for(int j = i+1; j < n; j++){
            if(v[Min] > v[j]) Min = j;
        }
        Troca(v[i], v[Min]);
    }

}
//Insercao
void Insercao(int *v, int n){
    int j;
    int aux;

    for (int i = 1; i < n; i++){
        aux = v[i];
        j = i-1;
        while((j>=0) && (aux < v[j])){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }  
}


int main()
{
    int operacao;

    int n = 1000;
    int VectorOrdenacao[1000];

    while (scanf("%d", &operacao) != EOF){

        MenuFunc();
        switch (operacao){

        case 0:
            for (int i = 0; i < n; i++){
                int v = rand() % n;
                VectorOrdenacao[i] = v;
            }
            cout << "Vetor Aleatorio definido" << endl;
            break;

        case 1:
            for (int i = 0; i < n; i++){
                cout << VectorOrdenacao[i] << " ";
            }
            cout << "\n";
            break;
        
        case 2:
            {
            auto start = high_resolution_clock::now();
            Bolha(VectorOrdenacao, n);
            auto stop = high_resolution_clock::now();

            //duration representa o tempo gasto pelo algoritmo
            auto duration = duration_cast<microseconds>(stop - start).count();

            cout << "Tempo levado pela funçao " << duration << " microseconds" << endl;
            break;
            }
        case 3:
            {
            auto start1 = high_resolution_clock::now();
            Selecao(VectorOrdenacao, n);
            auto stop1 = high_resolution_clock::now();

            //duration representa o tempo gasto pelo algoritmo
            auto duration1 = duration_cast<microseconds>(stop1 - start1).count();

            cout << "Tempo levado pela funçao " << duration1 << " microseconds" << endl;
            break;
            }
        case 4:
            {
            auto start1 = high_resolution_clock::now();
            Insercao(VectorOrdenacao, n);
            auto stop1 = high_resolution_clock::now();

            //duration representa o tempo gasto pelo algoritmo
            auto duration1 = duration_cast<microseconds>(stop1 - start1).count();

            cout << "Tempo levado pela funçao " << duration1 << " microseconds" << endl;
            break; 
            }
        }
    }
}