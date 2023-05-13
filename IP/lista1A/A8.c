#include <stdio.h>

int main(){
	int num;
	int u,d,c;
	
	scanf("%d", &num);
	
	if (num % 10 == 0 || num > 999 || num < 100){
		return 0;
	}
	
	c = num / 100;
	d = (num % 100) / 10;
	u = (num % 100) % 10;
	printf("%d%d%d\n",u,d,c);	

	return 0;
}
