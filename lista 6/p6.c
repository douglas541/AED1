#include <stdio.h>

#define N 1000

int BubbleSort(int*, int);

int main() {
   int n, l, k, i, j, soma, v[N];

   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      scanf("%d", &v[i]);
   }
   scanf("%d %d", &l, &k);

   BubbleSort(v, n);

   soma = v[l - 1] + v[k - 1];

   printf("%d\n", soma);
}

int BubbleSort(int* v, int tamanho) {
   int i, j, aux, trocas = 0;

   for (i = 0; i < tamanho; i++) {
      for (j = i; j < tamanho; j++) {
         if (v[i] > v[j]) {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            trocas++;
         }
      }
   }

   return trocas;
}