#include <stdio.h>
#include <string.h>
 
void inverter(char *p){
    int c, c2 = 0;
    char v2[500000];
    for(c = strlen(p) - 1; c >= 0; c--){
        v2[c2] = p[c];
        c2++;
    }
}
 
void espelhar(int a, int b){
    int c;
    char v[500000], t[500000];
    for(c = a; c <= b; c++){
            sprintf(t, "%d", c);
            strcat(v, t);
    }
    for(c = b; c >= a; c--){
        sprintf(t, "%d", c);
        inverter(t);
        strcat(v, t);
    }
    printf("%s\n", v);
    for(c = 0; c < strlen(v); c++){
        v[c] = '\0';
        t[c] = '\0';
    }
}
 
 
    int main(){
    int qtd, n1, n2;
    scanf("%d", &qtd);
    while(qtd--){
        scanf("%d %d", &n1, &n2);
        espelhar(n1 , n2);
    }
    return 0;
}