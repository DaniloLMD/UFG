#include <iostream>
using namespace std;

void print_rec(int inicio, int fim){
    cout << inicio;
    if(inicio < fim) cout << " ";
    else if(inicio == fim) cout << endl;
    if(inicio != fim) print_rec(inicio+1, fim);
}

int main(){
    int num;

    cin >> num;
    print_rec(1, num);

    return 0;
}