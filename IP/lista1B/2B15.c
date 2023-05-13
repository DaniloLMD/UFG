#include <stdio.h>

int main(){
	int n, contador = 0, amigosExibidos = 0;
	int amigos[18] = {220, 284, 1184, 1210,2620, 2924,5020, 5564, 6232, 6368, 10744, 10856, 12285, 14595, 17296, 18416,63020, 76084};
	
	scanf("%d", &n);
	
	if(n > 9 || n < 0){
		return 0;
	}
	
	while(amigosExibidos < n){ 
		if(contador % 2 == 0){
			printf("(%d,", amigos[contador]);
		}else if(contador % 2 == 1){
			printf("%d)\n", amigos[contador]);
			amigosExibidos++;
		}	
		contador++;
	}
	
	
	/*for(contador = 0; contador <= n; contador ){
		printf("cont = %d, n = %d\n", contador, n);
		printf("(%d,%d)\n", amigos[contador], amigos[contador + 1]);
	
	}*/

	return 0;
}
