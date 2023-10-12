#include <iostream>
using namespace std;

int qtd_acertos = 0;
int valores = {2, 5, 10, 20, 50, 100};

void banco_inteligente(int saque, int notas[5]){
    int s = saque;
    int i = 0;
    if(saque % notas[i] == 0){
        if(saque / notas[i] <= notas[i]) qtd_acertos++;
    }
    else{
        s = saque / valores[i];
        s = saque - valores[i]*s;
    }
}

int main(){
    int saque, i;
    int notas[6];

    cin >> saque;

    for(i = 0; i < 6; i++){
        cin >> notas[i];
    }

    banco_inteligente(saque, notas);

    cout << qtd_acertos << endl;

    return 0;
}