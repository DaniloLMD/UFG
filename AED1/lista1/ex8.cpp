//questao 8
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int qtd_pessoas, qtd_linhas;
    int qtd_familias;
    int pai, filho, t;

    cin >> qtd_pessoas >> qtd_linhas;

    vector<int> familias(qtd_pessoas);
    qtd_familias = qtd_pessoas;

    for(int i = 0; i < qtd_pessoas; i++){
        familias[i] = i;
    }

    for(int a = 0; a < qtd_linhas; a++){
        cin >> pai >> filho;
        pai--;
        filho--;
        if(pai < filho){
            t = pai;
            pai = filho;
            filho = t;
        }

        if(familias[filho] < 0){
            t = familias[pai];
            for(int i = 0; i < familias.size(); i++){
                if(familias[i] == t && familias[i] != familias[filho]){
                    familias[i] = familias[filho];
                    qtd_familias--;
                }
            }
        }
        else if(familias[pai] < 0){
            t = familias[filho];
            for(int i = 0; i < familias.size(); i++){
                if(familias[i] == t && familias[i] != familias[pai]){
                    familias[i] = familias[pai];
                    qtd_familias--;
                }
            }

        }
        else{
            if(familias[filho] != familias[pai]) qtd_familias--;
            familias[filho] = -familias[pai];
            familias[pai] = -familias[pai];
        }
    }


    cout << qtd_familias << endl;
    return 0;
}