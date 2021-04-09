#include <stdio.h>

#define N 1000
#define K 20

typedef struct {
   int indice;
   int qtd;
} Carta;

int main() {
   int n, n2, k, i, j, menor = N;
   Carta cartas[N];

   scanf("%d %d", &n, &k);

   for (i = 0; i < n; i++) {
      scanf("%d", &n2);
      cartas[n2 - 1].indice = n2;
      cartas[n2 - 1].qtd++;
   }

   for (i = 0; i < k; i++) {
      if (cartas[i].qtd < menor)
         menor = cartas[i].qtd;
   }

   printf("%d\n", menor);

   // for (i = 0; i < k; i++) {
   //    printf("%d %d\n", cartas[i].indice, cartas[i].qtd);
   // }

   return 0;
}