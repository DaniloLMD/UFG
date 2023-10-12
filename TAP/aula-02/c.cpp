#include <iostream>

#include <algorithm>

using namespace std;

int main(){
    string str;
    int l, r;

    cin >> l >> r;
    cin >> str;

    reverse(str.begin()+l-1, str.begin()+r);

    cout << str << endl;

    return 0;
}