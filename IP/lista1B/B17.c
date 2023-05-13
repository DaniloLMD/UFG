#include <stdio.h>
#include <math.h>

int fatorial(int x);

int main(){
	int n, contador;
	int divisor;
	double x;
	double resultado;
	
	scanf("%lf", &x);
	scanf("%d", &n);
	
	if(n > 9){
		return 0;
	}
	
	for(contador = 0; contador <= n; contador++){
		divisor = fatorial(contador);
		resultado += pow(x, contador) / divisor;
	}
	printf("e^%.2lf = %.6lf\n", x,resultado);
	return 0;
}

int fatorial(int x){
	int contador;
	long int fatorial = 1;
	while(x > 0){
		fatorial *= x;
		x--;
	}
	return fatorial;
}
