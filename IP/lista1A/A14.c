#include <stdio.h>

int main(){
	int i;
	float a, b, c;
	float maior, menor, medio;
	
	scanf("%d", &i);
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	
	if(a >= b && a >= c){
		maior = a;
		if(b >= c){
			medio = b;
			menor = c;
		}else if(c >= b){
			medio = c;
			menor = b;
		}
	}else if(b >= a && b >= c){
		maior = b;
		if(a >= c){
			medio = a;
			menor = c;
		}else if(c >= a){
			medio = c;
			menor = a;
		}
	
	}else if (c >= a && c >= b){
		maior = c;
		if(a >= b){
			medio = a;
			menor = b;
		}else if(b >= a){
			medio = b;
			menor = a;
		}
	}
	
	switch(i){
		case 1:
			printf("%.2f %.2f %.2f\n", menor, medio, maior);
			break;
		case 2:
			printf("%.2f %.2f %.2f\n", maior, medio, menor);
			break;
		case 3:
			printf("%.2f %.2f %.2f\n",medio , maior, menor);
			break;
		default:
			return 0;
	
	}

	return 0;
}
