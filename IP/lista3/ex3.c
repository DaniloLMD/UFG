#include <stdio.h>
 
int main(){
    int n, v[4999], c;
 
    scanf("%d", &n);
    for(c = 0; c < n; c++){
        scanf("%d", &v[c]);
    }
    for(c = n - 1; c >= 0; c--){
        printf("%d", v[c]);
        if(c != 0) printf(" ");
    }
 
    return 0;
}