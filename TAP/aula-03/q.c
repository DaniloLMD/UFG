#include<stdio.h>
#include<math.h>
 
int calculateBase4(int num){
    if (num == 0) return 0;
    int rest;
    int result = 0;
    int i = 0;
    do{
        rest = num % 4;
        num = num / 4;
        result += rest * pow(10,i);
        i++;
    } while (num != 0);
    
    return result;
}
 
int main(){
    int n;
    scanf("%d", &n);
    int i,num;
    for (i = 0; i < n; i++){
        if (i != n-1) scanf ("%d ", &num);
        else scanf ("%d", &num);
        if (i != n-1) printf("%d ", calculateBase4(num));
        else printf("%d\n", calculateBase4(num));
    }
}