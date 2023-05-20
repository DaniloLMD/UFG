#include <stdio.h>

int somaDivisores(int n){
    int c, ultimoDiv;
    int s = 0;

    for(c = 1; c < n; c++){
        if(n % c == 0){
            ultimoDiv = c;
        }
        
    }

    for(c = 1; c < n; c++){
        if (n % c == 0){
            s += c;
            printf("%d", c);
            if(c < ultimoDiv){
                printf(" + ");
            }
        }

    }
    return s;
}

int main(){
    int num;
    int soma;

    scanf("%d", &num);
    printf("%d = ", num);
    soma = somaDivisores(num);
    printf(" = %d", soma);
    if(soma == num){
        printf(" (NUMERO PERFEITO)");
    }else{
        printf(" (NUMERO NAO E PERFEITO)");
    }



    return 0;
}