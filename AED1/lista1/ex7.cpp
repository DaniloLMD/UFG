//questao 7
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define max_index 5
#define qtd_notas 6

int saque, acertos = 0;
int peso[qtd_notas] = {2, 5, 10, 20, 50, 100};
int disponiveis[qtd_notas] = {0, 0, 0, 0, 0, 0};
int ultimo_index = 0;   

//guarda todas as combinacoes de notas, sem repeticoes
vector<string> controle;

void banco(int num_notas){
    if(saque / num_notas < 2) return;

    if(num_notas == 1){ 
        string temp = "0";
        for(int i = 0; i <= max_index; i++){
            controle.push_back(temp);
            temp[0]++;
        }
    } 

    else{
        string tmp;
        char nota_atual;
        bool iguais;
        int tam = controle.size();
        int i, i2, limite;    


        nota_atual = '0';
        limite = 0;
        for(i = 0; i < qtd_notas; i++){

            for(i2 = ultimo_index; i2 < tam; i2++){

                //gerando novas combinacoes
                tmp = controle[i2];
                tmp.push_back(nota_atual);

                //verificando se a combinacao ja foi calculada anteriormente
                if(limite > 0){
                    iguais = true;
                    for(int i3 = 0; i3 < tmp.size(); i3++){
                        if(tmp[i3] - '0' < limite){
                            iguais = false;
                            break;
                        }
                    }   
                    if(iguais == false) continue;
                }

                controle.push_back(tmp);
            }
            limite++;
            nota_atual++;
            ultimo_index++;
        }
        ultimo_index = i2;
    }

    banco(num_notas+1);
}

int main(){

    int soma, soma_total, index;
    int contador[qtd_notas] = {0, 0, 0, 0, 0, 0};
    cin >> saque;

    for(int i = 0; i < qtd_notas; i++){
        cin >> disponiveis[i];
    }

    banco(1);

    for(string h: controle){

        for(int i = 0; i < qtd_notas; i++){
            contador[i] = disponiveis[i];
        }

        soma = 0;
        soma_total = 0;
        for(int i = 0; i < h.size(); i++){
            index = h[i] - '0';

            if(contador[index] > 0) soma += peso[index];
            contador[index]--;

            soma_total += peso[index];
            //if(soma_total > saque) break;
        }

        if(soma == saque && soma_total <= soma){
            acertos++;
        }
    }


    cout <<  acertos << endl;

    return 0;
}