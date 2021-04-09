#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 60000

//--------------lista.h---------------
typedef struct lista Lista;
Lista* criaListaVazia();
bool inserirFinal(Lista*, int);
bool removerChave(Lista*, int);
bool destruirLista(Lista*);
int obtemTamanhoLista(Lista*);

//--------------lista.c---------------
struct lista {
   int tamanho;
   int pessoas[N];
};

Lista* criaListaVazia() {
   Lista* lista;
   lista = (Lista*)malloc(sizeof(Lista));

   if (lista != NULL) {
      lista->tamanho = 0;
   }

   return lista;
}

bool inserirFinal(Lista* lista, int dado) {
   if (lista == NULL) {
      return false;
   }
   if (lista->tamanho == N) {
      return false;
   }

   lista->pessoas[lista->tamanho] = dado;
   lista->tamanho++;

   return true;
}

bool removerChave(Lista* lista, int chave) {
   int i, j;

   for (i = 0; i < lista->tamanho; i++) {
      if (chave == lista->pessoas[i]) {
         for (j = i; j < lista->tamanho - 1; j++) {
            lista->pessoas[j] = lista->pessoas[j + 1];
         }
         lista->tamanho--;
         return true;
      }
   }

   return false;
}

bool destruirLista(Lista* lista) {
   if (lista != NULL) {
      free(lista);
      return true;
   }

   return false;
}

int obtemTamanhoLista(Lista* lista) {
   if (lista != NULL) {
      return lista->tamanho;
   }
}

//---------------MAIN.C---------------

int main() {
   int chavePessoa, i, n, n2, listaTamanho;
   Lista* lista;

   lista = criaListaVazia();

   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      scanf("%d", &chavePessoa);
      inserirFinal(lista, chavePessoa);
   }

   scanf("%d", &n2);
   for (i = 0; i < n2; i++) {
      scanf("%d", &chavePessoa);
      removerChave(lista, chavePessoa);
   }

   listaTamanho = obtemTamanhoLista(lista);
   for (i = 0; i < listaTamanho; i++) {
      printf("%d ", lista->pessoas[i]);
   }
   printf("\n");


   return 0;
}