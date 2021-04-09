#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 1000

//---------------lista.h----------------

typedef struct lista Lista;
Lista* criaListaVazia();
bool insereFinal(Lista* lista, int chave);
bool insereAposChave(Lista* lista, int chave, int chaveInserida);
bool removeChave(Lista* lista, int chave);
int quantidadeAB(Lista* lista, int a, int b);
bool mostraLista(Lista* lista);
bool destroiLista(Lista* lista);

//---------------lista.c----------------

struct lista {
   int tamanho;
   int dados[N];
};

Lista* criaListaVazia() {
   Lista* q = malloc(sizeof(Lista));

   if (q != NULL) {
      q->tamanho = 0;
   }

   return q;
}

bool insereFinal(Lista* lista, int chave) {
   if (lista == NULL) {
      return false;
   }
   if (lista->tamanho == N) {
      return false;
   }

   lista->dados[lista->tamanho] = chave;
   lista->tamanho++;

   return true;
}

bool insereAposChave(Lista* lista, int chave, int chaveInserida) {
   int i, posicao;

   if (lista == NULL) {
      return false;
   }
   if (lista->tamanho == N) {
      return false;
   }

   for (i = 0; i < lista->tamanho; i++) {
      if (lista->dados[i] == chave) {
         posicao = i + 1;
      }
   }

   for (i = lista->tamanho; i > posicao; i--) {
      lista->dados[i] = lista->dados[i - 1];
   }

   lista->tamanho++;
   lista->dados[posicao] = chaveInserida;

   return true;
}

bool removeChave(Lista* lista, int chave) {
   int i, posicao;

   if (lista == NULL) {
      return false;
   }
   if (lista->tamanho == 0) {
      return false;
   }

   for (i = 0; i < lista->tamanho; i++) {
      if (lista->dados[i] == chave) {
         posicao = i;
      }
   }

   for (i = posicao; i < lista->tamanho; i++) {
      lista->dados[i] = lista->dados[i + 1];
   }

   lista->tamanho--;

   return true;
}

int quantidadeAB(Lista* lista, int a, int b) {
   int i, posicaoA, posicaoB, distancia;

   if (lista == NULL) {
      return false;
   }
   if (lista->tamanho == 0) {
      return false;
   }

   for (i = 0; i < lista->tamanho; i++) {
      if (lista->dados[i] == a) {
         posicaoA = i;
         break;
      }
   }

   for (i = 0; i < lista->tamanho; i++) {
      if (lista->dados[i] == b) {
         posicaoB = i;
         break;
      }
   }

   // printf("posicaoA: %d\nposicaoB: %d\n", posicaoA, posicaoB);

   distancia = posicaoA - posicaoB;
   if (distancia < 0) {
      distancia = distancia * -1;
      // printf("entrou na condicional\n");
   }
   distancia = distancia - 1;

   if (distancia < 0) {
      return 0;
   }

   return distancia;
}

bool mostraLista(Lista* lista) {
   int i;

   if (lista == NULL) {
      return false;
   }
   if (lista->tamanho == 0) {
      return false;
   }

   printf("lista ");
   for (i = 0; i < lista->tamanho; i++) {
      printf("%d ", lista->dados[i]);
   }
   printf("\n");
}

bool destroiLista(Lista* lista) {
   if (lista != NULL) {
      free(lista);
      return true;
   }

   return false;
}

//-----------------MAIN.C---------------------

int main() {
   int i, n, n1, n2, saida;
   char operacao = '0';
   Lista* lista = criaListaVazia();

   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      scanf("%d", &n1);
      insereFinal(lista, n1);
   }
   while (operacao != 'F') {
      scanf(" %c", &operacao);

      if (operacao == 'I') {
         scanf("%d", &n1);
         scanf("%d", &n2);
         insereAposChave(lista, n2, n1);
         printf("inserido %d\n", n1);
      }
      if (operacao == 'R') {
         scanf("%d", &n1);
         removeChave(lista, n1);
         printf("removido %d\n", n1);
      }
      if (operacao == 'C') {
         scanf("%d", &n1);
         scanf("%d", &n2);
         printf("quantidade %d\n", quantidadeAB(lista, n1, n2));
      }
      if (operacao == 'M') {
         mostraLista(lista);
      }
   }
   printf("fim\n");

   destroiLista(lista);

   return 0;
}