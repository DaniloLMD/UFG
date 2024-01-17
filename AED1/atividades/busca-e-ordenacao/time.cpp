#include <iostream>
#include <unistd.h>

int main(){
    time_t start, end;

    time(&start);
    
    sleep(1);

    time(&end);
    double time_taken = double(end-start);
    printf("Tempo = %.5lf seg\n", time_taken);
    
    time(&start);
    
    sleep(2);

    time(&end);
    time_taken = double(end-start);
    printf("Tempo = %.5lf seg\n", time_taken);
    

    

    return 0;
}