#include <iostream>

using namespace std;

int main(){

    string str;
    int i1, i2, i12, i22, tam;
    bool achei;

    cin >> str;

    for(i1 = 0, i2 = str.size() - 1; i1 < i2; i1++, i2--){
        tam = 0;
        achei = true;
        for(i12 = 0, i22 = i2; i12 <= i1 && i22 < str.size(); i12++, i22++){
            if(str[i12] == str[i22]){
                tam++;
            }
            else{
                achei = false;
                break;
            }
        }
        if(achei){
            cout << tam << " ";  
        }
    }

    return 0;
}