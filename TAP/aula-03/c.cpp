#include <iostream>

using namespace std;

const long int modulo = 1e9+7;

long int pot(int base, int exp){
    if(exp == 0) return 1;

    long int p = pot(base % modulo, exp/2) % modulo;

    if(exp%2 == 0){
        return p % modulo * p % modulo;
    }else{
        return p % modulo * p % modulo * base % modulo;
    }

}

int main(){
    int qtd, base, exp;

    cin >> qtd;

    while(qtd--){
        cin >> base >> exp;

        cout << pot(base, exp) << endl;
    }

    return 0;
}