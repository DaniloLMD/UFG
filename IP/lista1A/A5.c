#include <stdio.h>

int main(){
	float a,b,c;
	float maior,menor, medio;
	int contador;
	
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	maior = a;
	menor = a;
	medio = a;

	while (1){
		contador++;
		if (b >= maior){
			maior = b;
		}else if (b < maior && b > menor){
			medio = b;
		}else if (b <= menor){
			menor = b;
		}
	
		if (c >= maior){
			maior = c;
		}else if (c < maior && c > menor){
			medio = c;
		}else if (c <= menor){
			menor = c;
		}
		if (contador > 1){
			if(maior >= medio && medio >= menor){
				break;
			}
		}
	}
	
	printf("%.2f, %.2f, %.2f\n", menor, medio, maior);


}
