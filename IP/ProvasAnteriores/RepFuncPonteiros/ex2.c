#include <stdio.h>

int primo(int x){
    int c;
    for(c = 2; c < x; c++){
        if(x % c == 0) return 0;
    }
    return 1;
}

int powEu(int x, int y){
    int z, res = 1;
    for(z = 1; z <= y; z++){
        res *= x;
    }
    return res;
}

int potencia_prima( int n, int * k, int * p ){
    *k = 2;
    *p = 1;
    while(*k <= n){
        if(primo(*k)){
        for(*p = 1; *p; *p += 1){
            if(powEu(*k, *p) == n){
                printf("%d : %d^%d\n", n, *k, *p);
                return 1;  
            }
            else if(powEu(*k, *p) > n) break;
            }
        }
        *k += 1;
    }
    return 0;
}

int main(){
    int qtd, cont = 0, num = 2;
    int base = 2, exp = 1;
    
    scanf("%d", &qtd);
    
    while(cont < qtd){
          cont += potencia_prima(num, &base, &exp);
          num++;
    }
    
    return 0;
}
