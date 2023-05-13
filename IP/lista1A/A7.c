#include <stdio.h>

int main(){
	int binario[8];
	int n, contador;
	
	scanf("%d", &n);
	if (n < 0 || n > 255){
		printf("Numero invalido!\n");
		return 0;
	}
	for (contador = 0; contador < 8; contador++){
		binario[contador] = n % 2;
		n = n / 2;
	}
	for(contador = 7; contador >= 0; contador--){
		printf("%d", binario[contador]);
	}
	

	return 0;
}
