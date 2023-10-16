#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> z_func(string &palavra, string &padrao){
    string nova = padrao+'#'+palavra;
    int tam = nova.size();
    int r = 0, l = 0;
    int i2 = 0;
    vector<int> z(palavra.size());

    for(int i = padrao.size() + 1; i < tam; i++){
        i2 = i - (padrao.size() + 1);

        if(i < r){
            z[i2] = min(r - i, z[i2 - l]);
        }

        while(i + z[i2] < tam && nova[z[i2]] == nova[i + z[i2]]){
            z[i2]++;
        }
        
        if(i + z[i]> r){
            l = i2;
            r = i2 + z[i2];
        }
    }
    return z;
}

int main(){
    int qtd = 0;
    string palavra, padrao, nova;
    cin >> palavra >> padrao;
    vector<int> checa = z_func(palavra, padrao);
    
    for(int h: checa){
        if(h == padrao.size()){
            qtd++;
        }
    }

    cout << qtd << endl;

    return 0;
}