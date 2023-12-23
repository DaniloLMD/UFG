#include <iostream>

using namespace std;

#define humberto long long

int main(){

    double c, v;

    cin >> c >> v;

    humberto limite = v / c;
    humberto h = 0, atual = 0, total;

    for(int i = 1; total < limite ;i++){
        atual = atual + i;
        total += atual;
        if(total <= limite)
            h++;
    }

    cout << h << endl;

    return 0;
}