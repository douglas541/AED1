#include <stdio.h>

#define N 100

int BubbleSort(int*, int);

int main() {
   int vFinal[N], vPar[N], vImpar[N], i, j, n, insersao, tamVImpar = 0, tamVPar = 0;

   scanf("%d", &n);

   for (i = 0; i < n; i++) {
      scanf("%d", &insersao);

      if ((insersao % 2) == 0) {
         vPar[tamVPar] = insersao;
         tamVPar++;
      }
      else {
         vImpar[tamVImpar] = insersao;
         tamVImpar++;
      }
   }

   BubbleSort(vPar, tamVPar);
   BubbleSort(vImpar, tamVImpar);

   // for (i = 0; i < tamVPar; i++) {
   //    vFinal[i] = vPar[i];
   // }
   // for (i = tamVPar; i < (tamVPar + tamVImpar); i++) {
   //    vFinal[((tamVPar + tamVImpar) - (i - tamVPar) - 1)] = vImpar[(i - tamVPar)];
   // }

   for (i = 0; i < tamVPar; i++) {
      printf("%d ", vPar[i]);
   }
   printf("\n");
   for (i = (tamVImpar - 1); i >= 0; i--) {
      printf("%d ", vImpar[i]);
   }
   printf("\n");

   // printf("total: %d\n", (tamVPar + tamVImpar));

   // for (i = 0; i < (tamVPar + tamVImpar); i++)
   //    printf("%d ", vFinal[i]);
   // printf("\n");

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