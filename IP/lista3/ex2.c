#include <stdio.h>
 
int main(){
    int n,c, k, x = 0;
    int v[1000];
 
    while(1){
        scanf("%d", &n);
        if(n >= 1 && n <= 1000) break;
    }
    for(c = 0; c < n; c++){
        scanf("%d", &v[c]);
    }
    printf("\n");
 
    scanf("%d", &k);
    for(c = 0; c < n; c++){
        if(v[c] >= k) x++;
    }
    printf("%d\n", x);
 
    return 0;
}