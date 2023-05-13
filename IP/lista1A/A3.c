#include <stdio.h>

int main(){

	float a,b,c, delta;
	
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	
	delta = b * b - (4 * a * c);
	
	printf("O VALOR DE DELTA E = %.2f\n", delta);
	

	return 0;
}
