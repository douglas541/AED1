#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//-------------------lista.h--------------------
typedef struct lista Lista;
typedef struct no No;
Lista* criaListaVazia();
bool insereInicio(Lista*, char*);
char* removeInicio(Lista*);
bool destroiLista(Lista*);
int listaObtemTamanho(Lista*);

//-------------------lista.c--------------------
struct lista {
   int tamanho;
   No* primeiro;
   No* ultimo;
};

struct no {
   char* dado;
   No* proximo;
};

Lista* criaListaVazia() {
   Lista* q = (Lista*)malloc(sizeof(Lista));

   if (q != NULL) {
      q->primeiro = NULL;
      q->ultimo = NULL;
      q->tamanho = 0;
   }

   return q;
}

bool insereInicio(Lista* lista, char* dado) {
   No* q = (No*)malloc(sizeof(No));
   char* aux = (char*)malloc(sizeof(char));
   strcpy(aux, dado);

   if (lista == NULL || dado == NULL) {
      return false;
   }
   else {
      q->dado = aux;
      q->proximo = lista->primeiro;
      lista->primeiro = q;

      if (lista->tamanho == 0) {
         lista->ultimo = q;
      }

      lista->tamanho++;
   }

   return true;
}

char* removeInicio(Lista* lista) {
   No* auxNo;
   char* auxDado = (char*)malloc(sizeof(char));

   if (lista == NULL || lista->tamanho == 0) {
      return (char*)NULL;
   }
   else {
      auxNo = lista->primeiro;
      strcpy(auxDado, auxNo->dado);

      lista->primeiro = lista->primeiro->proximo;

      if (lista->tamanho == 1) {
         lista->ultimo = lista->primeiro;
      }

      lista->tamanho--;
      free(auxNo->dado);
      free(auxNo);

      return auxDado;
   }
}

bool destroiLista(Lista* lista) {
   No* aux = (No*)malloc(sizeof(No));
   if (lista != NULL) {
      return false;
   }

   if (lista->tamanho == 0) {
      free(lista);
   }
   else {
      if (lista->tamanho == 1) {
         free(lista->primeiro);
         free(lista);
      }
      else {
         while (lista->tamanho != 0) {
            aux = lista->primeiro;
            lista->primeiro = lista->primeiro->proximo;
            free(aux);
         }
      }
   }

   free(aux);
   return true;
}

int listaObtemTamanho(Lista* lista) {
   if (lista != NULL) {
      return (lista->tamanho);
   }
}

//--------------------main.c--------------------
int main() {
   Lista* lista;
   char* aux = (char*)malloc(sizeof(char) * 20);
   int n, i, j, tamanho;

   lista = criaListaVazia();

   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      while (strcmp(aux, "ESCOLA")) {
         scanf("%s", aux);
         insereInicio(lista, aux);
      }
      removeInicio(lista);

      tamanho = listaObtemTamanho(lista);
      for (j = 0; j < tamanho; j++) {
         if (listaObtemTamanho(lista) > 1) {
            aux = removeInicio(lista);

            if (!strcmp(aux, "DIREITA")) {
               printf("Vire a ESQUERDA na rua %s.\n", removeInicio(lista));
            }
            else {
               printf("Vire a DIREITA na rua %s.\n", removeInicio(lista));
            }
         }
         else {
            aux = removeInicio(lista);

            if (!strcmp(aux, "DIREITA")) {
               printf("Vire a ESQUERDA na sua CASA.\n");
            }
            else {
               printf("Vire a DIREITA na sua CASA.\n");
            }

            break;
         }
      }
   }



   // insereInicio(lista, "um");
   // insereInicio(lista, "dois");

   // printf("%s\n", removeInicio(lista));
   // printf("%s\n", removeInicio(lista));


   destroiLista(lista);

   return 0;
}