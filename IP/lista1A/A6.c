#include <stdio.h>
#include <math.h>

int main(){
	float a,b,c;
	float delta, x1, x2;
	
	scanf("%f %f %f", &a, &b, &c);
	delta = b * b - 4 * a * c;
	x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);
	
	if (delta > 0){
		printf("RAIZES DISTINTAS\n");
		if (x1 < x2){
			
			printf("X1 = %.2f\n", x1);
			printf("X2 = %.2f\n", x2);
		}else if (x2 < x1){
			printf("X1 = %.2f\n", x2);
			printf("X2 = %.2f\n", x1);
		}
	}else if (delta == 0){
		printf("RAIZ UNICA\n");
		printf("X1 = %.2f\n", x1);
	}else if (delta < 0){
		printf("RAIZES IMAGINARIAS\n");
	}
	
	return 0;
}
