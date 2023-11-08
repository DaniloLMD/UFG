#include <bits/stdc++.h>
using namespace std;

int main(){
    int q, n, busca, caso = 1;
    
    while(1){
        cin >> q >> n;
        if(q == 0 && n == 0) break;
        printf("CASE# %d:\n", caso++);

        vector<int> bolas(q);
        for(int c = 0; c < q; c++){
            cin >> bolas[c];
        }

        sort(bolas.begin(), bolas.end());

        for(int c = 0; c < n; c++){
            cin >> busca;
            q = lower_bound(bolas.begin(), bolas.end(), busca) - bolas.begin();
            
            if(bolas[q] == busca){
                cout << busca << " found at " << q+1 << endl;
            }
            else{
                cout << busca << " not found\n";
            }
        }

    }

    return 0;
}