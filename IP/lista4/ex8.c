#include <stdio.h>

/**
* Função que verifica se a matriz é de permutação
* @param matriz Indica a matriz a ser verificada
* @param n indica a dimensão da matriz
* @param *soma parâmetro de saída, que armazenará a soma de todos os ’n’ elementos
da matriz.
* @return int
*/
int ehPermutacao( int matriz[500][500], int n, int *soma ){
	int i, j, permutacao = 1;
	int contNulo = 0, contUm = 0;
	
	//percorrendo a matriz horizontalmente e somando
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			*soma += matriz[i][j];
			if(matriz[i][j] == 0) contNulo++;
			else if(matriz[i][j] == 1) contUm++;
		}
		if(contNulo != n - 1 || contUm != 1) permutacao = 0;
		contNulo = contUm = 0;
	}
	
	
	//percorrendo a matriz verticalmente
	for(j = 0; j < n; j++){
		for(i = 0; i < n; i++){
			if(matriz[i][j] == 0) contNulo++;
			else if(matriz[i][j] == 1) contUm++;
		}
		if(contNulo != n - 1 || contUm != 1) permutacao = 0;
		contNulo = contUm = 0;
	}
	
	return permutacao;
}



int main(){
	int dimensao, matriz[500][500];
	int c, c2, soma = 0;
	
	//lendo a matriz
	scanf("%d", &dimensao);
	for(c = 0; c < dimensao; c++){
		for(c2 = 0; c2 < dimensao; c2++) scanf("%d", &matriz[c][c2]);
	}

	//saidas
	printf("%d\n", dimensao);
	
	if(ehPermutacao(matriz, dimensao, &soma) ) printf("PERMUTACAO\n");
	else printf("NAO EH PERMUTACAO\n");
	
	printf("%d\n", soma);


	return 0;
	
}
