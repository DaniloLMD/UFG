//questao 13
#include <iostream>
#include <vector>

using namespace std;

int possiveis = 0;

bool labirinto(vector<vector<vector<int>>>& lab, int i_atual, int j_atual, vector<vector<bool>>& visitados){
    if(i_atual == 0 && j_atual == 0){
        return true;
    }
    else if(visitados[i_atual][j_atual] == true){
        return false;
    }
    
    int i, j;
    visitados[i_atual][j_atual] = true;
    i = lab[i_atual][j_atual][0];
    j = lab[i_atual][j_atual][1];

    labirinto(lab, i, j, visitados);
}

void controle(vector<vector<vector<int>>>& lab, int i, int j, int i_atual, int j_atual, vector<vector<bool>>& visitados, vector<vector<bool>>& testados){

    bool teste = labirinto(lab, i_atual, j_atual, visitados);
    if(teste == true) possiveis++;

    testados[i_atual][j_atual] = true;

    for(int a = 0; a < i; a++){
        for(int b = 0; b < i; b++){
            visitados[a][b] = false;
        }
    }

    j_atual++;
    if(j_atual == j){
        j_atual = 0;
        i_atual++;
    }

    if(testados[i-1][j-1] == false) controle(lab, i, j, i_atual, j_atual, visitados, testados);
}

int main(){

    int i, j, i_atual, j_atual;
    cin >> i >> j;

    vector<vector<vector<int>>> matrix3d (i, vector<vector<int>>(j, vector<int>(2)));
    vector<vector<bool>> visitados(i, vector<bool>(j));
    vector<vector<bool>> testados(i, vector<bool>(j));

    for(int c = 0; c < i; c++){
        for(int d = 0; d < j; d++){
            for(int e = 0; e < 2; e++){
                cin >> matrix3d[c][d][e];
            }
        }
    }
    
    controle(matrix3d, i, j, 0, 0, visitados, testados);

    cout << possiveis << endl;

    return 0;
}