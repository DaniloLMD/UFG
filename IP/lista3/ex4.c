#include <stdio.h>
 
int main(){
    int n, c;
    char v[1000];
    int led[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int numLed = 0, t;
 
 
    scanf("%d", &n);
 
    while(n--){
        scanf("%s", v);
        for(c = 0; v[c] != '\0'; c++){
            t = v[c] - '0';
            numLed += led[t];
        }
        printf("%d leds\n", numLed);
        numLed = 0;
    }
 
    return 0;
}