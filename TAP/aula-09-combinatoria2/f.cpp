#include <iostream>
#include <vector>

using namespace std;
#define ll long long

ll pot(int base, int exp){
    if(exp == 0) return 1;
    ll p = pot(base, exp/2);
    p = (p*p);
    if(exp%2 == 1)
        p = (p*base);
    return p;
}

int main(){
    int k;
    ll n;

    cin >> n >> k;

    vector<ll> primos(k);
    for(int i = 0; i < k; i++)
        cin >> primos[i];

    ll res = 0;
    ll max = pot(2, k);
    ll atual = 0, temp, comb;

    while(atual != max){
        temp = atual;
        comb = 1;
        for(int i = 0; i < k; i++){
            if(temp%2)
                comb *= primos[i];
            
            temp = temp >> 1;
        }

        if(comb != 1)
            res = (res - (n/comb));

        atual++;
    }

    for(int i = 0; i < k; i++){
        res = (res + 2 * (n/primos[i]));
    }

    cout << res << endl;

    return 0;
}