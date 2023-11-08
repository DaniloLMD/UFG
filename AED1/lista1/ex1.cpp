//questao 1
#include <iostream>
using namespace std;
 
void print_rec(int inicio, int fim){
    cout << inicio << " ";
    if(inicio != fim) print_rec(inicio+1, fim);
}
 
int main(){
    int num;
 
    cin >> num;
    print_rec(1, num);
    cout << endl;
 
    return 0;
}