#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    int k;

    cin >> n >> k;

    vector<ll> primes(k);

    for(int i = 0; i < k; i++)
        cin >> primes[i];

    vector<ll> count(k+1);

    for(int mask = 1; mask < (1<<k); mask++){
        int numberOfDivisors = 0;
        ll tmp = n;
        for(int i = 0; i < k; i++){
            if((1<<i)&mask){
                numberOfDivisors++;
                tmp /= primes[i];
            }
        }

        count[numberOfDivisors] += tmp;
    }

    ll answer = 0;

    for(int i = 1; i <= k; i++){
        if(i%2 == 0){
            answer -= count[i];
        }   
        else{
            answer += count[i];
        }
    }

    cout << answer << endl;


    return 0;
}