//questao 12
#include <iostream>
#include <vector>

using namespace std;

void labirinto(vector<vector<vector<int>>>& lab, int i_atual, int j_atual, vector<vector<bool>>& visitados){
    if(i_atual == 0 && j_atual == 0){
        cout << "VENCE\n";
        return;
    }
    else if(visitados[i_atual][j_atual] == true){
        cout << "PRESO\n";
        return;
    }

    int i, j;
    visitados[i_atual][j_atual] = true;
    i = lab[i_atual][j_atual][0];
    j = lab[i_atual][j_atual][1];

    labirinto(lab, i, j, visitados);
}


int main(){

    int i, j, i_atual, j_atual;
    cin >> i >> j;

    vector<vector<vector<int>>> matrix3d (i, vector<vector<int>>(j, vector<int>(2)));
    vector<vector<bool>> visitados(i, vector<bool>(j));

    for(int c = 0; c < i; c++){
        for(int d = 0; d < j; d++){
            for(int e = 0; e < 2; e++){
                cin >> matrix3d[c][d][e];
            }
        }
    }
    
    cin >> i_atual >> j_atual;

    labirinto(matrix3d, i_atual, j_atual, visitados);

    return 0;
}