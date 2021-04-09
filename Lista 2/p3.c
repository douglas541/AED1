#include <stdio.h>

int fack(int, int);

int main() {
   int m, n;

   scanf("%d %d", &m, &n);
   printf("%d", fack(m, n));
   printf("\n");

   return 0;
}

int fack(int m, int n) {
   if (m == 0)
      return n + 1;
   if (n == 0 && m > 0)
      return fack(m - 1, 1);
   if (n > 0 && m > 0)
      return fack(m - 1, fack(m, n - 1));
}