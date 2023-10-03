#include <iostream>
#include <vector>

using namespace std;

int main(){
    int qtd;
    string pessoas;
    int peso_atual = 0, maior_peso = 0, peso_certo;
    int acertos = 0, maior_acertos = 0;

    cin >> qtd;
    cin >> pessoas;

    vector<int> peso(qtd);
    vector<int> peso_criancas(qtd);
    vector<int> peso_adultos(qtd);

    for(int i = 0; i < qtd; i++){
        cin >> peso[i];
        if(peso[i] > maior_peso) maior_peso = peso[i];
    }

    for(peso_atual = 0; peso_atual <= maior_peso + 1; peso_atual++){

        acertos = 0;
        for(int i = 0; i < qtd; i++){
            if(pessoas[i] == '0' && peso[i] < peso_atual){
                acertos++;
            }
            else if(pessoas[i] == '1' && peso[i] >= peso_atual){
                acertos++;  
            }
        }

        if(acertos > maior_acertos){
            maior_acertos = acertos;
            peso_certo = peso_atual;
        }
    }

    cout << maior_acertos << endl;

    



    return 0;
}