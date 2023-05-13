#include <stdio.h>

int main(){
	int contador;
	int num1, num2, num3;
	int maior, medio, menor;
	char ordem[3];
	
	scanf("%d %d %d", &num1, &num2, &num3);
	
	if (num1 > 100 || num2 > 100 || num3 > 100){
		return 0;
	}
	
	scanf("%s", ordem);
	
	maior = num1;
	menor = num1;
	medio = num1;
	
	while (1){
		contador++;
		if (num2 >= maior){
			maior = num2;
		}else if (num2 < maior && num2 > menor){
			medio = num2;
		}else if (num2 <= menor){
			menor = num2;
		}
	
		if (num3 >= maior){
			maior = num3;
		}else if (num3 < maior && num3 > menor){
			medio = num3;
		}else if (num3 <= menor){
			menor = num3;
		}
		if (contador > 1){
			if(maior >= medio && medio >= menor){
				break;
			}
		}
	}
	switch (ordem[0]){
		case 'A':
			printf("%d", menor);
			break;
		case 'B':
			printf("%d", medio);
			break;
		case 'C':
			printf("%d", maior);
			break;
		default:
			return 0;			
	}
	switch (ordem[1]){
		case 'A':
			printf(" %d", menor);
			break;
		case 'B':
			printf(" %d", medio);
			break;
		case 'C':
			printf(" %d", maior);
			break;
		default:
			return 0;			
	}
	switch (ordem[2]){
		case 'A':
			printf(" %d\n", menor);
			break;
		case 'B':
			printf(" %d\n", medio);
			break;
		case 'C':
			printf(" %d\n", maior);
			break;
		default:
			return 0;			
	}
	
	return 0;
}
