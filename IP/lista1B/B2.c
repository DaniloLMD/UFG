#include <stdio.h>

int main(){
	int n, contador;
	
	scanf("%d", &n);
	if (n <= 5 || n >= 2000){
		return 0;
	}
	
	for (contador = 1; contador <= n; contador++){
		if ( contador % 2 == 0){
			printf("%dˆ2 = %d\n", contador, contador * contador);
		}
	
	}
	
	return 0;
}
