#include <iostream>
#include <vector>

using namespace std;

bool tem_contest(int val){
    return val == 1 || val == 3;
}

bool tem_gym(int val){
    return val == 2 || val == 3;
}

int minimo(int a, int b, int c = -1){
    int min = a;
    if(b < min) min = b;
    if(c < min && c != -1) min = c;
    return min;
}

int main(){
    int dias, hoje;

    cin >> dias;

    vector<vector<int>> dp(dias+1, vector<int>(3, 0));

    for(int i = 1; i < dias+1; i++){
        cin >> hoje;
        
        dp[i][0] = minimo(dp[i-1][0], dp[i-1][1], dp[i-1][2]) + 1;

        if(!tem_contest(hoje)){
            dp[i][1] = dp[i-1][1] + 1;
        }
        else{
            dp[i][1] = minimo(dp[i-1][0], dp[i-1][2]);
        }

        if(!tem_gym(hoje)){
            dp[i][2] = dp[i-1][2] + 1;
        }
        else{
            dp[i][2] = minimo(dp[i-1][0], dp[i-1][1]);
        }
    }

    cout << minimo(dp[dias][0], dp[dias][1], dp[dias][2]) << "\n";

    return 0;
}