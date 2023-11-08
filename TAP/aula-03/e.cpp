#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd, n, total = 0;

    cin >> qtd;
    vector<int> grupos(qtd);

    for(int c = 0; c < qtd; c++){
        cin >> n;
        grupos[c] = total+1;
        total += n;
    }

    cin >> qtd;
    for(int c = 0; c < qtd; c++){
        cin >> n;
        cout << grupos.size() + (upper_bound(grupos.begin(), grupos.end(), n) - grupos.end()) << endl;
    }

    return 0;
}