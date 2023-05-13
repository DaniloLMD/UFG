#include <stdio.h>
#include <math.h>

int main(){
	int n;
	int h = 5, c1 = 3, c2 = 4, contador, contador1, contador2;
	
	scanf("%d", &n);

	while(h <= n){
		if(h == sqrt(c1 * c1 + c2 * c2)){
			printf("hipotenusa = %d, catetos %d e %d\n", h, c1, c2);
		}
		if(c2 < n){
			c2++;
		}else if(c2 >= n){
			c1++;
			c2 = c1;
		}
		if(c1 >= h){
			h++;
			c1 = 1;
			c2 = 2;
		}
	}

	return 0;
}
