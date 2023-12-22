#include <iostream>
#include <vector>

using namespace std;
#define ll long long

const int mod = 1e9+7;

int main(){

    int t, n, qtd, num;

    char impar;

    cin >> t;
    while(t--){
        cin >> n;

        qtd = 1;
        impar = -1;
        for(int i = 0; i < n; i++){
            cin >> num;
            if(num%2 == 0)
                qtd = (qtd*2)%mod;
            else{
                impar = 1;
            }
        }

        if(impar == -1){
            qtd -= 1;
        }

        cout << qtd << endl;
    }


    return 0;
}