#include <bits/stdc++.h>
#define ll long long

using namespace std;

int biggest_sum(vector<vector<int>> &vals, vector<vector<int>> &calc, int lin, int col){
    if(calc[lin][col] != -1){
        return calc[lin][col];
    }

    if(lin == vals.size() - 1){
        return calc[lin][col] = vals[lin][col];
    }

    for(int c = col; c <  col + 2; c++){
        if(biggest_sum(vals, calc, lin + 1, c) > calc[lin][col]){
            calc[lin][col] = biggest_sum(vals, calc, lin + 1, c);
        }
    }

    return calc[lin][col] += vals[lin][col];

}

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> values;
        vector<vector<int>> calc;
        for(int c = 1;c <= n; c++){
            values.push_back(vector<int> (c));
            calc.push_back(vector<int>(c, -1));
        }
        for(int c = 0;c < n; c++){
            for(int d = 0; d < values[c].size(); d++){    
                cin >> values[c][d];
            }
        }
        cout << biggest_sum(values, calc, 0, 0) << "\n";
    }

    return 0;
}