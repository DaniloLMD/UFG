#include <stdio.h>
#include <math.h>

#define pi 3.14

int main(){
    char esc;
    int n, n2;
    double seno, cosseno;
    scanf("%c%d", &esc, &n);

    if(esc != 's' && esc != 'c' || n > 360){
        return 0;
    }
    seno = sin(n * pi / 180);
    cosseno = cos(n * pi / 180);

    if(n <= 180 && n > 90) n2 = 180 - n;
    else if(n >= 180 && n < 270) n2 = n - 180;
    else if(n >= 270) n2 = 360 - n;
    else n2 = n;

    printf("%d\n", n2);
    if(esc == 's') printf("%.3lf\n", fabs(seno));
    else printf("%.3lf\n", fabs(cosseno));

    if(esc == 's' && seno < 0 || esc == 'c' && cosseno < 0) printf("SINAL INVERTIDO\n");
    else printf("SINAL IGUAL\n");
    return 0;
}