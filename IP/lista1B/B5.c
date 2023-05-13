#include <stdio.h>

int main(){
	int n, contador;
	int fatorial = 1;
	
	scanf("%d", &n);
	
	if (n < 0){
		return 0;
	}
	
	for (contador = n; contador > 0; contador--){
		fatorial *= contador;
	}
	
	printf("%d! = %d\n", n, fatorial);


	return 0;
}
