#include <stdio.h>

#define MAX_WORDS 200
#define MAX_WORD_LEN 64 + 1

/*
* @param *str string que sera analisada
* @return tamanho da string
*/
int len(char *str){
	int c;
	for(c = 0; str[c] != '\0'; c++);
	
	return c;
}


/**
* @param x caracter a ser analisado
* @param *proibidos ponteiro da string com caracteres proibidos
* @return 0 (F) ou 1(V) se é separador ou não
*/
int ehSeparador(char x, char *proibidos){
	int cont;

	for(cont = 0; proibidos[cont] != '\0'; cont++){
		if(proibidos[cont] == x) return 1;
	}
	return 0;
}

/**
* @brief Função de separação de palavras de acordo com a uma lista de separadores.
* Exemplo de chamada da função:
* str_split("Ola mundo! 1,23", m, ", .!?");
*
* O resultado é a separação das strings "Ola", "mundo", "1", "23", cada uma
* ocupando uma linha da matriz m, com base nos caracteres de pontuação fornecidos.
*
* @param str ponteiro para o início da string original
* @param m matriz de caracteres, sendo cada linha uma palavra da string original
* @param sep string com a lista de caracteres separadores
* @return int quantidade de palavras detectadas
*/
int str_split(char * str, char m[MAX_WORDS][MAX_WORD_LEN], char * sep){
	int i = 0, j = 0, c;
	int totPalavras = 1;
	
	for(c = 0; str[c] != '\0'; c++){
		if( !ehSeparador(str[c], sep)){
			m[i][j] = str[c];
			j++;
			
		}
		else if( !ehSeparador(str[c + 1], sep) && str[c+1] != '\0'){
			j = 0;
			i++;
			totPalavras++;
		}
	}
	
	return totPalavras;
}

int main(){
	char matriz[MAX_WORDS][MAX_WORD_LEN];
	char texto[50000], separadores[100];
	int qtdPalavras, i, maiorPalavra = 0, contMaiores = 0, tamanhoPalavra;
	
	scanf("%[^\n]%*c", texto);
	scanf("%[^\n]", separadores);
	
	qtdPalavras = str_split(texto, matriz, separadores);
	
	//percorrendo a matriz
	for(i = 0; i < qtdPalavras; i++){
		tamanhoPalavra = len(matriz[i]);
		printf("(%d)%s\n", tamanhoPalavra, matriz[i]);
		if(tamanhoPalavra > maiorPalavra) maiorPalavra = tamanhoPalavra;
	}
	
	//vendo quantas palavras sao iguais a maior
	for(i = 0; i < qtdPalavras; i++){
	tamanhoPalavra = len(matriz[i]);
	if(tamanhoPalavra == maiorPalavra) contMaiores++;
	}
	
	printf("%d\n", contMaiores);
	
	return 0;
}
