#include <iostream>
#include <vector>

using namespace std;

int base[2][2] = {{0, 1}, {1, 1}};
int modulo = 1e9+7;

void mult_matriz(int a[2][2], int b[2][2], int resultado[2][2]){
    resultado[0][0] = a[0][0] % modulo * b[0][0] % modulo + a[0][1] % modulo * b[1][0] % modulo;
    resultado[0][1] = a[0][0] % modulo * b[0][1] % modulo + a[0][1] % modulo * b[1][1] % modulo;
    resultado[1][0] = a[1][0] % modulo * b[0][0] % modulo + a[1][1] % modulo * b[1][0] % modulo;
    resultado[1][1] = a[1][0] % modulo * b[0][1] % modulo + a[1][1] % modulo * b[1][1] % modulo;
}

void pot_matriz(int ){
    
}

int main(){
    int x[2][2];
    int x2[2][2];
    mult_matriz(base, base, x); //x2
    mult_matriz(x , x, x2); // (x2)2
    mult_matriz(x2, base, x); //x.(x2)2
    mult_matriz(x, x, x2);

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << x2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}