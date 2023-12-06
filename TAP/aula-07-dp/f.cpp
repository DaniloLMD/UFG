#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct init_value{
    ll value = -1;
};


ll solve(map<ll, init_value>& calc, ll val){
    ll pre = calc[val].value;

    if(pre != -1){
        return pre;
    }

    if(val == 0){
        return calc[val].value = 0;
    }

    ll post = solve(calc, val/2) + solve(calc, val / 3) + solve(calc, val/4);

    return calc[val].value = max(val, post);

}

int main(){
    map<ll, init_value> calculated;
    ll value;
    while(cin >> value){
        cout << solve(calculated, value) << "\n";
    }

    return 0;
}