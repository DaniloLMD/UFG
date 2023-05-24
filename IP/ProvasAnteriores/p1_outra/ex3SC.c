#include <stdio.h>
int main(){
    int dia, mes, ano, bissexto = 0;
    int qtdDias = 0;
    scanf("%d/%d/%d", &dia, &mes, &ano);
    
    if(ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) bissexto = 1;
    qtdDias = dia;

    switch(mes){
        case 12:
            qtdDias += 30;
        case 11:
            qtdDias += 31;
        case 10:
            qtdDias += 30;
        case 9:
            qtdDias += 31;
        case 8:
            qtdDias += 31; 
        case 7:
            qtdDias += 30;
        case 6:
            qtdDias += 31;
        case 5:
            qtdDias += 30;
        case 4:
            qtdDias += 31;
        case 3:
            qtdDias += 28 + bissexto;
        case 2:
            qtdDias += 31;
    }

    printf("NUMERO DE DIAS E %d\n", qtdDias);
    return 0;
}