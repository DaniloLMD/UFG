#include <iostream>

using namespace std;

int main(){

    string temp;    
    int n;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == "and" || temp == "not" || temp == "that" || temp == "the" || temp == "you"){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}