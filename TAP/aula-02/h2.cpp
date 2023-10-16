#include <iostream>
#include <vector>
using namespace std;

vector<int> z_function(string palavra){
    int l = 0, r = 0, n = palavra.size();
    vector<int> z(n);

    int i2;

    for(int i = 1; i < n; i++){

        if(i < r){
            z[i] = min(r - i, z[i - l]);
        }

        i2 = i;
        while(z[i] < n && palavra[ i2 ] == palavra[z[i]]){
            z[i]++;
            i2++;
            if(i2 >= n) i2 = i;
        }

        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }

    }

    for(int h: z){
        cout << h;
    }
    cout << endl;

    return z;
}   

/*  0123456
    abcabca

    4 + 0 = 4 % 7 = 4
    4 + 1 = 5 % 7 = 5
    4 + 2 = 6 % 7 = 6

    4 + 3 = 3 % 7 = 0 + 4 = 4
    4 + 4 = 8 % 7 = 1 + 4 = 5
    4 + 5 = 9 % 7 = 2 + 4 = 6

    4 + 6 = 10 % 7 = 3 + 1 = 4

       . 
    ...####
    abcabca

        
    abcabc#abcabca

*/


int main(){
    string str;

    cin >> str;

    vector<int> z = z_function(str);

    /*for(int c = 0; c < str.size() - 1; c++){
        if(z[str.size() - 1 - c] == c + 1){
            cout << c+1 << " ";
        }
    }*/

    return 0;
}