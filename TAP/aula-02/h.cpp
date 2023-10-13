#include <iostream>

using namespace std;

int main(){
    string str;
    bool valido;

    cin >> str;

    for(int i = 0; i < str.size(); i++){
        
        valido = true;
        
        for(int i2 = i+1; i2 < str.size(); i2++){
            if(str[i2] != str[i2 % (i+1)]){
                valido = false;
                break;
            }
        }

        if(valido) cout << i+1 << " ";
    }

    return 0;
}