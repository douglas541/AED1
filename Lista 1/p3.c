#include <stdio.h>
#include <string.h>

int main()
{
   int n1, n2, overflow, operacao;
   char sinal;

   scanf("%d %d %c %d", &overflow, &n1, &sinal, &n2);

   if (sinal == 'x')
   {
      operacao = n1 * n2;
      if (operacao > overflow)
         printf("overflow\n");
      else
         printf("no overflow\n");
   }
   else
   {
      operacao = n1 + n2;
      if (operacao > overflow)
         printf("overflow\n");
      else
         printf("no overflow\n");
   }

   return 0;
}