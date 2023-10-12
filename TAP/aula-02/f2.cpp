#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*     .     
    AB#ABC

*/

vector<int> z_function(string palavra, string padrao) {
    string nova = padrao+'#'+palavra;
    int n = nova.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && nova[z[i]] == nova[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
    int qtd = 0;
    string palavra, padrao, nova;
    cin >> palavra >> padrao;
    //nova = padrao + '#' + palavra;
    vector<int> checa = z_function(palavra, padrao);
    for(int h: checa){
        if(h == padrao.size()){
            qtd++;
        }
    }

    cout << qtd << endl;

    return 0;
}