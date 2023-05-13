#include <stdio.h>

int main(){

	int n1, n2, n3;
	int resultado, quadrado;
	
	scanf("%d", &n1);
	scanf("%d", &n2);
	scanf("%d", &n3);
	if (n1 >= 10|| n2 >= 10 || n3 >=10){
		printf("DIGITO INVALIDO\n");
		return 0;
	}
	resultado = n1 * 100 + n2 * 10 + n3;
	quadrado = resultado * resultado;
	printf("%d, %d\n", resultado, quadrado);
	return 0;	
}
