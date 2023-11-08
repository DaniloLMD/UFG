//questao 5
#include <iostream>

using namespace std;

void bin(int num){
    if(num/2 != 0) bin(num/2);
    cout << num % 2;
}

int main(){
    int qtd, num, c;

    cin >> qtd;

    for(c = 0; c < qtd; c++){
        cin >> num;
        bin(num);
        cout << endl;
    }   

    return 0;   
}