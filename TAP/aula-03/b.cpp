#include <bits/stdc++.h>

using namespace std;

int main(){
    int tama, tamb, c = 0;

    cin >> tama >> tamb;
    vector<int> a(tama);
    vector<int> b(tamb);

    for(int i = 0; i < tama; i++){
        cin >> a[i];
    }

    for(int i = 0; i < tamb; i++){
        cin >> b[i];
    }

    sort(a.begin(), a.end());

    for(int j = 0; j < tamb; j++){
        int c = upper_bound(a.begin(), a.end(), b[j]) - a.end();
        cout << a.size() + c << " ";
    }
    cout << endl;



    return 0;
}