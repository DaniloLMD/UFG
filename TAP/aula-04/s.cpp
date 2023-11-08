#include <iostream>

using namespace std;

int gdc(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gdc(b, a % b);
    }
}

int qtd_div(int num){
    int k = 0;
    for(int c = 1; c * c <= num; c++){
        if(num % c == 0){
            k++;
            if(num / c != c){
                k++;
            }
        }   
    }
    return k;
}

int main(){
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
 
    while(n--){
        int checa1, checa2;
        cin >> checa1 >> checa2;
        cout << qtd_div(gdc(checa1, checa2)) << '\n';
    }
    
    return 0;
}