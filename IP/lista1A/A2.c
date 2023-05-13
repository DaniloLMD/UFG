#include <stdio.h>

int main(){
	float fahrenheit, celsius;
	float polegadas, mm;
	
	scanf("%f", &fahrenheit);
	scanf("%f", &polegadas);
	
	celsius = (fahrenheit - 32) / 9 * 5;
	mm = 25.4 * polegadas;
	
	printf("O VALOR EM CELSIUS = %.2f\n", celsius);
	printf("A QUANTIDADE DE CHUVA E = %.2f\n", mm);

	return 0;
}	
