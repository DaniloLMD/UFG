#include<stdio.h>

int main(){

    int contador;
    int num;
    int quadrado;

    scanf("%d", &num);

    if((num > 5) && (num < 2000)){

        for(contador = 2; contador <= num; contador += 2){
			if(contador % 2 == 0){
		        quadrado = contador * contador;
		        printf("%d^2 = %d\n", contador, quadrado);
	        }
        }

    }
	return 0;
}
