#include <stdio.h>
#define L 1000

int BubbleSort(int* , int);

int main() {
   int v[L], trocas = 0, n, n2, l, i, j, k, aux;

   scanf("%d", &n);

   for (k = 0; k < n; k++) {
      scanf("%d", &l);

      for (i = 0; i < l; i++) {
         scanf("%d", &v[i]);
      }
      
      trocas = BubbleSort(v, l);

      printf("%d\n", trocas);
      trocas = 0;
   }

   return 0;
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