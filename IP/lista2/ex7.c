#include <stdio.h>
 
void print_bytes( const void * end_byte, int n ){
    unsigned char *p = (unsigned char*) end_byte;
    int peso = 128, res;
    int c, d;
 
    for(c = 0; c < n; c++){
        for(d = 0; d < 8; d++){
            res = *p / peso;
            printf("%d", res);
            if(res == 1) *p = *p - peso; 
            peso = peso / 2;
        }
        printf(" ");
        *p++;
        peso = 128;
    }
    printf("\n");
}
 
int main(){
    double num;
    scanf("%lf", &num);
 
    unsigned char a = (unsigned char) num;
    unsigned short b = (unsigned short) num;
    unsigned int c = (unsigned int) num;
    float d = (float) num;
 
    print_bytes(&a, 1);
    print_bytes(&b, 2);
    print_bytes(&c, 4);
    print_bytes(&d, 4);
    print_bytes(&num, 8);
 
    return 0;
}
