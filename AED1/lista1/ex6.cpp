#include <iostream>

using namespace std;

long int fatDuplo(int n){
    if(n % 2 == 1 && n > 1){
        return n * fatDuplo(n-1);
    }
    else if(n == 1) return 1;
    return fatDuplo(n-1);
}

int main(){
    int num;

    cin >> num;
    cout << fatDuplo(num) << endl;

    return 0;
}