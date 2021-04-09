#include <stdio.h>

double fDuplo(int);

int main() {
   int n;

   scanf("%d", &n);
   printf("%.0lf\n", fDuplo(n));

   return 0;
}

double fDuplo(int n) {
   if (n == 1)
      return 1;

   if (n % 2 == 0)
      return fDuplo(n - 1);         // se o fatorando n for par, chame a função para o próximo ímpar

   return n * fDuplo(n - 2);
}