//questao 14
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

//algoritmo n! (muito lento!!) que vai fixando um FOR por vez, jeito de otimizar: utilizar arvore de combinação e DFS
void n_fatorial(int k , int anterior, vector<int> &numeros, int index_atual, int *maior){
    if(k == 1){
        for(int cont = index_atual; cont < numeros.size(); cont++){
            int calculo = anterior ^ numeros[cont];
            if(calculo > *maior){
                *maior = calculo;
            }
        }
    } else{
        for(int c = index_atual; c < numeros.size(); c++){
            n_fatorial(k - 1, numeros[c] ^ anterior, numeros, c+1, maior);
        }
    }
}

int main(){
    int casos_t;
    int n, k;
    int maior;
    cin >> casos_t;

    for(int caso = 0; caso < casos_t; caso++){
        maior = -INT_MAX;
        cin >> n >> k;
        vector<int> valores(n);
        vector<int> final;
        for(int val = 0; val < n; val++){
            cin >> valores[val];
        }

        n_fatorial(k, 0, valores,0, &maior);

        cout << maior << endl;
    }

    return 0;
}