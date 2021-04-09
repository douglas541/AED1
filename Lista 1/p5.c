#include <stdio.h>

#define SIZE 100

int main() {
   int nTestes, n, nSaida[SIZE], i, j, k, l;

   scanf("%d", &nTestes);

   for (i = 0; i < nTestes; i++) {
      scanf("%d", &n);

      for (k = 0; n > 0; k++) {
         nSaida[k] = (n % 4);
         n = n / 4;
      }

      // printf("%d\n", k);
      // printf("%d ", nSaida[0]);
      // printf("%d\n", nSaida[1]);

      for (l = k-1; l >= 0; l--) {
         if (nSaida[l] == 0)
            printf("A");
         if (nSaida[l] == 1)
            printf("C");
         if (nSaida[l] == 2)
            printf("G");
         if (nSaida[l] == 3)
            printf("T");
      }
      printf("\n");
   }

   return 0;
}