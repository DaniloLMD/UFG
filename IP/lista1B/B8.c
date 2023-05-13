#include <stdio.h>

int main(){
	int n;
	int cont1, cont2, contador = 1;
	
	scanf("%d", &n);
	
	if(n < 2){
		printf("Campeonato invalido!\n");
		return 0;
	}
	
	for (cont1 = 1; cont1 < n; cont1++){
		for(cont2 = cont1 + 1;cont2 <= n; cont2++){
			printf("Final %d: Time%d X Time%d\n", contador, cont1, cont2);
			contador++;
		}
	}

	return 0;
}
