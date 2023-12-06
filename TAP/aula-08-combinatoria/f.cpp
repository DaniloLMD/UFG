#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll l;
    cin >> l;

    ll res = 1;

    for(int i = 1; i <= 11; i++){
        res = (res * (l-i)) / i;
    }

    cout << res << endl;

    return 0;
}