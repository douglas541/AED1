#include <stdio.h>

int main()
{
   int i, nRepeticoes, nEntrada, n1, n2;

   scanf("%d", &nRepeticoes);
   for (i = 0; i < nRepeticoes; i++)
   {
      scanf("%d", &nEntrada);
      n1 = (((nEntrada / 100) % 10) * 10) + (nEntrada / 1000);
      n2 = nEntrada % 100;
      if(n1 == n2)
         printf("yes ");
      else
         printf("no ");
   }
   printf("\n");
   return 0;
}