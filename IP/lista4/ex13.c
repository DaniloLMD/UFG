#include <stdio.h>
#include <stdlib.h>

int main(){
	int matriz[6][6] = {
		{0, 63, 210, 190, -1, 190}, 
		{63, 0, 160, 150, 95, 10},
		{210, 160, 0, 10, 1, 10},
		{190, 150, 10, 0, 10, 20},
		{10, 95, 7, 21, 0, 80},
		{190, 2, -1, 41, 80, 0}
	};
	
	int i, j, tamRota, posicao, destino, distancia = 0, viagem;
	int *rota;
	
	//le o tamanho da rota e aloca o vetor com as viagens
	scanf("%d", &tamRota);
	rota = (int*)calloc(tamRota, sizeof(int));
	for(i = 0; i < tamRota; i++) scanf("%d", &rota[i]);
	
	//fazendo as viagens	
	viagem = 1;
	posicao = rota[0];
	while(tamRota-- > 1){
		destino = rota[0 + viagem];
		i = posicao;
		for(j = 0; j < 6; j++){
			if(j == destino){
				//se nao tiver caminho mata o programa
				if(matriz[i][j] == -1){
					printf("rota invalida!\n");
					return 0;
				}
				
				distancia += matriz[i][j];
				posicao = destino;
				viagem++;
				break;
			}
		} 
	}
	
	printf("%d\n", distancia);

	return 0;
}

