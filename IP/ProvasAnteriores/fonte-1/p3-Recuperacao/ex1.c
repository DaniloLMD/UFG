#include <stdio.h>


int main(){
    int c, alit;
    char v[100];
    char p, p2;

    while(scanf("%[^\n]%*c", v) != EOF){
        alit = 0;
        p2 = 'A';
        for(c = 0; v[c] != '\0'; c++){
            if(v[c] >= 'A' && v[c] <= 'Z') v[c] += 'a' - 'A';
        }

        for(c = 0; v[c] != '\0'; c++){
            if(c == 0 || v[c-1] == ' ') p = v[c];
            if(v[c] == ' '){
                if(p == v[c+1] && p != p2){
                    alit += 1;
                    p2 = p;
                }
                else if(p != v[c+1]) p2 = 'A';
            }
        }
        printf("%d\n", alit);
    }


    return 0;
}