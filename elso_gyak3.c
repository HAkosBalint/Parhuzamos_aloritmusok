#include <stdio.h>
#include <unistd.h>

int main() {

    int szam;

    printf("Adja meg az idozito hosszat: ");

    scanf("%d",&szam);

    sleep(szam);

    printf("Lejart az ido!!");

}