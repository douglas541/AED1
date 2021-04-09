#include <stdio.h>

int main()
{
   int nEntrada1, nEntrada2, nInverso1, nInverso2, maior;

   scanf("%d %d", &nEntrada1, &nEntrada2);

   nInverso1 = ((nEntrada1 % 10) * 100) + (((nEntrada1 % 100) / 10) * 10) + nEntrada1 / 100;
   nInverso2 = ((nEntrada2 % 10) * 100) + (((nEntrada2 % 100) / 10) * 10) + nEntrada2 / 100;

   maior = nInverso1 > nInverso2 ? nInverso1 : nInverso2;

   printf("%d\n", maior);

   return 0;
}