#include <iostream>
#include <vector>
#include <algorithm>

#include <unistd.h>

using namespace std;

vector<int> nums1(4);
vector<int> nums2(4);
string str;
int n1, n2, n3;

int get_first_number(){
    int n = 0, peso = 1000;
    for(int i = 0; i < 4; i++){
        n += nums1[i] * peso;
        peso /= 10;
    }
    return n;
}

int get_second_number(){
    int n = 0, peso = 1000;
    for(int i = 0; i < 4; i++){
        n += nums2[i] * peso;
        peso /= 10;
    }
    return n;
}

void number_to_str(int num){

    for(int i = 0; i < 4; i++){
        str[i] = (num%10) + '0';
        num /= 10;
    }

    reverse(str.begin(), str.end());
}

void str_to_number(){
    nums1[0] = str[0] - '0';
    nums1[1] = str[1] - '0';
    nums1[2] = str[2] - '0';
    nums1[3] = str[3] - '0';

    sort(nums1.begin(), nums1.end());
    reverse(nums1.begin(), nums1.end());

    nums2[0] = nums1[3];
    nums2[1] = nums1[2];
    nums2[2] = nums1[1];
    nums2[3] = nums1[0];

   /* printf("nums1:");
    for(int h: nums1){
        cout << h;
    }cout << endl;

    printf("nums2:");
    for(int h: nums2){
        cout << h;
    }cout << endl;*/

    n1 = get_first_number();
    n2 = get_second_number();

   // cout << "n2 = " << n1 << endl;
   // cout << "n3 = " << n2 << endl;
    n3 = n1 - n2;
    
    number_to_str(n3);
}

int main(){


    cin >> str;

    long long int vezes = 0;

    if(str == "6174"){
        cout << 1 << endl;
        return 0;
    }

    while(str != "6174"){
       // cout << "string = " << str << endl;;
        str_to_number();
        vezes++;
       // cout << "----> string = " << str << endl;

        //sleep(1);
    }

    cout << vezes << endl;
    return 0;
}