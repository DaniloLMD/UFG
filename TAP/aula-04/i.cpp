#include <iostream>
#include <vector>

using namespace std;

int mdc(int a, int b) { return b == 0 ? a : mdc(b, a % b);}

int gauss(int num){
    int div = 0;

    for(int c = 1; c * c <= num; c++){
        if(num % c == 0){
            div++;
            if(num/c != c) div++;  
        }
    }


    return div;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd, n1, n2;
    cin >> qtd;

    while(qtd--){
        cin >> n1 >> n2;

        cout << gauss(mdc(n1, n2)) << '\n';
    }

    return 0;
}