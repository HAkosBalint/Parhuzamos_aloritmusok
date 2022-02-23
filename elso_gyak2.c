#include <stdio.h>

int main(void){

    printf("Kerlek adj me ey maximum 8 szamjeyu szamot:\n");

    int szam;

    scanf("%d", &szam);

   printf("0-akkal: %.8d\n",szam);

   printf("Szokozokkel:");

   for(int i = 0; i < 8; i++)
   {
      printf(" ");
   }
   printf("%d",szam);


}