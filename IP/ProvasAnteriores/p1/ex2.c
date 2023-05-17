#include <stdio.h>

int main(){
    int senha;
    char categoria;

    scanf("%d %c", &senha, &categoria);

    if(categoria != 'A' && categoria != 'G' && categoria != 'U'){
        printf("CATEGORIA INVALIDA: %c\n", categoria);
        return 0;
    }

    if(senha < 100000){
        printf("SENHA INVALIDA: %d - MINIMO 6 DIGITOS\n", senha);
    }

    if (senha == 321456 && categoria == 'A'){
        printf("ACESSO PERMITIDO A CATEGORIA %c\n", categoria);
    }else if(senha == 9510753 && categoria == 'G'){
        printf("ACESSO PERMITIDO A CATEGORIA %c\n", categoria);

    }else if(senha == 78955632 && categoria == 'U'){
        printf("ACESSO PERMITIDO A CATEGORIA %c\n", categoria);
    }else{
        printf("ACESSO NEGADO\n");
    }
    return 0;
}
/*
    A = 321456
    G = 9510753
    U = 78955632
*/