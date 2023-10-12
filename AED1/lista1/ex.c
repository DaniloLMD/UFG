#include <stdio.h>

void towers(int nDiscos, char dePino, char paraPino, char auxPino) {
    /* Se um disco somente, mova−o e retorne */
    if(nDiscos==1) {
        printf("(%c,%c)\n", dePino, paraPino);
        return;
    }

    /* Move n−1 discos superiores de A para C, usando B */
    towers(nDiscos-1, dePino, auxPino, paraPino);
    
    /* Move discos restantes de A para B */
    printf("(%c,%c)\n",dePino,
    paraPino);

    /* Move n−1 discos de C para B usando A como auxiliar */
    towers(nDiscos-1, auxPino, paraPino, dePino);
 }

 int main(){    

    int num;
    scanf("%d", &num);
    towers(num, 'O', 'D', 'A');

    return 0;
 }