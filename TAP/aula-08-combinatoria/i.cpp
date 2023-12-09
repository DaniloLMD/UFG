#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;
#define ll long long

int main(){
    ll n;
    cin >> n;
    

    vector<ll> a(n);

    ll max = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > max)
            max = a[i];
    }

    vector<vector<ll>> b(max+1, vector<ll>());

    for(ll i = 0; i < n; i++){
        b[a[i]].push_back(i);
    }

    /*for(int i = 0; i < max+1; i++){
        cout << i << ": ";
        for(int j = 0; j < b[i].size(); j++){
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }*/


    ll res = 0;
    ll controle;
    for(int i = 0; i < max+1; i++){

        int size = b[i].size();
        for(int j = 0; j < size; j++){
            
            res += -1 * (size - 2 * j - 1) * b[i][j] - (j+1);
            //cout << -1 * (b[i].size() - 2 * j - 1) * b[i][j] - (j+1) << endl;
            cout << size - 2 * j - 1 << endl;
            /*controle = 1;
            res += b[i][k] - b[i][j] - controle;
            controle++;*/
        }
    }
    
    cout << res << endl;
    return 0;
}