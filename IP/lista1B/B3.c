#include <stdio.h>

int main(){
	int x, y;
	int contador;
	
	scanf("%d %d", &x, &y);
	
	if (x % 2 != 0){
		printf("O PRIMEIRO NUMERO NAO E PAR.\n");
		return 0;
	}
	
	for(contador = 0; contador < y * 2; contador++){
		if ((contador + x) % 2 == 0){
			printf("%d ", contador + x);
		}
	}
	
	printf(" \n");
	
	return 0;
}
