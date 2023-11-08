#include <iostream>
#include <vector>

using namespace std;

const long int modulo = 1e9+7;

vector<vector<long long int>> mult_matrix(vector<vector<long long int>>& a, vector<vector<long long int>>& b){
        vector<vector<long long int>> resultado = {{0,0}, {0,0}};
        
        resultado[0][0] += ((((a[0][0] % modulo) * (b[0][0] % modulo)) %modulo) + ((a[0][1] % modulo) * (b[1][0] % modulo))) % modulo;
        
        resultado[0][1] += ((((a[0][0] % modulo) * (b[0][1] % modulo)) %modulo) + ((a[0][1] % modulo) * (b[1][1] % modulo))) % modulo;
        
        resultado[1][0] += ((((a[1][0] % modulo) * (b[0][0] % modulo)) %modulo) + ((a[1][1] % modulo) * (b[1][0] % modulo))) % modulo;
        
        resultado[1][1] += ((((a[1][0] % modulo) * (b[0][1] % modulo)) %modulo) + ((a[1][1] % modulo) * (b[1][1] % modulo))% modulo) % modulo;
        
        
        
        

        return resultado;
}

void pot(vector<vector<long long int>>& matriz, int exp){

    if(exp == 0){
        matriz = {{0, 0}, {0, 0}};
    }
    else if(exp == 1) return;

    else if(exp > 1){
        if(exp%2 == 0){
            matriz = mult_matrix(matriz, matriz);
            pot(matriz, exp/2);
        }else{
            vector<vector<long long int>> t = matriz;
            matriz = mult_matrix(matriz, matriz);
            pot(matriz, exp/2);
            matriz = mult_matrix(matriz, t);
        }
    }
}

int main(){
    int termo;
    vector<vector<long long int>> base = {{0, 1}, {1, 1}};

    cin >> termo;

    pot(base, termo);

    cout << base[0][1] << endl;

    return 0;
}