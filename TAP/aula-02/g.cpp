#include <iostream>
#include <vector>
using namespace std;

vector<int> z_function(string palavra){
    int l = 0, r = 0, n = palavra.size();
    vector<int> z(n);

    for(int i = 1; i < n; i++){

        if(i < r){
            z[i] = min(r - i, z[i - l]);
        }

        while(i + z[i] < n && palavra[i+z[i]] == palavra[z[i]]){
            z[i]++;
        }

        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }

    }

    return z;
}   


int main(){
    string str;

    cin >> str;

    vector<int> z = z_function(str);

    for(int c = 0; c < str.size() - 1; c++){
        if(z[str.size() - 1 - c] == c + 1){
            cout << c+1 << " ";
        }
    }

    return 0;
}