#include <stdio.h>

// c = 5 * (f - 32) / 9
int main(){
	int contador;
	int n;
	scanf("%d", &n);
	double temp[n];
	
	for (contador = 0; contador < n; contador++){
		scanf("%lf", &temp[contador]);
	}
	for (contador = 0; contador < n; contador++){
		printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n",
		temp[contador], 5 *(temp[contador] - 32)/9);
	}
	
	return 0;
}
