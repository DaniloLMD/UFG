#include <stdio.h>

int main(){
	int n;
	int contador;
	
	scanf("%d", &n);
	contador = n;
	int sequencia[n];
	int x = 1, maior = 1;
	
	for(contador = 0; contador < n; contador++){
		scanf("%d", &sequencia[contador]);
	}	
	for(contador = 0; contador < (n -1); contador++){
		if(sequencia[contador] < sequencia[contador + 1]){
			x++;
			if(x > maior){
			maior = x;
			}
		}else{
			
			x = 1;
		}
	}
	
	printf("O comprimento do segmento crescente maximo e: %d\n", maior);
	
	return 0;
}
