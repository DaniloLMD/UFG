#include <iostream>

using namespace std;

int main(){
    int N;

    cin >> N;
    string anterior = "1";
    string atual = "1";

    int cont = 2;
    while(--N){
        if(cont < 10){
            atual.push_back('0' + cont);
        }else{
            atual.push_back('0' + (cont/10));
            atual.push_back('X');
            atual.push_back('0' + (cont%10));
        }

        atual += anterior;
        anterior = atual;
        cont++;
    }

    for(int i = 0; i < atual.size(); i++){
        printf("%c", atual[i]);
        if(i+1 != atual.size()){
            if(atual[i+1] == 'X'){
                printf("%c", atual[i+2]);
                i+=2;
            }
        }
        printf(" ");
        //if(i+1 != atual.size()) printf(" ");
    }
   cout << '\n';
   return 0;
}