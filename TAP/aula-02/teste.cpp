#include <iostream>
using namespace std;
int main(){
    
    char x = 'a';
    for(int c = 0; c <= 1000000; c++){
        cout << x;
        x++;
        if(x > 'z') x = 'a';
    }   
    cout << endl;

    return 0;
}