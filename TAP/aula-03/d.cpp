#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int busca_binaria(vector<int> v, int l, int r, int chave){
    int c;

    if(l <= r){
        c = l + (r-l)/2;
        if(v[c] == chave){
            return c;
        }
        else if(v[c] > chave){
           // r = c;
           return busca_binaria(v, l, c-1, chave);
        }   
        else if(v[c] < chave){
            //l = c;
            return busca_binaria(v, c+1, r, chave);
        }
    }

    return -1; //nao achou a chave no vetor
}

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
            q = busca_binaria(bolas, 0, bolas.size()-1, busca);
            q++;
            if(q == 0){
                cout << busca << " not found\n";
            }
            else{
                cout << busca << " found at " << q << endl;
            }
        }

    }

    return 0;
}