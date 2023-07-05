#include <stdio.h>
#include <stdlib.h>

int main(){
	//partes do wally
	int camisa = 1111, cabeca = 4, braco = 0, perna = 8;
	int **matriz, lin, col, i, j, partesAchadas, achei = 0;
	
	//alocando a matriz
	scanf("%d %d", &lin, &col);
	matriz = (int **) malloc( lin * sizeof(int*));
	for( i = 0; i < lin; i++) matriz[i] = (int*) malloc(col * sizeof(int));
	
	//lendo a matriz
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	
	//achando o wally
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			partesAchadas = 0;
			if(matriz[i][j] == camisa){
				//achando braço esquerdo
				if(j == 0){
					if(matriz[i][col-1] == braco) partesAchadas++;
				}
				else if(matriz[i][j-1] == braco) partesAchadas++;
				
				//achando braço direito
				if(j == col - 1){
					if(matriz[i][0] == braco) partesAchadas++;
				}
				else if(matriz[i][j+1] == braco) partesAchadas++;
				
				//achando a cabeça
				if(i == 0){
					if(matriz[lin-1][j] == cabeca) partesAchadas++;
				}
				else if(matriz[i-1][j] == cabeca) partesAchadas++;
				
				//achando a perna
				if(i == lin-1){
					if(matriz[0][j] == perna) partesAchadas++;
				}
				else if(matriz[i+1][j] == perna) partesAchadas++;
			}
			if(partesAchadas == 4){
				printf("%d %d\n", i, j);
				achei = 1;
			}
		}
	}
	
	if( !achei ) printf("WALLY NAO ESTA NA MATRIZ\n"); 	
	
	return 0;
}
