#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void z_func_transtornada(string palavra){
    int tam = palavra.size();
    int l = 0, r = 0;
    vector<int> z(tam);
    vector<int> indices;

    for(int i = 1; i < tam; i++){
        if(i < r){
            z[i] = min(r - i, z[i - l]);
        }
        while(z[i] + i < tam && palavra[z[i]] == palavra[z[i] + i]){
            z[i]++;
        }
        if(z[i] + i > r){
            l = i;
            r = z[i] + i;
        }
        if(z[i] > 0){
            indices.push_back(i);
        }
    }

    for(int c = 0; c < indices.size(); c++){
        bool passou = true;

        for(int passo = 1; passo*indices[c] < tam; passo++){
            if(z[passo*indices[c]] != tam - passo*indices[c]){
                passou = false;
            }
        }

        if(passou){
           
            cout << indices[c] << " ";
        }
    }
    cout << tam << endl;
    
}

int main(){
    string palavra;
    cin >> palavra;
    z_func_transtornada(palavra);
        
    return 0;
}

/*
    abcabca
    -004001
*/