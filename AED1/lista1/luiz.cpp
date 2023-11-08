#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void forca_bruta(int k , int anterior, vector<int> &numeros, int indice_atual, int *maior){
    if(k == 1){
        for(int cont = indice_atual; cont < numeros.size(); cont++){
            int calculo = anterior ^ numeros[cont];
            if(calculo > *maior){
                *maior = calculo;
            }
        }
    } else{
        for(int cont = indice_atual; cont < numeros.size(); cont++){
            forca_bruta(k - 1, numeros[cont] ^ anterior, numeros, cont + 1, maior);
        }
    }
}

int main(){
    int casos_t;
    cin >> casos_t;
    for(int c = 0; c < casos_t; c++){
        int maior = -INT_MAX;
        int n, k;
        cin >> n >> k;
        vector<int> valores(n);
        vector<int> final;
        for(int d = 0; d < n; d++){
            cin >> valores[d];
        }
        forca_bruta(k, 0, valores,0, &maior);
        cout << maior << endl;
    }

    return 0;
}