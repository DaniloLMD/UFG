#include <bits/stdc++.h>

using namespace std;

int main(){
    long long unsigned int N, max = 0, teste = 1;

    cin >> N;

    while(teste >1){
        N /= 2;
        max++;
    }

    cout << max - 1 << endl;
    return 0;
}