#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){

    vector<long int> adultos(0);
    vector<long int> criancas(0);
    string pessoas;    
    long int qtd_pessoas;
    long int peso;
    long int maior_acertos = 0;
    long int crianca_atual = 0, criancas_leves = 0;

    cin >> qtd_pessoas;
    cin >> pessoas;

    for(int c  = 0; c < qtd_pessoas; c++){
        cin >> peso;

        if(pessoas[c] == '0'){ //crianca
            criancas.push_back(peso);
        }else if(pessoas[c] == '1'){ // adulto
            adultos.push_back(peso);
        }
    }

    sort(criancas.begin(), criancas.end());
    sort(adultos.begin(), adultos.end());

    //checando se tem apenas adultos
    if(criancas.size() == 0){
        cout << adultos.size() << endl;
    }
    //checando se tem apenas criancas
    else if(adultos.size() == 0){
        cout << criancas.size() << endl;
    }
    else{
        for(int c = 0; c < adultos.size(); c++){

            for(int c2 = crianca_atual; c2 < criancas.size(); c2++){
                //verificando se a crianca atual e mais pesada
                if(criancas[c2] >= adultos[c]){
                    break;
                }
                //aumentando a quantidade de criancas mais leves
                else{
                    criancas_leves++;
                }

                crianca_atual++;
            }
            //maior acertos = quantidade de adultos + quantidade de criancas leves - quantidade de adultos verificados
            if(adultos.size() + criancas_leves - c >= maior_acertos){
                maior_acertos = adultos.size() + criancas_leves - c;
            }

        }

        cout << maior_acertos << endl;
    }




    return 0;
}
