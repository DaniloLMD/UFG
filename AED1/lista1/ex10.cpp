//questao 10
#include <iostream>
#include <vector>

using namespace std;

int seguros = 0;

void percorre(vector<vector<char>>& m, int size, int i_atual, int j_atual, vector<vector<bool>>& visitados){
    

    if(i_atual < 0 || j_atual < 0 || i_atual == size || j_atual == size){
        return;
    }

    if(visitados[i_atual][j_atual] == true){
        printf("consegui para (%d,%d)\n", i_atual, j_atual);
        seguros++;
        return;
    }

    visitados[i_atual][j_atual] = true;

    switch(m[i_atual][j_atual]){
        case 'A':
            i_atual--;
            break;

        case 'V':
            i_atual++;
            break;
        case '>':
            j_atual++;
            break;

        case '<':
            j_atual--;
            break;
    }

    percorre(m, size, i_atual, j_atual, visitados);
    
}

void controle(vector<vector<char>>& m, int size, int i_atual, int j_atual, vector<vector<bool>>& visitados){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            visitados[i][j] = false;
        }
    }


    if(j_atual >= size){
        j_atual = 0;
        i_atual++;
    }

    if(i_atual >= size){
        return;
    }


    percorre(m, size, i_atual, j_atual, visitados);

    controle(m, size, i_atual, j_atual+1, visitados);
}

int main(){
    int n;
    cin >> n;

    vector<vector<char>> m(n, vector<char>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }  

    vector<vector<bool>> visitados(n, vector<bool>(n));
    controle(m, n, 0, 0, visitados);

    cout << seguros << endl;

    return 0;
}