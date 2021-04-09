#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct aluno {
   int pontos;
   char nome[20];
} Aluno;

int BubbleSort(Aluno*, int);

int main() {
   int n1, pontos, i, j;
   char nome[20];
   Aluno alunos[N];

   scanf("%d", &n1);
   for (i = 0; i < n1; i++) {
      scanf("%s", alunos[i].nome);
      scanf("%d", &alunos[i].pontos);
   }

   BubbleSort(alunos, n1);

   for (i = 0; i < n1; i++) {
      printf("%s ", alunos[i].nome);
      printf("%d", alunos[i].pontos);

      if (i != n1 - 1) {
         printf("\n");
      }
   }

   printf(" #reprovado(a)\n");
}

int BubbleSort(Aluno* alunos, int tamanho) {
   int i, j, trocas = 0;
   Aluno aux;

   for (i = 0; i < tamanho; i++) {
      for (j = i; j < tamanho; j++) {
         if (alunos[i].pontos < alunos[j].pontos) {
            aux = alunos[i];
            alunos[i] = alunos[j];
            alunos[j] = aux;
            trocas++;
         }
      }
   }
   for (i = 0; i < tamanho; i++) {
      for (j = i; j < tamanho; j++) {
         if ((strcmp(alunos[i].nome, alunos[j].nome) > 0) && (alunos[i].pontos == alunos[j].pontos)) {
            aux = alunos[i];
            alunos[i] = alunos[j];
            alunos[j] = aux;
            trocas++;
         }
      }
   }

   return trocas;
}