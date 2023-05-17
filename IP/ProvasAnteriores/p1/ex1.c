#include <stdio.h>

int main(){
	double s1, s2, s3;
	
	scanf("%lf %lf %lf", &s1, &s2, &s3);
	
	if(s2 > s3 && s2 > s1){
		printf("VOLTAR\n");
	}else if(s3 > s2 && s3 > s1){
		printf("DIREITA\n");
	}else if(s1 == s3 == s2){
		printf("PARAR\n");
	}else if(s1 > s3 && s1 > s2){
		printf("ESQUERDA\n");
	}
	
	return 0;
}
