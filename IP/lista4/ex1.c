#include <stdio.h>

int main(){
    int m[2][2];
    int det = 0;
    int i, j;

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            scanf("%d", &m[i][j]);
        }
    }

    det += (m[0][0] * m[1][1]) - (m[0][1]*m[1][0]);

   printf("%d\n", det);


    return 0;
}