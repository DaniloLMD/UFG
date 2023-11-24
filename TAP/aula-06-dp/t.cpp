#include <bits/stdc++.h>
using namespace std;
const int MAX= (int) 60;
const int MAX_N= (int) 1e4+10;

pair<int,int> lista[MAX]; // preco e qtd
int lista2[MAX]; // qtd que eu usei
signed char dp[MAX_N][MAX][MAX];
int n;

signed char solve(int sum, int i){
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(i == n) return 0;
    if(dp[sum][i][lista2[i]] != -1) return dp[sum][i][lista2[i]];
    if(lista2[i] < lista[i].second){
        lista2[i]++;
        if(solve(sum-lista[i].first,i)) return dp[sum][i][lista2[i]]=1;
        lista2[i]--;
    }
    if(solve(sum,i+1)) return dp[sum][i][lista2[i]]=1;
    return dp[sum][i][lista2[i]]=0;
}

int32_t main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int x;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> lista[i].first >> lista[i].second;
    }
    for(int i=0; i<=x; i++) for(int j=0; j<=n; j++) for(int k=0; k<=55; k++) dp[i][j][k] =-1;
    if(solve(x,0)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}