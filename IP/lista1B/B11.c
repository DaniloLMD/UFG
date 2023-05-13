#include <stdio.h>

int main() {
    int T, A, B;
    int inversoA, inversoB;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &A, &B);
        inversoA = (A % 10) * 100 + ((A % 100) / 10) * 10 + (A / 100);
        inversoB = (B % 10) * 100 + ((B % 100) / 10) * 10 + (B / 100);

        if (inversoA > inversoB) {
            printf("%d\n", inversoA);
        } else {
            printf("%d\n", inversoB);
        }
    }

    return 0;
}
