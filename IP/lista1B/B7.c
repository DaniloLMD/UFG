#include <stdio.h>

int main(){
	int num;
	int contadorPar = 0;
	int contadorImpar = 0;
	double mediaPar = 0;
	double mediaImpar = 0;
	
	while (1){
		scanf("%d", &num);
		if (num == 0){
			break;
		}
		
		if(num % 2 == 0){
			mediaPar += num;
			contadorPar += 1;
		}else{
			mediaImpar += num;
			contadorImpar += 1;
		}
	}
	if(contadorPar == 0){
		contadorPar = 1;
	}
	if(contadorImpar == 0){
		contadorImpar = 1;
	}
	
	mediaImpar /= contadorImpar;
	mediaPar /= contadorPar;
	
	printf("MEDIA PAR: %.6lf\n", mediaPar);
	printf("MEDIA IMPAR: %.6lf\n", mediaImpar);
	

	return 0;
}
