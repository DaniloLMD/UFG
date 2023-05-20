#include <stdio.h>

int somaDiv(int x){
    int c, s = 0;
    for(c = 1; c <= (x/2); c++){
        if(x % c == 0){
            s += c;
        }
    }
    return s;
}

int main(){
    int qtd, exibidos = 0, cont = 1;
    int n1 = 220, s1 = 0, n2, s2 = 0;
    scanf("%d", &qtd);

    while(qtd > exibidos){
        s1 = somaDiv(n1);
        n2 = s1;
        s2 = somaDiv(n2);
        if(s2 == n1 && s1 == n2 && n1 < n2){
            printf("(%d,%d)\n", n1, n2);
            exibidos++;
        }
        n1++;
    }
    return 0;
}