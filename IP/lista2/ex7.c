#include <stdio.h>
#include <math.h>

void print_bytes( const void * end_byte, int n ){


}

int main(){
    double n;
    double *pont;

    scanf("%lf", &n);
    pont = &n;

    print_bytes(pont, sizeof(double));
    return 0;
}