//questao 11
#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

/*
    '#' barco
    'a' agua
    '*' barco ja registrado
    'X' tiro
*/

struct barco{
    int tamanho;
    vector<int> coord_i;
    vector<int> coord_j;
};

void procura_barco(vector<vector<char>>& m, int i, int j, int i_atual, int j_atual, barco* ship){

    //checa se faz parte do barco
    if(i_atual < i && j_atual < j && i_atual >= 0 && j_atual >= 0){
        if(m[i_atual][j_atual] == '#'){
            ship->tamanho++;
            ship->coord_i.push_back(i_atual);
            ship->coord_j.push_back(j_atual);
            m[i_atual][j_atual] = '*';
        }
    }

    //procura pra cima
    if(i_atual-1 >= 0){
        if(m[i_atual-1][j_atual] == '#'){
            procura_barco(m, i, j, i_atual-1, j_atual, ship);
        }
    }
    //procura pra direita
    if(j_atual+1 < j){
        if(m[i_atual][j_atual+1] == '#'){
            procura_barco(m, i, j, i_atual, j_atual+1, ship);
        }
    }
    //procura pra baixo
    if(i_atual+1 < i){
        if(m[i_atual+1][j_atual] == '#'){
            procura_barco(m, i, j, i_atual+1, j_atual, ship);
        }
    }
    //procura pra esquerda
    if(j_atual-1 >= 0){
        if(m[i_atual][j_atual-1] == '#'){
            procura_barco(m, i, j, i_atual, j_atual-1, ship);
        }
    }
}

int main(){
    int n_l, n_c;
    int qtd_tiros, i_tiro, j_tiro;
    int qtd_destruidos = 0;
    bool destruido;

    cin >> n_l >> n_c;
    vector<vector<char>>m(n_l, vector<char>(n_c));
    vector<barco> barcos;
    barco novo_barco;

    //lendo a matriz
    for(int l = 0; l < n_l; l++){
        for(int c = 0; c < n_c; c++){
            cin >> m[l][c];
        }
    }

    //procurando os barcos
    for(int l = 0; l < n_l; l++){
        for(int c = 0; c < n_c; c++){
            if(m[l][c] == '#'){
               novo_barco.coord_i.clear();
               novo_barco.coord_j.clear();
               novo_barco.tamanho = 0;
               procura_barco(m, n_l, n_c, l, c, &novo_barco);
               if(novo_barco.tamanho > 0) barcos.push_back(novo_barco);
            }
        }
    }

    //realizando os disparos
    cin >> qtd_tiros;
    while(qtd_tiros--){
        cin >> i_tiro >> j_tiro;
        i_tiro--;
        j_tiro--;
        m[i_tiro][j_tiro] = 'X';
    }

    //checando quais barcos foram destruidos
    for(int b = 0; b < barcos.size(); b++){
        destruido = true;

        for(int c = 0; c < barcos[b].tamanho; c++){
            if(m[barcos[b].coord_i[c]][barcos[b].coord_j[c]] == '*'){
                destruido = false;
            }
        }

        if(destruido) qtd_destruidos++;
    }
    
    cout << qtd_destruidos << endl;
    return 0;
}