#include <stdio.h>

unsigned int reverso(unsigned int);

int main() {
   unsigned int n1, result;

   scanf("%d", &n1);
   printf("%d\n", reverso(n1));

   return 0;
}

unsigned int result = 0, resto;
unsigned int reverso(unsigned int n1) {
   if (n1 == 0)
      return 0;

   resto = n1 % 10;
   result = (result * 10) + resto;
   reverso(n1 / 10);
   return result;
}