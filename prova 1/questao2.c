#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10000
#define C_MAIOR -1000001

//-----------------Vetor.h------------------

int* criaVetorVazio();
bool destroiVetor(int* vetor);

//-----------------Vetor.c------------------

int* criaVetorVazio() {
   int* v = (int*)malloc(sizeof(int) * N);

   if (v != NULL) {
      return v;
   }
}

bool destroiVetor(int* vetor) {
   if (vetor != NULL) {
      free(vetor);
      return true;
   }

   return false;
}

//-------------CORPO PRINCIPAL--------------

int main() {
   int* v;
   int n1, n2, i, j, k, maior, contadorMaiores, produto;

   v = criaVetorVazio();

   scanf("%d", &n1);
   for (k = 0; k < n1; k++) {
      contadorMaiores = 0;
      maior = C_MAIOR;

      scanf("%d", &n2);
      for (i = 0; i < n2; i++) {
         scanf("%d", &v[i]);
      }

      for (i = 0; i < n2; i++) {
         for (j = i; j < n2; j++) {
            // printf("(%d, %d) ", v[i], v[j]);

            produto = v[i] * v[j];

            if (produto > maior) {
               maior = produto;
               contadorMaiores = 0;
            }

            if (produto == maior) {
               contadorMaiores++;
            }
         }
      }
      // printf("\nmaior produto: %d\ncontador maiores: %d\n", produto, contadorMaiores);
      printf("%d\n", contadorMaiores);
   }

   destroiVetor(v);
   return 0;
}