#include <stdio.h>

#define N 1000

int insertionSort(int*, int);
int selectionSort(int*, int);

int main() {
   int vSelection[N], vInsertion[N], trocasInsertion, trocasSelection, diferenca, i, j, n;

   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      scanf("%d", &vSelection[i]);
      vInsertion[i] = vSelection[i];
   }

   trocasInsertion = insertionSort(vInsertion, n);
   trocasSelection = selectionSort(vSelection, n);

   diferenca = trocasInsertion - trocasSelection;

   printf("%d\n", diferenca);

   return 0;
}

int insertionSort(int* v, int n) {
   int i, j, aux, trocas = 0;

   i = 0;
   j = 1;
   aux = 0;
   while (j < n) {
      aux = v[j];
      i = j - 1;
      while ((i >= 0) && (v[i] > aux)) {
         v[i + 1] = v[i];
         i--;
         trocas++;
      }
      v[i + 1] = aux;
      j++;
      trocas++;
   }

   return trocas;
}

int selectionSort(int* v, int n) {
   int i, j, min, aux, trocas = 0;

   for (i = 0; (i < (n - 1)); i++) {
      min = i;
      for (j = (i + 1); (j < n); j++) {
         if (v[j] < v[min])
            min = j;
      }
      if (v[i] != v[min]) {
         aux = v[i];
         v[i] = v[min];
         v[min] = aux;
         trocas++;
      }
   }

   return trocas;
}