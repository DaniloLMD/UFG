#include <stdio.h>

int main(){
	int n, contador;
	double soma = 1;
	
	scanf("%d", &n);	
	if (n < 1){
		printf("Numero invalido!\n");
		return 0;
	}
	for(contador = 2; contador <= n; contador++){
		soma += (1.0 / contador);
	}
	
	printf("%.6lf\n", soma);
	
	return 0;
}
