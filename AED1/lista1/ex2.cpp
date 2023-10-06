#include <iostream>

using namespace std;

unsigned long int fib(int termo){
    if(termo == 0){
        return 0;
    }
    else if(termo == 1){
        return 1;
    }
    else{
        return fib(termo-1) + fib(termo-2);   
    }
}

void print_fib_rec(int inicio, int fim){
    cout << fib(inicio);
    if(inicio == fim) cout << endl;
    else if(inicio < fim) cout << " ";

    if(inicio != fim) print_fib_rec(inicio+1, fim);
}

int main(){
    int qtd_termos;

    cin >> qtd_termos;

    
    print_fib_rec(0, qtd_termos);

    return 0;
}