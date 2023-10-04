#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool **matriz;
bool *visitados; 

int i,j;
int qtd_vertices;
int origem, destino;

int cont, maior;

void zera_visitados(void){
    for(int c = 0; c < qtd_vertices; c++){
        visitados[c] = false;
    }
}

void busca(void){
    i = origem;
    cont = 0;
    zera_visitados();

    while(1){
        if(i == destino){
            cout << "Visitados: " << cont << endl;
            break;
        }

            
        for(j = 1; j < qtd_vertices; j++){
            if(matriz[i][j] == true && visitados[j] == false){
                visitados[j] = true;
                cout << visitados[j] << endl;
                i = j;
                cont++;
                break;
            }
        }

    }
}


int main(){

    cin >> qtd_vertices;

    cin >> origem;
    cin >> destino;

    qtd_vertices++;

    matriz = (bool**) calloc(qtd_vertices, sizeof(bool*));
    for(i = 0; i < qtd_vertices; i++) matriz[i] = (bool*) calloc(qtd_vertices, sizeof(bool));

    visitados = (bool*) calloc(qtd_vertices, sizeof(bool));

    cout << "Visitados[0] = " << visitados[0] << endl;
    
    for(int c = 1; c < qtd_vertices - 1; c++){
        cin >> i;
        cin >> j;
        matriz[i][j] = true;
        matriz[j][i] = true;
    }

    cout << origem << " ate " << destino << ": " << endl;
    busca();

    return 0;
}