#include <stdio.h>

unsigned long int fibo(unsigned long int);

int main() {
   unsigned long int n, i;

   scanf("%lu", &n);
   for (i = 0; i <= n; i++) {
      printf("%lu ", fibo(i));
   }
   printf("\n");

   return 0;
}

unsigned long int fibo(unsigned long int n) {
   if (n == 0)
      return 0;
   if (n == 1)
      return 1;

   return fibo(n - 1) + fibo(n - 2);
}