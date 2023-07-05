#include <stdio.h>

int main(){
	int qtd, c;
	scanf("%d", &qtd);
	
	printf("%d\n", qtd);
	
	for(c = qtd; c >= 1; c--) printf("%d\n", c);
	
	printf("0\n");
	return 0;
}
