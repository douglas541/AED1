#include <stdio.h>

#define N 230

int BubbleSort(int*, int);

int main() {
   int n1, n2, insersao, v[N], i, j, k;

   scanf("%d", &n1);
   for (i = 0; i < n1; i++) {
      scanf("%d", &n2);
      for (j = 0; j < n2; j++) {
         scanf("%d", &v[j]);
      }

      BubbleSort(v, n2);

      for (j = 0; j < n2; j++) {
         printf("%d ", v[j]);
      }
      printf("\n");
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