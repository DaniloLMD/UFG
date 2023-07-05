#include <stdio.h>
#include <stdlib.h>

int main(){
	int *vOriginal, *vCount, *vOrd;
	int tamanho, cont, maior;
	
	while(1){
	
		scanf("%d", &tamanho);
		if(tamanho <= 0) break;
		
		//alocando o vetor original
		vOriginal = (int*) realloc(vOriginal, tamanho * sizeof(int));
		
		//lendo o vetor original
		for(cont = 0; cont < tamanho; cont++) scanf("%d", &vOriginal[cont]);
		
		//pegando o maior numero do vetor original
		maior = vOriginal[0];
		for(cont = 1; cont < tamanho; cont++){
			if(vOriginal[cont] > maior) maior = vOriginal[cont];
		}
		
		//passo 1 (alocando vetor Contador e vetor Ordenado)
		vOrd = (int*) realloc(vOrd, tamanho * sizeof(int));
		vCount = (int*) realloc(vCount, (maior + 1) * sizeof(int));
		
		//passo 2 (zerando o vCount)
		for(cont = 0; cont <= maior; cont++) vCount[cont] = 0;
		
		//passo 3 (contando no vCount as repeticoes de numeros do vOriginal)
		for(cont = 0; cont < tamanho; cont++){
			vCount[ vOriginal[cont] ]++;
		}
		
		//passo 4 (somando cada elemento do vCount com o anterior)
		for(cont = 1; cont <= maior; cont++){
			vCount[cont] = vCount[cont] + vCount[cont-1];
		}
		
		//passo 5 (colocando os valores no vOrd)
		for(cont = 0; cont < tamanho; cont++){
			vOrd[ vCount[vOriginal[cont]] -1] = vOriginal[cont];
			vCount[vOriginal[cont]]--;	
		}
		
		//printando o vOrd (vetor original ordenado)
		for(cont = 0; cont < tamanho; cont++){
			printf("%d ", vOrd[cont]);
		}
		printf("\n");
	}	

	return 0;
}

