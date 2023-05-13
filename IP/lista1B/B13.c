#include <stdio.h>

int main(){
	int m, n = 1, contador;
	int exibidos = 0;
	scanf("%d", &m);
	
	while(n <= m){
		printf("%d*%d*%d = ", n, n, n);
		contador = n * (n-1) + 1; 
		for(contador; exibidos < n; contador += 2){
			printf("%d", contador);
			if(exibidos <= (n-2)){
				printf("+");
			}
			exibidos++;
		}
		exibidos = 0;
		printf("\n");
		n++;
	}	
	
	return 0;
}
