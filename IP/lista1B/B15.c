#include <stdio.h>

int main(){
	int n;
	int num1 = 220;
	int num2 = 284;
	int divisores1, divisores2;
	int amigosExibidos = 0;
	int contador;
	
	scanf("%d", &n);
	
	if(n > 9){
		return 0;
	}
	while(amigosExibidos < n){
		for(contador = 1; contador < num1; contador++){
			if(num1 % contador == 0){
				divisores1 +=  contador;
			}
		}
		for(contador = 1; contador < num2; contador++){
			if(num2 % contador == 0){
				divisores2 +=  contador;
			}
		}
		
		if(divisores1 == num2 && divisores2 == num1 && num1 != num2){
			printf("(%d,%d)\n", num1, num2);
			amigosExibidos += 1;
			num2 = num1;
			num1++;
		}
		if(num2 >= 2*num1){
			num2 = num1;
			num1++;
		}
		divisores1 = 0;
		divisores2 = 0;
		num2++;
		
	}
	

	return 0;
}
