#include <stdio.h>

#define N 256

void str_clean(char *str, char *proibidos){
	int c, c2, contTemp = 0;
	int ehProibido = 0;
	char strTemp[N];
	
	strTemp[0] = '\0';
	for(c = 0; str[c] != '\0'; c++){
		for(c2 = 0; proibidos[c2] != '\0'; c2++){
			if(str[c] == proibidos[c2]){
				ehProibido = 1;
				break;
			}
		}
		if( !ehProibido){
			strTemp[contTemp] = str[c];
			if(contTemp < N - 1) strTemp[contTemp+1] = '\0';
			contTemp++;
		}
		ehProibido = 0; // resetando pra falso
		
			
	}
	for(c = 0; strTemp[c] != '\0'; c++){
		str[c] = strTemp[c];
	}	
	str[c] = '\0';
}	


int main() {
	char str[N]; // string original
	char clr[N]; // lista de caracteres indesejados
	scanf("%[^\n]", str);
	scanf("\n%[^\n]", clr);
	str_clean(str, clr) ;
	printf("%s\n", str);
	return 0;
}
