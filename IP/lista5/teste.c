#include <stdio.h>

int str_len(char *s){
	int c;
	for(c = 0; s[c] != '\0'; c++);
	return c;
}

int main(){
	char t[] = "123";
	printf("%d\n", str_len(t));

	return 0;
}
