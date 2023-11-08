#include <iostream>
#include <vector>

using namespace std;

int main(){
    int tot, k;
    cin >> tot >> k;
    vector<int>val(tot);

    for(int i = 1; i <= tot; i++){
        val[i-1] = i;
    }

    int a = 0;
    for(int i = 0; i < tot; i++){
        for(int j = i+k-1; j < tot; j++){
            for(int k = i; k <= j; k++){
                cout << k+1 << " ";
            }
            cout << endl;
        }
    }



    return 0;
}