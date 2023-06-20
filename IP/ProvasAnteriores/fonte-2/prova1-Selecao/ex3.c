#include <stdio.h>
int main(){
    int dia, mes, ano, bissexto = 0;
    int qtdDias = 0;
    scanf("%d/%d/%d", &dia, &mes, &ano);
    
    if(ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) bissexto = 1;
    qtdDias = dia;
    if(mes > 1)  qtdDias += 31;
    if(mes > 2)  qtdDias += 28 + bissexto;
    if(mes > 3)  qtdDias += 31;
    if(mes > 4)  qtdDias += 30;
    if(mes > 5)  qtdDias += 31; 
    if(mes > 6)  qtdDias += 30; 
    if(mes > 7)  qtdDias += 31; 
    if(mes > 8)  qtdDias += 31; 
    if(mes > 9)  qtdDias += 30;
    if(mes > 10) qtdDias += 31;
    if(mes > 11) qtdDias += 30;

    printf("NUMERO DE DIAS E %d\n", qtdDias);
    return 0;
}