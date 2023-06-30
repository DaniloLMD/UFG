#include <stdio.h>

/**
* param @*vetor vetor a ser analisado
* return 1(V) ou 0(F) se o vetor tem os numeros de 1 a 9 sem repetição
*/
int tem9Numeros(int *vetor){
	int qtdDigitos = 0; 
	int cont, cont2;
	
	//checando se os numeros de 1 a 9 estao no vetor
	for(cont = 1; cont <= 9; cont++){
		for(cont2 = 0; cont2 < 9; cont2++){
			if(vetor[cont2] == cont){
				qtdDigitos++;
				break;
			}
		}	
	}		
	if(qtdDigitos == 9) return 1;
	else return 0;
}

int main(){
	int matriz[9][9];
	int valido = 1; //verdadeiro
	int i, j, c;
	int vetorTeste[9], indiceVet = 0;
	
	//lendo a matriz
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++) scanf("%d", &matriz[i][j]);
	}
	
	//checando as linhas
	for(i = 0; i < 9; i++){
		if( !tem9Numeros(matriz[i])) valido = 0;
	}
	
	//checando as colunas
	for(j = 0; j < 9; j++){
		for(i = 0; i < 9; i++){
			vetorTeste[i] = matriz[i][j];
		}
		if( !tem9Numeros(vetorTeste) ) valido = 0; 
	}
	
	//checando as matrizes 3x3
	for(i = 0; i < 9; i += 3){
		for(c = 0; c < 3; c++){
			for(j = 0; j < 3; j++){
				vetorTeste[indiceVet] = matriz[i + c][j];
				indiceVet++;
			}
		}
		indiceVet = 0;
		if( !tem9Numeros(vetorTeste)) valido = 0;
	}
		
	//print da validade
	if(valido) printf("valido\n");
	else printf("invalido\n");

	return 0;
}
