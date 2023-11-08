//questao 4
#include <iostream>

using namespace std;

void reverse(int num, bool primeiro){
    if(primeiro == true && num%10 != 0 || primeiro == false){
        cout << num % 10;
        primeiro = false;
    }

    if(num/10 != 0) reverse(num/10, primeiro);
}

int main(){
    int num;

    cin >> num;
    reverse(num, true);
    cout << endl;

    return 0;
}