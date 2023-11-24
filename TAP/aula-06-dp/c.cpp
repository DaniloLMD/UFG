#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll modulo = 1e9+7;

ll conta(vector<ll>& degraus, vector<bool>& quebrados, int degrau_atual){

    if(quebrados[degrau_atual]){
        degraus[degrau_atual] = 0;
        return degraus[degrau_atual];
    }

    if(degrau_atual == 0){
        degraus[0] = 1;
        return degraus[0];
    }

    if(degrau_atual == 1){
        if(quebrados[1]){
            degraus[1] = 0;
        }
        else{
            degraus[1] = 1;
        }

        return degraus[1];
    }

    if(degraus[degrau_atual] >= 0){
        return degraus[degrau_atual];
    }

    degraus[degrau_atual] = (conta(degraus, quebrados, degrau_atual-1) % modulo + conta(degraus, quebrados, degrau_atual-2) % modulo ) % modulo;

    return degraus[degrau_atual];
}

int main(){
    ll N, M, index;

    cin >> N >> M;

    vector<ll> degraus(N+1, -1);
    vector<bool> quebrados(N, false);

    for(int i = 0; i < M; i++){
        cin >> index;
        quebrados[index] = true;
    }

    cout << conta(degraus, quebrados, N) << "\n";

    return 0;
}