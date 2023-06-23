#include <stdio.h>

void comparaMatriz(char matriz[2048][2048], int linhaFinal);


void zeraVetor(char *v){
	int i;
	for(i = 0; v[i] != '\0'; i++) v[i] = '\0';
}

int tamanhoString(char *p){
    int t = 0, c;
    for(c = 0; p[c] != '\0'; c++) t++;
    return t;
}

/**
* @param s1 primeira string
* @param s2 segunda string
* @return quantidade de caracteres diferentes, -1 se o tamanho for diferente
*/
int comparaString(char *s1, char *s2){
    int diferenca = 0;
    int c, tamanho1, tamanho2;

    tamanho1 = tamanhoString(s1);
    tamanho2 = tamanhoString(s2);
    if(tamanho1 != tamanho2) return -1;

    for(c = 0; s1[c] != '\0'; c++){
        if(s1[c] != s2[c]) diferenca++;
    }

    return diferenca;
}

/**
* param @x caracter que será verificado se está no alfabeto
* return 1(V) ou 0(F) se o caracter está no alfabeto
*/
int alfabeto(char x){
	char proibidos[15] = " .,!?()[]{}";
	int c;

	for(c = 0; proibidos[c] != '\0'; c++){
		if(x == proibidos[c]) return 0;
	}

	return 1;
}


/**
* param @string string que será colocada na matriz
* param @matriz matriz que será usada
* param @linha linha da matriz que entrará a string
*/
void botaNaMatriz(char *string, char mat[2048][2048], int linha){
	int col, contString = 0;
	
	for(col = 0; string[contString] != '\0'; col++){
		mat[linha][col] = string[contString];
		contString++;
	}
}

int main(){
	char string[2048], palavra[2048];
	char matriz[2048][2048];
	int qtdPalavras = 1;
	int c, contador = 0, i ,j, contPalavra = 1, linhaMatriz = 0;
	

	for(i = 0; i < 2048; i++){
		for(j = 0; j < 2048; j++) matriz[i][j] = '\0';
	}

	//lendo a string
	scanf("%[^\n]", string);	

	//trocando os caracteres não aceitos por ' '
	for(c = 0; string[c] != '\0'; c++){
		if(!alfabeto(string[c])){
			string[c] = ' ';
		}
	}

	//formando as palavras e colocando na matriz
	palavra[0] = string[0];
	for(c = 1; string[c] != '\0'; c++){
	
		if(string[c] == ' ' && string[c+1] == ' ') continue;
		
		
		if(alfabeto(string[c])){
			palavra[contPalavra] = string[c];
			contPalavra++;
		}
		if(string[c] == ' ' && alfabeto(string[c + 1])
		 || string[c+1] == '\0'){
			botaNaMatriz(palavra, matriz, linhaMatriz);
			linhaMatriz++;
			zeraVetor(palavra);
			contPalavra = 0;
		}
	}
	botaNaMatriz(palavra, matriz, linhaMatriz);
	
	//printando a matriz 
	/*for(i = 0; i < linhaMatriz; i++){
		for(j = 0; matriz[i][j] != '\0'; j++){
			printf("%c", matriz[i][j]);
		}
		printf("\n");
	}*/

	comparaMatriz(matriz, linhaMatriz);
	
	return 0;	
}	

void comparaMatriz(char matriz[2048][2048], int linhaFinal){
	int i, j, contPalavra, lin, frequencia;
	char palavra[2048];

	for(i = 0; i < linhaFinal; i++){
		zeraVetor(palavra);
		frequencia = 0;
		contPalavra = 0;
		for(j = 0; matriz[i][j] != '\0'; j++){
			palavra[contPalavra] = matriz[i][j];
			contPalavra++;
		}
		palavra[contPalavra] = matriz[i][j];

		for(lin = 0; lin < linhaFinal; lin++){
			if(comparaString(palavra, matriz[lin]) == 0) frequencia++;
		}

		printf("(%s)%d\n", palavra, frequencia);
	}
}