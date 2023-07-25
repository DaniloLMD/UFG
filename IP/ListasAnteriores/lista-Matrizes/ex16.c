#include <stdio.h>
#include <stdlib.h>

int procura(int **matriz, int **logotipo, int tamanhoLog, int lin, int col){
	int linM, colM, linL = 0, colL = 0;
	int iguais = 0;
	
	for(linM = lin; linM < lin + tamanhoLog; linM++){
		for(colM = col; colM < col + tamanhoLog; colM++){
			if(matriz[linM][colM] == logotipo[linL][colL]) iguais++;
			colL++;
		}
		colL = 0;
		linL++;
	}	
	
	if(iguais == tamanhoLog * tamanhoLog) return 1; //V
	return 0; //F
}

int main(){
	int **logotipo, **matriz;
	int i, j, dimensao, dimensao2, achouLogotipo = 0;
	
	//alocando e lendo o logotipo
	scanf("%d", &dimensao);
	logotipo = (int**) malloc(dimensao * sizeof(int*));
	for(i = 0; i < dimensao; i++) logotipo[i] = (int*) malloc(dimensao * sizeof(int));
	
	for(i = 0; i < dimensao; i++){
		for(j = 0; j < dimensao; j++){
			scanf("%d", &logotipo[i][j]);
		}
	}
	
	//alocando e lendo a matriz
	scanf("%d", &dimensao2);
	matriz = (int**) malloc(dimensao2 * sizeof(int*));
	for(i = 0; i < dimensao2; i++) matriz[i] = (int*) malloc(dimensao2 * sizeof(int));
	
	for(i = 0; i < dimensao2; i++){
		for(j = 0; j < dimensao2; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	
	//percorrendo a matriz procurando o logotipo
	for(i = 0; i < dimensao2  - (dimensao - 1); i++){
		for(j = 0; j < dimensao2 - (dimensao - 1); j++){
			achouLogotipo = procura(matriz, logotipo, dimensao, i, j);
			if(achouLogotipo){
				printf("sim\n");
				return 0;
			}	
		}
	}
	
	printf("nao\n");
	
	return 0;
}
