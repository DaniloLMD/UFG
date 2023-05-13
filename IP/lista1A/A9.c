#include <stdio.h>

int main(){
	int num;
	int num2;
	int u, d, c, uMil, dMil;
	
	scanf("%d", &num);
	if (num > 99999){
		printf("NUMERO INVALIDO\n");
		return 0;
	}
	u = (num % 10);
	d = (num % 100) / 10;
	c = (num % 1000) / 100;
	uMil = (num / 1000) % 10;
	dMil = num / 10000;
	
	if (dMil == 0){
	
		if (d == 0 && c == 0 && uMil == 0){
			printf("PALINDROMO\n");
		}
	
		else if (c == 0 && uMil == 0){
			if (u == d){
				printf("PALINDROMO\n");
			}
			else{
				printf("NAO PALINDROMO\n");
			}
		}
		
		else if (uMil == 0){
			if (u == c){
				printf("PALINDROMO\n");
			}
			else{
				printf("NAO PALINDROMO\n");
			}
		}
		else{	
			if (u == uMil && c == d){
				printf("PALINDROMO\n");
			}
			else{
				printf("NAO PALINDROMO\n");
			}
		}
	}else{
		if (u == dMil && d == uMil){
			printf("PALINDROMO\n");
		}else{
			printf("NAO PALINDROMO\n");
		}
	}
	return 0;
}
