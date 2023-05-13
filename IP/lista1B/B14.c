#include <stdio.h>

int main(){
	int n, contador, soma = 0, ultimoDiv; 
	
	scanf("%d", &n);
	
	if(n <= 1){
		return 0;
	}
	
	printf("%d = ", n);
	
	for(contador = 1; contador < n; contador++){
		if(n % contador == 0){
			ultimoDiv = contador;
		}
	}
	
	for(contador = 1; contador < n; contador++){
		if(n % contador == 0){
			soma += contador;
			printf("%d", contador);
			if(contador < ultimoDiv){
				printf(" + ");
			}
		}
	}
	
	printf(" = %d", soma);
	if(soma == n){
		printf(" (NUMERO PERFEITO)");
	}else{
		printf(" (NUMERO NAO E PERFEITO)");
	}
	return 0;
}
