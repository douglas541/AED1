#include <stdio.h>

#define N 1000

//se n for primo retorna 1 ; se não for retorna 0
int isPrime(int);
int BubbleSort(int*, int);

int main() {
   int n, i, j, primo = 1, cont = 2, v[N];

   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      scanf("%d", &v[i]);
   }

   BubbleSort(v, n);

   for (i = 0; i < n; i++) {
      for (j = 0; j < v[i]; j++) {
         primo++;
         while (isPrime(primo) != 1) {
            primo++;
         }
      }
      printf("%d ", primo);
      primo = 1;
   }

   printf("\n");

   return 0;
}

int isPrime(int inNumber) {
   int prime = 1, i;

   if (inNumber == 1)
      prime = 0;
   if (inNumber >= 2) {
      for (i = 2; i < (inNumber + 3) / 2; i++) {
         if (inNumber % i == 0) {
            prime = 0;
         }
      }
   }

   return prime;
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