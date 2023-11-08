#include <iostream>
#include <vector>

using namespace std;

const long long int mod = 1e9 + 7;

vector<vector<long long int>> mull_matrix(vector<vector<long long int>> matrix1, vector<vector<long long int>> matrix2){
    vector<vector<long long int>> retorno = {{0,0},{0,0}};
    for(int linha = 0; linha < 2; linha++){
        for(int coluna = 0; coluna < 2; coluna++){
            for(int k = 0; k < 2; k++){
                retorno[linha][coluna] += ((matrix1[linha][k] % mod) * (matrix2[k][coluna] % mod))%mod;
                retorno[linha][coluna] = retorno[linha][coluna]%mod;
            }
        }
    }
    return retorno;
}

void fibo(vector<vector<long long int>> &matrix, long long int exp){
    if(exp == 0){
        matrix = {{0,0}, {0,0}};
    }else if(exp == 1){
        return;
    }else if(exp > 1){
        if(exp % 2 == 0){
            matrix = mull_matrix(matrix, matrix);
            fibo(matrix, exp/2);
        }else{
            vector<vector<long long int>> nova = matrix;
            matrix = mull_matrix(matrix, matrix);
            fibo(matrix, exp/2);
            matrix = mull_matrix(matrix, nova);
        }
    }
}

int main(){
    long long int exp;
    vector<vector<long long int>> mat_fibo = {{1,1},{1,0}};
    cin >> exp;
    fibo(mat_fibo, exp);
    cout << mat_fibo[1][0] << endl;
    return 0;
}