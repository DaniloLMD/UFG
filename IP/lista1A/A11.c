#include <stdio.h>

int main(){
	float lista[4];
	float temp;
	int cont;
	
	scanf("%f", &lista[0]);
	scanf("%f", &lista[1]);
	scanf("%f", &lista[2]);
	scanf("%f", &lista[3]);
	
	while (1){
		if (lista[0] > lista[1]){
			temp = lista[0];
			lista[0] = lista[1];
			lista[1] = temp;
		}
		if (lista[1] > lista[2]){
			temp = lista[1];
			lista[1] = lista[2];
			lista[2] = temp;
		}
		if (lista[2] > lista[3]){
			temp = lista[2];
			lista[2] = lista[3];
			lista[3] = temp;
		}
		
		if (lista[3] >= lista[2] && lista[2] >= lista[1] && lista[1] >= 					lista[0]){
			break;
		}
	}
	
	printf("%.2f, %.2f, %.2f, %.2f\n", lista[0], lista[1], lista[2], lista[3]);
	
	return 0;
}
