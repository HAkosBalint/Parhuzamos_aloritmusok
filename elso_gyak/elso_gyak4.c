#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
int main() {
   
    srand(time(NULL)); 

    int szam = (rand() % (1000 - 500 + 1)) + 500;

    printf("Egesz szam: %d\n",szam);

    float lebegoszam = ((float)rand()/RAND_MAX)*(float)(100.0);

    printf("Lebegopontos: %lf",lebegoszam);

    return 0;
}