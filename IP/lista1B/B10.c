#include <stdio.h>

int main(){
	int i, j;
	int linhas, colunas;
	
	scanf("%d", &linhas);
	scanf("%d", &colunas);
	
	for(i = 2; i <= linhas; i++){
		for(j = 1; j <= colunas; j++){
			
			if (i == j){
				break;
			}
			printf("(%d,%d)", i, j);
			if(j < (i - 1) && j < colunas){
				printf("-");
			}
		}
		printf("\n");
	}

	return 0;
}
