#include <stdio.h>

int main(){
    char v[1000], v2[1000];
    int n, c, c2 = 0, c3 = 0;

    for(c = 0; c < 1000; c++){
        v2[c] = '\0';
    }

    scanf("%d%*c", &n);
    while(n--){
        c2 = 0;
        c3 = 0;
        scanf("%[^\n]%*c", v);

        for(c = 0; v[c] != '\0'; c++){
            if(v[c] >= 'A' && v[c] <= 'Z' || v[c] >= 'a' && v[c] <= 'z') v[c] += 3;
            c2++;
        }

        for(c = c2 - 1; c >= 0 ; c--){
            v2[c3] = v[c];
            c3++;
        }
        for(c = 0; v2[c] != '\0'; c++){
            v[c] = v2[c];
        }

        for(c = c2 / 2; c < c2; c++){
            v[c] -= 1;
        }

        for(c = 0; v[c] != '\0'; c++){
            printf("%c", v[c]);
        }

        for(c = 0; c < 1000; c++){
            v2[c] = '\0';
            v[c] = '\0';
        }
        printf("\n");
    }
    return 0;
}

//abc
//def - 1
//fed - 2
//fdc - 3