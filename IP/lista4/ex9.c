#include <stdio.h>

int main(){
	int lin, col,matriz[1000][1000];
	int i, j, maior = 0, menor = 1000, total;
	double contMaior = 0, contMenor = 0;
	
	//lendo a matriz
	scanf("%d %d", &lin, &col);
	total = lin * col;
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			scanf("%d", &matriz[i][j]);
			if(matriz[i][j] > maior) maior = matriz[i][j];
			else if(matriz[i][j] < menor) menor = matriz[i][j];
		}
	}
	
	//vendo a frequencia do maior e menor
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			if(matriz[i][j] == maior) contMaior++;
			if(matriz[i][j] == menor) contMenor++;
		}
	}
	
	printf("%d %.2lf%%\n", menor, contMenor/total * 100);
	printf("%d %.2lf%%\n", maior,  contMaior / total * 100);

	return 0;
}
