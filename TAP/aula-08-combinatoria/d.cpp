#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;
    vector<int> c(n);

    ll mod = 1e9+7;
    ll r = 1;

    for(int i = 0; i < n; i++)
        cin >> c[i];

    sort(c.begin(), c.end());

    for(int i = 0; i < n; i++){
        r = ((r%mod) * (c[i]-i)) % mod;
    }

    cout << r << endl;

    return 0;
}