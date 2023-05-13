#include <stdio.h>
#include <math.h>

#define pi M_PI

long int fatorial(int x);

int main(){
	int n, cont;
	float x;
	double y = 0;

	scanf("%f", &x);
	scanf("%d", &n);
	
	for(cont = 0; cont <= n; cont++){
		y += (pow(-1, cont) * pow(x, 2 * cont)) / fatorial(2 * cont);	
	}
	printf("cos(%.2f) = %.6lf\n", x, y);
	
	return 0;
}


long int fatorial(int x){
	long int fat = 1;
	while(x > 1){
		fat *= x;
		x--;
	}
	return fat;
}
