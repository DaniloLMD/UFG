#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<ll>> dp(m+1, vector<ll>(n+1));

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[j-1] == t[i-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int i = m-1;
    int j = n-1;

    string maior = "";

    while(i >= 0 && j >= 0){
        if(t[i] == s[j]){
            maior.push_back(t[i]);
            i--;
            j--;
        }

        else if(dp[i+1][j+1] > dp[i][j+1]){
            j--;
        }
        else i--;
    }

    reverse(maior.begin(), maior.end());

    cout << maior << endl;
    return 0;
}