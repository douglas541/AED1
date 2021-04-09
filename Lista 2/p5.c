#include <stdio.h>

int binary(int);

int main() {
   int n, n2, i;

   scanf("%d", &n2);
   for (i = 0; i < n2; i++) {
      scanf("%d", &n);
      binary(n);
      printf("\n");
   }

   return 0;
}

int binary(int n) {
   if (n == 1) {
      printf("%d", n);
      return 0;
   }
   if (n == 0)
      return 0;

   int binaryDig = n % 2;
   binary(n / 2);
   printf("%d", binaryDig);
}