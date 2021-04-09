#include <stdio.h>

int main() {
   int isPrime = 1; // se for primo = 1 ; se não for = 0
   int n, i, j;
   unsigned long int inNumber;

   scanf("%d", &n);

   for (j = 0; j < n; j++) {
      scanf("%lu", &inNumber);
      if (inNumber == 1)
         isPrime = 0;
      if (inNumber >= 2) {
         for (i = 2; i < (inNumber + 3) / 2; i++) {
            if (inNumber % i == 0) {
               isPrime = 0;
               // printf("inNumber: %d\ni: %d\no resto e: %d\n", inNumber, i, inNumber % i);
            }
         }
      }
      if (isPrime == 1)
         printf("primo\n");
      else
         printf("composto\n");
   }

   return 0;
}