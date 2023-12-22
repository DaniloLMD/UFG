#include <iostream>
#include <vector>

using namespace std;
#define ll long long

ll pot(int base, int exp){
    if(exp == 0)
        return 1;

    ll p = pot(base, exp>>1);
    p *= p;

    if(exp&1)
        p *= base;

    return p;
}

int main(){
    int k;
    ll n;
    ll res = 0;

    cin >> n >> k;

    vector<ll> primos(k);
    for(int i = 0; i < k; i++){
        cin >> primos[i];
    }

    ll atual = 1, max = 1<<k , tmp, count, comb;
    
    while(atual != max){

        count = 0;
        comb = 1;
        tmp = atual;

        for(int i = 0; i < k; i++){
            if(tmp%2 == 1){
                
                count++;
                if(n / primos[i] < comb){
                    goto invalido;
                }
                comb *= primos[i];


            }

            tmp = tmp >> 1;
        }

        if(count&1){
            res += n/comb;
        }
        else{
            res -= n/comb;
        } 

        invalido:

        atual++;
    }

    cout << res << endl;

    return 0;
}