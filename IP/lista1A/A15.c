#include <stdio.h>

int main(){
	float a, b, c, d, e, f;
	float z, w;
	
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	scanf("%f", &d);
	scanf("%f", &e);
	scanf("%f", &f);
	
	if (a > 0 && d < 0){
		w = (d*c + a*e) / (b*d + a*e);
	}else{
		w = (d*c - a*f) / (b*d - a*e);
	}
	z = (c - b*w) / a;
	
	printf("O VALOR DE X E = %.2f\n", z);
	printf("O VALOR DE Y E = %.2f\n", w);

	return 0;
}
