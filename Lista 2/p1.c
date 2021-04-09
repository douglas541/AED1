#include <stdio.h>

int printaNumeros(int);

int main() {
   int n;

   scanf("%d", &n);
   printaNumeros(n);
   printf("\n");

   return 0;
}

int printaNumeros(int n) {
   if (n == 0)
      return 0;
   
   printaNumeros(n-1);
   printf("%d ", n);
}