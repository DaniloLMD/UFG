#include <stdio.h>
#include <stdlib.h>

#define N 50

typedef struct{
	char nome[N];
	float preco;
} feira;

int str_len(char *s){
	int c;
	for(c = 0; s[c] != '\0'; c++);
	return c;
}

int str_comp(char* s1, char* s2){
	int c;
	
	//checando se tem o mesmo tamanho
	if( str_len(s1) != str_len(s2) ) return 0;
	
	//checando se tem as mesmas letras
	for(c = 0; s1[c] != '\0'; c++){
		if(s1[c] != s2[c]) return 0;
	}
	
	return 1;
}

int main(){
	int qtd, qtdProdutos, c, c2, qtdCompra, quantidade;
	float total;
	char compra[N];
	feira* loja;

	scanf("%d", &qtd);
	
	while(qtd--){
		//lendo os produtos disponiveis na feira
		scanf("%d%*c", &qtdProdutos);
		loja = (feira*) malloc(qtdProdutos * sizeof(feira));
		for(c = 0; c < qtdProdutos; c++){
			scanf("%s %f%*c", loja[c].nome, &loja[c].preco);
			//scanf("%f%*c", &loja[c].preco);
		}
		
		//lendo os produtos que ela vai comprar
		total = 0;
		scanf("%d%*c", &qtdCompra);
		for(c = 0; c < qtdCompra; c++){
			scanf("%s %d%*c", compra, &quantidade);
			//scanf("%d%*c", &quantidade);
			for(c2 = 0; c2 < qtdProdutos; c2++){
				if( str_comp(compra, loja[c2].nome) ){
					total += loja[c2].preco * quantidade;
					break;
				}
			}
		}
		
		printf("R$ %.2f\n", total);
		free(loja);
	}	
	
	
	return 0;
}
