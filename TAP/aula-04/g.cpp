#include <iostream>
#include <vector>

using namespace std;

int main(){
    int qtd, n, div;
    int c2;

    cin >> qtd;

    while(qtd--){
        cin >> n;
        div = 0;

        for(int c = 1; ; c++){
            c2 = n / c;
            
            if(c > c2) break;
            else if(c * c2 == n){
                if(c == c2){
                    div++;
                }
                else{
                    div += 2;
                }
            }
            
        }

        cout << div << endl;

    }

    return 0;
}
