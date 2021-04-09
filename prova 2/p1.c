#include <stdio.h>
#define N 1000

//retorna o valor procurado se sao iguais, -1 se forem diferentes
int buscaSequencial(int*, int, int);
int BubbleSort(int*, int);
int iguais(int*, int, int*, int);

int main() {
   int input, v1[N], v2[N], cont, tamV1, tamV2, igual = 0, diferentes[N], diferente = 0, i;

   input = 0;
   cont = 0;
   while (1) {
      scanf("%d", &input);

      if (input == -1) {
         break;
      }

      if (buscaSequencial(v1, cont, input) == -1) {
         v1[cont] = input;
         cont++;
      }
      else {

      }
   }

   tamV1 = cont;
   cont = 0;
   input = 0;
   while (1) {
      scanf("%d", &input);

      if (input == -1) {
         break;
      }

      if (buscaSequencial(v2, cont, input) == -1) {
         v2[cont] = input;
         cont++;
      }
      else {

      }
   }
   tamV2 = cont;

   if (tamV1 > tamV2) {
      for (i = 0; i < tamV1; i++) {
         if (buscaSequencial(v1, tamV1, v2[i]) != -1) {
            igual++;
         }
         else {
            diferente = 1;
         }
      }
   }
   else {
      for (i = 0; i < tamV2; i++) {
         if (buscaSequencial(v2, tamV2, v1[i]) != -1) {
            igual++;
         }
         else {
            diferente = 1;
         }
      }
   }

   //--------printa os vetores----------

   // for (i = 0; i < tamV1; i++) {
   //    printf("%d ", v1[i]);
   // }
   // printf("\n");
   // for (i = 0; i < tamV2; i++) {
   //    printf("%d ", v2[i]);
   // }
   // printf("\n");

   //-----------------------------------

   cont = 0;
   if (diferente == 1) {
      for (i = 0; i < tamV2; i++) {
         if (buscaSequencial(v1, tamV1, v2[i]) == -1) {
            diferentes[cont] = v2[i];
            cont++;
         }
      }
      for (i = 0; i < tamV1; i++) {
         if (buscaSequencial(v2, tamV2, v1[i]) == -1) {
            diferentes[cont] = v1[i];
            cont++;
         }
      }
   }

   BubbleSort(diferentes, cont);
   if (diferente == 1) {
      printf("diferentes");
      for (i = 0; i < cont; i++) {
         printf(" %d", diferentes[i]);
      }
   }
   else {
      printf("iguais %d", igual);
   }
   printf("\n");

   return 0;
}

int buscaSequencial(int* v, int tamanho, int pesq) {
   int i;
   // printf("tamanho: %d, pesquisa: %d, v[i]: %d\n", tamanho, pesq, v[i]);
   for (i = 0;i < tamanho;i++) {
      if (v[i] == pesq) {
         return i;
      }
   }
   return -1;
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

int iguais(int* v1, int tamV1, int* v2, int tamV2) {
   int igual = 1, i, j;

   for (i = 0; i < tamV1; i++) {
      if (buscaSequencial(v1, tamV1, v2[i]) != -1) {
         igual = 0;
      }
   }
}