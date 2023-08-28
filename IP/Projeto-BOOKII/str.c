#include <stdio.h>
#include <stdlib.h>

void str_copy(char* s1, char *s2){
	int c;
	
	for(c = 0; s2[c] != '\0'; c++){
		s1[c] = s2[c];
	}
	
	s1[c] = '\0';
}

int str_len(char* s){
	int c;
	for(c = 0; s[c] != '\0'; c++);
	return c;
}	

//funcao que recebe 2 strings e retorna 1(V) ou 0(F) se elas sao iguais
int str_compare(char *s1, char *s2){
	int c;
	//checa os tamanhos
	if(str_len(s1) != str_len(s2)) return 0;
	//checa se tem algum caracter diferente
	for(c = 0; s1[c] != '\0'; c++){
		if(s1[c] != s2[c]) return 0;
	}
	return 1;
}

//consome o buffer do terminal
void consome_buffer(void){
	char x;
	while(1){
		scanf("%c", &x);
		if(x == '\n') break;
	}
}

//recebe uma string e realoca ela para o novo tamanho
char* realoca_str(int tamanho){
	char* s = NULL;
	while(1){
		s = (char*) realloc(s, tamanho * sizeof(char));
		if(s != NULL) break;
	}
	return s;
}