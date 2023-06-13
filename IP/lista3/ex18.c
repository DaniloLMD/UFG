#include <stdio.h>

int main(){
    char v[50];
    int c, k;

    while(scanf("%[^\n]%*c", v) != EOF){
        k = 0;
        for(c = 0; v[c] != '\0'; c++){
            if(k % 2 == 0){
                if(v[c] >= 'a' && v[c] <= 'z') v[c] -= 32;
            }
            else if(k % 2 == 1){
                if(v[c] >= 'A' && v[c] <= 'Z') v[c] += 32;
            }
            printf("%c", v[c]);
            if(v[c] != ' ') k++;
        }
        printf("\n");
    }


    return 0;
}