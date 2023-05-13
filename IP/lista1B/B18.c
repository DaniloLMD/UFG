#include <stdio.h>

int main(){
	int divisores, num;
	int contador, contador2;
	
	while(1){
		scanf("%d", &num);
		if(num < 1){
			printf("Fatoracao nao e possivel para o numero %d!\n", num);
			
		}else if(num >= 1){
			break;
		}
	}
	if(num == 1){
		printf("%d = 1\n", num);
	}else{
		printf("%d = ", num);
		for(contador = 1; contador <= num; contador++){
			for(contador2 = 1; contador2 <= contador; contador2++){
				if(contador % contador2 == 0){
					divisores += 1;
				}
			}
			if (divisores == 2){
				while(num % contador == 0){
					num /= contador;
					if(num > 1){
						printf("%d x ", contador);
					}else if(num == 1){
						printf("%d\n", contador);
					}
					
				}
			}
			divisores = 0;
		}
	}
	

	return 0;
}
