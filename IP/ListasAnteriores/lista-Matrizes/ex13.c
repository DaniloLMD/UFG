#include <stdio.h>
#include <stdlib.h>

int **matriz;
int cor;

void coloreFundo(int dimensao){
	int i, j;
	for(i = 0; i < dimensao; i++){
		for(j = 0; j < dimensao; j++){
			matriz[i][j] = cor;
		}
	}
}

void desenhaBorda(int minL, int maxL, int minC, int maxC){
    int i, j;
    //desenhando linhas de cima e de baixo
     for(j = minC; j <= maxC; j++){
		matriz[minL][j] = cor;
		matriz[maxC][j] = cor;
     }

    //desenhando colunas da direita e da esquerda
	for(i = minL; i <= maxL; i++){
		matriz[i][minC] = cor;
		matriz[i][maxC] = cor;
	}
}

void desenhaTudo(int minL, int maxL, int minC, int maxC){
	int i, j;
	
	while(minL <= maxL){
		for(j = minC; j <= maxC; j++){
			matriz[minL][j] = cor;
		}
		minL++;
	}
}

int main(){
    int linha, coluna, raio, borda;
    int dimensao, minLin, maxLin, maxCol, minCol;

    scanf("%d %d", &dimensao, &cor);
	
	//alocando dinamicamente
	matriz = (int**) malloc(dimensao * sizeof(int*));
	for(linha = 0; linha < dimensao; linha++) matriz[linha] = (int*) malloc(dimensao * sizeof(int));

	coloreFundo(dimensao);
	
    while(1){
        scanf("%d %d", &coluna, &linha);
        if(linha == -1 || coluna == -1) break;
        
        scanf("%d %d %d", &cor, &raio, &borda);
        
        minLin = linha - raio;
        maxLin = linha + raio;
        maxCol = coluna + raio;
        minCol = coluna - raio;

        if(minLin < 0 || maxLin >= dimensao || minCol < 0 || maxCol >= dimensao) continue;

        if(borda == 1) desenhaBorda(minLin, maxLin, minCol, maxCol);
        else if(borda == 2) desenhaTudo(minLin, maxLin, minCol, maxCol);
    }
    
    //printando
    printf(
    	"P2\n"
    	"%d %d\n"
    	"255\n", dimensao, dimensao
    );
    for(linha = 0; linha < dimensao; linha++){
    	for(coluna = 0; coluna < dimensao; coluna++){
    		printf("%d ", matriz[linha][coluna]);
    	}
    	printf("\n");
    }
    
    
    return 0;
}

