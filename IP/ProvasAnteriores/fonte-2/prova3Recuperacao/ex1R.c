#include <stdio.h>

int main(){
	char texto[100], matriz[100][100];
	int i, j, c, alit, teveAlitAntes;
	char letra1, letra2;
	
	while(scanf("%[^\n]%*c", texto) != EOF){
		alit = teveAlitAntes = i = j = 0;
		
		
		//trocando maiusculo pra minusculo
		for(c = 0; texto[c] != '\0'; c++){
			if(texto[c] >= 'A' && texto[c] <= 'Z') texto[c] += 'a'-'A';
		}
		
		for(c = 0; texto[c] != '\0'; c++){
			
			if(texto[c] == ' '){
				matriz[i][j] = '\0';
				j = 0;
				i++;
				continue;
			}
			
			matriz[i][j] = texto[c];
			j++;
		}
		
		for(c = 0; c < i; c++){
			letra1 = matriz[c][0];
			letra2 = matriz[c+1][0];
			if(letra1 == letra2 && !teveAlitAntes){
				alit++;
				teveAlitAntes = 1;
			}
			else if(letra1 == letra2 && teveAlitAntes); //n faz nada pq a anterior foi aliteracao
			else teveAlitAntes = 0;
		}
		printf("%d\n", alit);
	}


	return 0;
}
