#include <stdio.h>

void espelhar(int x, int y){
    int c, c2;
    for(c = x; c <= y; c++){
        printf("%d", c);
    }
    for(c = y; c >= x; c--){
        if(c < 10) printf("%d", c);
        else if(c >= 10){
            c2 = c;
            while(c2 != 0){
                printf("%d", c2 % 10);
                c2 /= 10;
            }
        }
    }
    printf("\n");
}

int main(){
    int qtd, n1, n2;

    scanf("%d", &qtd);

    while(qtd--){
        scanf("%d %d", &n1, &n2);
        espelhar(n1, n2);
    }
}