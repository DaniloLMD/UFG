#include <iostream>
#include <vector>
using namespace std;

void hanoi(int qtd_discos, vector<int>& origem, vector<int>& destino, vector<int>& auxilliar){
    if(origem.size() == qtd_discos){
        destino.push_back(origem.back());
        origem.pop_back();

        hanoi(qtd_discos, origem, auxilliar, destino);
    }
    
}

int main(){

    int qtd_discos;
    cin >> qtd_discos;
    vector<int> origem(qtd_discos) ,destino(qtd_discos), auxiliar(qtd_discos);
    
    for(int i = 1; i <= qtd_discos; i++){
        origem[i-1] = i;
    }

    hanoi(qtd_discos, origem, destino, auxiliar);

    return 0;
}