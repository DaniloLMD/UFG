#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll mod = 1e9+7; 

    int n;
    cin >> n;

    vector<vector<char>>matrix(n, vector<char>(n));
    vector<vector<ll>>paths(n, vector<ll>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
            if(matrix[0][0] == '*'){
                printf("0\n");
                return 0;
            }
        }
    }

    paths[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == '*') continue;
            if(i-1 >= 0){
                paths[i][j] = ((paths[i][j] % mod) + (paths[i-1][j] % mod)) % mod;
            }
            if(j-1 >= 0){
                paths[i][j] = ((paths[i][j] % mod) + (paths[i][j-1] % mod)) % mod; 
            }
        }
    }

    cout << paths[n-1][n-1]  % mod << "\n";

    return 0;
}


/*
    2...
    .*..

*/