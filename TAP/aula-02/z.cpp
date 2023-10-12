#include <iostream>
using namespace std;

int main(){
    string s;

    int n = s.size(); //tamanho de S
    int z[n] = {0}; //Z function

    int l = 0, r = 0; 

    for(int i = 1; i < n; i++) { //percorrendo caracter a caracter da string S
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }

        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }//
}