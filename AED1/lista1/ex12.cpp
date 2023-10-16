#include <iostream>
#include <vector>

using namespace std;

int n = 3;

vector<vector<vector<int>>> matrix3d (n, vector<vector<int>>(n, vector<int>(n)));

int main(){

    for(int c = 0; c < n; c++){
        for(int d = 0; d < n; d++){
            for(int e = 0; e < n; e++){
                matrix3d[c][d][e] = c + d + e;
            }
        }
    }
    cout << endl;

    for(int c = 0; c < n; c++){
        for(int d = 0; d < n; d++){
            for(int e = 0; e < n; e++){
                cout << matrix3d[c][d][e] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}